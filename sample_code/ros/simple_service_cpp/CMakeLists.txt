cmake_minimum_required(VERSION 3.0.2)
project(simple_service_cpp)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_srvs
)

## catkin specific configuration
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_srvs
)

## Build
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(simple_server src/main_server.cpp)
add_dependencies(simple_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(simple_server ${catkin_LIBRARIES})

add_executable(simple_client src/main_client.cpp)
add_dependencies(simple_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(simple_client ${catkin_LIBRARIES})

## Install
install(TARGETS simple_server simple_client
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

## Testing
