// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from obstacle_detector:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__STRUCT_H_
#define OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'segments'
#include "obstacle_detector/msg/detail/segment_obstacle__struct.h"
// Member 'circles'
#include "obstacle_detector/msg/detail/circle_obstacle__struct.h"

/// Struct defined in msg/Obstacles in the package obstacle_detector.
typedef struct obstacle_detector__msg__Obstacles
{
  std_msgs__msg__Header header;
  obstacle_detector__msg__SegmentObstacle__Sequence segments;
  obstacle_detector__msg__CircleObstacle__Sequence circles;
} obstacle_detector__msg__Obstacles;

// Struct for a sequence of obstacle_detector__msg__Obstacles.
typedef struct obstacle_detector__msg__Obstacles__Sequence
{
  obstacle_detector__msg__Obstacles * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} obstacle_detector__msg__Obstacles__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__OBSTACLES__STRUCT_H_
