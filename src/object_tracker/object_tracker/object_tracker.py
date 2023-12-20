import rclpy
from rclpy.node import Node 

from std_msgs.msg import Float64MultiArray,  MultiArrayDimension
from sensor_msgs.msg import LaserScan
import time

import numpy as np
from sklearn.cluster import DBSCAN

class ObjectTracker(Node):
    def __init__(self):
        super().__init__("object_tracker")
        self.subscription = self.create_subscription(
            LaserScan,
            '/scan',
            self.callback_laser_scan,
            10
        )

        self.laser_publisher = self.create_publisher(
                Float64MultiArray,
                'obej_pos_vel',
                10
        )

        self.subscription
        self._last_scan_time = time.time()
        self.last_position =None
        self.last_time = self.get_clock().now()

       
    def filter(self,msg):
        for x in msg.ranges:
            if x < 0.05:
                msg.ranges.remove(x)
        return msg
    

    def callback_laser_scan(self,msg):
        object_position = self.detect_object_position(msg)
        current_time = self.get_clock().now()
        valid_change_positions = []
        if self.last_position is not None and self.last_time is not None:
            change_positions = np.array(object_position) - np.array(self.last_position)

            time_interval = (current_time - self.last_time).nanoseconds / 1e9

            self.get_logger().info(f'the size of changen_position is: {change_positions.shape}')
            for change_position in change_positions:
                if np.linalg.norm(change_position) > 1e-4:
                    #valid_change_positions= np.vstack((valid_change_positions,change_position))
                    valid_change_positions.append(change_position)
                else:
                    #valid_change_positions= np.vstack((valid_change_positions,np.zeros(1,2)))
                    valid_change_positions.append([0,0])
            valid_change_positions = np.array(valid_change_positions)
            self.get_logger().info(f'the valid change_position is: {valid_change_positions} ')
            self.get_logger().info(f'the size is: \n {valid_change_positions.shape}')
            velocity = np.array([valid_change_position / time_interval for valid_change_position in valid_change_positions])
                       
            self.get_logger().info(f'the velocity of object is: {velocity} m/s')
            self.get_logger().info(f'the size is: {velocity.shape} ')
            #publish
            self.publisher_object_tracker(object_position,velocity)

        self.last_position = object_position
        self.last_time = current_time
    
    def detect_object_position(self, msg):
    
        angles = np.linspace(msg.angle_min, msg.angle_max, len(msg.ranges))
        x = msg.ranges * np.cos(angles)
        y = msg.ranges * np.sin(angles)
        points = np.hstack((x.reshape(-1,1), y.reshape(-1,1)))

        DB = DBSCAN(eps=0.5, min_samples=5).fit(points)
        labels = DB.labels_

        unique_labels = set(labels)
        object_positions =[]

        for label in unique_labels:
            if label != -1:
                cluster_points = points[labels == label]
                object_position = np.mean(cluster_points, axis=0)
                object_positions.append(object_position)
        if not object_positions:
            return []
        
        distance_tax = [(np.linalg.norm(position), position) for position in  object_positions]
        distance_tax.sort(key=lambda x:x[0], reverse=True)
        top_positions = np.array([pair[1] for pair in distance_tax[0:2]])  #select top five distances and position

        
        return top_positions

    def publisher_object_tracker(self,object_positions,velocitys):
        object_positions = np.array(object_positions)
        velocitys = np.array(velocitys)
        combined_data = np.hstack((object_positions[:, 0], velocitys[:, 0], object_positions[:, 1], velocitys[:, 1]))
        flat_data = combined_data.flatten() #?

        pos_vel_msg = Float64MultiArray()
        pos_vel_msg.layout.dim = [
            MultiArrayDimension(label='rows', size=2, stride=4*2),
            MultiArrayDimension(label='columns', size=4, stride=4)
            
        ]

        pos_vel_msg.data = flat_data.tolist()

           
        self.laser_publisher.publish(pos_vel_msg)


    #def calc_verlocity(self,change_positions,time_interval):
    #   delta_time = time.time() - self._last_scan_time
    #   self._last_scan_time = time.time()

    #    if delta_time < 1.0:
    #        return change_positions / time_interval
    #    else:
    #         self.get_logger().warning("Time Step longer than 1 sec " + str(delta_time))
    
def main(args=None):
    rclpy.init(args=args)
    minimal_subscriber = ObjectTracker()
    rclpy.spin(minimal_subscriber)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

