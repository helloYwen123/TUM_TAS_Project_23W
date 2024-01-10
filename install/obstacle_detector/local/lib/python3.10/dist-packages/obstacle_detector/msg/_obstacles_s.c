// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from obstacle_detector:msg/Obstacles.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "obstacle_detector/msg/detail/obstacles__struct.h"
#include "obstacle_detector/msg/detail/obstacles__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "obstacle_detector/msg/detail/circle_obstacle__functions.h"
#include "obstacle_detector/msg/detail/segment_obstacle__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool obstacle_detector__msg__segment_obstacle__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * obstacle_detector__msg__segment_obstacle__convert_to_py(void * raw_ros_message);
bool obstacle_detector__msg__circle_obstacle__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * obstacle_detector__msg__circle_obstacle__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool obstacle_detector__msg__obstacles__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("obstacle_detector.msg._obstacles.Obstacles", full_classname_dest, 42) == 0);
  }
  obstacle_detector__msg__Obstacles * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // segments
    PyObject * field = PyObject_GetAttrString(_pymsg, "segments");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'segments'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!obstacle_detector__msg__SegmentObstacle__Sequence__init(&(ros_message->segments), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create obstacle_detector__msg__SegmentObstacle__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    obstacle_detector__msg__SegmentObstacle * dest = ros_message->segments.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!obstacle_detector__msg__segment_obstacle__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // circles
    PyObject * field = PyObject_GetAttrString(_pymsg, "circles");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'circles'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!obstacle_detector__msg__CircleObstacle__Sequence__init(&(ros_message->circles), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create obstacle_detector__msg__CircleObstacle__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    obstacle_detector__msg__CircleObstacle * dest = ros_message->circles.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!obstacle_detector__msg__circle_obstacle__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * obstacle_detector__msg__obstacles__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Obstacles */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("obstacle_detector.msg._obstacles");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Obstacles");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  obstacle_detector__msg__Obstacles * ros_message = (obstacle_detector__msg__Obstacles *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // segments
    PyObject * field = NULL;
    size_t size = ros_message->segments.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    obstacle_detector__msg__SegmentObstacle * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->segments.data[i]);
      PyObject * pyitem = obstacle_detector__msg__segment_obstacle__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "segments", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // circles
    PyObject * field = NULL;
    size_t size = ros_message->circles.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    obstacle_detector__msg__CircleObstacle * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->circles.data[i]);
      PyObject * pyitem = obstacle_detector__msg__circle_obstacle__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "circles", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
