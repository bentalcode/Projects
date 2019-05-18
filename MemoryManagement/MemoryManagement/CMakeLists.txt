cmake_minimum_required(VERSION 3.13)
project(MemoryManagement VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(. Interface Core)

set(SOURCES
    Core/MemoryAllocator.cpp
    Core/MemoryBlock.cpp
    Core/MemoryPool.cpp
    MemoryManagementException.h)

add_library(MemoryManagement ${SOURCES})
