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

#
# Base Library...
#
set(BASE_INCLUDES_FILES
    ../Base/interfaces/LogStreamWriter.h
    ../Base/interfaces/Pair.h
    ../Base/interfaces/SharedPtr.h
    ../Base/interfaces/Triple.h
    ../Base/core/BaseDependencies.h
    ../Base/core/PreCompiled.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
    ../Base/BaseException.h)

set(BASE_SOURCES_FILES
    ../Base/core/LogStreamWriter.cpp
    ../Base/core/PreCompiled.cpp)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES})

set(BASE_INCLUDES
    ../Base
    ../Base/interfaces
    ../Base/core)

include_directories(
    ${BASE_INCLUDES}
    ${BOOT_ROOT})

add_library(Base ${BASE_SOURCES})
