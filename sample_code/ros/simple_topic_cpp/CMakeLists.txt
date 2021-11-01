cmake_minimum_required(VERSION 3.0.2)
project(simple_topic_cpp)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

## catkin specific configuration
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_msgs
)

## Build
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(simple_pub src/main_pub.cpp)
add_dependencies(simple_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(simple_pub ${catkin_LIBRARIES})

add_executable(simple_sub src/main_sub.cpp)
add_dependencies(simple_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(simple_sub ${catkin_LIBRARIES})

## Install
install(TARGETS simple_pub simple_sub
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

## Testing
