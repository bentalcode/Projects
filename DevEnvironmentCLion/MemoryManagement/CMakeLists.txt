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
    ../Base/interfaces/ComparatorFactory.h
    ../Base/interfaces/CompareToBuilder.h
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/EqualBuilder.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IComparableComparator.h
    ../Base/interfaces/IEquatableComparator.h
    ../Base/interfaces/IHashCodeProvider.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/IList.h
    ../Base/interfaces/Interval.h
    ../Base/interfaces/Intervals.h
    ../Base/interfaces/ISizebleCollection.h
    ../Base/interfaces/IterableComparator.h
    ../Base/interfaces/IteratorComparator.h
    ../Base/interfaces/ITwoDimensionalList.h
    ../Base/interfaces/LogStreamWriter.h
    ../Base/interfaces/Pair.h
    ../Base/interfaces/SharedPtr.h
    ../Base/interfaces/Triple.h
    ../Base/core/BaseDependencies.h
    ../Base/core/BaseLogic.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/EquatableComparator.h
    ../Base/core/ListIterator.h
    ../Base/core/PreCompiled.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
    ../Base/core/StringIterator.h
    ../Base/core/TwoDimensionalList.h
    ../Base/BaseException.h)

set(BASE_SOURCES_FILES
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/EqualBuilder.cpp
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
    ../MemoryManagement/interfaces/IMemoryAllocator.h
    ./interfaces/IMemoryPool.h
    ./interfaces/IObjectPool.h
    ./interfaces/MemoryPool.h
    ./interfaces/ObjectPool.h
    ./interfaces/ObjectPoolElement.h
    ./core/FixedMemoryPool.h
    ./core/MemoryAllocator.h
    ./core/PreCompiled.h
    ./MemoryManagementException.h)

set(MEMORY_MANAGEMENT_SOURCES_FILES
    ./core/FixedMemoryPool.cpp
    ./core/MemoryAllocator.cpp
    ./core/MemoryPool.cpp
    ./core/PreCompiled.cpp)

set(MEMORY_MANAGEMENT_SOURCES
    ${MEMORY_MANAGEMENT_INCLUDES_FILES}
    ${MEMORY_MANAGEMENT_SOURCES_FILES})

set(MEMORY_MANAGEMENT_INCLUDES
    .
    interfaces
    core)

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
include_directories(
    ${MEMORY_MANAGEMENT_INCLUDES}
    ${BASE_INCLUDES}
    ${BOOT_ROOT})

add_library(MemoryManagement ${MEMORY_MANAGEMENT_SOURCES} ${BASE_SOURCES})
