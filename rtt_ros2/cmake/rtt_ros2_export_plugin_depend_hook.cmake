# Copyright 2020 Intermodalics BVBA
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

if(DEFINED ${PROJECT_NAME}_RTT_ROS2_PLUGIN_DEPENDS)
  message(STATUS "[rtt_ros2] Exporting RTT plugin dependencies '${${PROJECT_NAME}_RTT_ROS2_PLUGIN_DEPENDS}' of package '${PROJECT_NAME}'")
  ament_index_register_resource(
    "rtt_ros2_plugin_depends"
    CONTENT ${${PROJECT_NAME}_RTT_ROS2_PLUGIN_DEPENDS}
  )
endif()
