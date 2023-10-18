cmake_minimum_required(VERSION 3.6)

project(MemoryManagementTest VERSION 1.0)

set(CMAKE_CXX_STANDARD
    14
)
set(RESOURCES_DIRECTORY_NAME
    resources
)

#
# Configure build properties...
#
set(VERSION_MAJOR "1")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")


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
    set(BOOST_PATH $ENV{BOOST_ROOT})
else()
    set(BOOST_PATH "c:\\Boost\\boost_1_78_0")
endif()

add_compile_definitions(WINDOWS=1)


set(MEMORY_MANAGEMENT_TEST_INCLUDES_FILES
    ./interfaces/MemoryAllocatorUnitTest.h
    ./interfaces/ObjectPoolUnitTest.h
)

set(MEMORY_MANAGEMENT_TEST_SOURCES_FILES
    ./core/MemoryAllocatorUnitTest.cpp
    ./core/ObjectPoolUnitTest.cpp
    ./main.cpp
)

set(MEMORY_MANAGEMENT_TEST_INCLUDES
    ./interfaces
)

set(MEMORY_MANAGEMENT_TEST_SOURCES
    ${MEMORY_MANAGEMENT_TEST_INCLUDES_FILES}
    ${MEMORY_MANAGEMENT_TEST_SOURCES_FILES}
)

set(BASE_INCLUDES_FILES
    ../Base/core/AlmostComparator.h
    ../Base/core/AndBitOperator.h
    ../Base/core/BaseException.h
    ../Base/core/BaseLogic.h
    ../Base/core/Bits.h
    ../Base/core/ClassType.h
    ../Base/core/ClassTypes.h
    ../Base/core/CollectionComparator.h
    ../Base/core/Collections.h
    ../Base/core/ComparableComparator.h
    ../Base/core/Comparator.h
    ../Base/core/ComparatorFactory.h
    ../Base/core/CompareToBuilder.h
    ../Base/core/ConsoleColorSetter.h
    ../Base/core/DereferenceComparableComparator.h
    ../Base/core/DereferenceComparableComparator2.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/DereferenceEquatableComparator2.h
    ../Base/core/EqualBuilder.h
    ../Base/core/EquatableComparator.h
    ../Base/core/ErrorCodes.h
    ../Base/core/ErrorMessages.h
    ../Base/core/Indexes.h
    ../Base/core/Interval.h
    ../Base/core/IntervalMap.h
    ../Base/core/IntervalMapIterator.h
    ../Base/core/InvertComparator.h
    ../Base/core/IterableComparator.h
    ../Base/core/IterableObject.h
    ../Base/core/IteratorComparator.h
    ../Base/core/KmpStringSearch.h
    ../Base/core/List.h
    ../Base/core/ListIterator.h
    ../Base/core/ListReverseIterator.h
    ../Base/core/MapComparator.h
    ../Base/core/Matrix.h
    ../Base/core/MessageWriter.h
    ../Base/core/NotBitOperator.h
    ../Base/core/NotImplementedException.h
    ../Base/core/OrBitOperator.h
    ../Base/core/Pair.h
    ../Base/core/RandomGenerator.h
    ../Base/core/Range.h
    ../Base/core/ReferenceCounterHolder.h
    ../Base/core/SetIterator.h
    ../Base/core/SharedPtr.h
    ../Base/core/SkipIterator.h
    ../Base/core/Sorting.h
    ../Base/core/StringComparable.h
    ../Base/core/StringConversion.h
    ../Base/core/StringEquality.h
    ../Base/core/StringSearch.h
    ../Base/core/StringUtils.h
    ../Base/core/Strings.h
    ../Base/core/ToString.h
    ../Base/core/TwoDimensionalVector.h
    ../Base/core/TwoDimensionalVectorIterator.h
    ../Base/core/UnexpectedException.h
    ../Base/core/Uuid.h
    ../Base/core/VectorIterator.h
    ../Base/core/VectorReverseIterator.h
    ../Base/core/WindowsConsoleColorHandler.h
    ../Base/core/XorBitOperator.h
    ../Base/interfaces/ColorType.h
    ../Base/interfaces/Colors.h
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/DateTimeInterval.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/IBinaryBitOperator.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/IBitOperator.h
    ../Base/interfaces/IBuilder.h
    ../Base/interfaces/ICalculator.h
    ../Base/interfaces/IClassType.h
    ../Base/interfaces/IClone.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IComparableComparator.h
    ../Base/interfaces/IComparatorFactory.h
    ../Base/interfaces/IConsoleColorHandler.h
    ../Base/interfaces/IEquatableComparator.h
    ../Base/interfaces/IHashCodeProvider.h
    ../Base/interfaces/IIntervalMap.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/IKeyIterable.h
    ../Base/interfaces/IKeyReverseIterable.h
    ../Base/interfaces/IList.h
    ../Base/interfaces/IMatch.h
    ../Base/interfaces/IMatrix.h
    ../Base/interfaces/IMessageWriter.h
    ../Base/interfaces/IRandomGenerator.h
    ../Base/interfaces/IResourceReader.h
    ../Base/interfaces/IReverseIterable.h
    ../Base/interfaces/IReverseIterator.h
    ../Base/interfaces/ISizableCollection.h
    ../Base/interfaces/ISkipIterator.h
    ../Base/interfaces/IStringConversion.h
    ../Base/interfaces/IToString.h
    ../Base/interfaces/ITwoDimensionalVector.h
    ../Base/interfaces/IUnaryBitOperator.h
    ../Base/interfaces/IUuid.h
    ../Base/interfaces/IValueIterable.h
    ../Base/interfaces/IValueReverseIterable.h
    ../Base/interfaces/IVisitor.h
    ../Base/interfaces/ReferenceCounter.h
    ../Base/interfaces/ReferenceCounterHolder.h
    ../Base/interfaces/SmartPointers.h
    ../Base/interfaces/StandardFileDescriptor.h
    ../Base/interfaces/StringComparisonType.h
    ../Base/interfaces/TimeUnit.h
    ../Base/interfaces/TimeUtils.h
)

