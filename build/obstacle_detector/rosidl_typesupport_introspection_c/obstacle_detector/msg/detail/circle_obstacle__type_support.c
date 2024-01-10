// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from obstacle_detector:msg/CircleObstacle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "obstacle_detector/msg/detail/circle_obstacle__rosidl_typesupport_introspection_c.h"
#include "obstacle_detector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "obstacle_detector/msg/detail/circle_obstacle__functions.h"
#include "obstacle_detector/msg/detail/circle_obstacle__struct.h"


// Include directives for member types
// Member `center`
#include "geometry_msgs/msg/point.h"
// Member `center`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `velocity`
#include "geometry_msgs/msg/vector3.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `semclass`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  obstacle_detector__msg__CircleObstacle__init(message_memory);
}

void obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_fini_function(void * message_memory)
{
  obstacle_detector__msg__CircleObstacle__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_member_array[7] = {
  {
    "uid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__CircleObstacle, uid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__CircleObstacle, center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__CircleObstacle, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__CircleObstacle, radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "true_radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__CircleObstacle, true_radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "semclass",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__CircleObstacle, semclass),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obstacle_detector__msg__CircleObstacle, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_members = {
  "obstacle_detector__msg",  // message namespace
  "CircleObstacle",  // message name
  7,  // number of fields
  sizeof(obstacle_detector__msg__CircleObstacle),
  obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_member_array,  // message members
  obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_init_function,  // function to initialize message memory (memory has to be allocated)
  obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_type_support_handle = {
  0,
  &obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_obstacle_detector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, obstacle_detector, msg, CircleObstacle)() {
  obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_type_support_handle.typesupport_identifier) {
    obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &obstacle_detector__msg__CircleObstacle__rosidl_typesupport_introspection_c__CircleObstacle_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
