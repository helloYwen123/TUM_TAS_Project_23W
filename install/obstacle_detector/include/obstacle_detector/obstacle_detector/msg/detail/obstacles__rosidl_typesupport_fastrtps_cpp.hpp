// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from obstacle_detector:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "obstacle_detector/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "obstacle_detector/msg/detail/obstacles__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace obstacle_detector
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_obstacle_detector
cdr_serialize(
  const obstacle_detector::msg::Obstacles & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_obstacle_detector
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  obstacle_detector::msg::Obstacles & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_obstacle_detector
get_serialized_size(
  const obstacle_detector::msg::Obstacles & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_obstacle_detector
max_serialized_size_Obstacles(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace obstacle_detector

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_obstacle_detector
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, obstacle_detector, msg, Obstacles)();

#ifdef __cplusplus
}
#endif

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
