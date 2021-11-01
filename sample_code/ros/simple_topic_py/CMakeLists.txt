cmake_minimum_required(VERSION 3.0.2)
project(simple_topic_py)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
)

catkin_python_setup()

## catkin specific configuration
catkin_package()
