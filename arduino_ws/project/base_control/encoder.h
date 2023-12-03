#ifndef __ENCODER_H__
#define __ENCODER_H__

#define ENCODER_FREQUENCY 10 // Hz

#define MOTOR1_ENCODER_PIN 2
#define MOTOR2_ENCODER_PIN 3
#define MOTOR3_ENCODER_PIN 4
#define MOTOR4_ENCODER_PIN 5

namespace ENCODER {

extern double velocity[4];

void Init();
void ReadSpeed();

}

#endif