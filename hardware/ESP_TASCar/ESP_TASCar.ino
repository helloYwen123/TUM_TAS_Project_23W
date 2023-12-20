// ESP32-DEVKITC V4 for Steering Stepper Motors with the driver TMC5160
// May 2023 by Michael Fink

// Dependencies:
// - Add ESP32 board
// - Install Libary TMCStepper by teemuatlut
// - Install Libary HerkulexServo by Cesar Vandeverlde   (different Lib as in Previous code)
// - Install Libary CircularBuffur by AgileWare (needed vor HerkulexServo)
// - Install Libary EspSoftware Serial by Dirk Kaar and Peter Lerup

#include "TAScar.h"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

const int CYCLE_TIME_MS = 10;
const int DEBUG_TIME_MS = 5000;
const int INIT_DRIVER_TIME_MS = 3000;
int computation_time;
float load;
int deadtime = 0;

float velocity = 0;
float angular_velocity = 0;
float vel_left = 0;
float vel_right = 0;
float phi_left = 0;
float phi_right = 0;
float steering_angle = 0;
float servo_angle = 0;


float vel_left_measured = 0;
float vel_right_measured = 0;
float velocity_measured = 0;
float angular_velocity_measured = 0;
float pos_left_measured = 0;
float pos_right_measured = 0;


void setup() {
  // Start comunication with the NUC
  Serial.begin(115200);
  setup_rc();
  setup_servo();
  setup_enc();
  setup_driver();
  // Setup
  TaskHandle_t cycle_h;
  TaskHandle_t debug_msg_h;
  TaskHandle_t refresh_init_h;
  xTaskCreatePinnedToCore(cycle, "Cycle", 10000, NULL, 1, &cycle_h, 0);
  // xTaskCreatePinnedToCore(debug_msg, "Debug Message", 10000, NULL, 2, &debug_msg_h, 1);
  xTaskCreatePinnedToCore(debug_msg, "Debug Message", 10000, NULL, 2, &debug_msg_h, 0);
  // xTaskCreatePinnedToCore(refresh_init, "Init Stepper", 10000, NULL, 2, &refresh_init_h, 0);
}

void loop() {
}

void refresh_init(void *pvParameters) {
  // Need to be tested 
  // Reinitialize stepper driver if they get connected later 
  TickType_t xLastWakeTime = xTaskGetTickCount();
  while (1) {
  setup_driver();
  setup_servo();
  vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(INIT_DRIVER_TIME_MS));
  }
}

void cycle(void *pvParameters) {
  TickType_t xLastWakeTime = xTaskGetTickCount();
  while (1) {
    // Start of Time measurement
    int64_t time_start = esp_timer_get_time();

    // Decide which mode is used (auto or manual)
    if (is_auto_mode()) {  // Automatic Mode: ROS2
      if (Serial.available()) {
        deadtime = 0;
        stepper_on();
        servo_on();
        receive_from_nuc(velocity, angular_velocity);
        steering_angle = compute_steering_angle(velocity, angular_velocity);
      } else {  // Stop car if no Information are send from the nuc
        deadtime ++;
        if (deadtime > 100) {  //Deadtime 1 sec
          velocity = 0;
          steering_angle = 0;
        }
        if (deadtime > 500){  // Deadtime 5 sec
          stepper_off();
          // servo_off();
        }
      }
    } else {  // Manual Mode: Remote Control
      // receive data from RC
      velocity = max_velocity * get_throttle();
      steering_angle = 0.8* max_steering_angle * get_steering();
      deadtime = 101; // Stops the car immediately as soon as the rc is turned off 
      stepper_on();
      servo_on();
    }

    // compute steering and velocity
    compute_ackermann(velocity, steering_angle, vel_left, vel_right, servo_angle, phi_left, phi_right);

    // apply vlaue
    set_servo_in_rad(-servo_angle);
    set_velocity(vel_left, vel_right);

    // Measurement
    // get_velocity(vel_left_measured, vel_right_measured);
    get_velocity_enc(vel_left_measured, vel_right_measured);

    compute_twist(vel_left_measured, vel_right_measured, velocity_measured, angular_velocity_measured);
    // get_pos(pos_left_measured, pos_right_measured);
    get_pos_enc(pos_left_measured, pos_right_measured);

    // Comunication
    transmit_to_nuc(velocity_measured, angular_velocity_measured, pos_left_measured, pos_right_measured, phi_left, phi_right);

    // End of Time measurement
    computation_time = esp_timer_get_time() - time_start;
    load = computation_time / float(CYCLE_TIME_MS) / 10.0;
    // variable xLastWakeTime is updated internally
    vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(CYCLE_TIME_MS));
  }
}

void debug_msg(void *pvParameters) {
  TickType_t xLastWakeTime = xTaskGetTickCount();
  while (1) {
    Serial.println("Start Debug Msg");
    Serial.print("Automode ");
    Serial.println(is_auto_mode());
    Serial.print("Steering ");
    Serial.println(get_steering());
    Serial.print("Throttle: ");
    Serial.println(get_throttle());

    // get_velocity(vel_left_measured, vel_right_measured);
    // Serial.print("Current speed TMC: ");
    // Serial.print(vel_left_measured);
    // Serial.print(" ");
    // Serial.println(vel_right_measured);

    // Serial.print("Current speed ENC: ");
    // get_velocity_enc(vel_left_measured, vel_right_measured);
    // Serial.print(vel_left_measured);
    // Serial.print(" ");
    // Serial.println(vel_right_measured);

    // Serial.print("Current position ENC: ");
    // get_pos_enc(pos_left_measured, pos_right_measured);
    // Serial.print(pos_left_measured);
    // Serial.print(" ");
    // Serial.println(pos_right_measured);

    Serial.print("Computation time in µs: ");
    Serial.println(computation_time);
    Serial.print("Load ");
    Serial.print(load);
    Serial.println(" %");
    Serial.println("End Debug Msg");
    // variable xLastWakeTime is updated internally
    vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(DEBUG_TIME_MS));
  }
}
