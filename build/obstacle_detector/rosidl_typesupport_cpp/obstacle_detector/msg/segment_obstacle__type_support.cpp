// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from obstacle_detector:msg/SegmentObstacle.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "obstacle_detector/msg/detail/segment_obstacle__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace obstacle_detector
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _SegmentObstacle_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SegmentObstacle_type_support_ids_t;

static const _SegmentObstacle_type_support_ids_t _SegmentObstacle_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SegmentObstacle_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SegmentObstacle_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SegmentObstacle_type_support_symbol_names_t _SegmentObstacle_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, obstacle_detector, msg, SegmentObstacle)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, obstacle_detector, msg, SegmentObstacle)),
  }
};

typedef struct _SegmentObstacle_type_support_data_t
{
  void * data[2];
} _SegmentObstacle_type_support_data_t;

static _SegmentObstacle_type_support_data_t _SegmentObstacle_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SegmentObstacle_message_typesupport_map = {
  2,
  "obstacle_detector",
  &_SegmentObstacle_message_typesupport_ids.typesupport_identifier[0],
  &_SegmentObstacle_message_typesupport_symbol_names.symbol_name[0],
  &_SegmentObstacle_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SegmentObstacle_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SegmentObstacle_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace obstacle_detector

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<obstacle_detector::msg::SegmentObstacle>()
{
  return &::obstacle_detector::msg::rosidl_typesupport_cpp::SegmentObstacle_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, obstacle_detector, msg, SegmentObstacle)() {
  return get_message_type_support_handle<obstacle_detector::msg::SegmentObstacle>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
