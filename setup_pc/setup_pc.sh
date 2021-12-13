#!/bin/bash

# Install
bash ros/install_ros.sh
bash ros2/install_ros2.sh
bash terminator/install_terminator.sh
bash vscode/install_vscode.sh

# Configure
cat bashrc/bashrc >> ~/.bashrc
cp terminator/config ~/.config/terminator/config

# Configure ROS workspace
mkdir ~/catkin_ws/.vscode
cp ros/settings.json ~/catkin_ws/.vscode/settings.json
cp ros/c_cpp_properties.json ~/catkin_ws/.vscode/c_cpp_properties.json
#cp config/ROS/launch.json ~/catkin_ws/.vscode/launch.json
#cp config/ROS/tasks.json ~/catkin_ws/.vscode/tasks.json

# Configure ROS2 workspace
mkdir ~/colcon_ws/.vscode
cp ros2/settings.json ~/colcon_ws/.vscode/settings.json
cp ros2/c_cpp_properties.json ~/colcon_ws/.vscode/c_cpp_properties.json
#cp config/ROS2/launch.json ~/colcon_ws/.vscode/launch.json
#cp config/ROS2/tasks.json ~/colcon_ws/.vscode/tasks.json

echo '-------------------------------'
echo 'PC will reboot in five seconds.'
echo '-------------------------------'
sleep 5
reboot
