cmake_minimum_required(VERSION 3.13)
project(Base VERSION 1.0)

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
    ${BOOT_ROOT})

set(INCLUDES
    interfaces/SharedPtr.h
    core/PreCompiled.h
    BaseException.h)

set(SOURCES
    core/PreCompiled.cpp)

add_library(Base ${SOURCES} ${INCLUDES})
