// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from obstacle_detector:msg/Obstacles.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "obstacle_detector/msg/detail/obstacles__rosidl_typesupport_introspection_c.h"
#include "obstacle_detector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "obstacle_detector/msg/detail/obstacles__functions.h"
#include "obstacle_detector/msg/detail/obstacles__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `segments`
#include "obstacle_detector/msg/segment_obstacle.h"
// Member `segments`
#include "obstacle_detector/msg/detail/segment_obstacle__rosidl_typesupport_introspection_c.h"
// Member `circles`
#include "obstacle_detector/msg/circle_obstacle.h"
// Member `circles`
#include "obstacle_detector/msg/detail/circle_obstacle__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  obstacle_detector__msg__Obstacles__init(message_memory);
}

void obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_fini_function(void * message_memory)
{
  obstacle_detector__msg__Obstacles__fini(message_memory);
}

size_t obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__segments(
  const void * untyped_member)
{
  const obstacle_detector__msg__SegmentObstacle__Sequence * member =
    (const obstacle_detector__msg__SegmentObstacle__Sequence *)(untyped_member);
  return member->size;
}

const void * obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__segments(
  const void * untyped_member, size_t index)
{
  const obstacle_detector__msg__SegmentObstacle__Sequence * member =
    (const obstacle_detector__msg__SegmentObstacle__Sequence *)(untyped_member);
  return &member->data[index];
}

void * obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__segments(
  void * untyped_member, size_t index)
{
  obstacle_detector__msg__SegmentObstacle__Sequence * member =
    (obstacle_detector__msg__SegmentObstacle__Sequence *)(untyped_member);
  return &member->data[index];
}

void obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__segments(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const obstacle_detector__msg__SegmentObstacle * item =
    ((const obstacle_detector__msg__SegmentObstacle *)
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__segments(untyped_member, index));
  obstacle_detector__msg__SegmentObstacle * value =
    (obstacle_detector__msg__SegmentObstacle *)(untyped_value);
  *value = *item;
}

void obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__segments(
  void * untyped_member, size_t index, const void * untyped_value)
{
  obstacle_detector__msg__SegmentObstacle * item =
    ((obstacle_detector__msg__SegmentObstacle *)
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__segments(untyped_member, index));
  const obstacle_detector__msg__SegmentObstacle * value =
    (const obstacle_detector__msg__SegmentObstacle *)(untyped_value);
  *item = *value;
}

bool obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__segments(
  void * untyped_member, size_t size)
{
  obstacle_detector__msg__SegmentObstacle__Sequence * member =
    (obstacle_detector__msg__SegmentObstacle__Sequence *)(untyped_member);
  obstacle_detector__msg__SegmentObstacle__Sequence__fini(member);
  return obstacle_detector__msg__SegmentObstacle__Sequence__init(member, size);
}

size_t obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__circles(
  const void * untyped_member)
{
  const obstacle_detector__msg__CircleObstacle__Sequence * member =
    (const obstacle_detector__msg__CircleObstacle__Sequence *)(untyped_member);
  return member->size;
}

const void * obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__circles(
  const void * untyped_member, size_t index)
{
  const obstacle_detector__msg__CircleObstacle__Sequence * member =
    (const obstacle_detector__msg__CircleObstacle__Sequence *)(untyped_member);
  return &member->data[index];
}

void * obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__circles(
  void * untyped_member, size_t index)
{
  obstacle_detector__msg__CircleObstacle__Sequence * member =
    (obstacle_detector__msg__CircleObstacle__Sequence *)(untyped_member);
  return &member->data[index];
}

void obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__circles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const obstacle_detector__msg__CircleObstacle * item =
    ((const obstacle_detector__msg__CircleObstacle *)
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__circles(untyped_member, index));
  obstacle_detector__msg__CircleObstacle * value =
    (obstacle_detector__msg__CircleObstacle *)(untyped_value);
  *value = *item;
}

void obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__circles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  obstacle_detector__msg__CircleObstacle * item =
    ((obstacle_detector__msg__CircleObstacle *)
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__circles(untyped_member, index));
  const obstacle_detector__msg__CircleObstacle * value =
    (const obstacle_detector__msg__CircleObstacle *)(untyped_value);
  *item = *value;
}

bool obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__circles(
  void * untyped_member, size_t size)
{
  obstacle_detector__msg__CircleObstacle__Sequence * member =
    (obstacle_detector__msg__CircleObstacle__Sequence *)(untyped_member);
  obstacle_detector__msg__CircleObstacle__Sequence__fini(member);
  return obstacle_detector__msg__CircleObstacle__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__Obstacles, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "segments",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__Obstacles, segments),  // bytes offset in struct
    NULL,  // default value
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__segments,  // size() function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__segments,  // get_const(index) function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__segments,  // get(index) function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__segments,  // fetch(index, &value) function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__segments,  // assign(index, value) function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__segments  // resize(index) function pointer
  },
  {
    "circles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__Obstacles, circles),  // bytes offset in struct
    NULL,  // default value
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__circles,  // size() function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__circles,  // get_const(index) function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__circles,  // get(index) function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__circles,  // fetch(index, &value) function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__circles,  // assign(index, value) function pointer
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__circles  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_members = {
  "obstacle_detector__msg",  // message namespace
  "Obstacles",  // message name
  3,  // number of fields
  sizeof(obstacle_detector__msg__Obstacles),
  obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_member_array,  // message members
  obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_init_function,  // function to initialize message memory (memory has to be allocated)
  obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_type_support_handle = {
  0,
  &obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_obstacle_detector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, obstacle_detector, msg, Obstacles)() {
  obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, obstacle_detector, msg, SegmentObstacle)();
  obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, obstacle_detector, msg, CircleObstacle)();
  if (!obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_type_support_handle.typesupport_identifier) {
    obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &obstacle_detector__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
