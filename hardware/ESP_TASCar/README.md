This software is for a ESP32 DevkitC V4 and for the TAS-Car-PCB (Lowitz 18.08.2023)

# Components 

## ESP32 DevkitC V4 

To programm the ESP32 with the Arduino IDE, the ESP32 Add-on must be installed. 


1. In your Arduino IDE, go to File> Preferences
2. Enter the following into the “Additional Board Manager URLs” field:
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
3. Open the Boards Manager. Go to Tools > Board > Boards Manager…
4. Search for ESP32 and press install button for the “ESP32 by Espressif Systems“

Select your Board in Tools > Board menu  "DOIT ESP32 DEVKIT V1"

## Stepper Driver TMC5160

On the PCB, the driver [BIGTREETECH TMC5160 V1.3](https://biqu.equipment/products/bigtreetech-tmc5160-v1-0-driver-spi-mode-silent-high-precision-stepstick-stepper-motor-driver-with-heatsink-for-skr-v1-3-gen-v1-4-reprap?variant=39564434079842)
are used. 
As alternativethe PCB, the driver [BIGTREETECH TMC5160T V1.0](https://biqu.equipment/products/tmc5160-pro-v1-0)
can be used. 
The communication between ESP32 and TMC5160 uses SPI, therefore the jumper on the breakout board of the driver must be removed, such that the SPI_MODE pin is High and the SD_MODE pin is Low or open. 




## Remote-Control

The Remote Control Carson Modellsport Reflex Wheel Pro III is used to steer the car. 

Channel 1: Steering wheel

Channel 2: Throttle 

Channel 3: Indication whether the RC is switched on

## Servo Motor

Herkulex DRS-0201

# Features

## Energy Saving

When the RC is turned off and for more than 5 seconds no signal from the ROS stack is sent, the car turns off the stepper motors to safe energy. 
The servo steers to the 0 position. (In this setup, adjustment of the steering mechanism is possible)


## Switch between Auto and Manual mode

Manual mode is active as long as the RC is on. Otherwise, the Auto mode is active. In the Auto mode, commands (cmd_vel) from the ROS-Stack are executed. 