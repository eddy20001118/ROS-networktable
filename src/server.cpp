#include "ros/ros.h"
#include "ntcore.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
int main(int argc, char *argv[])
{   
    nt::NetworkTableEntry xEntry;
    ros::init(argc, argv, "testNode");
    ROS_INFO("Initial as server mode");
    auto inst = nt::NetworkTableInstance::GetDefault();
    inst.StartServer(); //设置networktable为服务端
    auto table = inst.GetTable("SmartDashboard");
    xEntry = table -> GetEntry("X");

    while (ros::ok())
    {
        xEntry.SetString("Hello world");
    }

    return 0;
}
