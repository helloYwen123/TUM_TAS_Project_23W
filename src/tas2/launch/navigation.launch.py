import launch
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, LogInfo
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from nav2_common.launch import RewrittenYaml
import os


def generate_launch_description():
    # Define Paths
    pkg_share = FindPackageShare(package="tas2").find("tas2")
    pkg_nav2 = FindPackageShare(package="nav2_bringup").find("nav2_bringup")
    nav2_config_file_path = os.path.join(pkg_share, "config/navigation.yaml")
    map_yaml_file = os.path.join(pkg_share, "maps/LSR_N5_basement.yaml")
    nav_to_pose_bt_path = os.path.join(pkg_share, "config/my_nav_to_pose_bt.xml")
    nav_through_poses_bt_path = os.path.join(
        pkg_share, "config/my_nav_through_poses_bt.xml"
    )

    # Define and declare Launch parameter
    use_sim_time = LaunchConfiguration("use_sim_time")
    slam = LaunchConfiguration("slam")
    declare_slam = DeclareLaunchArgument(
        "slam", default_value="False", description="Whether run a SLAM"
    )
    declare_use_sim_time = DeclareLaunchArgument(
        "use_sim_time",
        default_value="True",
        description="Use simulation (Gazebo) clock if true",
    )

    # Create our own temporary YAML files that include substitutions
    param_substitutions = {
        "use_sim_time": use_sim_time,
        "bt_navigator.ros__parameters.default_nav_to_pose_bt_xml": nav_to_pose_bt_path,
        "bt_navigator.ros__parameters.default_nav_through_poses_bt_xml": nav_through_poses_bt_path,
        "amcl.ros__parameters.initial_pose.x": "-10.0",
        "amcl.ros__parameters.initial_pose.y": "7.0",
        "amcl.ros__parameters.initial_pose.z": "0.0",
        "amcl.ros__parameters.initial_pose.yaw": "1.57",
    }

    nav2_config_file = RewrittenYaml(
        source_file=nav2_config_file_path,
        param_rewrites=param_substitutions,
        convert_types=True,
    )

    # robot localization via EKF
    robot_localization_node = Node(
        package="robot_localization",
        executable="ekf_node",
        name="ekf_filter_node",
        output="screen",
        parameters=[
            os.path.join(pkg_share, "config/ekf.yaml"),
            {"use_sim_time": use_sim_time},
        ],
    )

    # Start navigation
    navigation_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_nav2, "launch", "bringup_launch.py")
        ),
        launch_arguments={
            "slam": slam,
            "use_sim_time": use_sim_time,
            "params_file": nav2_config_file,
            "map": map_yaml_file,
            "bt_navigator.default_nav_to_pose_bt_xml": nav_to_pose_bt_path,
            "bt_navigator.default_nav_through_poses_bt_xml": nav_through_poses_bt_path,
        }.items(),
    )

    return launch.LaunchDescription(
        [
            declare_use_sim_time,
            declare_slam,
            # robot_localization_node,
            navigation_launch,
        ]
    )
