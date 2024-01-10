import launch
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.substitutions import FindPackageShare
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # 参数声明
    serial_no_arg = DeclareLaunchArgument('serial_no', default_value='')
    json_file_path_arg = DeclareLaunchArgument('json_file_path', default_value='')
    camera_arg = DeclareLaunchArgument('camera', default_value='camera')
    tf_prefix_arg = DeclareLaunchArgument('tf_prefix', default_value=LaunchConfiguration('camera'))
    external_manager_arg = DeclareLaunchArgument('external_manager', default_value='false')
    manager_arg = DeclareLaunchArgument('manager', default_value='realsense2_camera_manager')

    fisheye_width_arg = DeclareLaunchArgument('fisheye_width', default_value='640')
    fisheye_height_arg = DeclareLaunchArgument('fisheye_height', default_value='480')
    enable_fisheye_arg = DeclareLaunchArgument('enable_fisheye', default_value='false')

    depth_width_arg = DeclareLaunchArgument('depth_width', default_value='640')
    depth_height_arg = DeclareLaunchArgument('depth_height', default_value='480')
    enable_depth_arg = DeclareLaunchArgument('enable_depth', default_value='true')

    infra_width_arg = DeclareLaunchArgument('infra_width', default_value='640')
    infra_height_arg = DeclareLaunchArgument('infra_height', default_value='480')
    enable_infra1_arg = DeclareLaunchArgument('enable_infra1', default_value='false')
    enable_infra2_arg = DeclareLaunchArgument('enable_infra2', default_value='false')

    color_width_arg = DeclareLaunchArgument('color_width', default_value='640')
    color_height_arg = DeclareLaunchArgument('color_height', default_value='480')
    enable_color_arg = DeclareLaunchArgument('enable_color', default_value='true')

    fisheye_fps_arg = DeclareLaunchArgument('fisheye_fps', default_value='30')
    depth_fps_arg = DeclareLaunchArgument('depth_fps', default_value='30')
    infra_fps_arg = DeclareLaunchArgument('infra_fps', default_value='30')
    color_fps_arg = DeclareLaunchArgument('color_fps', default_value='30')
    gyro_fps_arg = DeclareLaunchArgument('gyro_fps', default_value='400')
    accel_fps_arg = DeclareLaunchArgument('accel_fps', default_value='250')
    enable_gyro_arg = DeclareLaunchArgument('enable_gyro', default_value='false')
    enable_accel_arg = DeclareLaunchArgument('enable_accel', default_value='false')

    enable_pointcloud_arg = DeclareLaunchArgument('enable_pointcloud', default_value='false')
    pointcloud_texture_stream_arg = DeclareLaunchArgument('pointcloud_texture_stream', default_value='RS2_STREAM_COLOR')
    pointcloud_texture_index_arg = DeclareLaunchArgument('pointcloud_texture_index', default_value='0')

    enable_sync_arg = DeclareLaunchArgument('enable_sync', default_value='false')
    align_depth_arg = DeclareLaunchArgument('align_depth', default_value='false')

    filters_arg = DeclareLaunchArgument('filters', default_value='pointcloud')
    clip_distance_arg = DeclareLaunchArgument('clip_distance', default_value='-2')
    linear_accel_cov_arg = DeclareLaunchArgument('linear_accel_cov', default_value='0.01')
    initial_reset_arg = DeclareLaunchArgument('initial_reset', default_value='false')
    unite_imu_method_arg = DeclareLaunchArgument('unite_imu_method', default_value='')
    topic_odom_in_arg = DeclareLaunchArgument('topic_odom_in', default_value='odom_in')
    calib_odom_file_arg = DeclareLaunchArgument('calib_odom_file', default_value='')
    publish_odom_tf_arg = DeclareLaunchArgument('publish_odom_tf', default_value='true')
    allow_no_texture_points_arg = DeclareLaunchArgument('allow_no_texture_points', default_value='true')

    realsense2_camera_launch_pkg = FindPackageShare("realsense2_camera").find("realsense2_camera")
    realsense2_camera_launch_dir = os.path.join(realsense2_camera_launch_pkg, 'launch','/rs_launch.py')
    
    realsense2_camera_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(realsense2_camera_launch_dir),
        launch_arguments={
            'tf_prefix': LaunchConfiguration('tf_prefix'),
            'serial_no': LaunchConfiguration('serial_no'),
            'json_file_path': LaunchConfiguration('json_file_path'),

            'enable_pointcloud': LaunchConfiguration('enable_pointcloud'),
            'pointcloud_texture_stream': LaunchConfiguration('pointcloud_texture_stream'),
            'pointcloud_texture_index': LaunchConfiguration('pointcloud_texture_index'),
            'enable_sync': LaunchConfiguration('enable_sync'),
            'align_depth': LaunchConfiguration('align_depth'),

            'fisheye_width': LaunchConfiguration('fisheye_width'),
            'fisheye_height': LaunchConfiguration('fisheye_height'),
            'enable_fisheye': LaunchConfiguration('enable_fisheye'),

            'depth_width': LaunchConfiguration('depth_width'),
            'depth_height': LaunchConfiguration('depth_height'),
            'enable_depth': LaunchConfiguration('enable_depth'),

            'color_width': LaunchConfiguration('color_width'),
            'color_height': LaunchConfiguration('color_height'),
            'enable_color': LaunchConfiguration('enable_color'),

            'infra_width': LaunchConfiguration('infra_width'),
            'infra_height': LaunchConfiguration('infra_height'),
            'enable_infra1': LaunchConfiguration('enable_infra1'),
            'enable_infra2': LaunchConfiguration('enable_infra2'),

            'fisheye_fps': LaunchConfiguration('fisheye_fps'),
            'depth_fps': LaunchConfiguration('depth_fps'),
            'infra_fps': LaunchConfiguration('infra_fps'),
            'color_fps': LaunchConfiguration('color_fps'),
            'gyro_fps': LaunchConfiguration('gyro_fps'),
            'accel_fps': LaunchConfiguration('accel_fps'),
            'enable_gyro': LaunchConfiguration('enable_gyro'),
            'enable_accel': LaunchConfiguration('enable_accel'),

            'filters': LaunchConfiguration('filters'),
            'clip_distance': LaunchConfiguration('clip_distance'),
            'linear_accel_cov': LaunchConfiguration('linear_accel_cov'),
            'initial_reset': LaunchConfiguration('initial_reset'),
            'unite_imu_method': LaunchConfiguration('unite_imu_method'),
            'topic_odom_in': LaunchConfiguration('topic_odom_in'),
            'calib_odom_file': LaunchConfiguration('calib_odom_file'),
            'publish_odom_tf': LaunchConfiguration('publish_odom_tf'),
            'allow_no_texture_points': LaunchConfiguration('allow_no_texture_points')
            }.items()

    )

    
    # rplidar Node , Robot_description, robot_state_publisher, rviz Node 
    # 

    pkg_depth_to_laser = FindPackageShare('depthimage_to_laserscan').find('depthimage_to_laserscan')
    scan_height = LaunchConfiguration("10")
    range_min = LaunchConfiguration('0.1')
    range_max = LaunchConfiguration('12')
    # launch depthimage_to_laserscan
    depthimage_to_laserscan_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(pkg_depth_to_laser,'launch','depthimage_to_laserscan-launch.py')),
        launch_arguments={
            "scan_height": scan_height,
            "range_min" : range_min,
            "range_max": range_max,
        }.items()
    )
    

    lidar_broadcast = Node(
        package= "obeject-detector-fusion",
        executable="lidar_tf2_broadcaster.py",
        name="lidar_broadcast"
    )

    laser_filter_pkg = FindPackageShare("laser_filters").find("laser_filters")
    laser_filter = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(laser_filter_pkg, "examples", "multiple_filters_example.launch.py"))
        #还要修改 remappings remap from="scan" to="laserscan"
    )

    camera_obstacle_extractor_node = Node(
            package='obstacle_detector_2',  
            executable='obstacle_extractor_node',  
            name='camera_obstacle_extractor',
            parameters=[{
                'active': True,
                'use_scan': True,
                'use_pcl': False,

                'use_split_and_merge': False,
                'circles_from_visibles': True,
                'discard_converted_segments': True,
                'transform_coordinates': True,
                'min_group_points': 20,

                'max_group_distance': 0.4,
                'distance_proportion': 0.002154,
                'max_split_distance': 0.2,
                'max_merge_separation': 0.2,
                'max_merge_spread': 0.2,
                'max_circle_radius': 0.8,
                'radius_enlargement': 0.3,
                'frame_id': 'camera_link',
                
            }],
            remappings=[
                ('scan', '/camera/depth/laserscan'),
                ('/raw_obstacles', '/raw_obstacles/camera_obstacles'),
            ],
            #output='screen',
        )
    
    lidar_obstacle_extractor_node = Node(
            
            package= "obstacle_detector_2",
            executable= "obstacle_extractor_node",
            name ="lidar_obstacle_extractor",
            parameters= [
                {
                    "active": True,
                    "use_scan": True,
                    "use_pcl": False,

                    "use_split_and_merge": True,
                    "circles_from_visibles": True,
                    "discard_converted_segments": True,
                    "transform_coordinates": True,

                    "min_group_points": 3,
                    "max_group_distance": 0.55,
                    "distance_proportion": 0.017453,
                    "max_split_distance": 0.4,
                    "max_merge_separation":0.4,
                    "max_merge_spread": 0.4,
                    "max_circle_radius": 1.5,
                    "radius_enlargement": 0.3,

                    "frame_id": "laser_front_link"                                  
                }
            ],
            remappings = [ 
                        ("scan", "/scan_filtered"),
                        ("raw_obstacles","/raw_obstacles/lidar_obstacles")
                        ],
           # output= "screen",

        )
            
    pub_pf_node = Node(
        package= "object-detector-fusion",
        executable="pub_pf.py",
        name="pf_publish"
    )

    particle_filter_node = Node(
        package="object-detector-fusion",
        executable="multipf.py",
        name="particle_filter"
    )
    


    return LaunchDescription([
        serial_no_arg,
        json_file_path_arg,
        camera_arg,
        tf_prefix_arg,
        external_manager_arg,
        manager_arg,
        fisheye_width_arg,
        fisheye_height_arg,
        enable_fisheye_arg,
        depth_width_arg,
        depth_height_arg,
        enable_depth_arg,
        infra_width_arg,
        infra_height_arg,
        enable_infra1_arg,
        enable_infra2_arg,
        color_width_arg,
        color_height_arg,
        enable_color_arg,
        fisheye_fps_arg,
        depth_fps_arg,
        infra_fps_arg,
        color_fps_arg,
        gyro_fps_arg,
        accel_fps_arg,
        enable_gyro_arg,
        enable_accel_arg,
        enable_pointcloud_arg,
        pointcloud_texture_stream_arg,
        pointcloud_texture_index_arg,
        enable_sync_arg,
        align_depth_arg,
        filters_arg,
        clip_distance_arg,
        linear_accel_cov_arg,
        initial_reset_arg,
        unite_imu_method_arg,
        topic_odom_in_arg,
        calib_odom_file_arg,
        publish_odom_tf_arg,
        allow_no_texture_points_arg,


        realsense2_camera_launch,
        depthimage_to_laserscan_launch,
        lidar_broadcast,
        laser_filter,
        camera_obstacle_extractor_node,
        lidar_obstacle_extractor_node,
        pub_pf_node,
        particle_filter_node

    ])

if __name__ == '__main__':
    generate_launch_description()
