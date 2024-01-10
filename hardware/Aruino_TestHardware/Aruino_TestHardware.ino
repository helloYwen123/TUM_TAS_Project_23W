
float velocity;
float angular_velocity;
float pos_left;
float pos_right;
float phi_left;
float phi_right;

long unsigned int prev_time;
long unsigned int prev_time2;


void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {       
    receive_from_nuc(velocity, angular_velocity);
  }
  if (millis() - prev_time > 10000){
    prev_time = millis();
    debug_msg();
  }
  if (millis() - prev_time2 > 10){
    prev_time2 = millis();
    transmit_to_nuc(velocity, angular_velocity);
  }
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
    // Serial.println("Received");
  } else {
    velocity = 0;
    angular_velocity = 0;
    Serial.println("Error");
  }
}

void transmit_to_nuc(float velocity, float angular_velocity) {
  // Send Data
  // Send data in the form:
  // v<number>o<number>l<number>r<number>
    pos_left += 0.01 * velocity;
    if (pos_left > 3.14){
      pos_left -= 2*3.14;
    }
    if (pos_left < -3.14){
      pos_left += 2*3.14;
    }
    pos_right = pos_left;
    if (abs(velocity)<0.1){
      phi_left = 0;
      phi_right = 0;
    }
    else {
      phi_left = angular_velocity/velocity;
      phi_right = phi_left; 
    }

  Serial.print("@v");
  Serial.print(velocity);
  Serial.print("o");
  Serial.print(angular_velocity);
  Serial.print("l");
  Serial.print(pos_left);
  Serial.print("r");
  Serial.print(pos_right);
  Serial.print("phil");
  Serial.print(phi_left);
  Serial.print("phir");
  Serial.println(phi_right);
}


void debug_msg() {
    Serial.println("Start Debug Msg");
    Serial.print("Automode ");
    Serial.println("1");
    Serial.print("Steering ");
    Serial.println("xxx");
    Serial.print("Throttle: ");
    Serial.println("xxx");
    Serial.print("Current speed TMC: ");
    Serial.println("xxx");
    Serial.print("Current speed ENC: ");
    Serial.println("xxx");
    Serial.print("Computation time in µs: ");
    Serial.println("xxx");
    Serial.print("Load ");
    Serial.print("xxx");
    Serial.println(" %");
    Serial.println("End Debug Msg");
}