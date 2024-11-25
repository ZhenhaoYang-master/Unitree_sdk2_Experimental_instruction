#include <cmath>
#include <signal.h>
#include <unistd.h>

#include <unitree/robot/go2/sport/sport_client.hpp>

bool stopped = false;

void sigint_handler(int sig)
{
    if (sig == SIGINT)
    {
        stopped = true;
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
        exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv[1]由终端传入，为机器人连接的网卡名称

    //创建一个sport_client对象
    unitree::robot::go2::SportClient sport_client;
    sport_client.SetTimeout(10.0f);             //超时时间
    sport_client.Init();                        //初始化sport client
    auto startTime = std::chrono::steady_clock::now();

    int timer = std::atoi(argv[2]);      
    std::cout<<"timer number: "<<timer<<std::endl;

    double t = 0;                       //程序运行时间
    double dt = 0.01;                   //控制步长

    //创建一个signal对象用于捕获程序退出的信号
    signal(SIGINT, sigint_handler);

    while(true)
    {
         // 获取当前时间点
        auto currentTime = std::chrono::steady_clock::now();
        // 计算经过的时间
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);

        t += dt;
        //姿态跟踪一个三角函数轨迹
        sport_client.Euler(0.2 * sin(2 * t), 0.2 * cos(2 * t) - 0.2, 0.);
        sport_client.BalanceStand();
        usleep(int(dt * 1000000));
        if(stopped)
        {
            break;
        }
        else if(elapsedTime.count() >= timer)
       {
           break;
       }
    }
    //程序退出时复位姿态
    sport_client.Euler(0, 0, 0);
    return 0;
}