### Qt检测系统中可用串口Demo

### 1、主要功能

* 通过继承**QAbstractNativeEventFilter**接口实现串口热插拔监测功能；
* 通过在QWidget中重写**nativeEvent**实现串口热插拔监测功能；
* 通过一个函数获取系统中所有可用串口名；
* 自动添加、移除可用串口。



### 2、适用系统

* Windows



### 3、实现情况

![串口状态检测](README%20.assets/%E4%B8%B2%E5%8F%A3%E7%8A%B6%E6%80%81%E6%A3%80%E6%B5%8B.gif)