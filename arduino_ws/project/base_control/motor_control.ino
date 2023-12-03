#include "motor_control.h"

namespace MOTOR {

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor[4] = { nullptr };

void Init() {
  Serial.println("Init Motor Shield ...");

  if (!AFMS.begin()) {
    Serial.println("Could not find Motor Shield. Check wiring.");
    Serial.println("Please reset the arduino ...");
    while (true) {}
  }

  for (int i = 0; i < 4; i++) {
    motor[i] = AFMS.getMotor(i + 1);
  }
  Stop();

  Serial.println("Done.");
}

void Forward(int PWM) {
  // motor[0]->run(FORWARD);
  // motor[0]->setSpeed(PWM);
  // for (int i = 0; i < 4; i++) {
  //   motor[i]->run(FORWARD);
  //   motor[i]->setSpeed(PWM);
  // }
}

void Stop() {
  for (int i = 0; i < 4; i++) {
    motor[i]->run(RELEASE);
  }
}

}