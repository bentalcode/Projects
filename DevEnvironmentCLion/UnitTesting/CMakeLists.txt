cmake_minimum_required(VERSION 3.6)

project(UnitTesting VERSION 1.0)

set(CMAKE_CXX_STANDARD
    14
)
set(RESOURCES_DIRECTORY_NAME
    resources
)


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


set(UNIT_TESTING_INCLUDES_FILES
    ./UnitTestingException.h
    ./core/PreCompiled.h
    ./core/TestRunningResult.h
    ./core/TestRunningResults.h
    ./core/UnitTestFunction.h
    ./core/UnitTestHandler.h
    ./core/UnitTestManager.h
    ./core/UnitTestingConsts.h
    ./interfaces/ITestFunction.h
    ./interfaces/ITestRegistration.h
    ./interfaces/ITestRunningResult.h
    ./interfaces/ITestRunningResults.h
    ./interfaces/IUnitTest.h
    ./interfaces/IUnitTestHandler.h
    ./interfaces/IUnitTestManager.h
    ./interfaces/UnitTestBase.h
    ./interfaces/UnitTestException.h
)

set(UNIT_TESTING_SOURCES_FILES
    ./core/PreCompiled.cpp
    ./core/TestRunningResult.cpp
    ./core/TestRunningResults.cpp
    ./core/UnitTestBase.cpp
    ./core/UnitTestHandler.cpp
    ./core/UnitTestManager.cpp
    ./core/UnitTestingConsts.cpp
)

set(UNIT_TESTING_INCLUDES
    .
    ./core
    ./interfaces
)

set(UNIT_TESTING_SOURCES
    ${UNIT_TESTING_INCLUDES_FILES}
    ${UNIT_TESTING_SOURCES_FILES}
)

set(BASE_INCLUDES_FILES
    ../Base/BaseException.h
    ../Base/NotImplementedException.h
    ../Base/WindowsException.h
    ../Base/core/AbstractPathBuilder.h
    ../Base/core/AndBitOperator.h
    ../Base/core/BaseDependencies.h
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
    ../Base/core/Conversion.h
    ../Base/core/DateTime.h
    ../Base/core/DereferenceComparableComparator.h
    ../Base/core/DereferenceComparableComparator2.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/DereferenceEquatableComparator2.h
    ../Base/core/Duration.h
    ../Base/core/EqualBuilder.h
    ../Base/core/EquatableComparator.h
    ../Base/core/Indexes.h
    ../Base/core/IntegerConversion.h
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
    ../Base/core/LocalFreeReleaser.h
    ../Base/core/Log.h
    ../Base/core/LogFactory.h
    ../Base/core/MapComparator.h
    ../Base/core/Matrix.h
    ../Base/core/MessageWriter.h
    ../Base/core/NotBitOperator.h
    ../Base/core/OrBitOperator.h
    ../Base/core/Pair.h
    ../Base/core/ParsingResult.h
    ../Base/core/PathBuilder.h
    ../Base/core/Position.h
    ../Base/core/PreCompiled.h
    ../Base/core/RandomGenerator.h
    ../Base/core/Range.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
    ../Base/core/ResourcePathBuilder.h
    ../Base/core/ResourceReader.h
    ../Base/core/SetIterator.h
    ../Base/core/SharedPtr.h
    ../Base/core/SkipIterator.h
    ../Base/core/SmartPointers.h
    ../Base/core/Sorting.h
    ../Base/core/StringComparable.h
    ../Base/core/StringConversion.h
    ../Base/core/StringEquality.h
    ../Base/core/StringIterator.h
    ../Base/core/StringSearch.h
    ../Base/core/Strings.h
    ../Base/core/Threads.h
    ../Base/core/Triple.h
    ../Base/core/TwoDimensionalVector.h
    ../Base/core/TwoDimensionalVectorIterator.h
    ../Base/core/VectorIterator.h
    ../Base/core/VectorReverseIterator.h
    ../Base/core/WindowsConsoleColorHandler.h
    ../Base/core/WindowsDependencies.h
    ../Base/core/WindowsErrors.h
    ../Base/core/XorBitOperator.h
    ../Base/interfaces/ColorType.h
    ../Base/interfaces/IBinaryBitOperator.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/IBitOperator.h
    ../Base/interfaces/IBuilder.h
    ../Base/interfaces/ICalculator.h
    ../Base/interfaces/IClassType.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IComparableComparator.h
    ../Base/interfaces/IConsoleColorHandler.h
    ../Base/interfaces/IEquatableComparator.h
    ../Base/interfaces/IFinder.h
    ../Base/interfaces/IFromString.h
    ../Base/interfaces/IHashCodeProvider.h
    ../Base/interfaces/IIntegerConversion.h
    ../Base/interfaces/IIntervalMap.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/IKeyIterable.h
    ../Base/interfaces/IKeyReverseIterable.h
    ../Base/interfaces/IList.h
    ../Base/interfaces/ILog.h
    ../Base/interfaces/ILogFactory.h
    ../Base/interfaces/IMainParser.h
    ../Base/interfaces/IMatch.h
    ../Base/interfaces/IMatrix.h
    ../Base/interfaces/IMessageWriter.h
    ../Base/interfaces/IParser.h
    ../Base/interfaces/IParsingResult.h
    ../Base/interfaces/IPathBuilder.h
    ../Base/interfaces/IRandomGenerator.h
    ../Base/interfaces/IResourceReader.h
    ../Base/interfaces/IReverseIterable.h
    ../Base/interfaces/IReverseIterator.h
    ../Base/interfaces/ISizableCollection.h
    ../Base/interfaces/ISkipIterator.h
    ../Base/interfaces/IStringConversion.h
    ../Base/interfaces/IToString.h
    ../Base/interfaces/ITransformer.h
    ../Base/interfaces/ITwoDimensionalVector.h
    ../Base/interfaces/IUnaryBitOperator.h
    ../Base/interfaces/IValidator.h
    ../Base/interfaces/IValueIterable.h
    ../Base/interfaces/IValueReverseIterable.h
    ../Base/interfaces/IVisitor.h
    ../Base/interfaces/LogLevelType.h
    ../Base/interfaces/StandardFileDescriptor.h
    ../Base/interfaces/StringComparisonType.h
)

