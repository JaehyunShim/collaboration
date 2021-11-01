cmake_minimum_required(VERSION 3.0.2)
project(simple_param_cpp)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
)

# catkin specific configuration
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp
)

# Build
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(simple_param src/main_param.cpp)
add_dependencies(simple_param ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(simple_param ${catkin_LIBRARIES})

# Install
install(TARGETS simple_param
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

# Test
