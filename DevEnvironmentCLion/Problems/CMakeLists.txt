cmake_minimum_required(VERSION 3.13)

project(Problems VERSION 1.0)

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

set(PROBLEMS_INCLUDES_FILES
    ./ProblemException.h
    ./core/CombinationSum.h
    ./core/MatchingTriplets.h
    ./core/MatrixFinder.h
    ./core/MergingIntervals.h
    ./core/MinimumWindowSubstring.h
    ./core/NumberValidator.h
    ./core/PositionQueens.h
    ./core/PreCompiled.h
    ./core/WordFinder.h
    ./interfaces/ICombinationSum.h
    ./interfaces/IMatchingTriplets.h
    ./interfaces/IMatrixFinder.h
    ./interfaces/IMergingIntervals.h
    ./interfaces/IMinimumWindowSubstring.h
    ./interfaces/IPositionQueens.h
)

set(PROBLEMS_SOURCES_FILES
    ./core/MinimumWindowSubstring.cpp
    ./core/NumberValidator.cpp
    ./core/PositionQueens.cpp
    ./core/PreCompiled.cpp
    ./core/WordFinder.cpp
)

set(PROBLEMS_SOURCES
    ${PROBLEMS_INCLUDES_FILES}
    ${PROBLEMS_SOURCES_FILES}
)

set(PROBLEMS_INCLUDES
    .
    ./core
    ./interfaces
)

set(BASE_INCLUDES_FILES
    ../Base/BaseException.h
    ../Base/core/BaseDependencies.h
    ../Base/core/BaseLogic.h
    ../Base/core/ComparableComparator.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/EquatableComparator.h
    ../Base/core/IntervalMap.h
    ../Base/core/IntervalMapIterator.h
    ../Base/core/List.h
    ../Base/core/ListIterator.h
    ../Base/core/Matrix.h
    ../Base/core/Position.h
    ../Base/core/PreCompiled.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
    ../Base/core/StringIterator.h
    ../Base/core/TwoDimensionalList.h
    ../Base/core/TwoDimensionalListIterator.h
    ../Base/interfaces/ComparatorFactory.h
    ../Base/interfaces/CompareToBuilder.h
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/EqualBuilder.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/ICalculator.h
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
    ../Base/interfaces/ISizableCollection.h
    ../Base/interfaces/ITwoDimensionalList.h
    ../Base/interfaces/IValidator.h
    ../Base/interfaces/Interval.h
    ../Base/interfaces/Intervals.h
    ../Base/interfaces/IterableComparator.h
    ../Base/interfaces/IteratorComparator.h
    ../Base/interfaces/LogStreamWriter.h
    ../Base/interfaces/Pair.h
    ../Base/interfaces/SharedPtr.h
    ../Base/interfaces/Strings.h
    ../Base/interfaces/Triple.h
)

set(BASE_SOURCES_FILES
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/EqualBuilder.cpp
    ../Base/core/LogStreamWriter.cpp
    ../Base/core/Position.cpp
    ../Base/core/PreCompiled.cpp
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

include_directories(Problems
    ${BASE_INCLUDES}
    ${PROBLEMS_INCLUDES}
)

add_library(Problems STATIC
    ${BASE_SOURCES}
    ${PROBLEMS_SOURCES}
)

include_directories(
    ${BOOST_PATH}
)
