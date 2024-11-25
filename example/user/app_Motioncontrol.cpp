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
    sport_client.SetTimeout(10.0f);                     //设置与机器狗的通信超时时间
    sport_client.Init();                                //初始化sport_client,建立与机器狗的连接
    sport_client.WaitLeaseApplied();                    //等待租约申请,通常是确保与机器狗的连接已成功
    int moveTime = 24;                                  //设置机器人的移动时间为:
    auto startTime = std::chrono::steady_clock::now();  //获取当前时间点,以便后续计算经过的时间

    //控制机器狗运动判断
    while(true)
    { 
        // 获取当前时间点
        auto currentTime = std::chrono::steady_clock::now();
        // 计算经过的时间
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
        int phase = static_cast<int>(elapsedTime.count() / (moveTime / 8));

        usleep(1000000);        // 休眠 1 秒，控制循环频率
        std::cout << "elapsed Time: " << elapsedTime.count() << " seconds" << "phase case: "<< phase << std::endl;
        switch (phase)
        {
        case 0:
            sport_client.Move(0.2,0,0);//前进
            break;
        case 1:
            sport_client.Move(-0.2,0,0);//后退
            break;
        case 2:
            sport_client.Move(0,0.2,0);//左移动
            break;
        case 3:
            sport_client.Move(0,-0.2,0);//右移动
            break;
        case 4:
            sport_client.BodyHeight(-0.07);//降低身体高度/参数为负数为下降,正数为上升,0为基准点(0.33m)
            break;
        case 5:
            sport_client.BodyHeight(0.0);//恢复默认高度
            break;
        case 6:
            sport_client.Move(0,0,1.57);//左转
            break;
        case 7:
            sport_client.Move(0,0,-1.57);//右转
            break;
        default:
            sport_client.BalanceStand();//平衡站立状态
            break;
        }
        
        /*
        //--------------测试Z轴方向,角速度旋转-------------------//
        //测试Z轴方向,角速度旋转
        float Angle_number = 0.0;
        int direction = 1;
        std::cout << "Angle_number: " << Angle_number << "      " << "direction: "<< direction << std::endl;
        if(direction == 1)
        {
            if(Angle_number <= 1.57)
            {
                sport_client.Move(0,0,Angle_number);
                Angle_number += 0.01;
            }
            else
            {
                Angle_number = 0;
                direction = -1;
            }
        }
        else if(direction == -1)
        {
            if(Angle_number >= -1.57)
            {
                
                sport_client.Move(0,0,Angle_number);
                Angle_number -= 0.01;
            }
            else
            {
                Angle_number = 0;
                direction = 1;
            }
        }
        usleep(10000);
        //--------------测试Z轴方向,角速度旋转-------------------//
        */
        
       if(elapsedTime.count() >= moveTime)
       {
           break;
       }
    }
  
    sleep(2);                   //暂停2秒,以确保机器人的动作完成后再执行下一步
    sport_client.BalanceStand(); // 恢复机器狗默认平衡站立状态
    return 0;
}