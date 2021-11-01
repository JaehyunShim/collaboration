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

#include "simple_service_cpp/simple_client.hpp"

namespace simple_service_cpp
{
SimpleClient::SimpleClient() : Node("simple_client")
{
  client_ = this->create_client<std_srvs::srv::SetBool>("robot_switch");

  while (!client_->wait_for_service(std::chrono::seconds(1))) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(this->get_logger(), "Interruped while waiting for the server.");
      return;
    }
    RCLCPP_INFO(this->get_logger(), "Server not available, waiting again...");
  }

  using std::placeholders::_1;
  auto request = std::make_shared<std_srvs::srv::SetBool::Request>();
  request->data = false;
  RCLCPP_INFO(this->get_logger(), "Sending request");
  RCLCPP_INFO(this->get_logger(), "Onoff: %s", request->data ? "true" : "false");
  client_->async_send_request(
    request, std::bind(&SimpleClient::client_response_callback, this, _1));
}

void SimpleClient::client_response_callback(ServiceResponseFuture future)
{
  auto response = future.get();
  RCLCPP_INFO(this->get_logger(), "Received response");
  RCLCPP_INFO(this->get_logger(), "Success: %s", response->success ? "true" : "false");
  RCLCPP_INFO(this->get_logger(), "Message: %s", response->message.c_str());
}
}  // namespace /* namespace_name */
