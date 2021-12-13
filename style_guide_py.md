# Style Guide for Python

## Rule
- Familiarize with the suggested style guide for Python
- Write objective-oriented programming (OOP) code
- Use linter to clean up code

## Sample Code
Python file with `py` extension for class declaration and definition
```
#!/usr/bin/env python                     ... python3 for ROS Noetic and ROS2
#
# Copyright Year University of Edinburgh  ... Add copyright with year and university name
# License                                 ... Add license (Use BSD 3-clause if no requirement to use others)
                                          ... 1 line break after copyright
import rospy
                                          ... 2 line break after imports

class ClassName():                        ... class name should be UpperCamelCase
                                          ... 1 line break after Class
    def __init__(self):                   ... 4 space indent

    def function_name(self):              ... function name should be snake_case
        variable_name = 0                 ... variable name should be snake_case
                                          ... 1 line break for EOF
```

## Linter
```
# ROS
$ autopep8 --in-place --recursive .

# ROS2
$ ament_pep257
$ ament_flake8
```
