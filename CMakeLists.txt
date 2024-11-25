cmake_minimum_required(VERSION 3.5)
project(unitree_sdk2 VERSION 2.0.0)

## Project Options
option(BUILD_EXAMPLES "Build examples" ON)

## Set compiler to use c++ 17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Chosse build type
set(default_build_type "Release")
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
            STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif ()

## Use GNUInstallDirs to install libraries into correct locations on all platforms.
include(GNUInstallDirs)

## Put all binary files into /bin and libraries into /lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

## Check system architecture
message(STATUS "Current system architecture: ${CMAKE_SYSTEM_PROCESSOR}")

## Import thirdparty libraries
add_subdirectory(thirdparty)

## Import Unitree SDK2 library
set(UNITREE_SDK_PATH ${CMAKE_CURRENT_LIST_DIR}/lib/${CMAKE_SYSTEM_PROCESSOR})
find_library(UNITREE_SDK_LIB unitree_sdk2 PATHS ${UNITREE_SDK_PATH} NO_DEFAULT_PATH)

if (NOT UNITREE_SDK_LIB)
    message(FATAL_ERROR "Unitree SDK library for the architecture is not found")
else ()
    message(STATUS "Unitree SDK library found at: ${UNITREE_SDK_LIB}")
endif ()

message(STATUS "Importing: ${UNITREE_SDK_LIB}")

find_package(Threads REQUIRED)

add_library(unitree_sdk2 STATIC IMPORTED GLOBAL)
set_target_properties(unitree_sdk2 PROPERTIES
        IMPORTED_LOCATION ${UNITREE_SDK_LIB})
target_link_libraries(unitree_sdk2 INTERFACE ddsc ddscxx Threads::Threads)
target_include_directories(unitree_sdk2 INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

if (BUILD_EXAMPLES)
    add_subdirectory(example)
endif ()

## Install the library
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${UNITREE_SDK_LIB}
    DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES cmake/unitree_sdk2Targets.cmake
    DESTINATION lib/cmake/unitree_sdk2)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    unitree_sdk2ConfigVersion.cmake
    VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}"
    COMPATIBILITY ExactVersion)

configure_file(cmake/unitree_sdk2Config.cmake.in unitree_sdk2Config.cmake @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/unitree_sdk2Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/unitree_sdk2ConfigVersion.cmake"
    DESTINATION lib/cmake/unitree_sdk2)

#----------------openCV Define----------------------------#
# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
#----------------openCV Define----------------------------#

##------------------USER Start----------------------------##    
add_executable(app_height example/user/app_height.cpp)
target_link_libraries(app_height unitree_sdk2)

add_executable(app_Attitudecontrol example/user/app_Attitudecontrol.cpp)
target_link_libraries(app_Attitudecontrol unitree_sdk2)

add_executable(app_Motioncontrol example/user/app_Motioncontrol.cpp) 
target_link_libraries(app_Motioncontrol unitree_sdk2)

add_executable(app_Video example/user/app_Video.cpp) 
target_link_libraries(app_Video unitree_sdk2)

add_executable(app_Dataset_acquisition example/user/app_Dataset_acquisition.cpp) 
target_link_libraries(app_Dataset_acquisition unitree_sdk2)

add_executable(app_Obstacles_avoid example/user/app_Obstacles_avoid.cpp) 
target_link_libraries(app_Obstacles_avoid unitree_sdk2)

add_executable(app_Volume_light example/user/app_Volume_light.cpp) 
target_link_libraries(app_Volume_light unitree_sdk2)

add_executable(app_High_level_control example/user/app_High_level_control.cpp) 
target_link_libraries(app_High_level_control unitree_sdk2)

add_executable(app_SwitchGait example/user/app_SwitchGait.cpp)
target_link_libraries(app_SwitchGait unitree_sdk2)

add_executable(app_Dancemovement example/user/app_Dancemovement.cpp)
target_link_libraries(app_Dancemovement unitree_sdk2)

add_executable(app_Attitudecontrol1 example/user/app_Attitudecontrol1.cpp) 
target_link_libraries(app_Attitudecontrol1 unitree_sdk2)

add_executable(app_Statusinformation example/user/app_Statusinformation.cpp) 
target_link_libraries(app_Statusinformation unitree_sdk2)

add_executable(app_test example/user/app_test.cpp)  
target_link_libraries(app_test unitree_sdk2)

#-----------openCV----------------#
# Declare the executable target built from your sources 
add_executable(app_opencv_test example/user/app_opencv_test.cpp) 
#target_link_libraries(app_opencv_test unitree_sdk2)
# Link your application with OpenCV libraries
target_link_libraries(app_opencv_test PRIVATE ${OpenCV_LIBS})
#-----------openCV----------------#

add_executable(app_Video_shiping example/user/app_Video_shiping.cpp) 
target_link_libraries(app_Video_shiping PRIVATE ${OpenCV_LIBS})

add_executable(test_Readmoudel example/opencv_yolov5/test_Readmoudel.cpp) 
target_link_libraries(test_Readmoudel PRIVATE ${OpenCV_LIBS})

add_executable(test example/opencv_yolov5/test.cpp) 
target_link_libraries(test PRIVATE ${OpenCV_LIBS})

add_executable(camera_test example/opencv_yolov5/camera_test.cpp) 
target_link_libraries(camera_test PRIVATE ${OpenCV_LIBS})

add_executable(yolov5_Imagedetection example/opencv_yolov5/yolov5_Imagedetection.cpp) 
target_link_libraries(yolov5_Imagedetection PRIVATE ${OpenCV_LIBS})

add_executable(yolov5_Cameradetection example/opencv_yolov5/yolov5_Cameradetection.cpp) 
target_link_libraries(yolov5_Cameradetection PRIVATE ${OpenCV_LIBS})
##------------------USER End----------------------------##  



