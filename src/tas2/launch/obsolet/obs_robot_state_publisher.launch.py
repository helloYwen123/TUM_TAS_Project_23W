import launch
import launch_ros
import os

def generate_launch_description():
    # Define Paths
    pkg_share = launch_ros.substitutions.FindPackageShare(package='tas2').find('tas2')
    model_path = os.path.join(pkg_share, 'models/tas_car.urdf.xacro')
    model = launch_ros.parameter_descriptions.ParameterValue(launch.substitutions.Command(['xacro ', model_path]),value_type=str)
    rviz_path_default = os.path.join(pkg_share, 'rviz/display.rviz')

    # Define and declare Launch parameter 
    use_simulation = launch.substitutions.LaunchConfiguration('simulation')
    declare_simulation = launch.actions.DeclareLaunchArgument(
        name="simulation",
        default_value='True',
        description="Either simulate (True) the TAS-Car in Gazebo or run it on the real hardware (False)."
    )


    rviz_path = launch.substitutions.LaunchConfiguration('rviz')
    declare_rviz = launch.actions.DeclareLaunchArgument(
        name="rviz",
        default_value=rviz_path_default,
        description="Set a different path for the RVIZ config file"
    )


    robot_state_publisher_node = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': model, 'use_sim_time': use_simulation}]
    )

    rviz_node = launch_ros.actions.Node(
        package="rviz2",
        executable="rviz2",
        arguments=['-d',rviz_path],
        parameters=[{'use_sim_time': use_simulation}]
    )

    return launch.LaunchDescription([
        declare_simulation,
        declare_rviz,
        robot_state_publisher_node,
        rviz_node
    ])
