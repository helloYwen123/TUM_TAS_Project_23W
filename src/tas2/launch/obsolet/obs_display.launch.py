import launch
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import launch_ros
import os


def generate_launch_description():
    # Define Paths
    pkg_share = launch_ros.substitutions.FindPackageShare(package='tas2').find('tas2')
    
    # Define and declare Launch parameter 
    use_simulation = LaunchConfiguration('simulation')
    declare_simulation = DeclareLaunchArgument(
        name="simulation",
        default_value='True',
        description="Either simulate (True) the TAS-Car in Gazebo or run it on the real hardware (False)."
    )

    use_gui = LaunchConfiguration('gui')
    declare_gui = DeclareLaunchArgument(
        name="gui",
        default_value='false',
        description="True: Gui for setting the Joint values, False: Joint Values at 0."
    )

    robot_state_publisher_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(pkg_share,'launch','robot_state_publisher.launch.py')]),
        launch_arguments={'simulation':use_simulation}.items()
    )


    joint_state_publisher_node = launch_ros.actions.Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',          
        condition=launch.conditions.UnlessCondition(use_gui)

    )

    joint_state_publisher_node_gui = launch_ros.actions.Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',          
        condition=launch.conditions.IfCondition(use_gui)
    )


    return launch.LaunchDescription([
        declare_simulation,
        declare_gui,
        robot_state_publisher_launch,
        joint_state_publisher_node,
        joint_state_publisher_node_gui
    ])
