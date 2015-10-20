#include "Arduino.h"

// Libraries for the Adafruit TCS34725 Color Sensor
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TCS34725.h"
#include "ColorSensor.h"

ColorSensor::ColorSensor()
{
  _tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
}

bool ColorSensor::init()
{
  /* Initialise the sensor */
  if (_tcs.begin()) {
    return true;
  } else {
    return false;
  }

  // Create gamma table to convert RGB colors to what humans see
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;
    _gammatable[i] = 255 - x;
    // _gammatable[i] = x; // Use this if things seem off.
  }
}

int ColorSensor::getRed() {
  uint16_t clear, red, green, blue;
  _tcs.setInterrupt(false);
  delay(60);
  _tcs.getRawData(&red, &green, &blue, &clear);
  _tcs.setInterrupt(true);

  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  return _gammatable[(int)r];
}

int ColorSensor::getGreen() {
  uint16_t clear, red, green, blue;
  _tcs.setInterrupt(false);
  delay(60);
  _tcs.getRawData(&red, &green, &blue, &clear);
  _tcs.setInterrupt(true);

  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  return _gammatable[(int)g];
}

int ColorSensor::getBlue() {
  uint16_t clear, red, green, blue;
  _tcs.setInterrupt(false);
  delay(60);
  _tcs.getRawData(&red, &green, &blue, &clear);
  _tcs.setInterrupt(true);

  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  return _gammatable[(int)b];
}
