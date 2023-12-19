import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Pose, Twist, TransformStamped
from std_msgs.msg import Float64MultiArray
from nav_msgs.msg import Odometry
from sensor_msgs.msg import JointState
from tf2_ros import TransformBroadcaster
import tf_transformations

import numpy as np


class TasSimulation(Node):
    def __init__(self):
        super().__init__("tas_simulation")  # Name of Node

        # Parameters
        self.l = 0.36
        self.w = 0.38
        self.alpha = 0.42984646481017397
        self.yoffset = 0.03294
        self.l3 = 0.017997210895024818
        self.wheel_radius = 0.07
        self.max_steering_angle = 35 / 180 * np.pi  # rad
        self.max_acceleration = 1.0  # m/s²

        # Init Odometry variables
        self.velocity = 0.0
        self.velocity_prev = 0.0
        self.angular_velocity = 0.0
        self.ang_vel_left_back = 0.0
        self.ang_vel_right_back = 0.0
        self.ang_vel_left_back_measured = 0.0
        self.ang_vel_right_back_measured = 0.0
        self.phi_left = 0.0
        self.phi_right = 0.0
        self.x = 0.0
        self.y = 0.0
        self.angle = 0.0
        self._last_odom_time = self.get_clock().now().nanoseconds * 1e-9

        # Init callbacks
        self.subscription = self.create_subscription(
            Twist, "cmd_vel", self.callback_listen_cmdvel, 10
        )
        self.subscription = self.create_subscription(
            JointState, "joint_states", self.callback_listen_joint_states, 10
        )
        self.subscription  # prevent unused variable warning
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.callback_publish)

        # Init Publisching
        self.publisher_odom = self.create_publisher(Odometry, "odom", 10)
        self.tf_broadcaster = TransformBroadcaster(self)
        self.publisher_position_cmd = self.create_publisher(
            Float64MultiArray, "forward_position_controller/commands", 10
        )
        self.publisher_velocity_cmd = self.create_publisher(
            Float64MultiArray, "forward_velocity_controller/commands", 10
        )

        # Inital publishing
        self.publish_odom()
        self.publish_tf()

    def callback_listen_cmdvel(self, cmd_vel):
        # Get current cmd_vel values
        self.velocity = cmd_vel.linear.x
        self.angular_velocity = cmd_vel.angular.z

    def callback_listen_joint_states(self, joint_states):
        # Mearue current angular velocity of back wheel for odometry
        for i, name in enumerate(joint_states.name):
            if name == "base_l_b_wheel_joint":
                self.ang_vel_left_back_measured = joint_states.velocity[i]
            if name == "base_r_b_wheel_joint":
                self.ang_vel_right_back_measured = joint_states.velocity[i]

    def callback_publish(self):
        self.delta_time = (
            self.get_clock().now().nanoseconds * 1e-9 - self._last_odom_time
        )
        self._last_odom_time = self.get_clock().now().nanoseconds * 1e-9
        self.calc_steering()
        self.calc_odometry()
        self.publish_odom()
        self.publish_tf()
        self.publish_cmd()
        # self.get_logger().info("time " + str(self.delta_time  ))

    def calc_steering(self):
        # compute steering angle of the front wheels and speed of the back wheels
        if (
            self.velocity - self.velocity_prev
        ) / self.delta_time > self.max_acceleration:
            velocity = self.velocity_prev + self.delta_time * self.max_acceleration
        elif (
            self.velocity - self.velocity_prev
        ) / self.delta_time < -self.max_acceleration:
            velocity = self.velocity_prev - self.delta_time * self.max_acceleration
        else:
            velocity = self.velocity

        self.velocity_prev = velocity

        if abs(velocity) < 0.1:
            steering_angle = 0
        else:
            steering_angle = np.clip(
                np.arctan(self.angular_velocity * self.l / velocity),
                -self.max_steering_angle,
                self.max_steering_angle,
            )

        self.phi_left = np.arctan(
            2
            * self.l
            * np.tan(steering_angle)
            / (2 * self.l - self.w * np.tan(steering_angle))
        )
        self.phi_right = np.arctan(
            2
            * self.l
            * np.tan(steering_angle)
            / (2 * self.l + self.w * np.tan(steering_angle))
        )
        self.ang_vel_left_back = (
            velocity
            * (1 - self.w * np.tan(steering_angle) / self.l / 2)
            / self.wheel_radius
        )
        self.ang_vel_right_back = (
            velocity
            * (1 + self.w * np.tan(steering_angle) / self.l / 2)
            / self.wheel_radius
        )

    def calc_odometry(self):
        """
        :description: Calculate the odometry parameters received from the robot and to be published to the ROS stack
        :return: x, y, angle
        """
        velocity = (
            (self.ang_vel_left_back_measured + self.ang_vel_right_back_measured)
            * self.wheel_radius
            / 2
        )
        angular_velocity = (
            (self.ang_vel_right_back_measured - self.ang_vel_left_back_measured)
            * self.wheel_radius
            / self.w
        )

        self.x = self.x + self.delta_time * velocity * np.cos(self.angle)
        self.y = self.y + self.delta_time * velocity * np.sin(self.angle)
        self.angle = self.angle + self.delta_time * angular_velocity

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
        # next, we will publish the tf message over ROS
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

    def publish_cmd(self):
        # Publisch control inputs for ROS2_control
        msg_pos = Float64MultiArray()
        msg_pos.data = [self.phi_left, self.phi_right]
        self.publisher_position_cmd.publish(msg_pos)
        msg_vel = Float64MultiArray()
        msg_vel.data = [self.ang_vel_left_back, self.ang_vel_right_back]
        self.publisher_velocity_cmd.publish(msg_vel)


def main(args=None):
    rclpy.init(args=args)
    minimal_subscriber = TasSimulation()
    rclpy.spin(minimal_subscriber)
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
