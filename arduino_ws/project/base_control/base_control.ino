#include "mecanum.h"
#include "fan.h"
#include "ros_interface.h"

void setup() {
  Serial.begin(9600);

  Serial.println("Start init ...");

  MECANUM::Init();
  FAN::Init();
  ROS_INTERFACE::Init();
}

void loop() {
  if (ROS_INTERFACE::target_cmd_vel.linear.x == 0 && ROS_INTERFACE::target_cmd_vel.linear.y == 0 && ROS_INTERFACE::target_cmd_vel.angular.z == 0) {
    MECANUM::Stop();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x > 0 && ROS_INTERFACE::target_cmd_vel.linear.y == 0) {
    MECANUM::Forward();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x < 0 && ROS_INTERFACE::target_cmd_vel.linear.y == 0) {
    MECANUM::Backward();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x == 0 && ROS_INTERFACE::target_cmd_vel.linear.y > 0) {
    MECANUM::Left();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x == 0 && ROS_INTERFACE::target_cmd_vel.linear.y < 0) {
    MECANUM::Right();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x > 0 && ROS_INTERFACE::target_cmd_vel.linear.y > 0) {
    MECANUM::ForwardLeft();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x > 0 && ROS_INTERFACE::target_cmd_vel.linear.y < 0) {
    MECANUM::ForwardRight();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x < 0 && ROS_INTERFACE::target_cmd_vel.linear.y > 0) {
    MECANUM::BackwardLeft();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x < 0 && ROS_INTERFACE::target_cmd_vel.linear.y < 0) {
    MECANUM::BackwardRight();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x == 0 && ROS_INTERFACE::target_cmd_vel.linear.y == 0 && ROS_INTERFACE::target_cmd_vel.angular.z > 0) {
    MECANUM::RotationLeft();
  } else if (ROS_INTERFACE::target_cmd_vel.linear.x == 0 && ROS_INTERFACE::target_cmd_vel.linear.y == 0 && ROS_INTERFACE::target_cmd_vel.angular.z < 0) {
    MECANUM::RotationRight();
  } else {
    MECANUM::Stop();
  }

  if (ROS_INTERFACE::fan_enable.data == true) {
    FAN::Enable();
  } else {
    FAN::Disable();
  }

  ROS_INTERFACE::Update();
}