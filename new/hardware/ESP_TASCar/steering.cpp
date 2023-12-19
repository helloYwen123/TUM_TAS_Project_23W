// misc.cpp
#include "TAScar.h"

// Parameter
const float max_acceleration = 0.5;              // m/s²
const float max_steering_vel = 5;                // rad/s
const float max_deceleration = 1;                // m/s′
const float max_velocity = 1.5;                  // m/s
const float max_steering_angle = 35 * PI / 180;  // rad
const float length = 0.36;                       // m
const float width = 0.38;                        // m
const float alpha = 0.42984646481017397;         // rad
const float y_offset = 0.03294;                  // m
const float l3 = 0.017997210895024818;           // m

// Variable
float prev_velocity = 0;
float prev_steering_angle = 0;


void limit(float &velocity, float &steering_angle) {
  velocity = min(velocity, max_velocity);
  velocity = max(velocity, -max_velocity);

  steering_angle = min(steering_angle, max_steering_angle);
  steering_angle = max(steering_angle, -max_steering_angle);

  if (prev_velocity > 0) {
    if ((velocity - prev_velocity) * 1000 / CYCLE_TIME_MS > max_acceleration) {
      velocity = prev_velocity + CYCLE_TIME_MS * max_acceleration / 1000;
    } else if ((velocity - prev_velocity) * 1000 / CYCLE_TIME_MS < -max_deceleration) {
      velocity = prev_velocity - CYCLE_TIME_MS * max_deceleration / 1000;
    }
  }else {
    if ((velocity - prev_velocity) * 1000 / CYCLE_TIME_MS > max_deceleration) {
      velocity = prev_velocity + CYCLE_TIME_MS * max_deceleration / 1000;
    } else if ((velocity - prev_velocity) * 1000 / CYCLE_TIME_MS < -max_acceleration) {
      velocity = prev_velocity - CYCLE_TIME_MS * max_acceleration / 1000;
    }
  }

  if ((steering_angle - prev_steering_angle) * 1000 / CYCLE_TIME_MS > max_steering_vel) {
    steering_angle = prev_steering_angle + CYCLE_TIME_MS * max_steering_vel / 1000;
  } else if ((steering_angle - prev_steering_angle) * 1000 / CYCLE_TIME_MS < -max_steering_vel) {
    steering_angle = prev_steering_angle - CYCLE_TIME_MS * max_steering_vel / 1000;
  }

  prev_velocity = velocity;
  prev_steering_angle = steering_angle;
}

float compute_angular_velocity(float velocity, float steering_angle) {
  if (abs(velocity) < 0.01) {
    return 0;
  } else {
    return velocity / length * tan(steering_angle);
  }
}

float compute_steering_angle(float velocity, float angular_velocity) {
  if (abs(velocity) < 0.01) {
    return 0;
  } else {
    return atan(angular_velocity * length / velocity);
  }
}

void compute_ackermann(float velocity, float steering_angle, float &vel_left, float &vel_right, float &servo_angle, float &phi_left, float &phi_right) {
  limit(velocity, steering_angle);

  phi_left = atan(2 * length * tan(steering_angle) / (2 * length - width * tan(steering_angle)));
  phi_right = atan(2 * length * tan(steering_angle) / (2 * length + width * tan(steering_angle)));

  float num = l3 * (sin(alpha + phi_left) - sin(alpha - phi_right));
  float den = l3 * cos(alpha + phi_left) + l3 * cos(alpha - phi_right) - 2 * y_offset;
  servo_angle = -atan(num / den);

  vel_left = velocity * (1 - width * tan(steering_angle) / length / 2);
  vel_right = velocity * (1 + width * tan(steering_angle) / length / 2);
}

void compute_twist(float vel_left, float vel_right, float &velocity, float &angular_velocity) {
  velocity = (vel_right + vel_left) / 2;
  angular_velocity = (vel_right - vel_left) / width;
}