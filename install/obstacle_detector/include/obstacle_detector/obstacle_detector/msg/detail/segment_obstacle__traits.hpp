// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from obstacle_detector:msg/SegmentObstacle.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__TRAITS_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "obstacle_detector/msg/detail/segment_obstacle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'first_point'
// Member 'last_point'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'first_velocity'
// Member 'last_velocity'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace obstacle_detector
{

namespace msg
{

inline void to_flow_style_yaml(
  const SegmentObstacle & msg,
  std::ostream & out)
{
  out << "{";
  // member: uid
  {
    out << "uid: ";
    rosidl_generator_traits::value_to_yaml(msg.uid, out);
    out << ", ";
  }

  // member: first_point
  {
    out << "first_point: ";
    to_flow_style_yaml(msg.first_point, out);
    out << ", ";
  }

  // member: last_point
  {
    out << "last_point: ";
    to_flow_style_yaml(msg.last_point, out);
    out << ", ";
  }

  // member: first_velocity
  {
    out << "first_velocity: ";
    to_flow_style_yaml(msg.first_velocity, out);
    out << ", ";
  }

  // member: last_velocity
  {
    out << "last_velocity: ";
    to_flow_style_yaml(msg.last_velocity, out);
    out << ", ";
  }

  // member: semclass
  {
    out << "semclass: ";
    rosidl_generator_traits::value_to_yaml(msg.semclass, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SegmentObstacle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: uid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "uid: ";
    rosidl_generator_traits::value_to_yaml(msg.uid, out);
    out << "\n";
  }

  // member: first_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "first_point:\n";
    to_block_style_yaml(msg.first_point, out, indentation + 2);
  }

  // member: last_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_point:\n";
    to_block_style_yaml(msg.last_point, out, indentation + 2);
  }

  // member: first_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "first_velocity:\n";
    to_block_style_yaml(msg.first_velocity, out, indentation + 2);
  }

  // member: last_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_velocity:\n";
    to_block_style_yaml(msg.last_velocity, out, indentation + 2);
  }

  // member: semclass
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "semclass: ";
    rosidl_generator_traits::value_to_yaml(msg.semclass, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SegmentObstacle & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace obstacle_detector

namespace rosidl_generator_traits
{

[[deprecated("use obstacle_detector::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const obstacle_detector::msg::SegmentObstacle & msg,
  std::ostream & out, size_t indentation = 0)
{
  obstacle_detector::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use obstacle_detector::msg::to_yaml() instead")]]
inline std::string to_yaml(const obstacle_detector::msg::SegmentObstacle & msg)
{
  return obstacle_detector::msg::to_yaml(msg);
}

template<>
inline const char * data_type<obstacle_detector::msg::SegmentObstacle>()
{
  return "obstacle_detector::msg::SegmentObstacle";
}

template<>
inline const char * name<obstacle_detector::msg::SegmentObstacle>()
{
  return "obstacle_detector/msg/SegmentObstacle";
}

template<>
struct has_fixed_size<obstacle_detector::msg::SegmentObstacle>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<obstacle_detector::msg::SegmentObstacle>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<obstacle_detector::msg::SegmentObstacle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__TRAITS_HPP_
