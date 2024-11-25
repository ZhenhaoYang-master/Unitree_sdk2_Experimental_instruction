#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
        exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv[1]由终端传入，为机器人连接的网卡名称

    int SwitchGait_flag = std::atoi(argv[2]); // 将步态模式从命令行强转为整数
    
    //创建sport client对象
    unitree::robot::go2::SportClient sport_client;
    sport_client.SetTimeout(10.0f);           //超时时间
    sport_client.Init();

    int moveTime = 5;                                    //设置机器人的移动时间为5S
    auto startTime = std::chrono::steady_clock::now();   //获取当前时间点,以便后续计算经过的时间

    while(true)
    { 
        // 获取当前时间点
        auto currentTime = std::chrono::steady_clock::now();
        // 计算经过的时间
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
        std::cout << "elapsed Time: " << elapsedTime.count() << " seconds" << "SwitchGait case: "<< SwitchGait_flag << std::endl;

        switch (SwitchGait_flag)
            {
            case 0:
                sport_client.SwitchGait(SwitchGait_flag); // 0  为  idle
                sport_client.Move(0.2,0,0);//前进
                break;
            case 1:
                sport_client.SwitchGait(SwitchGait_flag); // 1  为  trot
                sport_client.Move(0.2,0,0);//前进
                break;
            case 2:
                sport_client.SwitchGait(SwitchGait_flag); // 2  为  trot running 
                sport_client.Move(0.2,0,0);//前进
                break;
            case 3:
                sport_client.SwitchGait(SwitchGait_flag); // 3  正向爬楼模式
                sport_client.Move(0.2,0,0);//前进
                break;
            case 4:
                sport_client.SwitchGait(SwitchGait_flag); // 4：逆向爬楼模式 
                sport_client.Move(0.2,0,0);//前进
                break;
            default:
                sport_client.BalanceStand();//平衡站立状态
                break;
            }

        if(elapsedTime.count() >= moveTime)
        {
           break;
        }
    }
    
    sleep(2);                   //暂停2秒,以确保机器人的动作完成后再执行下一步
    sport_client.BalanceStand(); // 恢复机器狗默认平衡站立状态
    return 0;
}