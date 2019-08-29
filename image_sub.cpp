#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
 
//cv::Mat image;
void imgCallback(const sensor_msgs::ImageConstPtr& msg)
{
   cv::imwrite("results.jpg", cv_bridge::toCvShare(msg, "bgr8")->image);
   cvWaitKey(10);
}
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_sub");
  ros::NodeHandle nh;
  cv::namedWindow("view", 0);
  cv::startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("/darknet_ros/detection_image", 1, imgCallback);
   
  ros::spin();
  cv::destroyWindow("view");
}
