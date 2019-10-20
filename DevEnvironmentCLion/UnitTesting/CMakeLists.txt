cmake_minimum_required(VERSION 3.13)
project(UnitTesting VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

#
# Configure boost library...
#
if (NOT $ENV{BOOST_ROOT})
    set(BOOT_ROOT $ENV{BOOST_ROOT})
else()
    set(BOOT_ROOT "c:\\Boost\\boost_1_70_0")
endif()

#
# Unit Testing Library...
#
set(UNIT_TESTING_INCLUDES_FILES
    interfaces/IUnitTest.h
    interfaces/IUnitTestManager.h
    interfaces/UnitTestBase.h
    interfaces/UnitTestException.h
    interfaces/UnitTestManager.h
    interfaces/UnitTestRunningResult.h
    interfaces/UnitTestRunningResults.h
    core/PreCompiled.h
    UnitTestingException.h)

set(UNIT_TESTING_SOURCES_FILES
    core/PreCompiled.cpp
    core/UnitTestBase.cpp
    core/UnitTestManager.cpp
    core/UnitTestRunningResult.cpp
    core/UnitTestRunningResults.cpp)

set(UNIT_TESTING_SOURCES
    ${BASE_SOURCES}
    ${UNIT_TESTING_INCLUDES_FILES}
    ${UNIT_TESTING_SOURCES_FILES})

set(UNIT_TESTING_INCLUDES
    .
    interfaces
    core)

include_directories(
    ${UNIT_TESTING_INCLUDES}
    ${BOOT_ROOT})

add_library(UnitTesting ${UNIT_TESTING_SOURCES})
