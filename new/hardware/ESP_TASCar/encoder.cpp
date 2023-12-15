// encoder.cpp
// Read the velocity of the car with the encoders
#include "TAScar.h"

const int PIN_ENC_L1 = 39;  // Pin of the first encoder on the left side
const int PIN_ENC_L2 = 36;  // Pin of the second encoder on the left side
const int PIN_ENC_R1 = 35;  // Pin of the first encoder on the right side
const int PIN_ENC_R2 = 34;  // Pin of the second encoder on the right side

const float DIAMETER_WHEEL = 0.14;  // m
const int RESOLUTION = 100;

volatile uint32_t time_left;
volatile uint32_t time_right;
volatile int32_t cnt_left = 0;
volatile int32_t cnt_right = 0;
volatile uint32_t time_prev_left;
volatile uint32_t time_prev_right;
volatile int dir_left;
volatile int dir_right;


void IRAM_ATTR ISR_rising_left_pin() {  // Interupt Service Routine
  time_prev_left = time_left;
  time_left = esp_timer_get_time();
  dir_left = - 2 * digitalRead(PIN_ENC_L2) + 1;
  cnt_left += dir_left;
}


void IRAM_ATTR ISR_rising_right_pin() {  // Interupt Service Routine
  time_prev_right = time_right;
  time_right = esp_timer_get_time();
  dir_right = 2 * digitalRead(PIN_ENC_R2) - 1;
  cnt_right += dir_right;
}

void setup_enc() {  // setup nessesary for Function is_auto_mode()
  pinMode(PIN_ENC_L1, INPUT);
  pinMode(PIN_ENC_L2, INPUT);
  pinMode(PIN_ENC_R1, INPUT);
  pinMode(PIN_ENC_R2, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_ENC_L1), ISR_rising_left_pin, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_ENC_R1), ISR_rising_right_pin, RISING);
}


void get_pos_enc(float &pos_left, float &pos_right) {
  pos_left = float(cnt_left % RESOLUTION) / RESOLUTION * 2 * PI;
  pos_right = float(cnt_right % RESOLUTION) / RESOLUTION * 2 * PI;
}

void get_velocity_enc(float &vel_left, float &vel_right) {
  vel_left = DIAMETER_WHEEL * PI / RESOLUTION / (time_left - time_prev_left) * dir_left * 1e6;
  vel_right = DIAMETER_WHEEL * PI / RESOLUTION / (time_right - time_prev_right) * dir_right * 1e6;

  if (time_left == 0){
    vel_left = 0;
  }  
  if (time_right == 0){
    vel_right = 0;
  }

  if ( abs( esp_timer_get_time()- time_left) > 1e5 ) {
    vel_left = 0;
  }

  if ( abs( esp_timer_get_time()- time_right) > 1e5 ) {
    vel_right = 0;
  }

}
