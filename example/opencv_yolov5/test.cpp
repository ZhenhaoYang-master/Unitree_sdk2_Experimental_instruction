#include <opencv2/dnn.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 加载 ONNX 模型
    std::string modelPath = "/home/ikun/unitree_sdk2/example/opencv_yolov5/best.onnx"; // 替换为您的模型路径
    cv::dnn::Net net;

    try {
        net = cv::dnn::readNetFromONNX(modelPath);
    } catch (const cv::Exception &e) {
        std::cerr << "加载模型时出错: " << e.what() << std::endl;
        return -1;
    }

    // 获取层名称
    std::vector<std::string> layerNames = net.getLayerNames();
    std::cout << "模型的层名称：" << std::endl;
    for (size_t i = 0; i < layerNames.size(); ++i) {
        std::cout << i << ": " << layerNames[i] << std::endl;
    }

    // 创建一个模拟输入（根据模型的输入要求调整）
    // 这里假设模型输入是一个 3 通道的图像，大小为 224x224
    cv::Mat inputBlob = cv::dnn::blobFromImage(cv::Mat(224, 224, CV_32FC3, cv::Scalar(0, 0, 0)), 1.0, cv::Size(224, 224), cv::Scalar(0, 0, 0), true, false);

    // 设置输入
    net.setInput(inputBlob);

    // 进行前向推理并获取输出
    try {
        cv::Mat outputBlob = net.forward(); // 默认输出层
        std::cout << "模型输出形状: " << outputBlob.size << std::endl;
        std::cout << "模型输出: " << outputBlob << std::endl;
    } catch (const cv::Exception &e) {
        std::cerr << "推理时出错: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}