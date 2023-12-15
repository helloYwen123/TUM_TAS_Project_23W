// TAScar.h
#pragma once
#include <Arduino.h>
#include "esp_timer.h"

// header: ESP_TASCar.ino
extern const int CYCLE_TIME_MS;         // ms
extern const float max_velocity;        // m/s
extern const float max_steering_angle;  // rad

// heaer: steering.cpp
void compute_ackermann(float, float, float &, float &, float &, float &, float &);
float compute_steering_angle(float, float);
void compute_twist(float, float, float &, float &);

// heaer: com.cpp
void transmit_to_nuc(float, float, float, float, float, float);
void receive_from_nuc(float &, float &);

// header: rc.cpp
void setup_rc();
bool is_auto_mode();
float get_steering();
float get_throttle();

// header: servo.cpp
// header for Herkulex servo
void setup_servo();
void set_servo_in_deg(float desired_pos);
void set_servo_in_rad(float desired_pos);
float get_servo_in_deg();
void get_servo_status();
void servo_on();
void servo_off();

// header: encoder.cpp
void setup_enc();
void get_pos_enc(float &, float &);
void get_velocity_enc(float &, float &);

// header: stepper.cpp
void stepper_off();
void stepper_on();
void setup_driver();
void set_velocity(float, float);
void get_velocity(float &, float &);
void get_pos(float &, float &);
