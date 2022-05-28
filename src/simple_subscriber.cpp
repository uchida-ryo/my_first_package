#include "my_first_package/simple_subscriber.hpp"

SimpleSubscriber::SimpleSubscriber() : Node("simple_subscriber")
{
  using std::placeholders::_1;
  subscription_ = this->create_subscription<std_msgs::msg::String>("greeting", 1,
    std::bind(&SimpleSubscriber::topic_callback, this, _1));
}

void SimpleSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg) const
{
  RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
}
