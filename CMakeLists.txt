cmake_minimum_required(VERSION 3.21)
project(dom1)

set(CMAKE_CXX_STANDARD 14)

add_executable(dom1 main.cpp ComputerPart.cpp ComputerPart.h ComputerPartWriter.cpp ComputerPartWriter.h PartType.h ComputerPartReader.cpp ComputerPartReader.h)
