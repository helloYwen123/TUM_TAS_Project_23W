// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from obstacle_detector:msg/SegmentObstacle.idl
// generated code does not contain a copyright notice
#include "obstacle_detector/msg/detail/segment_obstacle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `first_point`
// Member `last_point`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `first_velocity`
// Member `last_velocity`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `semclass`
#include "rosidl_runtime_c/string_functions.h"

bool
obstacle_detector__msg__SegmentObstacle__init(obstacle_detector__msg__SegmentObstacle * msg)
{
  if (!msg) {
    return false;
  }
  // uid
  // first_point
  if (!geometry_msgs__msg__Point__init(&msg->first_point)) {
    obstacle_detector__msg__SegmentObstacle__fini(msg);
    return false;
  }
  // last_point
  if (!geometry_msgs__msg__Point__init(&msg->last_point)) {
    obstacle_detector__msg__SegmentObstacle__fini(msg);
    return false;
  }
  // first_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->first_velocity)) {
    obstacle_detector__msg__SegmentObstacle__fini(msg);
    return false;
  }
  // last_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->last_velocity)) {
    obstacle_detector__msg__SegmentObstacle__fini(msg);
    return false;
  }
  // semclass
  if (!rosidl_runtime_c__String__init(&msg->semclass)) {
    obstacle_detector__msg__SegmentObstacle__fini(msg);
    return false;
  }
  // confidence
  return true;
}

void
obstacle_detector__msg__SegmentObstacle__fini(obstacle_detector__msg__SegmentObstacle * msg)
{
  if (!msg) {
    return;
  }
  // uid
  // first_point
  geometry_msgs__msg__Point__fini(&msg->first_point);
  // last_point
  geometry_msgs__msg__Point__fini(&msg->last_point);
  // first_velocity
  geometry_msgs__msg__Vector3__fini(&msg->first_velocity);
  // last_velocity
  geometry_msgs__msg__Vector3__fini(&msg->last_velocity);
  // semclass
  rosidl_runtime_c__String__fini(&msg->semclass);
  // confidence
}

bool
obstacle_detector__msg__SegmentObstacle__are_equal(const obstacle_detector__msg__SegmentObstacle * lhs, const obstacle_detector__msg__SegmentObstacle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // uid
  if (lhs->uid != rhs->uid) {
    return false;
  }
  // first_point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->first_point), &(rhs->first_point)))
  {
    return false;
  }
  // last_point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->last_point), &(rhs->last_point)))
  {
    return false;
  }
  // first_velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->first_velocity), &(rhs->first_velocity)))
  {
    return false;
  }
  // last_velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->last_velocity), &(rhs->last_velocity)))
  {
    return false;
  }
  // semclass
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->semclass), &(rhs->semclass)))
  {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  return true;
}

bool
obstacle_detector__msg__SegmentObstacle__copy(
  const obstacle_detector__msg__SegmentObstacle * input,
  obstacle_detector__msg__SegmentObstacle * output)
{
  if (!input || !output) {
    return false;
  }
  // uid
  output->uid = input->uid;
  // first_point
  if (!geometry_msgs__msg__Point__copy(
      &(input->first_point), &(output->first_point)))
  {
    return false;
  }
  // last_point
  if (!geometry_msgs__msg__Point__copy(
      &(input->last_point), &(output->last_point)))
  {
    return false;
  }
  // first_velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->first_velocity), &(output->first_velocity)))
  {
    return false;
  }
  // last_velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->last_velocity), &(output->last_velocity)))
  {
    return false;
  }
  // semclass
  if (!rosidl_runtime_c__String__copy(
      &(input->semclass), &(output->semclass)))
  {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  return true;
}

obstacle_detector__msg__SegmentObstacle *
obstacle_detector__msg__SegmentObstacle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obstacle_detector__msg__SegmentObstacle * msg = (obstacle_detector__msg__SegmentObstacle *)allocator.allocate(sizeof(obstacle_detector__msg__SegmentObstacle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(obstacle_detector__msg__SegmentObstacle));
  bool success = obstacle_detector__msg__SegmentObstacle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
obstacle_detector__msg__SegmentObstacle__destroy(obstacle_detector__msg__SegmentObstacle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    obstacle_detector__msg__SegmentObstacle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
obstacle_detector__msg__SegmentObstacle__Sequence__init(obstacle_detector__msg__SegmentObstacle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obstacle_detector__msg__SegmentObstacle * data = NULL;

  if (size) {
    data = (obstacle_detector__msg__SegmentObstacle *)allocator.zero_allocate(size, sizeof(obstacle_detector__msg__SegmentObstacle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = obstacle_detector__msg__SegmentObstacle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        obstacle_detector__msg__SegmentObstacle__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
obstacle_detector__msg__SegmentObstacle__Sequence__fini(obstacle_detector__msg__SegmentObstacle__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      obstacle_detector__msg__SegmentObstacle__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

obstacle_detector__msg__SegmentObstacle__Sequence *
obstacle_detector__msg__SegmentObstacle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obstacle_detector__msg__SegmentObstacle__Sequence * array = (obstacle_detector__msg__SegmentObstacle__Sequence *)allocator.allocate(sizeof(obstacle_detector__msg__SegmentObstacle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = obstacle_detector__msg__SegmentObstacle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
obstacle_detector__msg__SegmentObstacle__Sequence__destroy(obstacle_detector__msg__SegmentObstacle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    obstacle_detector__msg__SegmentObstacle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
obstacle_detector__msg__SegmentObstacle__Sequence__are_equal(const obstacle_detector__msg__SegmentObstacle__Sequence * lhs, const obstacle_detector__msg__SegmentObstacle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!obstacle_detector__msg__SegmentObstacle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
obstacle_detector__msg__SegmentObstacle__Sequence__copy(
  const obstacle_detector__msg__SegmentObstacle__Sequence * input,
  obstacle_detector__msg__SegmentObstacle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(obstacle_detector__msg__SegmentObstacle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    obstacle_detector__msg__SegmentObstacle * data =
      (obstacle_detector__msg__SegmentObstacle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!obstacle_detector__msg__SegmentObstacle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          obstacle_detector__msg__SegmentObstacle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!obstacle_detector__msg__SegmentObstacle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
