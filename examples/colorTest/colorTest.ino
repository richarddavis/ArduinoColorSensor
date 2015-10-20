#include <ColorSensor.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

bool success;
ColorSensor tcs;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  success = tcs.init();
  if (success == false) {
    delay(1000);
    Serial.println("Color sensor is not connected.");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int r = tcs.getRed();
  int g = tcs.getGreen();
  int b = tcs.getBlue();
  Serial.print("Red value: ");
  Serial.println(r);
  Serial.print("Green value: ");
  Serial.println(g);
  Serial.print("Blue value: ");
  Serial.println(b);
  delay(100);
}
