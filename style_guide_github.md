# Style Guide for Github

## Rule
- Familiarize with the suggested style guide for Github
- Add minimum necessary files to make your repository sustainable and easy to maintain
  - `README.md`
  - `.clang-format`
  - `.gitignore`
  - `dependency.repos`
  - `LICENSE`
- Add additional files to your repository if you are considering making it open-source
  - `workflows`
  - `CHANGELOG.rst`
  - `CONTRIBUTING.md`
  - `ISSUE-TEMPLATE`
  - `PULL_REQUEST_TEMPLATE`
  - Documentation
  - Doxygen
  - Code Coverage

## README.md
Use the below template to provide users with minimal yet necessary information about your code. Refer to [Exotica README.md](https://github.com/ipab-slmc/exotica#readme)
```
# Repository Name

## Prerequisites

## Installation

## Run

```

## .clang-format
Add this [.clang-format]() file from the [ROS Control](https://github.com/ros-controls/ros_controllers/blob/noetic-devel/.clang-format) group to your repository to meet style guidelines used in the ROS community.

## .gitignore
Add this [.gitignore](.gitignore) file from [Exotica](https://github.com/ipab-slmc/exotica/blob/master/.gitignore) to your repository to exclude unncessary files (e.g., cache files) in your repository.

## dependency.repos
VCStool??? with repos file will be used for dependencies that are not binary-released yet.
```
# To create a repos file
$ cd ~/catkin_ws  # colcon_ws in ROS2
$ vcs export src

# To download dependency repositories using a repos file
$ cd ~/catkin_ws  # colcon_ws in ROS2
$ wget -O dependency.repos https://raw.githubusercontent.com/JaehyunShim/collaboration/master/dependency.repos?token=AJGY62OPJ63S7NZLBJT5KVTBP72XG
$ vcs import src < dependency.repos

# To install the rest of dependencies using rosdep
$ rosdep install --from-paths src --ignore-src --rosdistro noetic -r -y  # for ROS Noetic
```

## LICENSE
Add this [3-clause BSD license](LICENSE) to your repository unless you have requirement to use others for your code. For more infomation, read [Licenses & Standards](https://opensource.org/licenses) by Open Source Initiative.

## workflows
TODO

## CHANGELOG.rst
Add `CHANGELOG.rst` file to track changes in your code. Refer to the sample [CHANGELOG.rst](CHANGELOG.rst) provided in this repository.

## CONTRIBUTING.md
If you are considering collaborating with the community and accept contributions, consider adding a `CONTRIBUTING.md` file to your repository. Refer to this [file](https://github.com/ros-controls/ros2_control/blob/master/CONTRIBUTING.md) from ROS Control group.

## ISSUE-TEMPLATE
TODO

## PULL_REQUEST_TEMPLATE
TODO

## Documentation
TODO

## Doxygen
TODO

## Code Coverage
TODO
