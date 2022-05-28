#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class SimplePublisher : public rclcpp::Node
{
public:
  SimplePublisher();

private:
  void timer_callback();
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};
