cmake_minimum_required(VERSION 3.13)
project(UnitTesting VERSION 1.0)

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
    ../Base/core/ComparableComparator.h
    ../Base/core/EquatableComparator.h
    ../Base/core/PreCompiled.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
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
    interfaces/ITestFunction.h
    interfaces/ITestRegistration.h
    interfaces/ITestRunningResult.h
    interfaces/ITestRunningResults.h
    interfaces/IUnitTest.h
    interfaces/IUnitTestHandler.h
    interfaces/IUnitTestManager.h
    interfaces/UnitTestBase.h
    interfaces/UnitTestException.h
    core/PreCompiled.h
    core/UnitTestFunction.h
    core/UnitTestHandler.h
    core/UnitTestManager.h
    core/TestRunningResult.h
    core/TestRunningResults.h
    UnitTestingException.h)

set(UNIT_TESTING_SOURCES_FILES
    core/PreCompiled.cpp
    core/TestRunningResult.cpp
    core/TestRunningResults.cpp
    core/UnitTestBase.cpp
    core/UnitTestHandler.cpp
    core/UnitTestManager.cpp)

set(UNIT_TESTING_SOURCES
    ${BASE_SOURCES}
    ${UNIT_TESTING_INCLUDES_FILES}
    ${UNIT_TESTING_SOURCES_FILES})

set(UNIT_TESTING_INCLUDES
    .
    interfaces
    core)

include_directories(
    ${UNIT_TESTING_INCLUDES}
    ${TEST_BASE_INCLUDES}
    ${BASE_INCLUDES}
    ${BOOT_ROOT})

add_library(UnitTesting ${UNIT_TESTING_SOURCES} ${TEST_BASE_SOURCES} ${BASE_SOURCES})
