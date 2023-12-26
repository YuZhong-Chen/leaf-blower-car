#ifndef __ROS_INTERFACE_H__
#define __ROS_INTERFACE_H__

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Bool.h>

namespace ROS_INTERFACE {

extern geometry_msgs::Twist target_cmd_vel;
extern std_msgs::Bool fan_enable;

void Init();
void Update();

void Cmd_Vel_Callback(const geometry_msgs::Twist &msg);
void Fan_Enable_Callback(const std_msgs::Bool &msg);

}

#endif