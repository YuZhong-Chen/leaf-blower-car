#include "motor_control.h"
#include "encoder.h"

void setup() {
  Serial.begin(9600);

  Serial.println("Start init ...");

  MOTOR::Init();
  ENCODER::Init();
}

int temp = 70;
int add = 5;

void loop() {
  temp += add;
  if (temp > 250) {
    add = -10;
    temp = 255;
  } else if (temp < 75) {
    add = 10;
    temp = 70;
  }
  MOTOR::Forward(temp);
  ENCODER::ReadSpeed();
  Serial.print(ENCODER::velocity[0] * 10);
  Serial.print(" ");
  Serial.println(temp / 10);
  delay(600);
  MOTOR::Forward(temp);
  ENCODER::ReadSpeed();
  Serial.print(ENCODER::velocity[0] * 10);
  Serial.print(" ");
  Serial.println(temp / 10);
  delay(600);
}