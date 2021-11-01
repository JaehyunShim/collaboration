#!/bin/bash

# Setup Sources
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt install curl
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
sudo apt -y update

# Install ROS
sudo apt install -y ros-noetic-desktop-full
source /opt/ros/noetic/setup.bash
sudo apt install -y python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential python-catkin-tools

# Init & Update Rosdep
sudo -S rosdep init
rosdep update

# Create Workspace
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws
catkin config --cmake-args -DCMAKE_BUILD_TYPE=Release
catkin build
