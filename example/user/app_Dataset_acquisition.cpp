#include <unitree/robot/go2/video/video_client.hpp>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    /*
     * Initilaize ChannelFactory
     */
    //unitree::robot::ChannelFactory::Instance()->Init(0);

    // 检查命令行参数数量, 确保提供了网络接口参数
    if (argc < 2) 
    {
        std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
        exit(-1);
    }
    // 初始化接口, 通过 ChannelFactory 获取示例并初始化
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    
    unitree::robot::go2::VideoClient video_client;

    /*
     * Set request timeout 1.0s
     */
    video_client.SetTimeout(1.0f);
    video_client.Init();

    // Test Api
    std::vector<uint8_t> image_sample;      
    int ret;

    // Specify the folder to save images
    std::string folder_path = "images/"; 
    // Create the folder if it does not exist       
    struct stat info;
    if (stat(folder_path.c_str(), &info) != 0)
    {
        // Folder does not exist, create it
        mkdir(folder_path.c_str(), 0777);
    }
    
    std::cout << "Press Enter to capture an image (Ctrl+C to exit)..." << std::endl;

    time_t last_capture_time = 0;   //记录上一次捕获时间
    const int capture_interval = 1; //设置捕获间隔时间为1S

    while (true)
    {
        // 等待用户按下回车键
        std::cin.get(); // 等待输入

        time_t current_time = time(nullptr); // 获取当前时间

       // 检查当前时间与上次捕获时间的间隔
        if (difftime(current_time, last_capture_time) >= capture_interval) 
        {
            last_capture_time = current_time; // 更新上次捕获时间

            ret = video_client.GetImageSample(image_sample);

            if (ret == 0) {
                time_t rawtime;
                struct tm *timeinfo;
                char buffer[80];

                time(&rawtime);
                timeinfo = localtime(&rawtime);

                strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S.jpg", timeinfo);
                std::string image_name = folder_path + buffer; // Save path with folder

                std::ofstream image_file(image_name, std::ios::binary);
                if (image_file.is_open()) {
                    image_file.write(reinterpret_cast<const char*>(image_sample.data()), image_sample.size());
                    image_file.close();
                    std::cout << "Image saved successfully as " << image_name << std::endl;
                } else {
                    std::cerr << "Error: Failed to save image." << std::endl;
                }
            } else {
                std::cerr << "Error: Failed to get image sample." << std::endl;
            }
        } else {
            std::cout << "Please wait for " << (capture_interval - difftime(current_time, last_capture_time)) << " seconds before capturing again." << std::endl;
        }
    }
    return 0;
}