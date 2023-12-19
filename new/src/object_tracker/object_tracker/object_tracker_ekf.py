import numpy as np
from filterpy.kalman import KalmanFilter, UnscentedKalmanFilter, MerweScaledSigmaPoints
from filterpy.common import Q_discrete_white_noise
import rclpy
import rclpy.node as Node
import std_msgs.msg as Float64MultiArray


class ObjectTrackerEkf(Node):
    def __init__(self):
        super().__init__('obj_tra_ekf')

        self.subscription = self.create_subscription(
            Float64MultiArray,
            'object_tracker',
            10
        )

        
