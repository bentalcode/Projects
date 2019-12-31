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
# Test Base Library...
#
set(TEST_BASE_INCLUDES_FILES
    ../TestBase/interfaces/Assertion.h
    ../TestBase/core/PreCompiled.h
    ../TestBase/TestBaseException.h)

set(TEST_BASE_SOURCES_FILES
    ../TestBase/core/Assertion.cpp
    ../TestBase/core/PreCompiled.cpp)

set(TEST_BASE_SOURCES
    ${TEST_BASE_INCLUDES_FILES}
    ${TEST_BASE_SOURCES_FILES})

set(TEST_BASE_INCLUDES
    ../TestBase
    ../TestBase/interfaces
    ../TestBase/core)

#
# Unit Testing Library...
#
set(UNIT_TESTING_INCLUDES_FILES
    ../UnitTesting/interfaces/ITestFunction.h
    ../UnitTesting/interfaces/ITestRegistration.h
    ../UnitTesting/interfaces/IUnitTest.h
    ../UnitTesting/interfaces/IUnitTestHandler.h
    ../UnitTesting/interfaces/IUnitTestManager.h
    ../UnitTesting/interfaces/ITestRunningResult.h
    ../UnitTesting/interfaces/ITestRunningResults.h
    ../UnitTesting/interfaces/UnitTestBase.h
    ../UnitTesting/interfaces/UnitTestException.h
    ../UnitTesting/core/PreCompiled.h
    ../UnitTesting/core/UnitTestFunction.h
    ../UnitTesting/core/UnitTestHandler.h
    ../UnitTesting/core/UnitTestManager.h
    ../UnitTesting/core/TestRunningResult.h
    ../UnitTesting/core/TestRunningResults.h
    ../UnitTesting/UnitTestingException.h)

set(UNIT_TESTING_SOURCES_FILES
    ../UnitTesting/core/PreCompiled.cpp
    ../UnitTesting/core/UnitTestBase.cpp
    ../UnitTesting/core/UnitTestHandler.cpp
    ../UnitTesting/core/UnitTestManager.cpp
    ../UnitTesting/core/TestRunningResult.cpp
    ../UnitTesting/core/TestRunningResults.cpp)

set(UNIT_TESTING_SOURCES
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
    ${UNIT_TESTING_INCLUDES_FILES}
    ${UNIT_TESTING_SOURCES_FILES})

set(UNIT_TESTING_INCLUDES
    ../UnitTesting
    ../UnitTesting/interfaces
    ../UnitTesting/core)

#
# Memory Management Library...
#
set(MEMORY_MANAGEMENT_INCLUDES_FILES
    ../MemoryManagement/interfaces/IMemoryAllocator.h
    ../MemoryManagement/interfaces/IMemoryPool.h
    ../MemoryManagement/interfaces/IObjectPool.h
    ../MemoryManagement/interfaces/MemoryPool.h
    ../MemoryManagement/interfaces/ObjectPool.h
    ../MemoryManagement/interfaces/ObjectPoolElement.h
    ../MemoryManagement/core/FixedMemoryPool.h
    ../MemoryManagement/core/MemoryAllocator.h
    ../MemoryManagement/core/PreCompiled.h
    ../MemoryManagement/MemoryManagementException.h)

set(MEMORY_MANAGEMENT_SOURCES_FILES
    ../MemoryManagement/core/FixedMemoryPool.cpp
    ../MemoryManagement/core/MemoryAllocator.cpp
    ../MemoryManagement/core/MemoryPool.cpp
    ../MemoryManagement/core/PreCompiled.cpp)

set(MEMORY_MANAGEMENT_SOURCES
    ${MEMORY_MANAGEMENT_INCLUDES_FILES}
    ${MEMORY_MANAGEMENT_SOURCES_FILES})

set(MEMORY_MANAGEMENT_INCLUDES
    ../MemoryManagement
    ../MemoryManagement/interfaces
    ../MemoryManagement/core)

#
# Memory Management Test...
#
set(MEMORY_MANAGEMENT_TEST_INCLUDES_FILES
    interfaces/MemoryAllocatorUnitTest.h
    interfaces/ObjectPoolUnitTest.h
    core/PreCompiled.h)

set(MEMORY_MANAGEMENT_TEST_SOURCES_FILES
    main.cpp
    core/MemoryAllocatorUnitTest.cpp
    core/ObjectPoolUnitTest.cpp
    core/PreCompiled.cpp)

set(MEMORY_MANAGEMENT_TEST_SOURCES
    ${MEMORY_MANAGEMENT_TEST_INCLUDES_FILES}
    ${MEMORY_MANAGEMENT_TEST_SOURCES_FILES})

set(MEMORY_MANAGEMENT_TEST_INCLUDES
    .
    ./interfaces
    ./core)

# This is a "default" library, and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
include_directories(
    ${MEMORY_MANAGEMENT_TEST_INCLUDES}
    ${BASE_INCLUDES}
    ${TEST_BASE_INCLUDES}
    ${UNIT_TESTING_INCLUDES}
    ${MEMORY_MANAGEMENT_INCLUDES}
    ${BOOT_ROOT})

add_library(Base STATIC
    ${BASE_SOURCES})

add_library(TestBase STATIC
    ${TEST_BASE_SOURCES})

add_library(UnitTesting STATIC
    ${UNIT_TESTING_SOURCES})

add_library(MemoryManagement STATIC
    ${MEMORY_MANAGEMENT_SOURCES})

# Adding something we can run - Output name matches target name
add_executable(MemoryManagementTest ${MEMORY_MANAGEMENT_TEST_SOURCES})

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(MemoryManagementTest PRIVATE Base TestBase UnitTesting MemoryManagement)
