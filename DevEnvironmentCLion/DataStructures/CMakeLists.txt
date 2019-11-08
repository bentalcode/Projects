cmake_minimum_required(VERSION 3.13)
project(DataStructures VERSION 1.0)

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
# Data Structures Library...
#
set(DATA_STRUCTURES_INCLUDES_FILES
    ./core/IteratorOfIteratorCollection.h
    ./DataStructureExcpeption.h)

set(DATA_STRUCTURES_SOURCES_FILES
    ./core/PreCompiled.cpp)

set(DATA_STRUCTURES_SOURCES
    ${DATA_STRUCTURES_INCLUDES_FILES}
    ${DATA_STRUCTURES_SOURCES_FILES})

set(DATA_STRUCTURES_INCLUDES
    .
    interfaces
    core)

include_directories(
    ${DATA_STRUCTURES_INCLUDES}
    ${BOOT_ROOT})

add_library(DataStructures ${DATA_STRUCTURES_SOURCES})
