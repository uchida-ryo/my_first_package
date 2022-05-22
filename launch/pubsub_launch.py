from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    node1 = Node(
        package='my_first_package',
        executable='my_publisher'
    )
    node2 = Node(
        package='my_first_package',
        executable='my_subscriber'
    )
    return LaunchDescription([
        node1,
        node2
    ])
