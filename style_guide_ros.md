# Style Guide for ROS

## Rule
- Familiarize with the suggested style guide for ROS
- Understand the usage of basic ROS features through the provided sample code
- Utilize ROS extensions for fast and efficient development

## Package Structure
- ROS
```
catkin_ws
  - devel
  - build
  - logs
  - src
      - package_name (if cpp)
          - config
              - controller.yaml
            launch
              - controller.launch
          - urdf
              - robot.urdf
          - include/package_name
              - controller.h
          - src
              - controller.cpp
              - main.cpp
          - test
              - controller_test.cpp
          - CMakeLists.txt
          - package.xml
      - package_name2 (if python)
          - scripts/package_name
              - controller.py
              - main.py
          - CMakeLists.txt
          - package.xml
          - setup.py
```

- ROS2
```
colcon_ws
  - devel
  - install
  - log
  - src
      - package_name (if cpp)
          - config
              - controller.yaml
            launch
              - controller.launch.xml
              - controller.launch.py
          - urdf
              - robot.urdf
          - include/package_name
              - controller.hpp
          - src
              - controller.cpp
              - main.cpp
          - test
              - controller_test.cpp
          - CMakeLists.txt
          - package.xml
      - package_name2 (if python)
          - resource
              - package_name2
          - package_name2
              - __init__.py
              - controller.py
              - main.py
          - test
              - test_copyright.py
              - test_flake8.py
              - test_pep257.py
          - package.xml
          - setup.cfg
          - setup.py
```

## Sample Code
- [ROS](https://github.com/ipab-slmc/collaboration/tree/master/sample_code/ros)
- [ROS2](https://github.com/ipab-slmc/collaboration/tree/master/sample_code/ros2)

## VSCode Extension
**Utilize ROS extensions** to write clean ROS code effectively.
- [ROS extension](https://marketplace.visualstudio.com/items?itemName=JaehyunShim.vscode-ros)
- [ROS2 extension](https://marketplace.visualstudio.com/items?itemName=JaehyunShim.vscode-ros2)

You can set up to use the above extensions only in the specific workspace (e.g., ROS extension for catkin_ws and ROS2 extension for colcon_ws) by clicking `Manage -> Enable (Workspace)`.
