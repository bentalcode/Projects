cmake_minimum_required(VERSION 3.13)

project(ProblemsTest VERSION 1.0)

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
    set(BOOST_PATH "c:\\Boost\\boost_1_70_0")
endif()

set(PROBLEMS_TEST_INCLUDES_FILES
    ./core/PreCompiled.h
    ./interfaces/CombinationSumUnitTest.h
    ./interfaces/FlightRoutePlannerUnitTest.h
    ./interfaces/MatchingTripletsUnitTest.h
    ./interfaces/MatrixFinderUnitTest.h
    ./interfaces/MergingIntervalsUnitTest.h
    ./interfaces/MinimumWindowSubstringUnitTest.h
    ./interfaces/NumberValidatorUnitTest.h
    ./interfaces/PositionQueensUnitTest.h
    ./interfaces/TestData.h
    ./interfaces/WordFinderUnitTest.h
)

set(PROBLEMS_TEST_SOURCES_FILES
    ./core/CombinationSumUnitTest.cpp
    ./core/FlightRoutePlannerUnitTest.cpp
    ./core/MatchingTripletsUnitTest.cpp
    ./core/MatrixFinderUnitTest.cpp
    ./core/MergingIntervalsUnitTest.cpp
    ./core/MinimumWindowSubstringUnitTest.cpp
    ./core/NumberValidatorUnitTest.cpp
    ./core/PositionQueensUnitTest.cpp
    ./core/PreCompiled.cpp
    ./core/TestData.cpp
    ./core/WordFinderUnitTest.cpp
    ./main.cpp
)

set(PROBLEMS_TEST_SOURCES
    ${PROBLEMS_TEST_INCLUDES_FILES}
    ${PROBLEMS_TEST_SOURCES_FILES}
)

set(PROBLEMS_TEST_INCLUDES
    ./core
    ./interfaces
)

set(BASE_INCLUDES_FILES
    ../Base/BaseException.h
    ../Base/NotImplementedException.h
    ../Base/core/BaseDependencies.h
    ../Base/core/BaseLogic.h
    ../Base/core/ClassType.h
    ../Base/core/ComparableComparator.h
    ../Base/core/DereferenceComparableComparator.h
    ../Base/core/DereferenceComparableComparator2.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/DereferenceEquatableComparator2.h
    ../Base/core/EquatableComparator.h
    ../Base/core/IntervalMap.h
    ../Base/core/IntervalMapIterator.h
    ../Base/core/IterableObject.h
    ../Base/core/KmpStringSearch.h
    ../Base/core/List.h
    ../Base/core/ListIterator.h
    ../Base/core/Matrix.h
    ../Base/core/Position.h
    ../Base/core/PreCompiled.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
    ../Base/core/SkipIterator.h
    ../Base/core/StringIterator.h
    ../Base/core/TwoDimensionalList.h
    ../Base/core/TwoDimensionalListIterator.h
    ../Base/interfaces/ClassTypes.h
    ../Base/interfaces/ComparatorFactory.h
    ../Base/interfaces/CompareToBuilder.h
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/Dimensions.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/EqualBuilder.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/IBuilder.h
    ../Base/interfaces/ICalculator.h
    ../Base/interfaces/IClassType.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IComparableComparator.h
    ../Base/interfaces/IEquatableComparator.h
    ../Base/interfaces/IFinder.h
    ../Base/interfaces/IHashCodeProvider.h
    ../Base/interfaces/IIntervalMap.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/IList.h
    ../Base/interfaces/IMatrix.h
    ../Base/interfaces/IReverseIterable.h
    ../Base/interfaces/IReverseIterator.h
    ../Base/interfaces/ISizableCollection.h
    ../Base/interfaces/ISkipIterator.h
    ../Base/interfaces/ITwoDimensionalList.h
    ../Base/interfaces/IValidator.h
    ../Base/interfaces/IVisitor.h
    ../Base/interfaces/Interval.h
    ../Base/interfaces/Intervals.h
    ../Base/interfaces/IterableComparator.h
    ../Base/interfaces/IteratorComparator.h
    ../Base/interfaces/LogStreamWriter.h
    ../Base/interfaces/Pair.h
    ../Base/interfaces/SharedPtr.h
    ../Base/interfaces/StringComparable.h
    ../Base/interfaces/StringEquality.h
    ../Base/interfaces/StringSearch.h
    ../Base/interfaces/Strings.h
    ../Base/interfaces/Triple.h
)

set(BASE_SOURCES_FILES
    ../Base/core/ClassType.cpp
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/EqualBuilder.cpp
    ../Base/core/KmpStringSearch.cpp
    ../Base/core/LogStreamWriter.cpp
    ../Base/core/Position.cpp
    ../Base/core/PreCompiled.cpp
    ../Base/core/SkipIterator.cpp
    ../Base/core/StringComparable.cpp
    ../Base/core/StringEquality.cpp
    ../Base/core/StringSearch.cpp
    ../Base/core/Strings.cpp
)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES}
)

