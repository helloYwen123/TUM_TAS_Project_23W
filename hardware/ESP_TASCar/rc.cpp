// rc.cpp
// Remote control
#include "TAScar.h"

// Define constants
// Use here Interput pins
const int16_t STEERING_PIN = 21;    // steering, CH1
const int16_t THROTTLE_PIN = 22;    // throttle, CH2
const int16_t MODE_PIN = 23;        // control mode switch, CH3
const float PulseMin = 1000;  // microseconds (us)
const float PulseMax = 2000;  // Ideal values for your servo can be found with the "Calibration" example
const uint32_t TIMEOUT = 50000;  // Timeout in micro second to detect that the controller is switched off

// Define variables
volatile uint32_t time_rising_steering = 0;
volatile uint32_t time_rising_throttle = 0;
volatile uint32_t time_steering = 0;
volatile uint32_t time_throttle = 0;
volatile uint32_t time_mode = 0;

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float mapfloat_deadzone(float x, float in_min, float in_max, float out_min, float out_max, float deadzone) {
  float in_mean = (in_max+in_min)/2;
  float out_mean = (out_max+out_min)/2;
  float threshold = (in_max-in_min)*deadzone;
  if (x > in_mean + threshold){
    return mapfloat(x, in_mean + threshold, in_max, out_mean, out_max);
  }
  else if (x < in_mean - threshold){
    return mapfloat(x, in_min, in_mean - threshold, out_min, out_mean);
  }
  return 0;
}

void IRAM_ATTR ISR_rising_mode_pin() {  // Interupt Service Routine
  time_mode = esp_timer_get_time();
}

void IRAM_ATTR ISR_steering_pin() {  // Interupt Service Routine
  if (digitalRead(STEERING_PIN)) {
    time_rising_steering = esp_timer_get_time();
  } else {
    time_steering = esp_timer_get_time() - time_rising_steering;
  }
}

void IRAM_ATTR ISR_throttle_pin() {  // Interupt Service Routine
  if (digitalRead(THROTTLE_PIN)) {
    time_rising_throttle = esp_timer_get_time();
  } else {
    time_throttle = esp_timer_get_time() - time_rising_throttle;
  }
}

void setup_rc() {  // setup nessesary for Function is_auto_mode()
  pinMode(STEERING_PIN, INPUT);
  pinMode(THROTTLE_PIN, INPUT);
  pinMode(MODE_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(STEERING_PIN), ISR_steering_pin, CHANGE);
  attachInterrupt(digitalPinToInterrupt(THROTTLE_PIN), ISR_throttle_pin, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MODE_PIN), ISR_rising_mode_pin, RISING);
}

bool is_auto_mode() {  // Measure time since last rising edge
  return esp_timer_get_time() - time_mode > TIMEOUT;
}

float get_steering() {
  return mapfloat_deadzone(time_steering, PulseMin, PulseMax, -1.0, 1.0, 0.05);
}

float get_throttle() {
  return mapfloat_deadzone(time_throttle, PulseMin, PulseMax, -1.0, 1.0, 0.05);
}
