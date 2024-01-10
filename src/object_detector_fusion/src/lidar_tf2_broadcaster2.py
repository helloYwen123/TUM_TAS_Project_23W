import rclpy
from rclpy.node import Node
import tf2_ros
import geometry_msgs.msg

class FixedTFBroadcaster(Node):
    def __init__(self):
        super().__init__("fixed_tf2_broadcaster")
        self.publisher = self.create_publisher(tf2_ros.TransformStamped, '/tf', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)

    def timer_callback(self):
        t = geometry_msgs.msg.TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'camera_link'
        t.child_frame_id = 'laser_scanner_frame'
        t.transform.translation.x = 0.08
        t.transform.translation.y = 0.0
        t.transform.translation.z = -0.05

        t.transform.rotation.x = 0.0
        t.transform.rotation.y = 0.0
        t.transform.rotation.z = 0.0
        t.transform.rotation.w = 1.0

        self.publisher.publish(t)
def main(args = None):
    rclpy.init(args= args)
    fixed_tf2_broadcaster = FixedTFBroadcaster()
    rclpy.spin(fixed_tf2_broadcaster)

    fixed_tf2_broadcaster.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()