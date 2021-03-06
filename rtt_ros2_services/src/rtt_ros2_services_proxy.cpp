// Copyright 2020 Intermodalics BVBA
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "rtt_ros2_services/rtt_ros2_services_proxy.hpp"

#include <string>

namespace rtt_ros2_services
{

RosServiceProxyBase::RosServiceProxyBase(const std::string & service_name)
: service_name_(service_name)
{}

RosServiceProxyBase::~RosServiceProxyBase() = default;

RosServiceServerProxyBase::RosServiceServerProxyBase(const std::string & service_name)
: RosServiceProxyBase(service_name)
{}

RosServiceClientProxyBase::RosServiceClientProxyBase(const std::string & service_name)
: RosServiceProxyBase(service_name)
{}

RosServiceProxyFactoryBase::RosServiceProxyFactoryBase(const std::string & service_type)
: service_type_(service_type) {}

}  // namespace rtt_ros2_services
