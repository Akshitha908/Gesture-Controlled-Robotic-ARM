/*

  m11       m12          o/p
   0         0           off
   0         1           on   (anti-clock)
   1         0           on   (clock)  
   1         1           off

*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);



int m11 = 7;
int m12 = 6;

int m21 = 5;
int m22 = 4;


void setup() {
  // put your setup code here, to run once:

  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);

  digitalWrite(m11, 0);
  digitalWrite(m12, 0);
  digitalWrite(m21, 0);
  digitalWrite(m22, 0);

  if(!accel.begin())
  {
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
  accel.setRange(ADXL345_RANGE_16_G);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensors_event_t event; 
  accel.getEvent(&event);

  float x1 = event.acceleration.x + 20;
  float y1 = event.acceleration.y + 20;
  float z1 = event.acceleration.z + 20;

  if (x1 < 15.0) {
    Serial.println("Moving Up");

    digitalWrite(m11, 0);
    digitalWrite(m12, 1);
    delay(1000);
    digitalWrite(m11, 0);
    digitalWrite(m12, 0);
  }

  else if (x1 > 25.0) {
    Serial.println("Moving down");

    digitalWrite(m11, 1);
    digitalWrite(m12, 0);
    delay(1000);
    digitalWrite(m11, 0);
    digitalWrite(m12, 0);
  }

  else if (y1 < 15.0) {
    Serial.println("Picking");

    digitalWrite(m21, 1);
    digitalWrite(m22, 0);
    delay(1000);
    digitalWrite(m11, 0);
    digitalWrite(m12, 0);

  }

  else if (y1 > 25.0) {
    Serial.println("Release");

    digitalWrite(m21, 0);
    digitalWrite(m22, 1);
    delay(1000);
    digitalWrite(m11, 0);
    digitalWrite(m12, 0);

  }
  else {
    digitalWrite(m11, 0);
    digitalWrite(m12, 0);
    digitalWrite(m21, 0);
    digitalWrite(m22, 0);
  }
  delay(300);
}
