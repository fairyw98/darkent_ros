#include <ros/ros.h>
#include "std_msgs/String.h"
#include <darknet_ros_msgs/BoundingBoxes.h>
#include <darknet_ros_msgs/BoundingBox.h>
#include <opencv2/highgui/highgui.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

using namespace std;
void chatterCallback(const darknet_ros_msgs::BoundingBoxes::ConstPtr& msg)
{
    cout<<"==========start==========="<<endl;
    for(int i=0;i<msg->bounding_boxes.size();i++){
    cout<<"Bouding Boxes (header):" << msg->header <<endl;
    cout<<"Bouding Boxes (image_header):" << msg->image_header <<endl;
    cout<<"Bouding Boxes (Class):" << msg->bounding_boxes[i].Class <<endl;
    cout<<"Bouding Boxes (xmin):" << msg->bounding_boxes[i].xmin <<endl;
    cout<<"Bouding Boxes (xmax):" << msg->bounding_boxes[i].xmax <<endl;
    cout<<"Bouding Boxes (ymin):" << msg->bounding_boxes[i].ymin <<endl;
    cout<<"Bouding Boxes (ymax):" << msg->bounding_boxes[i].ymax <<endl;
    cout << "\033[2J\033[1;1H";     // clear terminal
    }
    cout<<"==========end==========="<<endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("/darknet_ros/bounding_boxes", 2000, chatterCallback);
  ros::spin();
  return 0;
}

