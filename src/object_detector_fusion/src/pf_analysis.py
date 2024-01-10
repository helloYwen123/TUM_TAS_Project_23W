import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Float32MultiArray
#from jsk_rviz_plugins.msg import OverlayText
from obstacle_detector.msg import Obstacles
import numpy as np
import csv
import sys
import math
#from sensor_msgs.msg import ColorRGBA

SAVE_TO_FILE = False
PUBLISH = False

class ParticleFilterViz:

    def __init__(self):
        super().__init__('pf_estimate_analysis')
        self.declare_parameter('publish', False)
        global PUBLISH
        PUBLISH = self.get_parameter('publish').value

        self.start_time = self.get_clock().now()
        self.time_elapsed = 0
        self.print_mu = [[], [], []]

        self.main_sub = self.create_subscription(
            Float32MultiArray, '/estimate/values/mean', self.callback, 10)
        self.runtime_sub = self.create_subscription(
            Float32, '/runtime', self.runtime_callback, 10)
        self.obstacle_sub = self.create_subscription(
            Obstacles, '/raw_obstacles/camera_obstacles', self.obstacle_callback, 10)
        self.lidar_sub = self.create_subscription(
            Obstacles, '/raw_obstacles/lidar_obstacles', self.lidar_callback, 10)
        # self.text_pub_1 = self.create_publisher(
        #     OverlayText, "/estimate/values/text_overlay/1", 1)
        # self.text_pub_2 = self.create_publisher(
        #     OverlayText, "/estimate/values/text_overlay/2", 1)
        # self.text_pub_3 = self.create_publisher(
        #     OverlayText, "/estimate/values/text_overlay/3", 1)
        if PUBLISH:
            self.dist = self.create_publisher(
                '/estimate/values/1/dist', Float32, queue_size=1)
            self.x_1 = self.create_publisher(
                '/estimate/values/1/pos_x', Float32, queue_size=1)
            self.y_1 = self.create_publisher(
                '/estimate/values/1/pos_y', Float32, queue_size=1)
            self.dist = self.create_publisher(
                '/estimate/values/1/vel', Float32, queue_size=1)
            self.x_vel_1 = self.create_publisher(
                '/estimate/values/1/vel_x', Float32, queue_size=1)
            self.y_vel_1 = self.create_publisher(
                '/estimate/values/1/vel_y', Float32, queue_size=1)
            self.x_acc_1 = self.create_publisher(
                '/estimate/values/1/acc_x', Float32, queue_size=1)
            self.y_acc_1 = self.create_publisher(
                '/estimate/values/1/acc_y', Float32, queue_size=1)
            self.rad_1 = self.create_publisher(
                '/estimate/values/1/rad', Float32, queue_size=1)
    def runtime_callback(self, msg):
        self.runtime = msg.data

    def obstacle_callback(self, msg):
        self.obstacles = msg.circles
    def lidar_callback(self, msg):
        self.lidars = msg.circles
    def callback(self, msg):
        main_msg = np.reshape(msg.data, [3, 7])
        #print(main_msg)
        
        pos_x = main_msg[0, 0]
        pos_y = main_msg[0, 1]
        vel_x = main_msg[0, 2]
        vel_y = main_msg[0, 3]
        acc_x = main_msg[0, 4]
        acc_y = main_msg[0, 5]
        rad = main_msg[0, 6]
        if PUBLISH:
            self.x_1.publish(pos_x)
            self.y_1.publish(pos_y)
            self.x_vel_1.publish(vel_x)
            self.y_vel_1.publish(vel_y)
            self.x_acc_1.publish(acc_x)
            self.y_acc_1.publish(acc_y)
            self.rad_1.publish(rad)

#         text = OverlayText()
#         text.width = 400
#         text.height = 600
#         text.left = 10
#         text.top = 10
#         text.text_size = 12
#         text.line_width = 2
#         text.fg_color = ColorRGBA(25 / 255.0, 1.0, 240.0 / 255.0, 1.0)
#         text.bg_color = ColorRGBA(0.0, 0.0, 0.0, 0.2)

