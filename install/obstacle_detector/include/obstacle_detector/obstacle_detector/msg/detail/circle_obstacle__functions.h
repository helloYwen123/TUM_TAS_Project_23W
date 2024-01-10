// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from obstacle_detector:msg/CircleObstacle.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__FUNCTIONS_H_
#define OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "obstacle_detector/msg/rosidl_generator_c__visibility_control.h"

#include "obstacle_detector/msg/detail/circle_obstacle__struct.h"

/// Initialize msg/CircleObstacle message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * obstacle_detector__msg__CircleObstacle
 * )) before or use
 * obstacle_detector__msg__CircleObstacle__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
bool
obstacle_detector__msg__CircleObstacle__init(obstacle_detector__msg__CircleObstacle * msg);

/// Finalize msg/CircleObstacle message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
void
obstacle_detector__msg__CircleObstacle__fini(obstacle_detector__msg__CircleObstacle * msg);

/// Create msg/CircleObstacle message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * obstacle_detector__msg__CircleObstacle__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
obstacle_detector__msg__CircleObstacle *
obstacle_detector__msg__CircleObstacle__create();

/// Destroy msg/CircleObstacle message.
/**
 * It calls
 * obstacle_detector__msg__CircleObstacle__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
void
obstacle_detector__msg__CircleObstacle__destroy(obstacle_detector__msg__CircleObstacle * msg);

/// Check for msg/CircleObstacle message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
bool
obstacle_detector__msg__CircleObstacle__are_equal(const obstacle_detector__msg__CircleObstacle * lhs, const obstacle_detector__msg__CircleObstacle * rhs);

/// Copy a msg/CircleObstacle message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
bool
obstacle_detector__msg__CircleObstacle__copy(
  const obstacle_detector__msg__CircleObstacle * input,
  obstacle_detector__msg__CircleObstacle * output);

/// Initialize array of msg/CircleObstacle messages.
/**
 * It allocates the memory for the number of elements and calls
 * obstacle_detector__msg__CircleObstacle__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
bool
obstacle_detector__msg__CircleObstacle__Sequence__init(obstacle_detector__msg__CircleObstacle__Sequence * array, size_t size);

/// Finalize array of msg/CircleObstacle messages.
/**
 * It calls
 * obstacle_detector__msg__CircleObstacle__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
void
obstacle_detector__msg__CircleObstacle__Sequence__fini(obstacle_detector__msg__CircleObstacle__Sequence * array);

/// Create array of msg/CircleObstacle messages.
/**
 * It allocates the memory for the array and calls
 * obstacle_detector__msg__CircleObstacle__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
obstacle_detector__msg__CircleObstacle__Sequence *
obstacle_detector__msg__CircleObstacle__Sequence__create(size_t size);

/// Destroy array of msg/CircleObstacle messages.
/**
 * It calls
 * obstacle_detector__msg__CircleObstacle__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
void
obstacle_detector__msg__CircleObstacle__Sequence__destroy(obstacle_detector__msg__CircleObstacle__Sequence * array);

/// Check for msg/CircleObstacle message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
bool
obstacle_detector__msg__CircleObstacle__Sequence__are_equal(const obstacle_detector__msg__CircleObstacle__Sequence * lhs, const obstacle_detector__msg__CircleObstacle__Sequence * rhs);

/// Copy an array of msg/CircleObstacle messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_obstacle_detector
bool
obstacle_detector__msg__CircleObstacle__Sequence__copy(
  const obstacle_detector__msg__CircleObstacle__Sequence * input,
  obstacle_detector__msg__CircleObstacle__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OBSTACLE_DETECTOR__MSG__DETAIL__CIRCLE_OBSTACLE__FUNCTIONS_H_
