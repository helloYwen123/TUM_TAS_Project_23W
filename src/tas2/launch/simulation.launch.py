import launch
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import launch_ros
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch_ros.parameter_descriptions import ParameterValue
import os


def generate_launch_description():
    # Define Paths
    pkg_share = FindPackageShare(package='tas2').find('tas2')
    pkg_gazebo = FindPackageShare(package='gazebo_ros').find('gazebo_ros')
    rviz_path = os.path.join(pkg_share, 'rviz/simulation.rviz')
    gazebo_world_path = os.path.join(pkg_share, 'world/basement.world')
    gazebo_path = '/usr/share/gazebo-11/models/' + ':' + os.path.join(pkg_share, 'world/gazeboModels') 
    os.environ["GAZEBO_MODEL_PATH"] = gazebo_path

    model_path = os.path.join(pkg_share, 'models/tas_car.urdf.xacro')
    model = ParameterValue(Command(['xacro ', model_path]),value_type=str)

    # Define and declare Launch parameter 
    use_sim_time = LaunchConfiguration('simulation')
    declare_use_sim_time = DeclareLaunchArgument(
        name="simulation",
        default_value='True',
        description="Either simulate (True) the TAS-Car in Gazebo or run it on the real hardware (False)."
    )


    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': model, 'use_sim_time': use_sim_time}]
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        arguments=['-d',rviz_path],
        parameters=[{'use_sim_time': use_sim_time}]
    )


    # Pose where we want to spawn the robot in Gazebo
    spawn_at_x = '-10.0'
    spawn_at_y = '7.0'
    spawn_at_z = '0.0'
    spawn_at_yaw = '1.57'


    # Start Gazebo 
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(pkg_gazebo , 'launch', 'gazebo.launch.py')),
        launch_arguments={
            'use_sim_time': use_sim_time,
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
    
    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
    )

    robot_controller_position_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["forward_position_controller"],
    )

    robot_controller_velocity_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["forward_velocity_controller"],
    )
    
    tas_simulation_node = Node(package='tas_hardware', 
                               executable='tas_simulation',
                               parameters=[{'use_sim_time': use_sim_time}]
                               )



    return launch.LaunchDescription([
        declare_use_sim_time,
        robot_state_publisher_node,
        rviz_node,
        gazebo_launch,
        spawn_entity_node,
        joint_state_broadcaster_spawner,
        robot_controller_position_spawner,
        robot_controller_velocity_spawner,
        tas_simulation_node,
    ])
