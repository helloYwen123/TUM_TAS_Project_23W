// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from obstacle_detector:msg/CircleObstacle.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__BUILDER_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "obstacle_detector/msg/detail/circle_obstacle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace obstacle_detector
{

namespace msg
{

namespace builder
{

class Init_CircleObstacle_confidence
{
public:
  explicit Init_CircleObstacle_confidence(::obstacle_detector::msg::CircleObstacle & msg)
  : msg_(msg)
  {}
  ::obstacle_detector::msg::CircleObstacle confidence(::obstacle_detector::msg::CircleObstacle::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::obstacle_detector::msg::CircleObstacle msg_;
};

class Init_CircleObstacle_semclass
{
public:
  explicit Init_CircleObstacle_semclass(::obstacle_detector::msg::CircleObstacle & msg)
  : msg_(msg)
  {}
  Init_CircleObstacle_confidence semclass(::obstacle_detector::msg::CircleObstacle::_semclass_type arg)
  {
    msg_.semclass = std::move(arg);
    return Init_CircleObstacle_confidence(msg_);
  }

private:
  ::obstacle_detector::msg::CircleObstacle msg_;
};

class Init_CircleObstacle_true_radius
{
public:
  explicit Init_CircleObstacle_true_radius(::obstacle_detector::msg::CircleObstacle & msg)
  : msg_(msg)
  {}
  Init_CircleObstacle_semclass true_radius(::obstacle_detector::msg::CircleObstacle::_true_radius_type arg)
  {
    msg_.true_radius = std::move(arg);
    return Init_CircleObstacle_semclass(msg_);
  }

private:
  ::obstacle_detector::msg::CircleObstacle msg_;
};

class Init_CircleObstacle_radius
{
public:
  explicit Init_CircleObstacle_radius(::obstacle_detector::msg::CircleObstacle & msg)
  : msg_(msg)
  {}
  Init_CircleObstacle_true_radius radius(::obstacle_detector::msg::CircleObstacle::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_CircleObstacle_true_radius(msg_);
  }

private:
  ::obstacle_detector::msg::CircleObstacle msg_;
};

class Init_CircleObstacle_velocity
{
public:
  explicit Init_CircleObstacle_velocity(::obstacle_detector::msg::CircleObstacle & msg)
  : msg_(msg)
  {}
  Init_CircleObstacle_radius velocity(::obstacle_detector::msg::CircleObstacle::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_CircleObstacle_radius(msg_);
  }

private:
  ::obstacle_detector::msg::CircleObstacle msg_;
};

class Init_CircleObstacle_center
{
public:
  explicit Init_CircleObstacle_center(::obstacle_detector::msg::CircleObstacle & msg)
  : msg_(msg)
  {}
  Init_CircleObstacle_velocity center(::obstacle_detector::msg::CircleObstacle::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_CircleObstacle_velocity(msg_);
  }

private:
  ::obstacle_detector::msg::CircleObstacle msg_;
};

class Init_CircleObstacle_uid
{
public:
  Init_CircleObstacle_uid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CircleObstacle_center uid(::obstacle_detector::msg::CircleObstacle::_uid_type arg)
  {
    msg_.uid = std::move(arg);
    return Init_CircleObstacle_center(msg_);
  }

private:
  ::obstacle_detector::msg::CircleObstacle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::obstacle_detector::msg::CircleObstacle>()
{
  return obstacle_detector::msg::builder::Init_CircleObstacle_uid();
}

}  // namespace obstacle_detector

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__BUILDER_HPP_
