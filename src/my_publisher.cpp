#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("my_publisher");
  auto publisher = node->create_publisher<std_msgs::msg::String>("greeting", 1);

  rclcpp::WallRate loop(1);
  int count = 0;
  while (rclcpp::ok()) {
    auto msg = std_msgs::msg::String();
    msg.data = "Hello, world " + std::to_string(count++);
    publisher->publish(msg);
    loop.sleep();
  }

  rclcpp::shutdown();
  return 0;
}
