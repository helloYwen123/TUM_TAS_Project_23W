// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from obstacle_detector:msg/Obstacles.idl
// generated code does not contain a copyright notice
#include "obstacle_detector/msg/detail/obstacles__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `segments`
#include "obstacle_detector/msg/detail/segment_obstacle__functions.h"
// Member `circles`
#include "obstacle_detector/msg/detail/circle_obstacle__functions.h"

bool
obstacle_detector__msg__Obstacles__init(obstacle_detector__msg__Obstacles * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    obstacle_detector__msg__Obstacles__fini(msg);
    return false;
  }
  // segments
  if (!obstacle_detector__msg__SegmentObstacle__Sequence__init(&msg->segments, 0)) {
    obstacle_detector__msg__Obstacles__fini(msg);
    return false;
  }
  // circles
  if (!obstacle_detector__msg__CircleObstacle__Sequence__init(&msg->circles, 0)) {
    obstacle_detector__msg__Obstacles__fini(msg);
    return false;
  }
  return true;
}

void
obstacle_detector__msg__Obstacles__fini(obstacle_detector__msg__Obstacles * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // segments
  obstacle_detector__msg__SegmentObstacle__Sequence__fini(&msg->segments);
  // circles
  obstacle_detector__msg__CircleObstacle__Sequence__fini(&msg->circles);
}

bool
obstacle_detector__msg__Obstacles__are_equal(const obstacle_detector__msg__Obstacles * lhs, const obstacle_detector__msg__Obstacles * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // segments
  if (!obstacle_detector__msg__SegmentObstacle__Sequence__are_equal(
      &(lhs->segments), &(rhs->segments)))
  {
    return false;
  }
  // circles
  if (!obstacle_detector__msg__CircleObstacle__Sequence__are_equal(
      &(lhs->circles), &(rhs->circles)))
  {
    return false;
  }
  return true;
}

bool
obstacle_detector__msg__Obstacles__copy(
  const obstacle_detector__msg__Obstacles * input,
  obstacle_detector__msg__Obstacles * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // segments
  if (!obstacle_detector__msg__SegmentObstacle__Sequence__copy(
      &(input->segments), &(output->segments)))
  {
    return false;
  }
  // circles
  if (!obstacle_detector__msg__CircleObstacle__Sequence__copy(
      &(input->circles), &(output->circles)))
  {
    return false;
  }
  return true;
}

obstacle_detector__msg__Obstacles *
obstacle_detector__msg__Obstacles__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obstacle_detector__msg__Obstacles * msg = (obstacle_detector__msg__Obstacles *)allocator.allocate(sizeof(obstacle_detector__msg__Obstacles), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(obstacle_detector__msg__Obstacles));
  bool success = obstacle_detector__msg__Obstacles__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
obstacle_detector__msg__Obstacles__destroy(obstacle_detector__msg__Obstacles * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    obstacle_detector__msg__Obstacles__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
obstacle_detector__msg__Obstacles__Sequence__init(obstacle_detector__msg__Obstacles__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obstacle_detector__msg__Obstacles * data = NULL;

  if (size) {
    data = (obstacle_detector__msg__Obstacles *)allocator.zero_allocate(size, sizeof(obstacle_detector__msg__Obstacles), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = obstacle_detector__msg__Obstacles__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        obstacle_detector__msg__Obstacles__fini(&data[i - 1]);
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
obstacle_detector__msg__Obstacles__Sequence__fini(obstacle_detector__msg__Obstacles__Sequence * array)
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
      obstacle_detector__msg__Obstacles__fini(&array->data[i]);
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

obstacle_detector__msg__Obstacles__Sequence *
obstacle_detector__msg__Obstacles__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obstacle_detector__msg__Obstacles__Sequence * array = (obstacle_detector__msg__Obstacles__Sequence *)allocator.allocate(sizeof(obstacle_detector__msg__Obstacles__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = obstacle_detector__msg__Obstacles__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
obstacle_detector__msg__Obstacles__Sequence__destroy(obstacle_detector__msg__Obstacles__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    obstacle_detector__msg__Obstacles__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
obstacle_detector__msg__Obstacles__Sequence__are_equal(const obstacle_detector__msg__Obstacles__Sequence * lhs, const obstacle_detector__msg__Obstacles__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!obstacle_detector__msg__Obstacles__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
obstacle_detector__msg__Obstacles__Sequence__copy(
  const obstacle_detector__msg__Obstacles__Sequence * input,
  obstacle_detector__msg__Obstacles__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(obstacle_detector__msg__Obstacles);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    obstacle_detector__msg__Obstacles * data =
      (obstacle_detector__msg__Obstacles *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!obstacle_detector__msg__Obstacles__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          obstacle_detector__msg__Obstacles__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!obstacle_detector__msg__Obstacles__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
