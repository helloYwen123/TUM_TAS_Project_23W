#include <HerkulexServo.h>
#include "TAScar.h"

const int16_t PIN_TX = 16;  // RXD of servo
const int16_t PIN_RX = 17;  // TXD of servo

const int16_t SERVO_ID = 253;  // servo ID (default is 253, brute force at 254)
//operating angle 320 degree

const float SERVO_MAX_IN_DEGREE = 25 ;
const float SERVO_MIN_IN_DEGREE = - SERVO_MAX_IN_DEGREE;
const float FACTOR_SERVO_TO_DEGREE = 0.325;

HerkulexServoBus herkulex_bus(Serial2);
HerkulexServo servo(herkulex_bus, SERVO_ID);

// // Info: my_servo.setPosition(pos);
// //  pos — This number indicates the target position to move to.
// //  pos is a unitless number ranging from 0 to 1023.
// //  512 is the neutral position, and each tick represents an increment of 0.325°.

void servo_on(){
  servo.setTorqueOn();  // turn power on
}

void servo_off(){
  servo.setTorqueOff();  // turn power on
}

void setup_servo() {
  // Serial2.begin(115200,SERIAL_8N1,PIN_RX,PIN_TX);
  Serial2.begin(115200,SERIAL_8N1,PIN_RX,PIN_TX);
  delay(500);
  servo.setTorqueOn();  // turn power on
}

void set_servo_in_deg(float desired_pos) {  // in degree
  if (desired_pos < SERVO_MIN_IN_DEGREE) {
    desired_pos = SERVO_MIN_IN_DEGREE;
  } else if (desired_pos > SERVO_MAX_IN_DEGREE) {
    desired_pos = SERVO_MAX_IN_DEGREE;
  }
  herkulex_bus.update();
  servo.setPosition(desired_pos / FACTOR_SERVO_TO_DEGREE + 512 ,10);
}

void set_servo_in_rad(float desired_pos) {  // in rad
  set_servo_in_deg(desired_pos*180/PI); 
}

void get_servo_status(){
  HerkulexStatusDetail detail;
  HerkulexStatusError error;
  servo.getStatus(error, detail );
  Serial.print("Error Servo: ");
  Serial.println(static_cast<int>(error), BIN);
  Serial.print("Detail Servo: ");
  Serial.println(static_cast<int>(detail), BIN);
  // see https://github.com/cesarvandevelde/HerkulexServo/blob/6ae3cae2af7e2817a9222a68512b43460c9b0a45/HerkulexServo.h#L173
}

float get_servo_in_deg() {  // Function takes 600 ms, far too long, use carefully
  herkulex_bus.update();
  int32_t measured_pos = servo.getRawPosition();
  return (measured_pos - 512) * FACTOR_SERVO_TO_DEGREE;
}


