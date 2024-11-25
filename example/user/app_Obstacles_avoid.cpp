#include <unitree/robot/go2/obstacles_avoid/obstacles_avoid_client.hpp>  // 引入 Unitree 机器人的避障客户端头文件

using namespace unitree::common;        // 使用 Unitree 公共命名空间
using namespace unitree::robot;         // 使用 Unitree 机器人命名空间
using namespace unitree::robot::go2;    // 使用 Unitree Go2 机器人命名空间

int main(int argc, char **argv)
{
    // 初始化网络接口，"enp4s0" 为网口号，用户需要根据自己的情况修改
    //unitree::robot::ChannelFactory::Instance()->Init(0, "enp4s0");

    //检查命令行参数数量,确保提供了网络接口参数
    if (argc < 2) 
    {
        std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
        exit(-1);
    }
    //初始化接口,通过ChannelFactory 获取示例并初始化
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

    // 创建一个避障客户端实例
    unitree::robot::go2::ObstaclesAvoidClient sc;
    sc.SetTimeout(5.0f);                // 设置超时时间为 5 秒
    sc.Init();                          // 初始化避障客户端
    sc.SwitchSet(true);                 // 开启避障功能
    usleep(1000000);                    // 休眠 1 秒，等待系统稳定
    sc.UseRemoteCommandFromApi(true);   // 抢夺遥控器的速度控制权，使得机器人可以自主控制
    sc.Move(0.2, 0.0, 0.0);             // 使机器人沿着机体的 x 方向以 1 m/s 的速度运动，并具备自动避障功能

    int tem = 0; // 初始化计数器

    // 无限循环，持续检查状态
    while (true)
    {
        usleep(1000000);        // 休眠 1 秒，控制循环频率
        
        // 计数器增加，最多增加到 5
        if (tem <= 5)
        {
            tem++;
        }
        else
        {
            // 5 秒后关闭遥控器的速度控制权
            sc.UseRemoteCommandFromApi(false);
            // 5 秒后关闭避障功能
            sc.SwitchSet(false);
        }
    }
    return 0; // 正常结束程序
}