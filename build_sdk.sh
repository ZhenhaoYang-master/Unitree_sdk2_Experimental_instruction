#!/bin/bash

# 定义 SDK 目录
SDK_DIR="/home/ikun/unitree_sdk2"
BUILD_DIR="$SDK_DIR/build"

# 创建构建目录，如果已存在则跳过
mkdir -p $BUILD_DIR

# 进入构建目录
cd $BUILD_DIR

# 运行 CMake 和 make 命令
cmake ..
make

# 检查构建是否成功
if [ $? -eq 0 ]; then
    echo "Build Successful！"
else
    echo "Build failure！"
fi