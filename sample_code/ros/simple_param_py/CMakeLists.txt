cmake_minimum_required(VERSION 3.0.2)
project(simple_param_py)

find_package(catkin REQUIRED COMPONENTS
  rospy
)

catkin_python_setup()

## catkin specific configuration
catkin_package()
