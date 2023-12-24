#ifndef __MOTOR_CONTROL_H__
#define __MOTOR_CONTROL_H__

#include <Adafruit_MotorShield.h>

/*

  Motor number ( Top view )
       X
   0 +---+ 1
     |   |
  Y  |   |
     |   |
   2 +---+ 3

*/

#define WHEEL_RADIUS 0.02
#define WHEEL_CIRCUMFERENCE (2 * 3.14159 * WHEEL_RADIUS)

namespace MOTOR {

// extern Adafruit_DCMotor *motor[4];

void Init();
void SetSpeed(int PWM_0, int PWM_1, int PWM_2, int PWM_3);

}

#endif