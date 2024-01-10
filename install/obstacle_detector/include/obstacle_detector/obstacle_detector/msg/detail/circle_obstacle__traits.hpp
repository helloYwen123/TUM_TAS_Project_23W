// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from obstacle_detector:msg/CircleObstacle.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__TRAITS_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "obstacle_detector/msg/detail/circle_obstacle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace obstacle_detector
{

namespace msg
{

inline void to_flow_style_yaml(
  const CircleObstacle & msg,
  std::ostream & out)
{
  out << "{";
  // member: uid
  {
    out << "uid: ";
    rosidl_generator_traits::value_to_yaml(msg.uid, out);
    out << ", ";
  }

  // member: center
  {
    out << "center: ";
    to_flow_style_yaml(msg.center, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: radius
  {
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << ", ";
  }

  // member: true_radius
  {
    out << "true_radius: ";
    rosidl_generator_traits::value_to_yaml(msg.true_radius, out);
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
  const CircleObstacle & msg,
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

  // member: center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center:\n";
    to_block_style_yaml(msg.center, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << "\n";
  }

  // member: true_radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "true_radius: ";
    rosidl_generator_traits::value_to_yaml(msg.true_radius, out);
    out << "\n";
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

inline std::string to_yaml(const CircleObstacle & msg, bool use_flow_style = false)
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
  const obstacle_detector::msg::CircleObstacle & msg,
  std::ostream & out, size_t indentation = 0)
{
  obstacle_detector::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use obstacle_detector::msg::to_yaml() instead")]]
inline std::string to_yaml(const obstacle_detector::msg::CircleObstacle & msg)
{
  return obstacle_detector::msg::to_yaml(msg);
}

template<>
inline const char * data_type<obstacle_detector::msg::CircleObstacle>()
{
  return "obstacle_detector::msg::CircleObstacle";
}

template<>
inline const char * name<obstacle_detector::msg::CircleObstacle>()
{
  return "obstacle_detector/msg/CircleObstacle";
}

template<>
struct has_fixed_size<obstacle_detector::msg::CircleObstacle>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<obstacle_detector::msg::CircleObstacle>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<obstacle_detector::msg::CircleObstacle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__TRAITS_HPP_
