// Copyright 2021, University of Edinburgh
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of  nor the names of its contributors may be used to
//    endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef SIMPLE_PARAM_CPP__SIMPLE_PARAM_HPP_
#define SIMPLE_PARAM_CPP__SIMPLE_PARAM_HPP_

#include <string>

#include "rclcpp/rclcpp.hpp"

namespace simple_param_cpp
{
class SimpleParam : public rclcpp::Node
{
public:
  SimpleParam()
  : Node("simple_param")
  {
    this->declare_parameter<std::string>("robot_name", "SimpleBot");
    this->declare_parameter<double>("robot_mass", 1.0);
    this->declare_parameter<int>("robot_number", 3);

    timer_ = this->create_wall_timer(
      std::chrono::seconds(1),
      std::bind(&SimpleParam::timer_callback, this));
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;

  void timer_callback()
  {
    auto robot_name = this->get_parameter("robot_name").get_value<std::string>();
    auto robot_mass = this->get_parameter("robot_mass").get_value<double>();
    auto robot_number = this->get_parameter("robot_number").get_value<int>();

    RCLCPP_INFO(this->get_logger(), "robot_name: %s", robot_name.c_str());
    RCLCPP_INFO(this->get_logger(), "robot_mass: %lf", robot_mass);
    RCLCPP_INFO(this->get_logger(), "robot_number: %d", robot_number);
  }
};
}  // namespace simple_param_cpp
#endif  // SIMPLE_PARAM_CPP__SIMPLE_PARAM_HPP_