#include <opencv2/dnn.hpp>
#include <iostream>

int main() {
    // 加载 ONNX 模型
    cv::dnn::Net net = cv::dnn::readNetFromONNX("/home/ikun/unitree_sdk2/example/opencv_yolov5/best.onnx");

    // 获取层名称
    std::vector<std::string> layerNames = net.getLayerNames();
    std::cout << "模型的层名称：" << std::endl;
    for (size_t i = 0; i < layerNames.size(); ++i) {
        std::cout << i << ": " << layerNames[i] << std::endl;
    }

    // 检查层数
    std::cout << "模型的层数：" << layerNames.size() << std::endl;

    // 访问特定的层
    try {
        int layer_id = 0; // 替换为有效的层 ID
        auto layerData = net.getLayer(layer_id);
        std::cout << "访问的层数据：" << layerData->name << std::endl;
    } catch (const cv::Exception& e) {
        std::cerr << "访问层时出错：" << e.what() << std::endl;
    }

    return 0;
}