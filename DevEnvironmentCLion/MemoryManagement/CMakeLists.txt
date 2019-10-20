cmake_minimum_required(VERSION 3.13)
project(MemoryManagement VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

print_all_variables()

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

#
# Memory Management Library...
#
set(MEMORY_MANAGEMENT_INCLUDES_FILES
    interfaces/IMemoryAllocator.h
    interfaces/IMemoryPool.h
    interfaces/IObjectPool.h
    interfaces/MemoryPool.h
    interfaces/ObjectPool.h
    interfaces/ObjectPoolElement.h
    core/FixedMemoryPool.h
    core/MemoryAllocator.h
    core/PreCompiled.h
    MemoryManagementException.h)

set(MEMORY_MANAGEMENT_SOURCES_FILES
    core/FixedMemoryPool.cpp
    core/MemoryAllocator.cpp
    core/MemoryPool.cpp
    core/PreCompiled.cpp)

set(MEMORY_MANAGEMENT_SOURCES
    ${MEMORY_MANAGEMENT_INCLUDES_FILES}
    ${MEMORY_MANAGEMENT_SOURCES_FILES})

set(MEMORY_MANAGEMENT_INCLUDES
    .
    ../MemoryManagement/interfaces
    ../MemoryManagement/core)

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
include_directories(
    ${BASE_INCLUDES}
    ${MEMORY_MANAGEMENT_INCLUDES}
    ${BOOT_ROOT})

add_library(Base STATIC
    ${BASE_SOURCES})

add_library(MemoryManagement STATIC
    ${MEMORY_MANAGEMENT_SOURCES})

add_library(MemoryManagement ${BASE_SOURCES} ${MEMORY_MANAGEMENT_SOURCES})
