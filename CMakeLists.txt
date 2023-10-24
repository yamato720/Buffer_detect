# 设置CMake的最低版本要求为3.10
cmake_minimum_required(VERSION 3.10)

# 定义项目名称为"yolov5"
project(yolov5)

# 添加编译选项，指定使用C++11标准
add_definitions(-std=c++11)
add_definitions(-DAPI_EXPORTS)
option(CUDA_USE_STATIC_CUDA_RUNTIME OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# 指定CUDA编译器路径
set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)
enable_language(CUDA)

# 包含和链接CUDA和TensorRT的头文件和库路径
# CUDA
include_directories(/usr/local/cuda/include)
link_directories(/usr/local/cuda/lib64)
# TensorRT
include_directories(/home/nvidia/TensorRT-8.2.5.1/include/)
link_directories(/home/nvidia/TensorRT-8.2.5.1/lib/)

# 包含项目源代码和插件代码的头文件路径
include_directories(${PROJECT_SOURCE_DIR}/src/)
include_directories(${PROJECT_SOURCE_DIR}/plugin/)

# 获取源代码文件列表
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.cu)
file(GLOB_RECURSE PLUGIN_SRCS ${PROJECT_SOURCE_DIR}/plugin/*.cu)

# 创建一个名为"myplugins"的共享库并链接到nvinfer和cudart库
add_library(myplugins SHARED ${PLUGIN_SRCS})
target_link_libraries(myplugins nvinfer cudart)

# 查找并包含OpenCV
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

# 创建可执行文件"yolov5_det"，并链接所需的库
add_executable(yolov5_det yolov5_det.cpp ${SRCS})
target_link_libraries(yolov5_det nvinfer)
target_link_libraries(yolov5_det cudart)
target_link_libraries(yolov5_det myplugins)
target_link_libraries(yolov5_det ${OpenCV_LIBS})

# # 创建可执行文件"yolov5_cls"，并链接所需的库
# add_executable(yolov5_cls yolov5_cls.cpp ${SRCS})
# target_link_libraries(yolov5_cls nvinfer)
# target_link_libraries(yolov5_cls cudart)
# target_link_libraries(yolov5_cls myplugins)
# target_link_libraries(yolov5_cls ${OpenCV_LIBS})

# # 创建可执行文件"yolov5_seg"，并链接所需的库
# add_executable(yolov5_seg yolov5_seg.cpp ${SRCS})
# target_link_libraries(yolov5_seg nvinfer)
# target_link_libraries(yolov5_seg cudart)
# target_link_libraries(yolov5_seg myplugins)
# target_link_libraries(yolov5_seg ${OpenCV_LIBS})
