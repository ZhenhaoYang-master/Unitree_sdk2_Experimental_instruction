#include <unitree/robot/client/client.hpp>
#include <unitree/robot/go2/sport/sport_client.hpp>

int main(int argc, char **argv)
{
    //检查命令行参数数量,确保提供了网络接口参数
    if (argc < 2) 
    {
        std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
        exit(-1);
    }
    //初始化接口,通过ChannelFactory 获取示例并初始化
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    
    //实例化sport_client对象,并初始化用于控制Go2机器狗
    unitree::robot::go2::SportClient sport_client;
    sport_client.SetTimeout(10.0f);                      //设置与机器狗的通信超时时间
    sport_client.Init();                                 //初始化sport_client,建立与机器狗的连接
    sport_client.WaitLeaseApplied();                     //等待租约申请,通常三确保与机器狗的连接已成功
    int moveTime = 5;                                   //设置机器人的移动时间为5S
    auto startTime = std::chrono::steady_clock::now();   //获取当前时间点,以便后续计算经过的时间

    //控制机器狗运动判断
    while(true)
    { 
    
        sport_client.RecoveryStand();
        sleep(3);
        sport_client.Move(0.2,0,0); //设置X方向上期望速度，控制Go2机器人向前走一段距离/参数为(前进速度,侧向速度,旋转速度)
        sport_client.BodyHeight(-0.07); //降低身体高度/参数为负数为下降,正数为上升,0为基准点(0.33m)
        
        // 获取当前时间点
        auto currentTime = std::chrono::steady_clock::now();
        // 计算经过的时间
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
        // 如果经过的时间大于等于两秒，退出循环
        if (elapsedTime.count() >= moveTime) 
        {
            break;
        }
    }
  
    sleep(2);                   //暂停2秒,以确保机器人的动作完成后再执行下一步
    sport_client.BodyHeight(0); // 恢复机器狗默认高度(0)
    return 0;
}