set(BASE_INCLUDES
    ../Base
    ../Base/core
    ../Base/interfaces
)

add_library(Base STATIC
    ${BASE_SOURCES}
)

set(TEST_BASE_INCLUDES_FILES
    ../TestBase/TestBaseException.h
    ../TestBase/core/PreCompiled.h
    ../TestBase/interfaces/Assertion.h
)

set(TEST_BASE_SOURCES_FILES
    ../TestBase/core/Assertion.cpp
    ../TestBase/core/PreCompiled.cpp
)

set(TEST_BASE_SOURCES
    ${TEST_BASE_INCLUDES_FILES}
    ${TEST_BASE_SOURCES_FILES}
)

set(TEST_BASE_INCLUDES
    ../TestBase
    ../TestBase/core
    ../TestBase/interfaces
)

add_library(TestBase STATIC
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
)

set(UNIT_TESTING_INCLUDES_FILES
    ../UnitTesting/UnitTestingException.h
    ../UnitTesting/core/PreCompiled.h
    ../UnitTesting/core/TestRunningResult.h
    ../UnitTesting/core/TestRunningResults.h
    ../UnitTesting/core/UnitTestFunction.h
    ../UnitTesting/core/UnitTestHandler.h
    ../UnitTesting/core/UnitTestManager.h
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
    ../UnitTesting/core/PreCompiled.cpp
    ../UnitTesting/core/TestRunningResult.cpp
    ../UnitTesting/core/TestRunningResults.cpp
    ../UnitTesting/core/UnitTestBase.cpp
    ../UnitTesting/core/UnitTestHandler.cpp
    ../UnitTesting/core/UnitTestManager.cpp
)

set(UNIT_TESTING_SOURCES
    ${UNIT_TESTING_INCLUDES_FILES}
    ${UNIT_TESTING_SOURCES_FILES}
)

set(UNIT_TESTING_INCLUDES
    ../UnitTesting
    ../UnitTesting/core
    ../UnitTesting/interfaces
)

add_library(UnitTesting STATIC
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
    ${UNIT_TESTING_SOURCES}
)

set(PROBLEMS_INCLUDES_FILES
    ../Problems/ProblemException.h
    ../Problems/core/CombinationSum.h
    ../Problems/core/FlightRoutePlanner.h
    ../Problems/core/MatchingTriplets.h
    ../Problems/core/MatrixFinder.h
    ../Problems/core/MergingIntervals.h
    ../Problems/core/MinimumWindowSubstring.h
    ../Problems/core/NumberValidator.h
    ../Problems/core/PositionQueens.h
    ../Problems/core/PreCompiled.h
    ../Problems/core/WordFinder.h
    ../Problems/interfaces/ICombinationSum.h
    ../Problems/interfaces/IFlightRoutePlanner.h
    ../Problems/interfaces/IMatchingTriplets.h
    ../Problems/interfaces/IMatrixFinder.h
    ../Problems/interfaces/IMergingIntervals.h
    ../Problems/interfaces/IMinimumWindowSubstring.h
    ../Problems/interfaces/IPositionQueens.h
)

set(PROBLEMS_SOURCES_FILES
    ../Problems/core/FlightRoutePlanner.cpp
    ../Problems/core/MinimumWindowSubstring.cpp
    ../Problems/core/NumberValidator.cpp
    ../Problems/core/PositionQueens.cpp
    ../Problems/core/PreCompiled.cpp
    ../Problems/core/WordFinder.cpp
)

set(PROBLEMS_SOURCES
    ${PROBLEMS_INCLUDES_FILES}
    ${PROBLEMS_SOURCES_FILES}
)

set(PROBLEMS_INCLUDES
    ../Problems
    ../Problems/core
    ../Problems/interfaces
)

add_library(Problems STATIC
    ${BASE_SOURCES}
    ${PROBLEMS_SOURCES}
)

include_directories(ProblemsTest
    ${BASE_INCLUDES}
    ${PROBLEMS_INCLUDES}
    ${PROBLEMS_TEST_INCLUDES}
    ${TEST_BASE_INCLUDES}
    ${UNIT_TESTING_INCLUDES}
)

add_executable(ProblemsTest
    ${BASE_SOURCES}
    ${PROBLEMS_SOURCES}
    ${PROBLEMS_TEST_SOURCES}
    ${TEST_BASE_SOURCES}
    ${UNIT_TESTING_SOURCES}
)

target_link_libraries(ProblemsTest
    PRIVATE Base TestBase UnitTesting Problems
)

include_directories(
    ${BOOST_PATH}
)
