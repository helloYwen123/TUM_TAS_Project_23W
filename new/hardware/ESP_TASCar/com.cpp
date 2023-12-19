// misc.cpp
#include "TAScar.h"

void transmit_to_nuc(float velocity, float angular_velocity, float pos_left, float pos_right, float phi_left, float phi_right) {
  // Send Data
  // Send data in the form:
  // v<number>o<number>l<number>r<number>
  Serial.printf("@v%fo%fl%fr%fphil%fphir%f\n", velocity, angular_velocity, pos_left, pos_right,phi_left, phi_right);
}

void receive_from_nuc(float &velocity, float &angular_velocity) {
  // Convert String in the following float values:
  // v<number>o<number>
  // e.g.    v1.23o1.23
  // Number behint v is for velocyity, Number behind o is omega, the angular velcotiy
  String received_string = Serial.readStringUntil('\n');

  uint16_t idx_v = received_string.indexOf("v");
  uint16_t idx_o = received_string.indexOf("o");
  uint16_t idx_end = received_string.length();

  if (idx_v != 65535 && idx_o != 65535) {
    velocity = received_string.substring(idx_v + 1, idx_o).toFloat();
    angular_velocity = received_string.substring(idx_o + 1, idx_end).toFloat();
    Serial.println("Received");
  } else {
    velocity = 0;
    angular_velocity = 0;
    Serial.println("Error");
  }
}
