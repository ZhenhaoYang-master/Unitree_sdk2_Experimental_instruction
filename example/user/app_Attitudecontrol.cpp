#include <unitree/robot/client/client.hpp>           // 包含 Unitree 机器人客户端的头文件
#include <unitree/robot/go2/sport/sport_client.hpp>  // 包含 Unitree 机器人的 Go2 运动客户端的头文件
#include <unistd.h>                                  // 提供对 POSIX 操作系统 API 的访问，例如 usleep 函数
#include <cmath>                                     // 提供数学函数，如 sin 和 cos

int main(int argc, char **argv)
{
  // 检查命令行参数数量，至少需要一个参数（网络接口）
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl; // 提示用户如何使用程序
    exit(-1);                                                              // 如果没有提供参数，退出程序，返回错误代码 -1
  }

  
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);   // 初始化网络接口，argv[1] 是用户提供的网络接口名称
  unitree::robot::go2::SportClient sport_client;                  // 实例化一个 SportClient 对象，用于控制机器人运动

  sport_client.SetTimeout(10.0f);     // 设置超时时间为 10 秒
  sport_client.Init();                // 初始化 SportClient
  sport_client.WaitLeaseApplied();    // 等待机器人应用租约,确保机器人处于可控制状态

  double t = 0;                       // 初始化时间变量 t
  double dt = 0.01;                   // 设置时间增量 dt 为 0.01 秒（10 毫秒）

  // 进入运动循环
  {
    // 更新当前时间 t
    t += dt;

    // 使用正弦和余弦函数计算机器人要运动到的目标位置
    // 这里的 Euler 是一种运动控制方法
    // 控制机器人沿某个轨迹运动，具体轨迹由 sin 和 cos 函数定义
    sport_client.Euler(0.4 * sin(2 * t), 0.4 * cos(2 * t) - 0.4, 0.); 

    // 使机器人保持平衡并站立
    sport_client.BalanceStand();

    // 休眠一段时间，控制循环频率
    usleep(int(dt * 1000000)); // 将 dt 转换为微秒并休眠
  }

  return 0; // 正常结束程序
}