#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

rclcpp::Node::SharedPtr g_node = nullptr;

void callback(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(g_node->get_logger(), "%s", msg->data.c_str());
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  g_node = rclcpp::Node::make_shared("my_subscriber");
  auto subscriber = g_node->create_subscription<std_msgs::msg::String>("greeting", 1, callback);

  rclcpp::spin(g_node);

  g_node = nullptr;
  rclcpp::shutdown();
  return 0;
}
