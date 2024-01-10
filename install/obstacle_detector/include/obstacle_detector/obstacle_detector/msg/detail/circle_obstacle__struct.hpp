// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from obstacle_detector:msg/CircleObstacle.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__STRUCT_HPP_
#define OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__obstacle_detector__msg__CircleObstacle __attribute__((deprecated))
#else
# define DEPRECATED__obstacle_detector__msg__CircleObstacle __declspec(deprecated)
#endif

namespace obstacle_detector
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CircleObstacle_
{
  using Type = CircleObstacle_<ContainerAllocator>;

  explicit CircleObstacle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center(_init),
    velocity(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uid = 0ull;
      this->radius = 0.0;
      this->true_radius = 0.0;
      this->semclass = "";
      this->confidence = 0.0;
    }
  }

  explicit CircleObstacle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center(_alloc, _init),
    velocity(_alloc, _init),
    semclass(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->uid = 0ull;
      this->radius = 0.0;
      this->true_radius = 0.0;
      this->semclass = "";
      this->confidence = 0.0;
    }
  }

  // field types and members
  using _uid_type =
    uint64_t;
  _uid_type uid;
  using _center_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _center_type center;
  using _velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _velocity_type velocity;
  using _radius_type =
    double;
  _radius_type radius;
  using _true_radius_type =
    double;
  _true_radius_type true_radius;
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
  Type & set__center(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->center = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__radius(
    const double & _arg)
  {
    this->radius = _arg;
    return *this;
  }
  Type & set__true_radius(
    const double & _arg)
  {
    this->true_radius = _arg;
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
    obstacle_detector::msg::CircleObstacle_<ContainerAllocator> *;
  using ConstRawPtr =
    const obstacle_detector::msg::CircleObstacle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<obstacle_detector::msg::CircleObstacle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<obstacle_detector::msg::CircleObstacle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      obstacle_detector::msg::CircleObstacle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<obstacle_detector::msg::CircleObstacle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      obstacle_detector::msg::CircleObstacle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<obstacle_detector::msg::CircleObstacle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<obstacle_detector::msg::CircleObstacle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<obstacle_detector::msg::CircleObstacle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__obstacle_detector__msg__CircleObstacle
    std::shared_ptr<obstacle_detector::msg::CircleObstacle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__obstacle_detector__msg__CircleObstacle
    std::shared_ptr<obstacle_detector::msg::CircleObstacle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CircleObstacle_ & other) const
  {
    if (this->uid != other.uid) {
      return false;
    }
    if (this->center != other.center) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->radius != other.radius) {
      return false;
    }
    if (this->true_radius != other.true_radius) {
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
  bool operator!=(const CircleObstacle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CircleObstacle_

// alias to use template instance with default allocator
using CircleObstacle =
  obstacle_detector::msg::CircleObstacle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace obstacle_detector

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__STRUCT_HPP_
