#include "ros/ros.h"
#include "ntcore.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
int main(int argc, char *argv[])
{
    nt::NetworkTableEntry xEntry;
    ros::init(argc, argv, "testNode");
    ROS_INFO("Hello world");
    auto inst = nt::NetworkTableInstance::GetDefault();
    inst.StartClient("127.0.0.1"); //设置networktable为客户端，且服务端ip为“127.0.0.1” 
    auto table = inst.GetTable("SmartDashboard");
    xEntry = table -> GetEntry("X");

    while (ros::ok())
    {
        xEntry.SetString("Hello world");
    }
    
    return 0;
}
