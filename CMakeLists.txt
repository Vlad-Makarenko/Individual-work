cmake_minimum_required(VERSION 3.17)
project(RGZ)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(RGZ_main src/main.cpp src/Backpack.cpp src/Backpack.h src/Container.cpp src/Container.h src/Controller.cpp src/Controller.h src/Menu.cpp src/Menu.h)
add_executable(RGZ_test test/ControllerTest.cpp src/Backpack.cpp src/Container.cpp src/Controller.cpp)