set(BASE_SOURCES_FILES
    ../Base/core/AbstractPathBuilder.cpp
    ../Base/core/AndBitOperator.cpp
    ../Base/core/Bits.cpp
    ../Base/core/ClassType.cpp
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/ConsoleColorSetter.cpp
    ../Base/core/Conversion.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/EqualBuilder.cpp
    ../Base/core/Indexes.cpp
    ../Base/core/IntegerConversion.cpp
    ../Base/core/KmpStringSearch.cpp
    ../Base/core/Log.cpp
    ../Base/core/LogFactory.cpp
    ../Base/core/MessageWriter.cpp
    ../Base/core/NotBitOperator.cpp
    ../Base/core/OrBitOperator.cpp
    ../Base/core/PathBuilder.cpp
    ../Base/core/Position.cpp
    ../Base/core/PreCompiled.cpp
    ../Base/core/RandomGenerator.cpp
    ../Base/core/ResourcePathBuilder.cpp
    ../Base/core/ResourceReader.cpp
    ../Base/core/SkipIterator.cpp
    ../Base/core/StringComparable.cpp
    ../Base/core/StringConversion.cpp
    ../Base/core/StringEquality.cpp
    ../Base/core/StringSearch.cpp
    ../Base/core/Strings.cpp
    ../Base/core/Threads.cpp
    ../Base/core/WindowsConsoleColorHandler.cpp
    ../Base/core/WindowsErrors.cpp
    ../Base/core/XorBitOperator.cpp
)

set(BASE_INCLUDES
    ../Base
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
    ../TestBase/TestBaseException.h
    ../TestBase/core/PreCompiled.h
    ../TestBase/interfaces/Assertion.h
    ../TestBase/interfaces/IterationTest.h
    ../TestBase/interfaces/ResourcePaths.h
)

set(TEST_BASE_SOURCES_FILES
    ../TestBase/core/Assertion.cpp
    ../TestBase/core/IterationTest.cpp
    ../TestBase/core/PreCompiled.cpp
)

set(TEST_BASE_INCLUDES
    ../TestBase
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

include_directories(UnitTesting
    ${BASE_INCLUDES}
    ${TEST_BASE_INCLUDES}
    ${UNIT_TESTING_INCLUDES}
)

add_library(UnitTesting STATIC
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
    ${UNIT_TESTING_SOURCES}
)

include_directories(
    ${BOOST_PATH}
)
