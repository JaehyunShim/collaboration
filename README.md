# Collaboration

[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://github.com/ipab-slmc/collaboration/blob/master/LICENSE)
<!-- [![GitHub CI Status](https://github.com/ipab-slmc/collaboration/workflows/CI/badge.svg)](https://github.com/ipab-slmc/collaboration/actions?query=workflow%3ACI)
[![GitHub Lint Status](https://github.com/ipab-slmc/collaboration/workflows/Lint/badge.svg)](https://github.com/ipab-slmc/collaboration/actions?query=workflow%3ALint) -->

<p align="left">
  <img src="/assets/no_thanks_too_busy.png" height="300">
</p>

**No more "no thanks, too busy" [(link)](https://www.jackvinson.com/blog/2016/8/11/no-thanks-too-busy). No more reinventing the wheel.**

## Table of Contents
- [Setup PC](#setup-pc)
  - [Operating System (OS)](#operating-system-os)
  - [Integrated Development Environment (IDE)](#integrated-development-environment-ide)
  - [Terminal Emulator](#terminal-emulator)
  - [Robot Operating System (ROS)](#robot-operating-system-ros)
- [Control Pieline](#control-pipeline)
- [Version Control System (VCS)](#version-control-system-vcs)
- [Style Guide](#style-guide)
- [Code Review](#code-review)
- [Summary](#summary)

## Setup PC
A unified development environment in a group plays an important role as it reduces the risk of potential compatibility issues within software developed in the group.

All the installations and configurations listed below are written in an install script and can be done fast by running the following. Utilize it to avoid repetitive installation tasks.
```
$ mkdir ~/.setup_pc && cd ~/.setup_pc
$ git clone git@github.com:ipab-slmc/collaboration.git
$ cd collaboration && rm -r sample_code && bash setup_pc/setup_pc.sh
```

**[⬆ back to top](#table-of-contents)**

### Operating System (OS)
[**Ubuntu 20.04**](https://releases.ubuntu.com/20.04/) is recommended. However, you will have to install an older version OS if the robot platform you are going to use only supports older version OS (e.g., ANYmal Bedi only supports Ubuntu 18.04 with ROS Melodic). Find the [lab software engineer](https://github.com/JaehyunShim) and discuss it.

**[⬆ back to top](#table-of-contents)**

### Integrated Development Environment (IDE)
[**Visual Studio Code**](https://code.visualstudio.com/) (VSCode) is recommended as it provides many intuitive and versatile features you need when writing clean code.

**Set up your own IDE environment** by adding [setings.json](setup_pc/ros/settings.json) and [c_cpp_properties.json](/setup_pc/ros/c_cpp_properties.json) files to the following path. If you already have your own preferred custom configuration, consider starting using the common setting or proactively suggesting alternatives to the [lab software engineer](https://github.com/JaehyunShim).
- `~/.vscode/`: to apply to all files in the system.
- `~/catkin_ws/.vscode/`: to apply to only the files in your workspace.

**VSCode Extensions** are recommended to install as they provide many useful features for development such as code browsing or snippets. The minimum recommended extensions are listed below.

```
# Programming Language
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools
https://marketplace.visualstudio.com/items?itemName=ms-python.python
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools
https://marketplace.visualstudio.com/items?itemName=redhat.vscode-xml
https://marketplace.visualstudio.com/items?itemName=redhat.vscode-yaml
https://marketplace.visualstudio.com/items?itemName=ms-azuretools.vscode-docker

# ROS
https://marketplace.visualstudio.com/items?itemName=JaehyunShim.vscode-ros
https://marketplace.visualstudio.com/items?itemName=JaehyunShim.vscode-ros2
https://marketplace.visualstudio.com/items?itemName=betwo.b2-catkin-tools

# Clean Code
https://marketplace.visualstudio.com/items?itemName=shardulm94.trailing-spaces
https://marketplace.visualstudio.com/items?itemName=msfukui.eof-mark
https://marketplace.visualstudio.com/items?itemName=coenraads.bracket-pair-colorizer-2

# Remote Access
https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers
https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh

# Others
https://marketplace.visualstudio.com/items?itemName=mhutchie.git-graph
https://marketplace.visualstudio.com/items?itemName=tht13.html-preview-vscode
https://marketplace.visualstudio.com/items?itemName=tomoki1207.pdf
```

TODO: Compile with VSCode

TODO: GDB with VSCode

**[⬆ back to top](#table-of-contents)**

### Terminal Emulator
[**Terminator**](https://gnometerminator.blogspot.com/p/introduction.html) is recommended to use as it supports splitting terminals that the default Ubuntu terminal application does not.

**Set up your Terminaor environment** by adding this [config](setup_pc/terminator/config) file to `~/.config/terminator/` directory unless you have your own preferred custom configuration file.

**[⬆ back to top](#table-of-contents)**

### Robot Operating System (ROS)
[**ROS Noetic**](http://wiki.ros.org/noetic/Installation/Ubuntu) & [**ROS2 Foxy**](https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html) on Ubuntu 20.04 is recommended. However, as written above in [Operating System (OS)](#operating-system-os), you will have to install older versions depending on the robot platform you use. Find the [lab software engineer](https://github.com/JaehyunShim) and discuss it.

**Set up your ROS environment** by adding the lines from this [bashrc](setup_pc/bashrc/bashrc) file to the `~/.bashrc` unless you have your own preferred custom configuration file.

**[⬆ back to top](#table-of-contents)**

## Control Pipeline
In the SLMC lab, there are many ongoing projects and the following are the current **control pipelines** for them. Find the [lab manager](https://github.com/VladimirIvan) and discuss to **know how your work will position in the whole control pipeline** as well as **avoid reinventing the wheel**.

TODO: Update below pipeline diagrams and consider how access rights should be assigned.
- [Kawada project](https://docs.google.com/presentation/d/16I5_9d1K5TfwPLwWwV8RBflDK-TTsM0gbwq8PBo8A-I/edit#slide=id.gfb820633a9_0_45)
- [Harmony project](https://docs.google.com/presentation/d/16I5_9d1K5TfwPLwWwV8RBflDK-TTsM0gbwq8PBo8A-I/edit#slide=id.gfb820633a9_0_82)
- [Memmo project](https://docs.google.com/presentation/d/16I5_9d1K5TfwPLwWwV8RBflDK-TTsM0gbwq8PBo8A-I/edit#slide=id.gfb820633a9_0_164)
- [Orca project](https://docs.google.com/presentation/d/16I5_9d1K5TfwPLwWwV8RBflDK-TTsM0gbwq8PBo8A-I/edit#slide=id.gfb820633a9_0_257)

TODO: add more ongoing projects if there are.

**[⬆ back to top](#table-of-contents)**

## Version Control System (VCS)
In the SLMC lab, **Git** is used for VCS and **Github** is used to store developed code in the cloud. Visit our [**SLMC Github page**](https://github.com/ipab-slmc) and request access to the page from the [lab manager](https://github.com/VladimirIvan).

**Understanding Git branching strategy** is necessary to collaborate with other members in a shared repository. The graph in ['A successful Git branching model'](https://nvie.com/posts/a-successful-git-branching-model/) visually demonstrates a good branching model. In the SLMC lab, the following Git branching strategy is used.
```
master/main (for code to be released)
develop (for code that is currently developed)
feature (for a new feature to be added to the whole code, e.g. feature-state-estimator)
hotfix (for fixing critical bugs in the released code)
ros-version (for code in different ROS versions, e.g. Noetic, Foxy)
```

Familiarize with **Git usage** by going through the following [Git cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)

[**Octotree**](https://www.octotree.io/), a powerful browser extension for Github code review and exploration, is recommended to install.

**[⬆ back to top](#table-of-contents)**

## Style Guide
The following **style guides** are established for consistency in the code across the lab. Consider applying the suggested rules to your work for better collaboration and communication with lab members.
- [Style Guide for C++](style_guide_cpp.md)
- [Style Guide for Python](style_guide_py.md)
- [Style Guide for ROS](style_guide_ros.md)
- [Style Guide for Github](style_guide_github.md)

[**Clean Code Summary**](https://github.com/ryanmcdermott/clean-code-javascript) is also highly recommended to read to write readable, reusable, and refactorable software.

**[⬆ back to top](#table-of-contents)**

## Code Review
TODO: There is no working group concept in the lab yet. In the future, code review within each working group can be considered (e.g., sending PRs to two people in the working group).

**[⬆ back to top](#table-of-contents)**

## Summary
**Go through the checklist** below and see if you omitted or did not understand anything.
- Setup PC
  - Operating System
    - Install OS
  - Integrated Development Environment
    - Install VSCode
    - Setup VSCode
    - Install VSCode Extensions
  - Terminal Emulator
    - Install Terminator
    - Setup Terminator
  - ROS
    - Install ROS
    - Setup ROS
- Control Pipeline
  - Understand the control pipeline of the project you are in
  - Discuss how your work will position in the control pipeline
- Version Control System
  - Create Github account
  - Request SLMC Github page access
  - Understand Git branching strategy
  - Familiarize with Git usage
  - Install Octotree
- Style Guide
  - Understand style guide for C++
  - Understand style guide for Python
  - Understand style guide for ROS
  - Understand style guide for Github
  - Read clean code summary
  - Apply style guides to your work
<!-- - Code Review
  - Understand code review guideline
  - Start code review in your working group -->

If you have any questions or requests for additional features, find the [lab software engineer](https://github.com/JaehyunShim) and discuss anytime.

**[⬆ back to top](#table-of-contents)**