set(BASE_SOURCES_FILES
    ../Base/core/AndBitOperator.cpp
    ../Base/core/Bits.cpp
    ../Base/core/ClassType.cpp
    ../Base/core/Collections.cpp
    ../Base/core/ComparatorFactory.cpp
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/ConsoleColorSetter.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/EqualBuilder.cpp
    ../Base/core/ErrorCodes.cpp
    ../Base/core/ErrorMessages.cpp
    ../Base/core/KmpStringSearch.cpp
    ../Base/core/MessageWriter.cpp
    ../Base/core/NotBitOperator.cpp
    ../Base/core/OrBitOperator.cpp
    ../Base/core/RandomGenerator.cpp
    ../Base/core/ReferenceCounter.cpp
    ../Base/core/SkipIterator.cpp
    ../Base/core/StringComparable.cpp
    ../Base/core/StringConversion.cpp
    ../Base/core/StringEquality.cpp
    ../Base/core/StringSearch.cpp
    ../Base/core/StringUtils.cpp
    ../Base/core/Strings.cpp
    ../Base/core/Tests.cpp
    ../Base/core/TimeUnit.cpp
    ../Base/core/TimeUtils.cpp
    ../Base/core/ToString.cpp
    ../Base/core/Uuid.cpp
    ../Base/core/WindowsConsoleColorHandler.cpp
    ../Base/core/XorBitOperator.cpp
)

set(BASE_INCLUDES
    ../Base/core
    ../Base/interfaces
)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES}
)

add_library(Base STATIC
    ${BASE_SOURCES}
)

set(TEST_BASE_INCLUDES_FILES
    ../TestBase/core/TestBaseException.h
    ../TestBase/interfaces/Assertion.h
    ../TestBase/interfaces/IterationTest.h
    ../TestBase/interfaces/ResourcePaths.h
)

set(TEST_BASE_SOURCES_FILES
    ../TestBase/core/Assertion.cpp
    ../TestBase/core/IterationTest.cpp
)

set(TEST_BASE_INCLUDES
    ../TestBase/core
    ../TestBase/interfaces
)

set(TEST_BASE_SOURCES
    ${TEST_BASE_INCLUDES_FILES}
    ${TEST_BASE_SOURCES_FILES}
)

