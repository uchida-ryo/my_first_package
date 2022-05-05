#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("hello");
  RCLCPP_INFO(node->get_logger(), "Hello, ROS2 world!");

  rclcpp::WallRate loop(1);
  while (rclcpp::ok()) {
    loop.sleep();
  }

  rclcpp::shutdown();
  return 0;
}
