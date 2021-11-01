cmake_minimum_required(VERSION 3.0.2)
project(simple_launch_py)

## Find catkin macros and libraries
find_package(catkin REQUIRED)


## catkin specific configuration
catkin_package()

## Install
install(DIRECTORY config launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

# Test
