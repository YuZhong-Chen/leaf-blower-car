#include "encoder.h"

namespace ENCODER {

double velocity[4];
const unsigned long ENCODER_PERIOD = (1 / ENCODER_FREQUENCY) * 1000;  // ms
unsigned long time = 0, last_time = 0;
unsigned long time_interval = 0;
unsigned long count = 0;

void ENCODER_1() {
  count++;
}

void Init() {
  attachInterrupt(digitalPinToInterrupt(MOTOR1_ENCODER_PIN), ENCODER_1, RISING);
  time = last_time = millis();
}

void ReadSpeed() {
  time = millis();
  time_interval = abs(time - last_time);
  if (time_interval >= 100) {
    velocity[0] = count;
    count = 0;

    // Serial.print(time_interval);
    // Serial.print(" ");
    // Serial.print(velocity[0]);
    // Serial.print(" ");

    velocity[0] = ((double)velocity[0] / time_interval * 1000) / 18.0;

    last_time = time;
  }
}

}