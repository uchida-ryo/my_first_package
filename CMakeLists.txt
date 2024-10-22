cmake_minimum_required(VERSION 3.5)
project(my_first_package)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(hello src/hello.cpp)
ament_target_dependencies(hello rclcpp)
install(TARGETS hello DESTINATION lib/${PROJECT_NAME})

set(NODES my_publisher;my_subscriber)
foreach(target IN LISTS NODES)
  add_executable(${target} src/${target}.cpp)
  ament_target_dependencies(${target} rclcpp std_msgs)
  install(TARGETS ${target} DESTINATION lib/${PROJECT_NAME})
endforeach()

add_executable(my_turtle_controller src/my_turtle_controller.cpp)
ament_target_dependencies(my_turtle_controller rclcpp geometry_msgs)
install(TARGETS my_turtle_controller DESTINATION lib/${PROJECT_NAME})

unset(NODES)
set(NODES simple_publisher;simple_subscriber)
foreach(target IN LISTS NODES)
  add_executable(${target}_node src/${target}_main.cpp src/${target}.cpp)
  ament_target_dependencies(${target}_node rclcpp std_msgs)
  install(TARGETS ${target}_node DESTINATION lib/${PROJECT_NAME})
  target_include_directories(${target}_node
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include>
  )
endforeach()

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
