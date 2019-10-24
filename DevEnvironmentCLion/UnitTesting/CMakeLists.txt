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
    interfaces/ITestFunction.h
    interfaces/ITestRegistration.h
    interfaces/ITestRunningResult.h
    interfaces/ITestRunningResults.h
    interfaces/IUnitTest.h
    interfaces/IUnitTestHandler.h
    interfaces/IUnitTestManager.h
    interfaces/UnitTestBase.h
    interfaces/UnitTestException.h
    core/PreCompiled.h
    core/UnitTestFunction.h
    core/UnitTestHandler.h
    core/UnitTestManager.h
    core/TestRunningResult.h
    core/TestRunningResults.h
    UnitTestingException.h)

set(UNIT_TESTING_SOURCES_FILES
    core/PreCompiled.cpp
    core/TestRunningResult.cpp
    core/TestRunningResults.cpp
    core/UnitTestBase.cpp
    core/UnitTestHandler.cpp
    core/UnitTestManager.cpp)

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
