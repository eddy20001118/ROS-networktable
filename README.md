# ROS-networktable

## 写在前面

这是frc-networktable在ros中的使用例子。

1. 在inc文件夹中，包含了所有wpilib的头文件
2. 在lib文件夹中，包含了不同系统，不同架构的ntcore,wpiutil链接库文件
3. 在CmakeLists中,默认配置了linux系统下x86_x64架构的链接库路径，可自行修改

## 如何使用

### 编译

1. 进入ros工作空间的src文件夹下  eg: cd ~/catkin_ws/src
2. git clone https://github.com/eddy20001118/ROS-networktable.git
3. cd ..
4. catkin_make --pkg networktable 

### 运行

1. 服务端模式：rosrun networktable server
2. 客户端模式：rosrun networktable client