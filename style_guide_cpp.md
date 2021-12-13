# Style Guide for C++

## Rule
- Familiarize with the suggested style guide for C++
- Write objective-oriented programming (OOP) code
- Use linter to clean up code

## Sample Code
Header file with `.h` extension for class declaration (`.hpp` for ROS2)
```
// Copyright Year University of Edinburgh ... Add copyright with year and university name
// License                                ... Add license (Use BSD 3-clause if no requirement to use others)
                                          ... 1 line break after copyright
#ifndef PACKAGE_NAME__FILE_NAME_H_        ... Use ifndef directive to prevent header files from being included multiple times
#define PACKAGE_NAME__FILE_NAME_H_
                                          ... 1 line break after ifndef directive
#include <ros/ros.h>
                                          ... 1 line break after directives
namespace namespace_name                  ... Namespace name should be snake_case
{
class ClassName : public OtherClass       ... Class name should be UpperCamelCase, 0 space indent when wrapping with a namespace
{
public:                                   ... 0 space indent for public/protected/private
  ClassName();                            ... 2 space indent otherwise

  // Comments                             ... Write comments above the function name like this
  void function_name();                   ... Member function name should be snake_case

  size_t size() const { return size_; }   ... Very simple functions can be implemented inline in a header

private:
  variable_name_;                         ... Member variable name should be snake_case and finish with an underscore
};
}  // namespace namespace_name            ... Close parenthesis for namespace like this
#endif  // PACKAGE_NAME__FILE_NAME_H_     ... Close with #endif directive
                                          ... 1 line break for EOF
```

C++ file with `.cpp` extension for class definition
```
// Copyright Year University of Edinburgh ... Add copyright with year and university name
// License                                ... Add license (Use BSD 3-clause if no requirement to use others)
                                          ... 1 line break after copyright
#include <ros/ros.h>
                                          ... 1 line break after directives
namespace namespace_name                  ... namespace name should be snake_case
{
void ClassName::function_name()           ... 0 space indent for Class
{
  for (size_t i = 0; i < x.size(); i++)
  {                                       ... break 1 line for if/for/while parenthesis
    xvec[i] = x[i];
  }
}
}  // namespace namespace_name            ... Close parenthesis for namespace like this
                                          ... 1 line break for EOF
```

## Linter
```
# ROS
# with .clang-format file (https://github.com/ipab-slmc/collaboration/blob/master/sample_code/ros/.clang-format)
$ find -name '*.cpp' -o -name '*.h' -o -name '*.hpp' | xargs clang-format-6.0 -style=file -i

# ROS2
$ ament_cpplint
$ ament_uncrustify
```
