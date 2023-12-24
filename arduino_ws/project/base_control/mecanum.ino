#include "mecanum.h"

namespace MECANUM {

void Init() {
  MOTOR::Init();
}

void SetVel(geometry_msgs::Twist) {
}

geometry_msgs::Twist GetVel() {
}

void Forward() {
  MOTOR::SetSpeed(150, 150, 150, 150);
}

void Backward() {
  MOTOR::SetSpeed(-150, -150, -150, -150);
}

void Left() {
  MOTOR::SetSpeed(-150, 150, 150, -150);
}

void Right() {
  MOTOR::SetSpeed(150, -150, -150, 150);
}

void ForwardLeft() {
  MOTOR::SetSpeed(0, 150, 150, 0);
}

void ForwardRight() {
  MOTOR::SetSpeed(150, 0, 0, 150);
}

void BackwardLeft() {
  MOTOR::SetSpeed(-150, 0, 0, -150);
}

void BackwardRight() {
  MOTOR::SetSpeed(0, -150, -150, 0);
}

void Stop() {
  MOTOR::SetSpeed(0, 0, 0, 0);
}

}