cmake_minimum_required(VERSION 3.13)
project(MemoryManagement VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

#
# Configure boost library...
#
if (NOT $ENV{BOOST_ROOT})
    set(BOOT_ROOT $ENV{BOOST_ROOT})
else()
    set(BOOT_ROOT "c:\\Boost\\boost_1_70_0")
endif()

include_directories(
    .
    Interface
    Core
    ${BOOT_ROOT})

set(INCLUDES
    Interface/IMemoryAllocator.h
    Interface/IMemoryPool.h
    Interface/IObjectPool.h
    Core/MemoryAllocator.h
    Core/FixedMemoryPool.h
    Core/MemoryPool.h
    Core/ObjectPool.h
    Core/PreCompiled.h
    MemoryManagementException.h)

set(SOURCES
    Core/MemoryAllocator.cpp
    Core/FixedMemoryPool.cpp
    Core/MemoryPool.cpp
    Core/PreCompiled.cpp)

add_library(MemoryManagement ${SOURCES} ${INCLUDES})
