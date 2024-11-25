#include <unitree/robot/go2/sport/sport_client.hpp>  // 包含 Unitree 机器人的 Go2 运动客户端的头文件
#include <unistd.h>                                  // 提供对 POSIX 操作系统 API 的访问，例如 usleep 函数


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
        exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv[1]由终端传入，为机器人连接的网卡名称
    
    //创建sport client对象
    unitree::robot::go2::SportClient sport_client;
    sport_client.SetTimeout(10.0f);     //超时时间
    sport_client.Init();

    sport_client.Hello();
    sleep(2);
    sport_client.Stretch();
    sleep(2);
    sport_client.ContinuousGait(true);
    sleep(2);
    sport_client.Pose(true);
    sleep(2);
    sport_client.Scrape();
    sleep(2);
    sport_client.Dance1();
    sleep(2);
    sport_client.Dance2();
    sleep(2);
    sport_client.Dance3();
    sleep(2);
    sport_client.Dance4();
    sleep(2);
    

    return 0;
}