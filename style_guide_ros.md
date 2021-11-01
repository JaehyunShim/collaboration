# Style Guide for ROS

## Rule
- Familiarize with the suggested style guide for ROS
- Understand the usage of basic ROS features through the provided sample code
- Utilize ROS extensions for fast and efficient development

## Package Structure
```
catkin_ws (colcon_ws in ROS2)
  - devel
  - build (install in ROS2)
  - logs (log in ROS2)
  - src
      - package_name
          - config
              - controller.yaml
            launch
              - controller.launch (controller.launch.xml or controller.launch.py in ROS2)
          - urdf
              - robot.urdf
          - include/package_name
              - controller.h (controller.hpp in ROS2)
          - src
              - controller.cpp
          - scripts/package_name
              - controller.py
          - test
              - controller_test.cpp
          - CMakeLists.txt
          - package.xml
          - setup.py (only if python package)
```

TODO: ROS2

## Sample Code
- [ROS](https://github.com/JaehyunShim/collaboration/tree/master/sample_code/ROS)
- [ROS2](https://github.com/JaehyunShim/collaboration/tree/master/sample_code/ROS2)

TODO: Write cpp files for the sample code
TODO: Apply linter

## VSCode Extension
**Utilize ROS extensions** to write clean ROS code effectively.
- [ROS extension](https://marketplace.visualstudio.com/items?itemName=JaehyunShim.vscode-ros)
- [ROS2 extension](https://marketplace.visualstudio.com/items?itemName=JaehyunShim.vscode-ros2)

You can set up to use the above extensions only in the specific workspace (e.g., ROS extension for catkin_ws and ROS2 extension for colcon_ws) by clicking `Manage -> Enable (Workspace)`.
