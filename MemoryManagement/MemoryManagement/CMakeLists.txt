cmake_minimum_required(VERSION 3.13)
project(MemoryManagement VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

include_directories(. Interface Core)

set(INCLUDES
    Core/MemoryAllocator.h
    Core/FixedMemoryPool.h
    Core/MemoryPool.h
    Core/PreCompiled.h
    MemoryManagementException.h)

set(SOURCES
    Core/MemoryAllocator.cpp
    Core/FixedMemoryPool.cpp
    Core/MemoryPool.cpp
    Core/PreCompiled.cpp)

add_library(MemoryManagement ${SOURCES} ${INCLUDES})
