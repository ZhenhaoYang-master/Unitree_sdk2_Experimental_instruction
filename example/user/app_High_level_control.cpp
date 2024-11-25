#include <unitree/robot/client/client.hpp>           // 包含 Unitree 机器人客户端的头文件
#include <unitree/robot/go2/sport/sport_client.hpp>  // 包含 Unitree 机器人的 Go2 运动客户端的头文件
#include <unistd.h>                                  // 提供对 POSIX 操作系统 API 的访问，例如 usleep 函数
#include <cmath>                                     // 提供数学函数，如 sin 和 cos

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

    sport_client.Damp();            //阻尼状态  
    sleep(3);                   
    sport_client.StandUp();         //关节锁定,站高
    sleep(3);

    sport_client.StandDown();       //关节锁定,站低  
    sleep(3);                   
    sport_client.StandUp();         //关节锁定,站高
    sleep(3);

    sport_client.Sit();             //特殊动作，机器狗坐下
    sleep(3);
    sport_client.RiseSit();         //恢复
    sleep(3);

    // sport_client.Euler(0.3,0.3,0.3);
    // sleep(3);

    sport_client.BalanceStand();
    sleep(3);

    return 0;
}