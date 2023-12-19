import launch
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import launch_ros
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import os


def generate_launch_description():
    # Define Paths
    pkg_share = FindPackageShare(package='tas2').find('tas2')
    pkg_gazebo = FindPackageShare(package='gazebo_ros').find('gazebo_ros')
    rviz_path_default = os.path.join(pkg_share, 'rviz/simulation.rviz')
    gazebo_world_path = os.path.join(pkg_share, 'world/basement.world')
    gazebo_path = '/usr/share/gazebo-11/models/' + ':' + os.path.join(pkg_share, 'world/gazeboModels') 
    os.environ["GAZEBO_MODEL_PATH"] = gazebo_path

    # Pose where we want to spawn the robot in Gazebo
    spawn_at_x = '-10.0'
    spawn_at_y = '7.0'
    spawn_at_z = '0.0'
    spawn_at_yaw = '1.57'

    # Define and declare Launch parameter 
    use_simulation = LaunchConfiguration('simulation')
    declare_simulation = DeclareLaunchArgument(
        name="simulation",
        default_value='True',
        description="Either simulate (True) the TAS-Car in Gazebo or run it on the real hardware (False)."
    )

    robot_state_publisher_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(pkg_share,'launch','robot_state_publisher.launch.py')]),
        launch_arguments={'simulation':use_simulation,'rviz':rviz_path_default}.items()
    )

    # Start Gazebo 
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(pkg_gazebo , 'launch', 'gazebo.launch.py')),
        launch_arguments={
            'use_sim_time': use_simulation,
            'world': gazebo_world_path
        }.items()
    )

    spawn_entity_node = Node(package='gazebo_ros', executable='spawn_entity.py',
                arguments=[
                            '-topic', 'robot_description',
                            '-entity', 'tas_car',
                            '-x', spawn_at_x,
                            '-y', spawn_at_y,
                            '-z', spawn_at_z,
                            '-Y', spawn_at_yaw
                            ],
                output='screen')



    return launch.LaunchDescription([
        declare_simulation,
        robot_state_publisher_launch,
        gazebo_launch,
        spawn_entity_node,
    ])
