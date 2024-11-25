#include <unitree/idl/go2/SportModeState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

//高层状态topic，其中rt表示实时，lf表示低频
#define TOPIC_HIGHSTATE "rt/sportmodestate"

using namespace unitree::robot; // 使用 Unitree 机器人命名空间以简化代码 

//获取运动状态的回调函数
void HighStateHandler(const void* message)
{
    // 将接收到的消息指针转换为 SportModeState_ 类型
    unitree_go::msg::dds_::SportModeState_ state = *(unitree_go::msg::dds_::SportModeState_*)message;

    //打印输出机器狗位置
    std::cout<<"position: "
            <<"x: "<<state.position()[0]<<", "              // x坐标
            <<"y: "<<state.position()[1]<<", "              // y坐标
            <<"z: "<<state.position()[2]<<std::endl;        // z坐标

    //打印输出三维速度
    std::cout<<"velocity: "
            <<"x: "<<state.velocity()[0]<<", "              // x方向
            <<"y: "<<state.velocity()[1]<<", "              // y方向
            <<"z: "<<state.velocity()[2]<<std::endl;        // z方向
    
    //打印输出机器狗姿态四元数 (w,x,y,z)
    std::cout<<"quaternion: "
            <<"w: "<<state.imu_state().quaternion()[0]<<", "        // w坐标
            <<"x: "<<state.imu_state().quaternion()[1]<<", "        // x坐标
            <<"y: "<<state.imu_state().quaternion()[2]<<", "        // y坐标
            <<"z: "<<state.imu_state().quaternion()[3]<<std::endl;  // z坐标

    //打印输出机器狗角速度
    std::cout<<"yaw: "<<state.yaw_speed()<<std::endl;               // 角速度
    
    //打印输出机器狗距离障碍物的距离
    std::cout<<"Obstacle distance: "
            <<"w: "<<state.range_obstacle()[0]<<", "            // w方向
            <<"x: "<<state.range_obstacle()[1]<<", "            // x方向
            <<"y: "<<state.range_obstacle()[2]<<", "            // y方向
            <<"z: "<<state.range_obstacle()[3]<<std::endl;      // z方向

    //打印输出机器狗加速度
    std::cout<<"accelerometer: "
            <<"x: "<<state.imu_state().accelerometer()[0]<<", "         // x方向
            <<"y: "<<state.imu_state().accelerometer()[1]<<", "         // y方向
            <<"z: "<<state.imu_state().accelerometer()[2]<<std::endl;   // z方向

    //打印输出机器狗欧拉角
    std::cout<<"rpy: "
            <<"rpy_x: "<<state.imu_state().rpy()[0]<<", "           // x方向
            <<"rpy_y: "<<state.imu_state().rpy()[1]<<", "           // y方向
            <<"rpy_z: "<<state.imu_state().rpy()[2]<<std::endl;     // z方向

    //打印输出机器狗角速度
    std::cout<<"gyroscope: "
            <<"gyroscope_x: "<<state.imu_state().gyroscope()[0]<<", "       // x方向
            <<"gyroscope_y: "<<state.imu_state().gyroscope()[0]<<", "       // y方向
            <<"gyroscope_z: "<<state.imu_state().gyroscope()[0]<<std::endl; // z方向i   
    
    //打印输出机器狗温度
    std::cout<<"temperature: "<<state.imu_state().temperature()<<std::endl;
    

}


int main(int argc, char **argv)
{
    //初始化sdk接口
    if (argc < 2)
        {
            std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
            exit(-1);
        }
        unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
        //argv[1]由终端传入，为机器人连接的网卡名称

    //创建一个Subscriber
    ChannelSubscriber<unitree_go::msg::dds_::SportModeState_> suber(TOPIC_HIGHSTATE);

    //初始化Channel
    suber.InitChannel(HighStateHandler);

    while(1)
    {
        usleep(20000);
    }

    return 0;
}