#include "ros_interface.h"

namespace ROS_INTERFACE {

ros::NodeHandle nh;

geometry_msgs::Twist target_cmd_vel;
ros::Subscriber<geometry_msgs::Twist> cmd_vel_sub("cmd_vel", &Cmd_Vel_Callback);

std_msgs::Bool fan_enable;
ros::Subscriber<std_msgs::Bool> fan_enable_sub("fan_enable", &Fan_Enable_Callback);

void Init() {
  nh.initNode();
  nh.subscribe(cmd_vel_sub);
  nh.subscribe(fan_enable_sub);
}

void Update() {
  nh.spinOnce();
}

void Cmd_Vel_Callback(const geometry_msgs::Twist &msg) {
  target_cmd_vel = msg;
}

void Fan_Enable_Callback(const std_msgs::Bool &msg) {
  fan_enable = msg;
}

}