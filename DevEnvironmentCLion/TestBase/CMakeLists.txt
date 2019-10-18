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

set(INCLUDES
    interfaces/IUnitTest.h
    interfaces/IUnitTestManager.h
    interfaces/UnitTestBase.h
    interfaces/UnitTestException.h
    interfaces/UnitTestManager.h
    interfaces/UnitTestRunningResult.h
    interfaces/UnitTestRunningResults.h
    core/PreCompiled.h
    TestBaseException.h)

set(SOURCES
    core/PreCompiled.cpp
    core/UnitTestManager.cpp
    core/UnitTestBase.cpp
    core/UnitTestRunningResult.cpp
    core/UnitTestRunningResults.cpp)

add_library(TestBase ${SOURCES} ${INCLUDES})
