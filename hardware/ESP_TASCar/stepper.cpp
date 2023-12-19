#include "TAScar.h"
#include <TMCStepper.h>

// Hardware defined Parameters (change parameters only when the hardware changes)
const int16_t EN_PIN = 15;          // Enable both motor dirvers
const int16_t CS_PIN_LEFT = 2;     // Chip select
const int16_t CS_PIN_RIGHT = 0;    // Chip select
const int16_t SW_MISO = 12;         // Software Master In Slave Out (MISO)
const int16_t SW_MOSI = 13;         // Software Master Out Slave In (MOSI)
const int16_t SW_SCK = 14;          // Software Slave Clock (SCK)
const float R_SENSE = 0.075;        // Bigtreetech TMC5160 uses 0.075 Ohm
const int32_t F_CLK = 12000000;     // Internal clock fequencey of TMC5160
const int16_t STEPS = 200;          // 200 steps are 1.8° Step angle
const int16_t MICROSTEP = 256;      // Microstepping
const float DIAMETER_WHEEL = 0.14;  // m

// Parameters for Tuning
// const int32_t MAX_SPEED = 2.3e5;  // almost sine wave @ 18V ... round a bout 1.5m/s   5km/h
const int32_t MAX_SPEED = 4.0e5;  // 2.5m/s   9km/h, Limit for outer wheel with ackermann to achive 5km/h of center of mass
// const int32_t MAX_SPEED = 3.3e5   //
// const int32_t ACCELERATION = 900;  // Start with 2000
const uint16_t ACCELERATION = 65535;
const int16_t MAX_CURRENT = 2300;  // max 3000 for the 0.075ohm resistor
// const int16_t MAX_CURRENT = 1000;  // For permanet run in test phase

// Precomputet Values
const float FACTOR_VELOCITY_MEASURMENT = (float)(1e6 / (float)MICROSTEP / (float)STEPS);
const float FACTOR_RPS_TO_MUSTEPS_PER_TIME = (float)((float)MICROSTEP * (float)STEPS * pow(2, 24) / (float)F_CLK);

// Inittialization of the TMC5160
TMC5160Stepper driverLeft(CS_PIN_LEFT, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);
TMC5160Stepper driverRight(CS_PIN_RIGHT, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);

volatile int32_t prev_xacutal_left = 0;
volatile int32_t prev_xacutal_right = 0;
volatile uint32_t prev_time = 0;

void setup_TMC5160(TMC5160Stepper &driver) {
  // Start SPI
  driver.begin();  //  SPI: Init CS pins and possible SW SPI pins
  // --------------  Setting up register  ------------------
  // Datasheet: Figure 22.1 Current setting and first steps with StealthChop
  // Current Setting:
  driver.rms_current(MAX_CURRENT);  // Set motor RMS current
  driver.microsteps(MICROSTEP);     // Set microsteps to 1/265th
  // Datasheet: Figure 22.2 Tuning StealthChop and SpreadCycle
  // speradCycle Configuration:
  driver.en_pwm_mode(false);  // False: speadCycle
  driver.toff(3);             // Longer have less switching and less losses but could lead to more sound
  driver.tbl(2);
  driver.hstrt(2);
  driver.hend(2);
  driver.chm(0);
  // // Datasheet: Figure 22.3 Moving the motor using the motion controller
  // // Move Motor:
  driver.RAMPMODE(1);  // 1: Velocity mode to positive VMAX (using AMAX acceleration)
  driver.AMAX(ACCELERATION);
  // driver.VMAX(MAX_SPEED);
  // Datasheet: Figure 22.4 Enabling CoolStep (only in combination with SpreadCycle

  // // Enable coolStep:
  // driver.THIGH(30);  // Max Speed for Coolstep in TSTEPS.  30 TSTEPS = 12 km/h
  // driver.sgt(5);
  // driver.TCOOLTHRS(230);  // Lower Speed for Coolstep in TSTEPS.   230 TSTEPS = 1.58 km/h
  // driver.semin(2);
  // driver.seup(2);
  // driver.seimin(1);
  // // Datasheet: Figure 22.5 Setting up DcStep
  // // Enable dcStep
  // driver.vhighfs(true);
  // driver.vhighchm(true);
  // driver.VDCMIN(7e4);  // Lower speed for DC Step, 71583 µstps/t = 1.58 km/h
  // driver.dc_time(37);
}

void stepper_off(){
  digitalWrite(EN_PIN, HIGH);
}

void stepper_on(){
  digitalWrite(EN_PIN, LOW);  // Enable both driver in hardware
}

void setup_driver() {
  // Enable driver
  pinMode(EN_PIN, OUTPUT);
  stepper_on();  // Enable both driver in hardware
  setup_TMC5160(driverLeft);
  setup_TMC5160(driverRight);
}



// set velocity in meter per second
void set_velocity(float vel_left, float vel_right) {
  // Check drive direction and ste rampmode

  if (vel_left > 0) {
    driverLeft.RAMPMODE(2);
    vel_left = vel_left * FACTOR_RPS_TO_MUSTEPS_PER_TIME / DIAMETER_WHEEL / PI;
  } else {
    driverLeft.RAMPMODE(1);
    vel_left = -vel_left * FACTOR_RPS_TO_MUSTEPS_PER_TIME / DIAMETER_WHEEL / PI;
  }
  if (vel_right > 0) {
    driverRight.RAMPMODE(1);
    vel_right = vel_right * FACTOR_RPS_TO_MUSTEPS_PER_TIME / DIAMETER_WHEEL / PI;
  } else {
    driverRight.RAMPMODE(2);
    vel_right = -vel_right * FACTOR_RPS_TO_MUSTEPS_PER_TIME / DIAMETER_WHEEL / PI;
  }
  // Check limit
  if (vel_left > MAX_SPEED) {
    vel_left = MAX_SPEED;
  }
  if (vel_right > MAX_SPEED) {
    vel_right = MAX_SPEED;
  }
  // Set speed in µsteps per time (time = 2^24/f_clk)
  driverLeft.VMAX((uint32_t)vel_left);
  driverRight.VMAX((uint32_t)vel_right);
}

// get velocity in meter per second
void get_velocity(float &vel_left, float &vel_right) {
  int32_t actual_xacutal_left = driverLeft.XACTUAL();
  int32_t actual_xacutal_right = driverRight.XACTUAL();
  uint32_t actual_time = esp_timer_get_time();

  float rps_left = FACTOR_VELOCITY_MEASURMENT * (actual_xacutal_left - prev_xacutal_left) / (actual_time - prev_time);
  float rps_right = FACTOR_VELOCITY_MEASURMENT * (actual_xacutal_right - prev_xacutal_right) / (actual_time - prev_time);

  vel_left = rps_left * DIAMETER_WHEEL * PI;
  vel_right = rps_right * DIAMETER_WHEEL * PI;

  prev_xacutal_left = actual_xacutal_left;
  prev_xacutal_right = actual_xacutal_right;
  prev_time = actual_time;
}

// get rotaion in rad
void get_pos(float &pos_left, float &pos_right) {
  int32_t actual_xacutal_left = driverLeft.XACTUAL();
  int32_t actual_xacutal_right = driverRight.XACTUAL();

  // TODO  , Modulo and scale
  pos_left  = (actual_xacutal_left %(200*256));
  pos_left = pos_left*PI*2/(200*256);
  pos_right = (actual_xacutal_right%(200*256));
  pos_right = pos_right*PI*2/(200*256);
}
