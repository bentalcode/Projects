cmake_minimum_required(VERSION 3.13)
project(MemoryCommand VERSION 1.0)

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
    Interface
    Core
    ../MemoryManagement
    ../MemoryManagement/Interface
    ../MemoryManagement/Core
    ${BOOT_ROOT})

set(INCLUDES)

set(SOURCES
    main.cpp)

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
add_library(MemoryManagement STATIC
    ../MemoryManagement/Interface/IMemoryAllocator.h
    ../MemoryManagement/Interface/IMemoryPool.h
    ../MemoryManagement/Interface/IObjectPool.h
    ../MemoryManagement/Interface/MemoryPool.h
    ../MemoryManagement/Interface/ObjectPool.h
    ../MemoryManagement/Core/MemoryAllocator.h
    ../MemoryManagement/Core/FixedMemoryPool.h
    ../MemoryManagement/Core/PreCompiled.h
    ../MemoryManagement/Core/MemoryAllocator.cpp
    ../MemoryManagement/Core/FixedMemoryPool.cpp
    ../MemoryManagement/Core/MemoryPool.cpp
    ../MemoryManagement/Core/PreCompiled.cpp
    ../MemoryManagement/MemoryManagementException.h)

# Adding something we can run - Output name matches target name
add_executable(MemoryCommand ${SOURCES} ${INCLUDES})

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(MemoryCommand PRIVATE MemoryManagement)
