// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from obstacle_detector:msg/SegmentObstacle.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__STRUCT_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'first_point'
// Member 'last_point'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'first_velocity'
// Member 'last_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__obstacle_detector__msg__SegmentObstacle __attribute__((deprecated))
#else
# define DEPRECATED__obstacle_detector__msg__SegmentObstacle __declspec(deprecated)
#endif

namespace obstacle_detector
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SegmentObstacle_
{
  using Type = SegmentObstacle_<ContainerAllocator>;

  explicit SegmentObstacle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : first_point(_init),
    last_point(_init),
    first_velocity(_init),
    last_velocity(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uid = 0ull;
      this->semclass = "";
      this->confidence = 0.0;
    }
  }

  explicit SegmentObstacle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : first_point(_alloc, _init),
    last_point(_alloc, _init),
    first_velocity(_alloc, _init),
    last_velocity(_alloc, _init),
    semclass(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uid = 0ull;
      this->semclass = "";
      this->confidence = 0.0;
    }
  }

  // field types and members
  using _uid_type =
    uint64_t;
  _uid_type uid;
  using _first_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _first_point_type first_point;
  using _last_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _last_point_type last_point;
  using _first_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _first_velocity_type first_velocity;
  using _last_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _last_velocity_type last_velocity;
  using _semclass_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _semclass_type semclass;
  using _confidence_type =
    double;
  _confidence_type confidence;

  // setters for named parameter idiom
  Type & set__uid(
    const uint64_t & _arg)
  {
    this->uid = _arg;
    return *this;
  }
  Type & set__first_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->first_point = _arg;
    return *this;
  }
  Type & set__last_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->last_point = _arg;
    return *this;
  }
  Type & set__first_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->first_velocity = _arg;
    return *this;
  }
  Type & set__last_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->last_velocity = _arg;
    return *this;
  }
  Type & set__semclass(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->semclass = _arg;
    return *this;
  }
  Type & set__confidence(
    const double & _arg)
  {
    this->confidence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    obstacle_detector::msg::SegmentObstacle_<ContainerAllocator> *;
  using ConstRawPtr =
    const obstacle_detector::msg::SegmentObstacle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__obstacle_detector__msg__SegmentObstacle
    std::shared_ptr<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__obstacle_detector__msg__SegmentObstacle
    std::shared_ptr<obstacle_detector::msg::SegmentObstacle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SegmentObstacle_ & other) const
  {
    if (this->uid != other.uid) {
      return false;
    }
    if (this->first_point != other.first_point) {
      return false;
    }
    if (this->last_point != other.last_point) {
      return false;
    }
    if (this->first_velocity != other.first_velocity) {
      return false;
    }
    if (this->last_velocity != other.last_velocity) {
      return false;
    }
    if (this->semclass != other.semclass) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const SegmentObstacle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SegmentObstacle_

// alias to use template instance with default allocator
using SegmentObstacle =
  obstacle_detector::msg::SegmentObstacle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace obstacle_detector

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__STRUCT_HPP_
