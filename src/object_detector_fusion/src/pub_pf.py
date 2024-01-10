#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32

class PFPublisher(Node):
    def __init__(self):
        super().__init__('pub_pf')
        self.publisher_ = self.create_publisher(Float32, '/pub_pf', 10)
        self.rate = self.create_rate(60)  # Rate on which PF estimate is running
        self.timer = self.create_timer(1.0 / 60, self.publish_pf)

    def publish_pf(self):
        msg = Float32()
        msg.data = 60  # Or any other value you wish to publish
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    pf_publisher = PFPublisher()
    rclpy.spin(pf_publisher)

    pf_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
