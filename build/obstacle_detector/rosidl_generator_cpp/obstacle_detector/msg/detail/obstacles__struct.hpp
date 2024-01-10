// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from obstacle_detector:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__STRUCT_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'segments'
#include "obstacle_detector/msg/detail/segment_obstacle__struct.hpp"
// Member 'circles'
#include "obstacle_detector/msg/detail/circle_obstacle__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__obstacle_detector__msg__Obstacles __attribute__((deprecated))
#else
# define DEPRECATED__obstacle_detector__msg__Obstacles __declspec(deprecated)
#endif

namespace obstacle_detector
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Obstacles_
{
  using Type = Obstacles_<ContainerAllocator>;

  explicit Obstacles_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Obstacles_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _segments_type =
    std::vector<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>>>;
  _segments_type segments;
  using _circles_type =
    std::vector<obstacle_detector::msg::CircleObstacle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<obstacle_detector::msg::CircleObstacle_<ContainerAllocator>>>;
  _circles_type circles;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__segments(
    const std::vector<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>>> & _arg)
  {
    this->segments = _arg;
    return *this;
  }
  Type & set__circles(
    const std::vector<obstacle_detector::msg::CircleObstacle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<obstacle_detector::msg::CircleObstacle_<ContainerAllocator>>> & _arg)
  {
    this->circles = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    obstacle_detector::msg::Obstacles_<ContainerAllocator> *;
  using ConstRawPtr =
    const obstacle_detector::msg::Obstacles_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<obstacle_detector::msg::Obstacles_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<obstacle_detector::msg::Obstacles_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      obstacle_detector::msg::Obstacles_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<obstacle_detector::msg::Obstacles_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      obstacle_detector::msg::Obstacles_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<obstacle_detector::msg::Obstacles_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<obstacle_detector::msg::Obstacles_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<obstacle_detector::msg::Obstacles_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__obstacle_detector__msg__Obstacles
    std::shared_ptr<obstacle_detector::msg::Obstacles_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__obstacle_detector__msg__Obstacles
    std::shared_ptr<obstacle_detector::msg::Obstacles_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Obstacles_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->segments != other.segments) {
      return false;
    }
    if (this->circles != other.circles) {
      return false;
    }
    return true;
  }
  bool operator!=(const Obstacles_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Obstacles_

// alias to use template instance with default allocator
using Obstacles =
  obstacle_detector::msg::Obstacles_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace obstacle_detector

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__STRUCT_HPP_
