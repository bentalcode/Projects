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
    interfaces/DateTime.h
    interfaces/Duration.h
    interfaces/LogStreamWriter.h
    interfaces/Pair.h
    interfaces/SharedPtr.h
    interfaces/Triple.h
    core/BaseDependencies.h
    core/PreCompiled.h
    core/ReferenceCount.h
    core/ReferenceCountHolder.h
    BaseException.h)

set(BASE_SOURCES_FILES
    core/DateTime.cpp
    core/LogStreamWriter.cpp
    core/PreCompiled.cpp)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES})

set(BASE_INCLUDES
    .
    interfaces
    core)

include_directories(
    ${BASE_INCLUDES}
    ${BOOT_ROOT})

add_library(Base ${BASE_SOURCES})
