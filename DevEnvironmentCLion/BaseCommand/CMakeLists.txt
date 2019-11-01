cmake_minimum_required(VERSION 3.13)
project(BaseCommand VERSION 1.0)

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
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/ISizebleCollection.h
    ../Base/interfaces/ITwoDimensionalList.h
    ../Base/interfaces/LogStreamWriter.h
    ../Base/interfaces/Pair.h
    ../Base/interfaces/SharedPtr.h
    ../Base/interfaces/Triple.h
    ../Base/core/BaseDependencies.h
    ../Base/core/PreCompiled.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
    ../Base/core/TwoDimensionalList.h
    ../Base/BaseException.h)

set(BASE_SOURCES_FILES
    ../Base/core/DateTime.cpp
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
# Base Command Test...
#
set(BASE_COMMAND_INCLUDES_FILES
    core/PreCompiled.h)

set(BASE_COMMAND_SOURCES_FILES
    main.cpp
    core/PreCompiled.cpp)

set(BASE_COMMAND_SOURCES
    ${BASE_COMMAND_INCLUDES_FILES}
    ${BASE_COMMAND_SOURCES_FILES})

set(BASE_COMMAND_INCLUDES
    .
    ./interfaces
    ./core)

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
include_directories(
    ${BASE_INCLUDES}
    ${BASE_COMMAND_INCLUDES}
    ${BOOT_ROOT})

add_library(Base STATIC
    ${BASE_SOURCES})

# Adding something we can run - Output name matches target name
add_executable(BaseCommand ${BASE_COMMAND_SOURCES})

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(BaseCommand PRIVATE Base)
