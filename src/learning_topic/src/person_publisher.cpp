#include <ros/ros.h>
#include "learning_topic/Person.h"

int main(int argc, char **argv)
{
  //初始化ROS，名称重映射（唯一），必须为base name，不含/
  ros::init(argc, argv, "person_publisher"); 

  // 为进程的节点创建一个句柄，第一个创建的NodeHandle初始化节点
  ros::NodeHandle n;

  // 告诉主机要在chatter topic上发布一个std_msgs消息

  // 主机会订阅所有chatter topic节点，参数表示发布队列的大小（先进先出）
  ros::Publisher person_info_pub = n.advertise<learning_topic::Person>("/person_info", 10);

  ros::Rate loop_rate(1);  // 自循环频率

  int count = 0;
  while (ros::ok())
  {
    learning_topic::Person person_msg;
    person_msg.name = "Tom";
    person_msg.age = 18;
    person_msg.sex = learning_topic::Person::male;

    person_info_pub.publish(person_msg);

    ROS_INFO("Publish Person Info: name:%s  age:%d  sex:%d",
	      person_msg.name.c_str(), person_msg.age, person_msg.sex);
    loop_rate.sleep();	 
  }
  return 0;
}

