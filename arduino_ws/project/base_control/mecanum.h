#ifndef __MECANUM_H__
#define __MECANUM_H__

#include "motor_control.h"
#include "encoder.h"
#include "ros_interface.h"

namespace MECANUM {

void Init();
void SetVel(geometry_msgs::Twist);
geometry_msgs::Twist GetVel();

void Forward();
void Backward();
void Left();
void Right();
void ForwardLeft();
void ForwardRight();
void BackwardLeft();
void BackwardRight();
void Stop();

}

#endif