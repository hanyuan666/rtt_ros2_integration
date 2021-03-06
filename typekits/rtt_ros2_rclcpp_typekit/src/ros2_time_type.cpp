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

#include "rtt_ros2_rclcpp_typekit/ros2_time_type.hpp"

#include <cassert>
#include <string>
#include <vector>

#include "rtt/types/TemplateConstructor.hpp"

#include "rtt_ros2_rclcpp_typekit/time_conversions.hpp"
#include "rtt_ros2_rclcpp_typekit/time_io.hpp"

using namespace RTT;  // NOLINT(build/namespaces)
using namespace RTT::types;  // NOLINT(build/namespaces)

namespace rtt_ros2_rclcpp_typekit
{

TimeTypeInfo::TimeTypeInfo()
: PrimitiveTypeInfo<rclcpp::Time, true>("/rclcpp/Time")
{}

bool TimeTypeInfo::installTypeInfoObject(TypeInfo * ti)
{
  // aquire a shared reference to the this object
  boost::shared_ptr<TimeTypeInfo> mthis =
    boost::dynamic_pointer_cast<TimeTypeInfo>(
    this->getSharedPtr());
  assert(mthis);
  // Allow base to install first
  PrimitiveTypeInfo<rclcpp::Time, true>::installTypeInfoObject(ti);
  // ti->setStreamFactory(mthis);

  // Conversions
  const auto types = TypeInfoRepository::Instance();
  {
    const auto built_interfaces_msg_time_ti =
      types->getTypeInfo<builtin_interfaces::msg::Time>();
    assert(built_interfaces_msg_time_ti != nullptr);
    if (built_interfaces_msg_time_ti != nullptr) {
      built_interfaces_msg_time_ti->addConstructor(newConstructor(&time_to_msg, true));
    }
    ti->addConstructor(newConstructor(&msg_to_time, true));
  }
  {
    // Note: Define conversions for int64_t before double, because Orocos implicit converts from
    // int64_t to double, but not from double to int64_t.
    const auto int64_ti = types->getTypeInfo<int64_t>();
    assert(int64_ti != nullptr);
    if (int64_ti != nullptr) {
      int64_ti->addConstructor(newConstructor(&time_to_int64));
    }
    ti->addConstructor(newConstructor(&int64_to_time, true));
    ti->addConstructor(newConstructor(&int64_to_time2));
  }
  {
    const auto double_ti = types->getTypeInfo<double>();
    assert(double_ti != nullptr);
    if (double_ti != nullptr) {
      double_ti->addConstructor(newConstructor(&time_to_double));
    }
    ti->addConstructor(newConstructor(&double_to_time, true));
    ti->addConstructor(newConstructor(&double_to_time2));
  }

  // Don't delete us, we're memory-managed.
  return false;
}

}  // namespace rtt_ros2_rclcpp_typekit
