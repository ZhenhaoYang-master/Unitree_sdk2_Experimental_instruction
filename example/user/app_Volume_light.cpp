#include <unitree/robot/go2/vui/vui_client.hpp>  // 引入 Unitree 机器人的音量灯光客户端头文件
#include <iostream>                              // 引入输入输出头文件
#include <cstdlib>                               // 引入标准库头文件,用于atoi
#include <unistd.h>                              // 引入unistd.h头文件,用于usleep

using namespace unitree::common;        // 使用 Unitree 公共命名空间
using namespace unitree::robot;         // 使用 Unitree 机器人命名空间
using namespace unitree::robot::go2;    // 使用 Unitree Go2 机器人命名空间

int main(int argc, char **argv)
{
    // 初始化网络接口，"enp4s0" 为网口号，用户需要根据自己的情况修改
    //unitree::robot::ChannelFactory::Instance()->Init(0, "enp4s0");

    //检查命令行参数数量,确保提供了网络接口参数
    if (argc < 3) 
    {
        std::cout << "Usage: " << argv[0] << " networkInterface" << " Lighting levle initialization" << std::endl;
        exit(-1);
    }
    //初始化接口,通过ChannelFactory 获取示例并初始化
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

    int levle = std::atoi(argv[2]); // 将亮度等级从命令行强转为整数

    // 创建一个灯光亮度参数设置实例
    unitree::robot::go2::VuiClient vl;
    vl.SetTimeout(5.0f);
    vl.Init();
    // vl.SetBrightness();
    
    int CurrentBrightness = 0;
    int tem = 0; // 初始化计数器

    // 无限循环，持续检查状态
    while (true)
    {   
        usleep(1000000);        // 休眠 1 秒，控制循环频率

        if (levle <= 10)
        {
            vl.SetBrightness(levle);
            vl.GetBrightness(CurrentBrightness);
            std::cout<<"当前灯光亮度 level value: "<<CurrentBrightness<<std::endl;
            levle ++;
        }
        else
        {
            vl.SetBrightness(0);
            vl.GetBrightness(CurrentBrightness);
            std::cout<<"当前灯光亮度 level value: "<<CurrentBrightness<<std::endl;
            break;
        }
    }
    
    sleep(3);
    return 0; // 正常结束程序
}