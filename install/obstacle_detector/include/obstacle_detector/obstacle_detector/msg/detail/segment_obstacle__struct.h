// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from obstacle_detector:msg/SegmentObstacle.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__STRUCT_H_
#define OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'first_point'
// Member 'last_point'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'first_velocity'
// Member 'last_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'semclass'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SegmentObstacle in the package obstacle_detector.
typedef struct obstacle_detector__msg__SegmentObstacle
{
  /// Unique identifier
  uint64_t uid;
  /// First point of the segment
  geometry_msgs__msg__Point first_point;
  /// Last point of the segment
  geometry_msgs__msg__Point last_point;
  /// Linear velocity
  geometry_msgs__msg__Vector3 first_velocity;
  /// Linear velocity
  geometry_msgs__msg__Vector3 last_velocity;
  /// Semantic class
  rosidl_runtime_c__String semclass;
  /// Confidence in semantic class
  double confidence;
} obstacle_detector__msg__SegmentObstacle;

// Struct for a sequence of obstacle_detector__msg__SegmentObstacle.
typedef struct obstacle_detector__msg__SegmentObstacle__Sequence
{
  obstacle_detector__msg__SegmentObstacle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} obstacle_detector__msg__SegmentObstacle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__SEGMENT_OBSTACLE__STRUCT_H_
