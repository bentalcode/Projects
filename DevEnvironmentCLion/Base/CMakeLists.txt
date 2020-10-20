cmake_minimum_required(VERSION 3.13)

project(Base VERSION 1.0)

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

set(BASE_INCLUDES_FILES
    ./BaseException.h
    ./NotImplementedException.h
    ./core/AndBitOperator.h
    ./core/BaseDependencies.h
    ./core/BaseLogic.h
    ./core/ClassType.h
    ./core/ComparableComparator.h
    ./core/Comparator.h
    ./core/Conversion.h
    ./core/DereferenceComparableComparator.h
    ./core/DereferenceComparableComparator2.h
    ./core/DereferenceEquatableComparator.h
    ./core/DereferenceEquatableComparator2.h
    ./core/EquatableComparator.h
    ./core/IntervalMap.h
    ./core/IntervalMapIterator.h
    ./core/InvertComparator.h
    ./core/IterableObject.h
    ./core/KmpStringSearch.h
    ./core/List.h
    ./core/ListIterator.h
    ./core/ListReverseIterator.h
    ./core/Matrix.h
    ./core/NotBitOperator.h
    ./core/OrBitOperator.h
    ./core/ParsingResult.h
    ./core/Position.h
    ./core/PreCompiled.h
    ./core/RandomGenerator.h
    ./core/ReferenceCount.h
    ./core/ReferenceCountHolder.h
    ./core/SkipIterator.h
    ./core/StringConversion.h
    ./core/StringIterator.h
    ./core/TwoDimensionalVector.h
    ./core/TwoDimensionalVectorIterator.h
    ./core/VectorIterator.h
    ./core/VectorReverseIterator.h
    ./core/XorBitOperator.h
    ./interfaces/Bits.h
    ./interfaces/ClassTypes.h
    ./interfaces/ComparatorFactory.h
    ./interfaces/CompareToBuilder.h
    ./interfaces/DateTime.h
    ./interfaces/Dimensions.h
    ./interfaces/Duration.h
    ./interfaces/EqualBuilder.h
    ./interfaces/IBinaryBitOperator.h
    ./interfaces/IBinaryComparator.h
    ./interfaces/IBitOperator.h
    ./interfaces/IBuilder.h
    ./interfaces/ICalculator.h
    ./interfaces/IClassType.h
    ./interfaces/ICollection.h
    ./interfaces/IComparableComparator.h
    ./interfaces/IEquatableComparator.h
    ./interfaces/IFinder.h
    ./interfaces/IHashCodeProvider.h
    ./interfaces/IIntervalMap.h
    ./interfaces/IIterable.h
    ./interfaces/IIterator.h
    ./interfaces/IKeyIterable.h
    ./interfaces/IKeyReverseIterable.h
    ./interfaces/IList.h
    ./interfaces/IMainParser.h
    ./interfaces/IMatch.h
    ./interfaces/IMatrix.h
    ./interfaces/IParser.h
    ./interfaces/IParsingResult.h
    ./interfaces/IRandomGenerator.h
    ./interfaces/IReverseIterable.h
    ./interfaces/IReverseIterator.h
    ./interfaces/ISizableCollection.h
    ./interfaces/ISkipIterator.h
    ./interfaces/IStringConversion.h
    ./interfaces/ITwoDimensionalVector.h
    ./interfaces/IUnaryBitOperator.h
    ./interfaces/IValidator.h
    ./interfaces/IValueIterable.h
    ./interfaces/IValueReverseIterable.h
    ./interfaces/IVisitor.h
    ./interfaces/Indexes.h
    ./interfaces/Interval.h
    ./interfaces/Intervals.h
    ./interfaces/IterableComparator.h
    ./interfaces/IteratorComparator.h
    ./interfaces/LogStreamWriter.h
    ./interfaces/Pair.h
    ./interfaces/Range.h
    ./interfaces/SharedPtr.h
    ./interfaces/StringComparable.h
    ./interfaces/StringEquality.h
    ./interfaces/StringSearch.h
    ./interfaces/Strings.h
    ./interfaces/Threads.h
    ./interfaces/Triple.h
)

set(BASE_SOURCES_FILES
    ./core/AndBitOperator.cpp
    ./core/Bits.cpp
    ./core/ClassType.cpp
    ./core/CompareToBuilder.cpp
    ./core/Conversion.cpp
    ./core/DateTime.cpp
    ./core/EqualBuilder.cpp
    ./core/Indexes.cpp
    ./core/KmpStringSearch.cpp
    ./core/LogStreamWriter.cpp
    ./core/NotBitOperator.cpp
    ./core/OrBitOperator.cpp
    ./core/Position.cpp
    ./core/PreCompiled.cpp
    ./core/RandomGenerator.cpp
    ./core/SkipIterator.cpp
    ./core/StringComparable.cpp
    ./core/StringConversion.cpp
    ./core/StringEquality.cpp
    ./core/StringSearch.cpp
    ./core/Strings.cpp
    ./core/Threads.cpp
    ./core/XorBitOperator.cpp
)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES}
)

set(BASE_INCLUDES
    .
    ./core
    ./interfaces
)

include_directories(Base
    ${BASE_INCLUDES}
)

add_library(Base STATIC
    ${BASE_SOURCES}
)

include_directories(
    ${BOOST_PATH}
)
