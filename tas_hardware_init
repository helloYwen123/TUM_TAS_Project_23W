import rclpy
from rclpy.node import Node 

from geometry_msgs.msg import Pose, Twist, TransformStamped
from nav_msgs.msg import Odometry
from sensor_msgs.msg import JointState
from tf2_ros import TransformBroadcaster
import tf_transformations

import serial
import time
import numpy as np

import traceback



class TasHardware(Node):

    def __init__(self):
        super().__init__('tas_hardware')  # Name of Node

        # Init topics
        self.subscription = self.create_subscription(
            Twist, 'cmd_vel', self.callback_listen_cmdvel, 10)
        self.subscription  # prevent unused variable warning
        self.publisher_odom = self.create_publisher(Odometry, 'odom', 10)
        self.publisher_joint_states = self.create_publisher(
            JointState, 'joint_states', 10)
        self.tf_broadcaster = TransformBroadcaster(self)

        # Serial
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.callback_read_port)
        # TODO: Expection handling, Error if no com-port is available, choos suitable on is onwn,
        # port = '/dev/ttyACM0'
        port = '/dev/ttyUSB0'
        self.ser = serial.Serial(port, 115200, timeout=0.05)
        self.get_logger().info("Connected to TAS-Car via Port " + port)
        self.ser.readline()
        self.ser.flushInput()
        self.ser.flushOutput()


        # Init Odometry
        self.velocity = 0.0
        self.angular_velocity = 0.0
        self.x = 0.0
        self.y = 0.0
        self.angle = 0.0
        self._last_odom_time = time.time()

        # Inital publishing
        self.publish_odom()
        self.publish_tf()
        self.publish_joint_states(0.0, 0.0, 0.0, 0.0)

    def callback_listen_cmdvel(self, cmd_vel):
        output_str = bytes('v' + str(cmd_vel.linear.x) +
                           'o' + str(cmd_vel.angular.z) + '\n', 'ascii')
        self.ser.write(output_str)
        self.get_logger().debug(output_str)
        # self.get_logger().info(output_str)

    def callback_read_port(self):
        # While loop to empty buffer
        while self.ser.in_waiting > 1:
            readline = str(self.ser.readline(), 'UTF-8')
            if readline[0:15] == "Start Debug Msg":

                readline_tmp = str(self.ser.readline(), 'UTF-8')
                i = 0
                while readline_tmp[0:13] != "End Debug Msg" and i < 20:
                    i = i + 1
                    readline = readline + readline_tmp
                    readline_tmp = str(self.ser.readline(), 'UTF-8')
                readline = readline + readline_tmp
                self.get_logger().info("\n" + readline)
            elif readline[0] == "@":
                self.get_logger().debug("cmd " + readline)

                try: 
                    index_v = readline.index('v')
                    index_o = readline.index('o')
                    index_l = readline.index('l')
                    index_r = readline.index('r')
                    index_phil = readline.index('phil')
                    index_phir = readline.index('phir')
                    index_end = readline.index('\n')

                    velocity = float(readline[index_v+1:index_o])
                    angular_velcotiy = float(readline[index_o+1:index_l])
                    pos_left = float(readline[index_l+1:index_r])
                    pos_right = float(readline[index_r+1:index_phil])
                    phi_left = float(readline[index_phil+4:index_phir])
                    phi_right = float(readline[index_phir+4:index_end])
                
                except Exception:
                    traceback.print_exc()
                    self.get_logger().warning("Cannot phrase ESP Command: cmd " + readline)

                else:

                    if  not (abs(velocity) < 10):
                        self.get_logger().warning("Unreasonable received velocity " + str(velocity))
                        self.get_logger().info("cmd " + readline)
                        velocity = 0
                    if  not (abs(angular_velcotiy) < 10):
                        self.get_logger().warning("Unreasonable received angular_velcotiy " + str(angular_velcotiy))
                        self.get_logger().info("cmd " + readline)
                        angular_velcotiy = 0
                    if  not (abs(pos_left) < 10):
                        self.get_logger().warning("Unreasonable received pos_left " + str(pos_left))
                        self.get_logger().info("cmd " + readline)
                    if  not (abs(pos_right) < 10):
                        self.get_logger().warning("Unreasonable received pos_right " + str(pos_right))
                        self.get_logger().info("cmd " + readline)
                    if  not (abs(phi_left) < 10):
                        self.get_logger().warning("Unreasonable received phi_left " + str(phi_left))
                        self.get_logger().info("cmd " + readline)
                    if  not (abs(phi_right) < 10):
                        self.get_logger().warning("Unreasonable received phi_right " + str(phi_right))
                        self.get_logger().info("cmd " + readline)


                    self.calc_odometry(velocity, angular_velcotiy)

                    self.publish_odom()
                    self.publish_tf()
                    self.publish_joint_states(pos_left, pos_right, phi_left, phi_right)
    

    # https://github.com/tslator/arlobot_rpi/blob/master/src/arlobot/arlobot_bringup/scripts/arlobot_odom_pub.py
    def publish_odom(self):
        # next, we will publish the odometry message over ROS
        msg = Odometry()
        msg.header.frame_id = "odom"
        msg.header.stamp = self.get_clock().now().to_msg()
        pose = Pose()
        pose.position.x = self.x
        pose.position.y = self.y
        pose.position.z = 0.0
        quaternion = tf_transformations.quaternion_from_euler(0, 0, self.angle)
        pose.orientation.x = quaternion[0]
        pose.orientation.y = quaternion[1]
        pose.orientation.z = quaternion[2]
        pose.orientation.w = quaternion[3]
        msg.pose.pose = pose

        msg.child_frame_id = "base_footprint"
        msg.twist.twist = Twist()
        msg.twist.twist.linear.x = self.velocity
        msg.twist.twist.angular.z = self.angular_velocity

        self.publisher_odom.publish(msg)

    
    def publish_tf(self):
        # next, we will publish the odometry message over ROS
        msg = TransformStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "odom"
        msg.child_frame_id = "base_footprint"
        msg.transform.translation.x = self.x
        msg.transform.translation.y = self.y
        msg.transform.translation.z = 0.0
        quaternion = tf_transformations.quaternion_from_euler(0, 0, self.angle)
        msg.transform.rotation.x = quaternion[0]
        msg.transform.rotation.y = quaternion[1]
        msg.transform.rotation.z = quaternion[2]
        msg.transform.rotation.w = quaternion[3]
        self.tf_broadcaster.sendTransform(msg)

    def publish_joint_states(self, pos_left, pos_right, phi_left, phi_right):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = ""
        msg.name = ["l_f_wheel_joint", "r_f_wheel_joint",
                    "base_l_b_wheel_joint", "base_r_b_wheel_joint",
                    "l_ack_link_l_f_wheel_joint", "r_ack_link_r_f_wheel_joint"]
        msg.position = [pos_left, pos_right,
                        pos_left, pos_right,
                        phi_left, phi_right]
        msg.velocity = []
        msg.effort = []
        self.publisher_joint_states.publish(msg)

    def calc_odometry(self, velocity, angular_veloctiy):
        """
        :description: Calculate the odometry parameters received from the robot and to be published to the ROS stack
        :return: x, y, angle 
        """
        delta_time = time.time() - self._last_odom_time
        self._last_odom_time = time.time()

        if delta_time < 1.0: 
            self.x = self.x + delta_time * velocity * np.cos(self.angle)
            self.y = self.y + delta_time * velocity * np.sin(self.angle)
            self.angle = self.angle + delta_time * angular_veloctiy
        else:
            self.get_logger().warning("Time Step longer than 1 sec " + str(delta_time))




def main(args=None):
    rclpy.init(args=args)
    minimal_subscriber = TasHardware()
    rclpy.spin(minimal_subscriber)
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
