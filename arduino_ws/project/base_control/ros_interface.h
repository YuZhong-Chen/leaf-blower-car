#ifndef __ROS_INTERFACE_H__
#define __ROS_INTERFACE_H__

#include <ros.h>
#include <geometry_msgs/Twist.h>

namespace ROS_INTERFACE {

extern geometry_msgs::Twist target_cmd_vel;

void Init();
void Update();

void Cmd_Vel_Callback(const geometry_msgs::Twist &msg);

}

#endif