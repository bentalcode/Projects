cmake_minimum_required(VERSION 3.6)

project(Base VERSION 1.0)

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


set(BASE_INCLUDES_FILES
    ./BaseException.h
    ./NotImplementedException.h
    ./WindowsException.h
    ./core/AbstractPathBuilder.h
    ./core/AndBitOperator.h
    ./core/BaseDependencies.h
    ./core/BaseLogic.h
    ./core/Bits.h
    ./core/ClassType.h
    ./core/ClassTypes.h
    ./core/CollectionComparator.h
    ./core/Collections.h
    ./core/ComparableComparator.h
    ./core/Comparator.h
    ./core/ComparatorFactory.h
    ./core/CompareToBuilder.h
    ./core/ConsoleColorSetter.h
    ./core/Conversion.h
    ./core/DateTime.h
    ./core/DereferenceComparableComparator.h
    ./core/DereferenceComparableComparator2.h
    ./core/DereferenceEquatableComparator.h
    ./core/DereferenceEquatableComparator2.h
    ./core/Duration.h
    ./core/EqualBuilder.h
    ./core/EquatableComparator.h
    ./core/Indexes.h
    ./core/IntegerConversion.h
    ./core/Interval.h
    ./core/IntervalMap.h
    ./core/IntervalMapIterator.h
    ./core/InvertComparator.h
    ./core/IterableComparator.h
    ./core/IterableObject.h
    ./core/IteratorComparator.h
    ./core/KmpStringSearch.h
    ./core/List.h
    ./core/ListIterator.h
    ./core/ListReverseIterator.h
    ./core/LocalFreeReleaser.h
    ./core/Log.h
    ./core/LogFactory.h
    ./core/MapComparator.h
    ./core/Matrix.h
    ./core/MessageWriter.h
    ./core/NotBitOperator.h
    ./core/OrBitOperator.h
    ./core/Pair.h
    ./core/ParsingResult.h
    ./core/PathBuilder.h
    ./core/Position.h
    ./core/PreCompiled.h
    ./core/RandomGenerator.h
    ./core/Range.h
    ./core/ReferenceCount.h
    ./core/ReferenceCountHolder.h
    ./core/ResourcePathBuilder.h
    ./core/ResourceReader.h
    ./core/SetIterator.h
    ./core/SharedPtr.h
    ./core/SkipIterator.h
    ./core/SmartPointers.h
    ./core/Sorting.h
    ./core/StringComparable.h
    ./core/StringConversion.h
    ./core/StringEquality.h
    ./core/StringIterator.h
    ./core/StringSearch.h
    ./core/Strings.h
    ./core/Threads.h
    ./core/Triple.h
    ./core/TwoDimensionalVector.h
    ./core/TwoDimensionalVectorIterator.h
    ./core/VectorIterator.h
    ./core/VectorReverseIterator.h
    ./core/WindowsConsoleColorHandler.h
    ./core/WindowsDependencies.h
    ./core/WindowsErrors.h
    ./core/XorBitOperator.h
    ./interfaces/ColorType.h
    ./interfaces/IBinaryBitOperator.h
    ./interfaces/IBinaryComparator.h
    ./interfaces/IBitOperator.h
    ./interfaces/IBuilder.h
    ./interfaces/ICalculator.h
    ./interfaces/IClassType.h
    ./interfaces/ICollection.h
    ./interfaces/IComparableComparator.h
    ./interfaces/IConsoleColorHandler.h
    ./interfaces/IEquatableComparator.h
    ./interfaces/IFinder.h
    ./interfaces/IFromString.h
    ./interfaces/IHashCodeProvider.h
    ./interfaces/IIntegerConversion.h
    ./interfaces/IIntervalMap.h
    ./interfaces/IIterable.h
    ./interfaces/IIterator.h
    ./interfaces/IKeyIterable.h
    ./interfaces/IKeyReverseIterable.h
    ./interfaces/IList.h
    ./interfaces/ILog.h
    ./interfaces/ILogFactory.h
    ./interfaces/IMainParser.h
    ./interfaces/IMatch.h
    ./interfaces/IMatrix.h
    ./interfaces/IMessageWriter.h
    ./interfaces/IParser.h
    ./interfaces/IParsingResult.h
    ./interfaces/IPathBuilder.h
    ./interfaces/IRandomGenerator.h
    ./interfaces/IResourceReader.h
    ./interfaces/IReverseIterable.h
    ./interfaces/IReverseIterator.h
    ./interfaces/ISizableCollection.h
    ./interfaces/ISkipIterator.h
    ./interfaces/IStringConversion.h
    ./interfaces/IToString.h
    ./interfaces/ITransformer.h
    ./interfaces/ITwoDimensionalVector.h
    ./interfaces/IUnaryBitOperator.h
    ./interfaces/IValidator.h
    ./interfaces/IValueIterable.h
    ./interfaces/IValueReverseIterable.h
    ./interfaces/IVisitor.h
    ./interfaces/LogLevelType.h
    ./interfaces/StandardFileDescriptor.h
    ./interfaces/StringComparisonType.h
)

set(BASE_SOURCES_FILES
    ./core/AbstractPathBuilder.cpp
    ./core/AndBitOperator.cpp
    ./core/Bits.cpp
    ./core/ClassType.cpp
    ./core/Collections.cpp
    ./core/CompareToBuilder.cpp
    ./core/ConsoleColorSetter.cpp
    ./core/Conversion.cpp
    ./core/DateTime.cpp
    ./core/EqualBuilder.cpp
    ./core/Indexes.cpp
    ./core/IntegerConversion.cpp
    ./core/KmpStringSearch.cpp
    ./core/Log.cpp
    ./core/LogFactory.cpp
    ./core/MessageWriter.cpp
    ./core/NotBitOperator.cpp
    ./core/OrBitOperator.cpp
    ./core/PathBuilder.cpp
    ./core/Position.cpp
    ./core/PreCompiled.cpp
    ./core/RandomGenerator.cpp
    ./core/ResourcePathBuilder.cpp
    ./core/ResourceReader.cpp
    ./core/SkipIterator.cpp
    ./core/StringComparable.cpp
    ./core/StringConversion.cpp
    ./core/StringEquality.cpp
    ./core/StringSearch.cpp
    ./core/Strings.cpp
    ./core/Threads.cpp
    ./core/WindowsConsoleColorHandler.cpp
    ./core/WindowsErrors.cpp
    ./core/XorBitOperator.cpp
)

set(BASE_INCLUDES
    .
    ./core
    ./interfaces
)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES}
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
