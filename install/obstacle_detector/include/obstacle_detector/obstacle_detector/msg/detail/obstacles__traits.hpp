// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from obstacle_detector:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__TRAITS_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "obstacle_detector/msg/detail/obstacles__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'segments'
#include "obstacle_detector/msg/detail/segment_obstacle__traits.hpp"
// Member 'circles'
#include "obstacle_detector/msg/detail/circle_obstacle__traits.hpp"

namespace obstacle_detector
{

namespace msg
{

inline void to_flow_style_yaml(
  const Obstacles & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: segments
  {
    if (msg.segments.size() == 0) {
      out << "segments: []";
    } else {
      out << "segments: [";
      size_t pending_items = msg.segments.size();
      for (auto item : msg.segments) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: circles
  {
    if (msg.circles.size() == 0) {
      out << "circles: []";
    } else {
      out << "circles: [";
      size_t pending_items = msg.circles.size();
      for (auto item : msg.circles) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Obstacles & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: segments
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.segments.size() == 0) {
      out << "segments: []\n";
    } else {
      out << "segments:\n";
      for (auto item : msg.segments) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: circles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.circles.size() == 0) {
      out << "circles: []\n";
    } else {
      out << "circles:\n";
      for (auto item : msg.circles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Obstacles & msg, bool use_flow_style = false)
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
  const obstacle_detector::msg::Obstacles & msg,
  std::ostream & out, size_t indentation = 0)
{
  obstacle_detector::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use obstacle_detector::msg::to_yaml() instead")]]
inline std::string to_yaml(const obstacle_detector::msg::Obstacles & msg)
{
  return obstacle_detector::msg::to_yaml(msg);
}

template<>
inline const char * data_type<obstacle_detector::msg::Obstacles>()
{
  return "obstacle_detector::msg::Obstacles";
}

template<>
inline const char * name<obstacle_detector::msg::Obstacles>()
{
  return "obstacle_detector/msg/Obstacles";
}

template<>
struct has_fixed_size<obstacle_detector::msg::Obstacles>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<obstacle_detector::msg::Obstacles>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<obstacle_detector::msg::Obstacles>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__TRAITS_HPP_
