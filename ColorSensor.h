/*
ColorSensor.h
*/

#ifndef ColorSensor_h
#define ColorSensor_h

#include "Arduino.h"
#include <Wire.h>

// Include libraries for the Adafruit LSM303 accelerometer
#include <Adafruit_Sensor.h>
#include "Adafruit_TCS34725.h"

class ColorSensor
{
 public:

  ColorSensor();
  bool init();
  int getRed();
  int getGreen();
  int getBlue();

  /* int getColor(); */

 private:

  Adafruit_TCS34725 _tcs;
  byte _gammatable[256];
};

#endif
