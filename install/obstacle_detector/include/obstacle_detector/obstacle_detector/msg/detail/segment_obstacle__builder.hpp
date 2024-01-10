// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from obstacle_detector:msg/SegmentObstacle.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__BUILDER_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "obstacle_detector/msg/detail/segment_obstacle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace obstacle_detector
{

namespace msg
{

namespace builder
{

class Init_SegmentObstacle_confidence
{
public:
  explicit Init_SegmentObstacle_confidence(::obstacle_detector::msg::SegmentObstacle & msg)
  : msg_(msg)
  {}
  ::obstacle_detector::msg::SegmentObstacle confidence(::obstacle_detector::msg::SegmentObstacle::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::obstacle_detector::msg::SegmentObstacle msg_;
};

class Init_SegmentObstacle_semclass
{
public:
  explicit Init_SegmentObstacle_semclass(::obstacle_detector::msg::SegmentObstacle & msg)
  : msg_(msg)
  {}
  Init_SegmentObstacle_confidence semclass(::obstacle_detector::msg::SegmentObstacle::_semclass_type arg)
  {
    msg_.semclass = std::move(arg);
    return Init_SegmentObstacle_confidence(msg_);
  }

private:
  ::obstacle_detector::msg::SegmentObstacle msg_;
};

class Init_SegmentObstacle_last_velocity
{
public:
  explicit Init_SegmentObstacle_last_velocity(::obstacle_detector::msg::SegmentObstacle & msg)
  : msg_(msg)
  {}
  Init_SegmentObstacle_semclass last_velocity(::obstacle_detector::msg::SegmentObstacle::_last_velocity_type arg)
  {
    msg_.last_velocity = std::move(arg);
    return Init_SegmentObstacle_semclass(msg_);
  }

private:
  ::obstacle_detector::msg::SegmentObstacle msg_;
};

class Init_SegmentObstacle_first_velocity
{
public:
  explicit Init_SegmentObstacle_first_velocity(::obstacle_detector::msg::SegmentObstacle & msg)
  : msg_(msg)
  {}
  Init_SegmentObstacle_last_velocity first_velocity(::obstacle_detector::msg::SegmentObstacle::_first_velocity_type arg)
  {
    msg_.first_velocity = std::move(arg);
    return Init_SegmentObstacle_last_velocity(msg_);
  }

private:
  ::obstacle_detector::msg::SegmentObstacle msg_;
};

class Init_SegmentObstacle_last_point
{
public:
  explicit Init_SegmentObstacle_last_point(::obstacle_detector::msg::SegmentObstacle & msg)
  : msg_(msg)
  {}
  Init_SegmentObstacle_first_velocity last_point(::obstacle_detector::msg::SegmentObstacle::_last_point_type arg)
  {
    msg_.last_point = std::move(arg);
    return Init_SegmentObstacle_first_velocity(msg_);
  }

private:
  ::obstacle_detector::msg::SegmentObstacle msg_;
};

class Init_SegmentObstacle_first_point
{
public:
  explicit Init_SegmentObstacle_first_point(::obstacle_detector::msg::SegmentObstacle & msg)
  : msg_(msg)
  {}
  Init_SegmentObstacle_last_point first_point(::obstacle_detector::msg::SegmentObstacle::_first_point_type arg)
  {
    msg_.first_point = std::move(arg);
    return Init_SegmentObstacle_last_point(msg_);
  }

private:
  ::obstacle_detector::msg::SegmentObstacle msg_;
};

class Init_SegmentObstacle_uid
{
public:
  Init_SegmentObstacle_uid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SegmentObstacle_first_point uid(::obstacle_detector::msg::SegmentObstacle::_uid_type arg)
  {
    msg_.uid = std::move(arg);
    return Init_SegmentObstacle_first_point(msg_);
  }

private:
  ::obstacle_detector::msg::SegmentObstacle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::obstacle_detector::msg::SegmentObstacle>()
{
  return obstacle_detector::msg::builder::Init_SegmentObstacle_uid();
}

}  // namespace obstacle_detector

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__BUILDER_HPP_
