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
  SetSpeed(0, 0, 0, 0);

  Serial.println("Done.");
}

void SetSpeed(int PWM_0, int PWM_1, int PWM_2, int PWM_3) {
  motor[0]->run((PWM_0 > 0) ? FORWARD : ((PWM_0 < 0) ? BACKWARD : RELEASE));
  motor[0]->setSpeed(PWM_0);

  motor[1]->run((PWM_1 > 0) ? FORWARD : ((PWM_1 < 0) ? BACKWARD : RELEASE));
  motor[1]->setSpeed(PWM_1);

  motor[2]->run((PWM_2 > 0) ? FORWARD : ((PWM_2 < 0) ? BACKWARD : RELEASE));
  motor[2]->setSpeed(PWM_2);

  motor[3]->run((PWM_3 > 0) ? FORWARD : ((PWM_3 < 0) ? BACKWARD : RELEASE));
  motor[3]->setSpeed(PWM_3);
}

}