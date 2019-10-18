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
    interfaces
    core
    ../Base
    ../Base/Interfaces
    ../Base/Core
    ${BOOT_ROOT})

set(INCLUDES
    ../Base/Core/BaseDependencies.h
    interfaces/IMemoryAllocator.h
    interfaces/IMemoryPool.h
    interfaces/IObjectPool.h
    interfaces/MemoryPool.h
    interfaces/ObjectPool.h
    core/MemoryAllocator.h
    core/FixedMemoryPool.h
    core/PreCompiled.h
    MemoryManagementException.h)

set(SOURCES
    core/PreCompiled.cpp
    core/MemoryAllocator.cpp
    core/FixedMemoryPool.cpp
    core/MemoryPool.cpp)

add_library(MemoryManagement ${SOURCES} ${INCLUDES})
