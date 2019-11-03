cmake_minimum_required(VERSION 3.13)
project(TestBase VERSION 1.0)

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

set(TEST_BASE_INCLUDES_FILES
    ./interfaces/Assertion.h
    ./core/PreCompiled.h
    ./TestBaseException.h)

set(TEST_BASE_SOURCES_FILES
    ./core/Assertion.cpp
    ./core/PreCompiled.cpp)

set(TEST_BASE_SOURCES
    ${TEST_BASE_INCLUDES_FILES}
    ${TEST_BASE_SOURCES_FILES})

add_library(TestBase ${TEST_BASE_SOURCES})