#         text.font = "DejaVu Sans Mono"
#         arg = [x for x in main_msg[0, :]]
#         dist = math.sqrt((arg[0]**2 + arg[1]**2))
#         speed = math.sqrt((arg[2]**2 + arg[3]**2))
#         text.text = """
# Runtime: %.2f ms
# Object 1
# Position = [%.2f, %.2f]
# Distance = %.2f
# Velocity = [%.2f, %.2f]
# Speed = %.2f
# Acceleration = [%.2f, %.2f]
# True Radius = %.2f
#   """ % (self.runtime, arg[0], arg[1], dist, arg[2], arg[3], speed, arg[4], arg[5], arg[6])
#         self.text_pub_1.publish(text)

#         arg = [x for x in main_msg[1, :]]
#         dist = math.sqrt((arg[0]**2 + arg[1]**2))
#         speed = math.sqrt((arg[2]**2 + arg[3]**2))
#         text.text = """
# Object 2
# Position = [%.2f, %.2f]
# Distance = %.2f
# Velocity = [%.2f, %.2f]
# Speed = %.2f
# Acceleration = [%.2f, %.2f]
# True Radius = %.2f
#   """ % (arg[0], arg[1], dist, arg[2], arg[3], speed, arg[4], arg[5], arg[6])
#         self.text_pub_2.publish(text)

#         arg = [x for x in main_msg[2, :]]
#         dist = math.sqrt((arg[0]**2 + arg[1]**2))
#         speed = math.sqrt((arg[2]**2 + arg[3]**2))
#         text.text = """
# Object 3
# Position = [%.2f, %.2f]
# Distance = %.2f
# Velocity = [%.2f, %.2f]
# Speed = %.2f
# Acceleration = [%.2f, %.2f]
# True Radius = %.2f
#   """ % (arg[0], arg[1],dist, arg[2], arg[3], speed, arg[4], arg[5], arg[6])
#         self.text_pub_3.publish(text)         
        
        for i, mu in enumerate(main_msg[:3]):
            self.time_elapsed = self.get_clock().now() - self.start_time
            circles = self.obstacles[i]
            circles_lidar = self.lidars[i]
            
            self.print_mu[i].append(np.append(mu, 
            (self.runtime, 
            self.time_elapsed, 
            circles.center.x, 
            circles.center.y, 
            circles.true_radius,
            circles_lidar.x,
            circles_lidar.y,
            circles_lidar.true_radius)))
            #self.print_mu[i].append(np.append(mu, (self.runtime, self.time_elapsed)))
        

def main(arg=None):
    rclpy.init(arg)
    particle_filter_viz = ParticleFilterViz()

    try:
        rclpy.spin(particle_filter_viz)
    except KeyboardInterrupt:
        particle_filter_viz.get_logger().info("ParticelFilter Node stops cleanly!")

    if SAVE_TO_FILE:
        for i in range(len(particle_filter_viz.print_mu)):
            with open("estimate_data_{}.csv".format(i), "w") as f:
                csvwriter = csv.writer(f)
                csvwriter.writerow(["x_estimate",
                                    "y_estimate",
                                    "x_vel_estimate",
                                    "y_vel_estimate",
                                    "x_accel_estimate",
                                    "y_accel_estimate",
                                    "true_rad_estimate",
                                    "runtime",
                                    "time",
                                    "x_cam",
                                    "y_cam",
                                    "rad_cam",
                                    "x_lid",
                                    "y_lid",
                                    "rad_lid"])
                csvwriter.writerows(particle_filter_viz.print_mu[i])
            print("Printed to estimate_data_{}.csv".format(i))
        f.close()
        particle_filter_viz.destroy_node()
        rclpy.shutdown()
    
if __name__ == '__main__':
    main()
    
