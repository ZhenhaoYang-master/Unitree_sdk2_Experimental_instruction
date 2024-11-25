#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 打开默认摄像头 (通常是0)
    cv::VideoCapture cap(0);
    
    // 检查摄像头是否成功打开
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera." << std::endl;
        return -1;
    }

    cv::Mat frame;
    
    while (true) {
        // 从摄像头捕捉一帧
        cap >> frame;

        // 检查捕捉是否成功
        if (frame.empty()) {
            std::cerr << "Error: Could not grab a frame." << std::endl;
            break;
        }

        // 显示捕捉到的帧
        cv::imshow("Camera Feed", frame);

        // 检查是否按下 'q' 键
        if (cv::waitKey(30) == 'q') {
            break; // 退出循环
        }
    }

    // 释放摄像头并关闭所有窗口
    cap.release();
    cv::destroyAllWindows();

    return 0;
}