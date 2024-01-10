# generated from rosidl_generator_py/resource/_idl.py.em
# with input from obstacle_detector:msg/CircleObstacle.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CircleObstacle(type):
    """Metaclass of message 'CircleObstacle'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('obstacle_detector')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'obstacle_detector.msg.CircleObstacle')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__circle_obstacle
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__circle_obstacle
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__circle_obstacle
            cls._TYPE_SUPPORT = module.type_support_msg__msg__circle_obstacle
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__circle_obstacle

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CircleObstacle(metaclass=Metaclass_CircleObstacle):
    """Message class 'CircleObstacle'."""

    __slots__ = [
        '_uid',
        '_center',
        '_velocity',
        '_radius',
        '_true_radius',
        '_semclass',
        '_confidence',
    ]

    _fields_and_field_types = {
        'uid': 'uint64',
        'center': 'geometry_msgs/Point',
        'velocity': 'geometry_msgs/Vector3',
        'radius': 'double',
        'true_radius': 'double',
        'semclass': 'string',
        'confidence': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.uid = kwargs.get('uid', int())
        from geometry_msgs.msg import Point
        self.center = kwargs.get('center', Point())
        from geometry_msgs.msg import Vector3
        self.velocity = kwargs.get('velocity', Vector3())
        self.radius = kwargs.get('radius', float())
        self.true_radius = kwargs.get('true_radius', float())
        self.semclass = kwargs.get('semclass', str())
        self.confidence = kwargs.get('confidence', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.uid != other.uid:
            return False
        if self.center != other.center:
            return False
        if self.velocity != other.velocity:
            return False
        if self.radius != other.radius:
            return False
        if self.true_radius != other.true_radius:
            return False
        if self.semclass != other.semclass:
            return False
        if self.confidence != other.confidence:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def uid(self):
        """Message field 'uid'."""
        return self._uid

    @uid.setter
    def uid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'uid' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'uid' field must be an unsigned integer in [0, 18446744073709551615]"
        self._uid = value

    @builtins.property
    def center(self):
        """Message field 'center'."""
        return self._center

    @center.setter
    def center(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'center' field must be a sub message of type 'Point'"
        self._center = value

    @builtins.property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'velocity' field must be a sub message of type 'Vector3'"
        self._velocity = value

    @builtins.property
    def radius(self):
        """Message field 'radius'."""
        return self._radius

    @radius.setter
    def radius(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'radius' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'radius' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._radius = value

    @builtins.property
    def true_radius(self):
        """Message field 'true_radius'."""
        return self._true_radius

    @true_radius.setter
    def true_radius(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'true_radius' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'true_radius' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._true_radius = value

    @builtins.property
    def semclass(self):
        """Message field 'semclass'."""
        return self._semclass

    @semclass.setter
    def semclass(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'semclass' field must be of type 'str'"
        self._semclass = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'confidence' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._confidence = value
