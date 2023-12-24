#include "ros_interface.h"

namespace ROS_INTERFACE {

ros::NodeHandle nh;

geometry_msgs::Twist target_cmd_vel;
ros::Subscriber<geometry_msgs::Twist> cmd_vel_sub("cmd_vel", &Cmd_Vel_Callback);

void Init() {
  nh.initNode();
  nh.subscribe(cmd_vel_sub);
}

void Update() {
  nh.spinOnce();
}

void Cmd_Vel_Callback(const geometry_msgs::Twist &msg) {
  target_cmd_vel = msg;
}

}