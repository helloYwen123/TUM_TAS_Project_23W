// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from obstacle_detector:msg/Obstacles.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "obstacle_detector/msg/detail/obstacles__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace obstacle_detector
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Obstacles_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) obstacle_detector::msg::Obstacles(_init);
}

void Obstacles_fini_function(void * message_memory)
{
  auto typed_message = static_cast<obstacle_detector::msg::Obstacles *>(message_memory);
  typed_message->~Obstacles();
}

size_t size_function__Obstacles__segments(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<obstacle_detector::msg::SegmentObstacle> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Obstacles__segments(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<obstacle_detector::msg::SegmentObstacle> *>(untyped_member);
  return &member[index];
}

void * get_function__Obstacles__segments(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<obstacle_detector::msg::SegmentObstacle> *>(untyped_member);
  return &member[index];
}

void fetch_function__Obstacles__segments(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const obstacle_detector::msg::SegmentObstacle *>(
    get_const_function__Obstacles__segments(untyped_member, index));
  auto & value = *reinterpret_cast<obstacle_detector::msg::SegmentObstacle *>(untyped_value);
  value = item;
}

void assign_function__Obstacles__segments(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<obstacle_detector::msg::SegmentObstacle *>(
    get_function__Obstacles__segments(untyped_member, index));
  const auto & value = *reinterpret_cast<const obstacle_detector::msg::SegmentObstacle *>(untyped_value);
  item = value;
}

void resize_function__Obstacles__segments(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<obstacle_detector::msg::SegmentObstacle> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Obstacles__circles(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<obstacle_detector::msg::CircleObstacle> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Obstacles__circles(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<obstacle_detector::msg::CircleObstacle> *>(untyped_member);
  return &member[index];
}

void * get_function__Obstacles__circles(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<obstacle_detector::msg::CircleObstacle> *>(untyped_member);
  return &member[index];
}

void fetch_function__Obstacles__circles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const obstacle_detector::msg::CircleObstacle *>(
    get_const_function__Obstacles__circles(untyped_member, index));
  auto & value = *reinterpret_cast<obstacle_detector::msg::CircleObstacle *>(untyped_value);
  value = item;
}

void assign_function__Obstacles__circles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<obstacle_detector::msg::CircleObstacle *>(
    get_function__Obstacles__circles(untyped_member, index));
  const auto & value = *reinterpret_cast<const obstacle_detector::msg::CircleObstacle *>(untyped_value);
  item = value;
}

void resize_function__Obstacles__circles(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<obstacle_detector::msg::CircleObstacle> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Obstacles_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector::msg::Obstacles, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "segments",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<obstacle_detector::msg::SegmentObstacle>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector::msg::Obstacles, segments),  // bytes offset in struct
    nullptr,  // default value
    size_function__Obstacles__segments,  // size() function pointer
    get_const_function__Obstacles__segments,  // get_const(index) function pointer
    get_function__Obstacles__segments,  // get(index) function pointer
    fetch_function__Obstacles__segments,  // fetch(index, &value) function pointer
    assign_function__Obstacles__segments,  // assign(index, value) function pointer
    resize_function__Obstacles__segments  // resize(index) function pointer
  },
  {
    "circles",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<obstacle_detector::msg::CircleObstacle>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector::msg::Obstacles, circles),  // bytes offset in struct
    nullptr,  // default value
    size_function__Obstacles__circles,  // size() function pointer
    get_const_function__Obstacles__circles,  // get_const(index) function pointer
    get_function__Obstacles__circles,  // get(index) function pointer
    fetch_function__Obstacles__circles,  // fetch(index, &value) function pointer
    assign_function__Obstacles__circles,  // assign(index, value) function pointer
    resize_function__Obstacles__circles  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Obstacles_message_members = {
  "obstacle_detector::msg",  // message namespace
  "Obstacles",  // message name
  3,  // number of fields
  sizeof(obstacle_detector::msg::Obstacles),
  Obstacles_message_member_array,  // message members
  Obstacles_init_function,  // function to initialize message memory (memory has to be allocated)
  Obstacles_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Obstacles_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Obstacles_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace obstacle_detector


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<obstacle_detector::msg::Obstacles>()
{
  return &::obstacle_detector::msg::rosidl_typesupport_introspection_cpp::Obstacles_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, obstacle_detector, msg, Obstacles)() {
  return &::obstacle_detector::msg::rosidl_typesupport_introspection_cpp::Obstacles_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
