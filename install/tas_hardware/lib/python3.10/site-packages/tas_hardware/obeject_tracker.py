import rclpy
from rclpy.node import Node 

from geometry_msgs import Vector3
from sensor_msgs.msg import LaserScan

import time
import numpy as np
from sklearn.cluster import DBSCAN

class objectTracker(Node):
    def __init__(self):
        super().__init__("object_tracker")
        self.subscriptions = self.create_publisher(
            LaserScan,
            '/scan',
            self.callback_laser_scan,
            10
        )

        self.laser_publisher = self.create_publisher(
                Vector3,
                'obej_pos_vel',
                10
        )

        self.subscriptions
        self.last_object_position =None
        self.last_time = None

        self.laser_publisher() #initialize publisher



    def callback_laser_scan(self,msg):
        object_position = self.get_object_position(msg)
        current_time = self.get_clock.now()
        
        if self.last_position != None and self.last_time != None:
            change_position = np.array(object_position) - np.array(object_position)

            time_interval = (current_time - self.last_time).nanoseconds / 1e9

            velocity = change_position / time_interval

            
            self.get_logger.info(f'the velocity of object is: {velocity} m/s')

            pos_vel_msg = Vector3()
            pos_vel_msg.x, pos_vel_msg.y, pos_vel_msg.z = *object_position, 0
            
            self.laser_publisher.publish(pos_vel_msg)

        self.last_position = object_position
        self.last_time = current_time
    
    def detect_object_position(self, msg):
    
        angles = np.arange(msg.angle_min, msg.angle_max, msg.angle_increment)
        x_coords = msg.ranges * np.cos(angles)
        y_coords = msg.ranges * np.sin(angles)
        points = np.array([x_coords, y_coords]).T

        # DBSCAN Cluster
        db = DBSCAN(eps=0.5, min_samples=5).fit(points)
        labels = db.labels_

    
        if len(set(labels)) > 1:
            largest_cluster = max(set(labels), key=list(labels).count)
            cluster_points = points[labels == largest_cluster]
            object_position = np.mean(cluster_points, axis=0)
            return object_position
        else:
            return None  # none detected object

        
    
def main(args=None):
    rclpy.init(args=args)
    object_tracker = objectTracker()
    rclpy.spin(object_tracker)
    object_tracker.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

