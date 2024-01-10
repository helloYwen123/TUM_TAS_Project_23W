// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from obstacle_detector:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__BUILDER_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "obstacle_detector/msg/detail/obstacles__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace obstacle_detector
{

namespace msg
{

namespace builder
{

class Init_Obstacles_circles
{
public:
  explicit Init_Obstacles_circles(::obstacle_detector::msg::Obstacles & msg)
  : msg_(msg)
  {}
  ::obstacle_detector::msg::Obstacles circles(::obstacle_detector::msg::Obstacles::_circles_type arg)
  {
    msg_.circles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::obstacle_detector::msg::Obstacles msg_;
};

class Init_Obstacles_segments
{
public:
  explicit Init_Obstacles_segments(::obstacle_detector::msg::Obstacles & msg)
  : msg_(msg)
  {}
  Init_Obstacles_circles segments(::obstacle_detector::msg::Obstacles::_segments_type arg)
  {
    msg_.segments = std::move(arg);
    return Init_Obstacles_circles(msg_);
  }

private:
  ::obstacle_detector::msg::Obstacles msg_;
};

class Init_Obstacles_header
{
public:
  Init_Obstacles_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Obstacles_segments header(::obstacle_detector::msg::Obstacles::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Obstacles_segments(msg_);
  }

private:
  ::obstacle_detector::msg::Obstacles msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::obstacle_detector::msg::Obstacles>()
{
  return obstacle_detector::msg::builder::Init_Obstacles_header();
}

}  // namespace obstacle_detector

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__BUILDER_HPP_