add_library(TestBase STATIC
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
)

set(UNIT_TESTING_INCLUDES_FILES
    ../UnitTesting/core/TestRunningResult.h
    ../UnitTesting/core/TestRunningResults.h
    ../UnitTesting/core/UnitTestFunction.h
    ../UnitTesting/core/UnitTestHandler.h
    ../UnitTesting/core/UnitTestManager.h
    ../UnitTesting/core/UnitTestingConsts.h
    ../UnitTesting/core/UnitTestingException.h
    ../UnitTesting/interfaces/ITestFunction.h
    ../UnitTesting/interfaces/ITestRegistration.h
    ../UnitTesting/interfaces/ITestRunningResult.h
    ../UnitTesting/interfaces/ITestRunningResults.h
    ../UnitTesting/interfaces/IUnitTest.h
    ../UnitTesting/interfaces/IUnitTestHandler.h
    ../UnitTesting/interfaces/IUnitTestManager.h
    ../UnitTesting/interfaces/UnitTestBase.h
    ../UnitTesting/interfaces/UnitTestException.h
)

set(UNIT_TESTING_SOURCES_FILES
    ../UnitTesting/core/TestRunningResult.cpp
    ../UnitTesting/core/TestRunningResults.cpp
    ../UnitTesting/core/UnitTestBase.cpp
    ../UnitTesting/core/UnitTestHandler.cpp
    ../UnitTesting/core/UnitTestManager.cpp
    ../UnitTesting/core/UnitTestingConsts.cpp
)

set(UNIT_TESTING_INCLUDES
    ../UnitTesting/core
    ../UnitTesting/interfaces
)

set(UNIT_TESTING_SOURCES
    ${UNIT_TESTING_INCLUDES_FILES}
    ${UNIT_TESTING_SOURCES_FILES}
)

add_library(UnitTesting STATIC
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
    ${UNIT_TESTING_SOURCES}
)

set(MEMORY_MANAGEMENT_INCLUDES_FILES
    ../MemoryManagement/MemoryManagementException.h
    ../MemoryManagement/core/FixedMemoryPool.h
    ../MemoryManagement/core/MemoryAllocator.h
    ../MemoryManagement/interfaces/IMemoryAllocator.h
    ../MemoryManagement/interfaces/IMemoryPool.h
    ../MemoryManagement/interfaces/IObjectPool.h
    ../MemoryManagement/interfaces/MemoryPool.h
    ../MemoryManagement/interfaces/ObjectPool.h
    ../MemoryManagement/interfaces/ObjectPoolElement.h
)

set(MEMORY_MANAGEMENT_SOURCES_FILES
    ../MemoryManagement/core/FixedMemoryPool.cpp
    ../MemoryManagement/core/MemoryAllocator.cpp
    ../MemoryManagement/core/MemoryPool.cpp
    ../MemoryManagement/core/Tests.cpp
)

set(MEMORY_MANAGEMENT_INCLUDES
    ../MemoryManagement
    ../MemoryManagement/core
    ../MemoryManagement/interfaces
)

set(MEMORY_MANAGEMENT_SOURCES
    ${MEMORY_MANAGEMENT_INCLUDES_FILES}
    ${MEMORY_MANAGEMENT_SOURCES_FILES}
)

add_library(MemoryManagement STATIC
    ${BASE_SOURCES}
    ${MEMORY_MANAGEMENT_SOURCES}
)

include_directories(MemoryManagementTest
    ${BASE_INCLUDES}
    ${MEMORY_MANAGEMENT_INCLUDES}
    ${MEMORY_MANAGEMENT_TEST_INCLUDES}
    ${TEST_BASE_INCLUDES}
    ${UNIT_TESTING_INCLUDES}
)

add_executable(MemoryManagementTest
    ${BASE_SOURCES}
    ${MEMORY_MANAGEMENT_SOURCES}
    ${MEMORY_MANAGEMENT_TEST_SOURCES}
    ${TEST_BASE_SOURCES}
    ${UNIT_TESTING_SOURCES}
)

target_link_libraries(MemoryManagementTest
    PRIVATE Base TestBase UnitTesting MemoryManagement
)

include_directories(
    ${BOOST_PATH}
)
