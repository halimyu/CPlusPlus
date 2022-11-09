cmake_minimum_required(VERSION 3.23)
project(hw1)

set(CMAKE_CXX_STANDARD 14)

configure_file(baumerRadarSensorData.csv baumerRadarSensorData.csv COPYONLY)
configure_file(exampleData.csv exampleData.csv COPYONLY)

add_executable(hw1 averageData.cpp)
