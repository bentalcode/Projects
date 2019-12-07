cmake_minimum_required(VERSION 3.13)
project(Problems VERSION 1.0)

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
# Problems Library...
#
set(PROBLEMS_INCLUDES_FILES
    ./interfaces/IMatchingTriplets.h
    ./core/MatchingTriplets.h
    ./core/PreCompiled.h
    ./ProblemExcpeption.h)

set(PROBLEMS_SOURCES_FILES
    ./core/PreCompiled.cpp)

set(PROBLEMS_SOURCES
    ${PROBLEMS_INCLUDES_FILES}
    ${PROBLEMS_SOURCES_FILES})

set(PROBLEMS_INCLUDES
    .
    interfaces
    core)

include_directories(
    ${PROBLEMS_INCLUDES}
    ${BOOT_ROOT})

add_library(Problems ${PROBLEMS_SOURCES})
