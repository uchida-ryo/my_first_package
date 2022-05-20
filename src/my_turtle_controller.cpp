#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("turtle_controller");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 1);

  rclcpp::WallRate loop(1);
  while (rclcpp::ok()) {
    auto msg = geometry_msgs::msg::Twist();
    msg.linear.x = 1.0;
    msg.angular.z = 1.0;
    publisher->publish(msg);
    loop.sleep();
  }

  rclcpp::shutdown();
  return 0;
}
