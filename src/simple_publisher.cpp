#include "my_first_package/simple_publisher.hpp"

SimplePublisher::SimplePublisher() : Node("simple_publisher")
{
  publisher_ = this->create_publisher<std_msgs::msg::String>("greeting", 1);

  using namespace std::chrono_literals;
  timer_ = this->create_wall_timer(1s, std::bind(&SimplePublisher::timer_callback, this));
}

void SimplePublisher::timer_callback()
{
  static int count = 0;
  auto msg = std_msgs::msg::String();
  msg.data = "Hello, world " + std::to_string(count++);
  publisher_->publish(msg);
}
