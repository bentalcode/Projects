cmake_minimum_required(VERSION 3.13)
project(MemoryManagementTest VERSION 1.0)

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

include_directories(
    .
    ./interfaces
    ./core
    ../Base
    ../Base/interfaces
    ../Base/core
    ../TestBase
    ../TestBase/interfaces
    ../TestBase/core
    ../MemoryManagement
    ../MemoryManagement/interfaces
    ../MemoryManagement/core
    ${BOOT_ROOT})

set(INCLUDES)

set(SOURCES
    main.cpp
    interfaces/ObjectPoolUnitTest.h
    core/ObjectPoolUnitTest.cpp)

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
add_library(Base STATIC
    ../Base/interfaces/SharedPtr.h
    ../Base/core/PreCompiled.h
    ../Base/core/PreCompiled.cpp
    ../Base/BaseException.h)

add_library(TestBase STATIC
    ../TestBase/interfaces/IUnitTest.h
    ../TestBase/interfaces/IUnitTestManager.h
    ../TestBase/interfaces/UnitTestBase.h
    ../TestBase/interfaces/UnitTestManager.h
    ../TestBase/core/UnitTestBase.cpp
    ../TestBase/core/UnitTestManager.cpp
    ../TestBase/core/PreCompiled.h
    ../TestBase/core/PreCompiled.cpp)

add_library(MemoryManagement STATIC
    ../MemoryManagement/interfaces/IMemoryAllocator.h
    ../MemoryManagement/interfaces/IMemoryPool.h
    ../MemoryManagement/interfaces/IObjectPool.h
    ../MemoryManagement/interfaces/MemoryPool.h
    ../MemoryManagement/interfaces/ObjectPool.h
    ../MemoryManagement/core/MemoryAllocator.h
    ../MemoryManagement/core/FixedMemoryPool.h
    ../MemoryManagement/core/PreCompiled.h
    ../MemoryManagement/core/MemoryAllocator.cpp
    ../MemoryManagement/core/FixedMemoryPool.cpp
    ../MemoryManagement/core/MemoryPool.cpp
    ../MemoryManagement/core/PreCompiled.cpp
    ../MemoryManagement/MemoryManagementException.h)

# Adding something we can run - Output name matches target name
add_executable(MemoryManagementTest ${SOURCES} ${INCLUDES})

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(MemoryManagementTest PRIVATE Base TestBase MemoryManagement)
