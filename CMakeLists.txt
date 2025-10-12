# 1. Minimum required CMake version(3.10)
cmake_minimum_required(VERSION 3.10)
project(cpp-blockchain)

#2 C++ 17 std
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#3 Include headers
include_directories(include)

#4 Executables
add_executable(cpp-blockchain src/main.cpp)
