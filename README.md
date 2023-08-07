# ESP32_ROS_wifi
ESP32 ROS support via wifi with simple hello world example code.

## My development environment
* Ubuntu 20.04
* ROS Noetic
* PlatformIO espressif32
* ESP32 Arduino Framework
* frankjoshua/Rosserial Arduino Library@^0.9.1


## Setup the Environment
### On your own PC or Raspberry Pi
```bash
$ sudo apt-get install ros-${ROS_DISTRO}-rosserial-arduino
$ sudo apt-get install ros-${ROS_DISTRO}-rosserial
$ roscore
```
Open a New Terminal
```bash
$ rosrun rosserial_python serial_node.py tcp
```


### On your embeded device(Here ESP32)

Flash the example code to the board.


## Result 

![result](https://img-blog.csdnimg.cn/0a8a8d875d1a40bbaff13e64c6be33f8.png)
