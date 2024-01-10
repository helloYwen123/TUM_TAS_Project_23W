// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from obstacle_detector:msg/CircleObstacle.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__STRUCT_H_
#define OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'semclass'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/CircleObstacle in the package obstacle_detector.
typedef struct obstacle_detector__msg__CircleObstacle
{
  /// Unique identifier
  uint64_t uid;
  /// Central point
  geometry_msgs__msg__Point center;
  /// Linear velocity
  geometry_msgs__msg__Vector3 velocity;
  /// Radius with added margin
  double radius;
  /// True measured radius
  double true_radius;
  /// Semantic class
  rosidl_runtime_c__String semclass;
  /// Confidence in semantic class
  double confidence;
} obstacle_detector__msg__CircleObstacle;

// Struct for a sequence of obstacle_detector__msg__CircleObstacle.
typedef struct obstacle_detector__msg__CircleObstacle__Sequence
{
  obstacle_detector__msg__CircleObstacle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} obstacle_detector__msg__CircleObstacle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__STRUCT_H_
