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

#ifndef SIMPLE_SERVICE_CPP__SIMPLE_CLIENT_H_
#define SIMPLE_SERVICE_CPP__SIMPLE_CLIENT_H_

#include <ros/ros.h>
#include <std_srvs/SetBool.h>

namespace simple_service_cpp
{
class SimpleClient
{
public:
  SimpleClient() : nh_(""), priv_nh_("~")
  {
    client_ = nh_.serviceClient<std_srvs::SetBool>("robot_switch");

    while (!client_.waitForExistence(ros::Duration(1.0)))
    {
      if (!ros::ok())
      {
        ROS_ERROR("Interruped while waiting for the server.");
        return;
      }
      ROS_INFO("Server not available, waiting again...");
    }

    auto srv = std_srvs::SetBool();
    srv.request.data = false;
    ROS_INFO("Sending request");
    ROS_INFO("Onoff: %s", srv.request.data ? "true" : "false");
    if (client_.call(srv))
    {
      auto response = srv.response;
      ROS_INFO("Received response");
      ROS_INFO("Success: %s", response.success ? "true" : "false");
      ROS_INFO("Message: %s", response.message.c_str());
    }
    else
    {
      ROS_ERROR("Failed to call service");
    }
  }

private:
  ros::NodeHandle nh_;
  ros::NodeHandle priv_nh_;

  ros::ServiceClient client_;
};
}  // namespace simple_service_cpp
#endif  // SIMPLE_SERVICE_CPP__SIMPLE_CLIENT_H_
