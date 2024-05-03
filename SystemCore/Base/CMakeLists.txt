cmake_minimum_required(VERSION 3.6)

project(Base VERSION 1.0)

set(CMAKE_CXX_STANDARD
    14
)
set(RESOURCES_DIRECTORY_NAME
    resources
)


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


set(BASE_INCLUDES_FILES
    ./core/AbstractPath.h
    ./core/AbstractPathBuilder.h
    ./core/AlmostComparator.h
    ./core/AndBitOperator.h
    ./core/BaseException.h
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
    ./core/DereferenceComparableComparator.h
    ./core/DereferenceComparableComparator2.h
    ./core/DereferenceEquatableComparator.h
    ./core/DereferenceEquatableComparator2.h
    ./core/Environment.h
    ./core/EqualBuilder.h
    ./core/EquatableComparator.h
    ./core/ErrorCodes.h
    ./core/ErrorMessages.h
    ./core/Indexes.h
    ./core/Interval.h
    ./core/IntervalMap.h
    ./core/IntervalMapIterator.h
    ./core/InvalidArgumentException.h
    ./core/InvertComparator.h
    ./core/IterableComparator.h
    ./core/IterableObject.h
    ./core/IteratorComparator.h
    ./core/KmpStringSearch.h
    ./core/List.h
    ./core/ListIterator.h
    ./core/ListReverseIterator.h
    ./core/MapComparator.h
    ./core/Matrix.h
    ./core/MessageWriter.h
    ./core/NotBitOperator.h
    ./core/NotImplementedException.h
    ./core/OperatingSystemControlSettings.h
    ./core/OperatingSystemType.h
    ./core/OrBitOperator.h
    ./core/Pair.h
    ./core/PathBuilder.h
    ./core/PathDecomposition.h
    ./core/RandomGenerator.h
    ./core/Range.h
    ./core/ReferenceCounterHolder.h
    ./core/SetIterator.h
    ./core/SharedPtr.h
    ./core/SkipIterator.h
    ./core/Sorting.h
    ./core/StringComparable.h
    ./core/StringConversion.h
    ./core/StringEquality.h
    ./core/StringSearch.h
    ./core/StringUtils.h
    ./core/Strings.h
    ./core/Thread.h
    ./core/ToString.h
    ./core/Triple.h
    ./core/TwoDimensionalVector.h
    ./core/TwoDimensionalVectorIterator.h
    ./core/UnexpectedException.h
    ./core/UnixPath.h
    ./core/UnixPathBuilder.h
    ./core/Uuid.h
    ./core/VectorIterator.h
    ./core/VectorReverseIterator.h
    ./core/WindowsConsoleColorHandler.h
    ./core/WindowsDefinitions.h
    ./core/WindowsOperatingSystemType.h
    ./core/WindowsPath.h
    ./core/WindowsPathSettings.h
    ./core/WindowsSystemPath.h
    ./core/XorBitOperator.h
    ./interfaces/ColorType.h
    ./interfaces/Colors.h
    ./interfaces/DateTime.h
    ./interfaces/DateTimeInterval.h
    ./interfaces/Duration.h
    ./interfaces/Handle.h
    ./interfaces/IBinaryBitOperator.h
    ./interfaces/IBinaryComparator.h
    ./interfaces/IBitOperator.h
    ./interfaces/IBuilder.h
    ./interfaces/ICalculator.h
    ./interfaces/IClassType.h
    ./interfaces/IClone.h
    ./interfaces/ICollection.h
    ./interfaces/IComparableComparator.h
    ./interfaces/IComparatorFactory.h
    ./interfaces/IConsoleColorHandler.h
    ./interfaces/IEquatableComparator.h
    ./interfaces/IFromString.h
    ./interfaces/IHashCodeProvider.h
    ./interfaces/IIntervalMap.h
    ./interfaces/IIterable.h
    ./interfaces/IIterator.h
    ./interfaces/IKeyIterable.h
    ./interfaces/IKeyReverseIterable.h
    ./interfaces/IList.h
    ./interfaces/IMatch.h
    ./interfaces/IMatrix.h
    ./interfaces/IMessageWriter.h
    ./interfaces/IOperatingSystemControlSettings.h
    ./interfaces/IOperatingSystemPathSettings.h
    ./interfaces/IOperatingSystemType.h
    ./interfaces/IPath.h
    ./interfaces/IPathBuilder.h
    ./interfaces/IPathDecomposition.h
    ./interfaces/IRandomGenerator.h
    ./interfaces/IResourceReader.h
    ./interfaces/IReverseIterable.h
    ./interfaces/IReverseIterator.h
    ./interfaces/ISizableCollection.h
    ./interfaces/ISkipIterator.h
    ./interfaces/IStringConversion.h
    ./interfaces/IThread.h
    ./interfaces/IToString.h
    ./interfaces/ITwoDimensionalVector.h
    ./interfaces/IUnaryBitOperator.h
    ./interfaces/IUuid.h
    ./interfaces/IValidator.h
    ./interfaces/IValueIterable.h
    ./interfaces/IValueReverseIterable.h
    ./interfaces/IVisitor.h
    ./interfaces/OperatingSystemType.h
    ./interfaces/Position.h
    ./interfaces/ReferenceCounter.h
    ./interfaces/ReferenceCounterHolder.h
    ./interfaces/SmartPointers.h
    ./interfaces/StandardFileDescriptor.h
    ./interfaces/StringComparisonType.h
    ./interfaces/TimeUnit.h
    ./interfaces/TimeUtils.h
    ./interfaces/WinHandle.h
    ./interfaces/WindowsSystemPathType.h
)

set(BASE_SOURCES_FILES
    ./core/AbstractPath.cpp
    ./core/AbstractPathBuilder.cpp
    ./core/AndBitOperator.cpp
    ./core/Bits.cpp
    ./core/ClassType.cpp
    ./core/Collections.cpp
    ./core/ComparatorFactory.cpp
    ./core/CompareToBuilder.cpp
    ./core/ConsoleColorSetter.cpp
    ./core/DateTime.cpp
    ./core/Environment.cpp
    ./core/EqualBuilder.cpp
    ./core/ErrorCodes.cpp
    ./core/ErrorMessages.cpp
    ./core/KmpStringSearch.cpp
    ./core/MessageWriter.cpp
    ./core/NotBitOperator.cpp
    ./core/OperatingSystemControlSettings.cpp
    ./core/OrBitOperator.cpp
    ./core/PathBuilder.cpp
    ./core/PathDecomposition.cpp
    ./core/RandomGenerator.cpp
    ./core/ReferenceCounter.cpp
    ./core/SkipIterator.cpp
    ./core/StringComparable.cpp
    ./core/StringConversion.cpp
    ./core/StringEquality.cpp
    ./core/StringSearch.cpp
    ./core/StringUtils.cpp
    ./core/Strings.cpp
    ./core/Tests.cpp
    ./core/Thread.cpp
    ./core/TimeUnit.cpp
    ./core/TimeUtils.cpp
    ./core/ToString.cpp
    ./core/UnixPath.cpp
    ./core/UnixPathBuilder.cpp
    ./core/Uuid.cpp
    ./core/WindowsConsoleColorHandler.cpp
    ./core/WindowsOperatingSystemType.cpp
    ./core/WindowsPath.cpp
    ./core/WindowsPathSettings.cpp
    ./core/WindowsSystemPath.cpp
    ./core/XorBitOperator.cpp
)

set(BASE_INCLUDES
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
