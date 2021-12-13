#!/bin/bash

# Install VSCode
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
rm -f packages.microsoft.gpg

sudo apt install apt-transport-https
sudo apt update
sudo apt install code

# Install Extensions
## Programming Language
code --install-extension ms-vscode.cpptools
code --install-extension ms-python.python
code --install-extension ms-vscode.cmake-tools
code --install-extension redhat.vscode-xml
code --install-extension redhat.vscode-yaml
code --install-extension ms-azuretools.vscode-docker

## ROS
code --install-extension JaehyunShim.vscode-ros
code --install-extension JaehyunShim.vscode-ros2
code --install-extension betwo.b2-catkin-tools

## Clean Code
code --install-extension shardulm94.trailing-spaces
code --install-extension msfukui.eof-mark
code --install-extension coenraads.bracket-pair-colorizer-2

## Remote Access
code --install-extension ms-vscode-remote.remote-containers
code --install-extension ms-vscode-remote.remote-ssh

## Others
code --install-extension mhutchie.git-graph
code --install-extension tht13.html-preview-vscode
code --install-extension tomoki1207.pdf
