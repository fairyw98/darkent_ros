# darkent_ros
参考  https://github.com/leggedrobotics/darknet_ros

```
mkdir -p catkin_ws/src
cd catkin_ws/src
git clone --recursive https://github.com/leggedrobotics/darknet_ros.git
cd ..
catkin_make -DCMAKE_BUILD_TYPE=Release
```
等待大约十分钟，权重文件会下载好

对于ros.yaml，里面主要定义了订阅的话题和发布的话题，我们可以修改订阅话题，主要是根据你自己发布图像数据的节点的话题名字。这里发布图像数据的话题叫/camera/image
这里修改成/image，并把发布的话题的latch都改为true


```
gedit catkin_ws/src/darknet_ros/darknet_ros/config/ros.yaml
```
改成下面这样

```
subscribers:

  camera_reading:
    topic: /image
    queue_size: 1

actions:

  camera_reading:
    name: /darknet_ros/check_for_objects

publishers:

  object_detector:
    topic: /darknet_ros/found_object
    queue_size: 1
    latch: true

  bounding_boxes:
    topic: /darknet_ros/bounding_boxes
    queue_size: 1
    latch: true

  detection_image:
    topic: /darknet_ros/detection_image
    queue_size: 1
    latch: true

image_view:

  enable_opencv: true
  wait_key_delay: 1
```
下载本项目的代码
```
cd /home/YOURNAME/catkin_ws/src/darknet_ros/darknet_ros
git clone https://github.com/fearywang/darkent_ros.git
```
把cpp文件移动到src文件夹下，把CMakeLists.txt文件放到本文件夹下，把launch文件放到launch文件夹下
然后把start.launch 移动到上一级目录的launch文件夹中
最后编译，运行
```
roslaunch darknet_ros yolo_v3.launch 
roslaunch usb_cam usb_cam-test.launch 
roslaunch darknet_ros start.launch 
```
等待几分钟后，按下空格便会拍照，并分析这张图片，/home/YOURNAME/catkin_ws/src/darknet_ros/darknet_ros/src下会出现一张照片
