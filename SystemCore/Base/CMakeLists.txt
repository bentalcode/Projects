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
    ./core/AlmostComparator.h
    ./core/AndBitOperator.h
    ./core/BaseException.h
    ./core/Bits.h
    ./core/ClassType.h
    ./core/ClassTypes.h
    ./core/CollectionComparator.h
    ./core/ComparatorFactory.h
    ./core/ErrorCodes.h
    ./core/ErrorMessages.h
    ./core/Indexes.h
    ./core/IterableComparator.h
    ./core/List.h
    ./core/ListIterator.h
    ./core/ListReverseIterator.h
    ./core/NotBitOperator.h
    ./core/NotImplementedException.h
    ./core/ReferenceCounterHolder.h
    ./core/SetIterator.h
    ./core/SharedPtr.h
    ./core/SkipIterator.h
    ./core/StringComparable.h
    ./core/StringEquality.h
    ./core/StringSearch.h
    ./core/StringUtils.h
    ./core/Strings.h
    ./core/ToString.h
    ./core/TwoDimensionalVector.h
    ./core/TwoDimensionalVectorIterator.h
    ./core/UnexpectedException.h
    ./core/Uuid.h
    ./core/VectorIterator.h
    ./core/VectorReverseIterator.h
    ./core/XorBitOperator.h
    ./interfaces/Colors.h
    ./interfaces/DateTime.h
    ./interfaces/DateTimeInterval.h
    ./interfaces/Duration.h
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
    ./interfaces/IEquatableComparator.h
    ./interfaces/IHashCodeProvider.h
    ./interfaces/IIterable.h
    ./interfaces/IIterator.h
    ./interfaces/IList.h
    ./interfaces/IRandomGenerator.h
    ./interfaces/IResourceReader.h
    ./interfaces/IReverseIterable.h
    ./interfaces/IReverseIterator.h
    ./interfaces/ISizableCollection.h
    ./interfaces/ISkipIterator.h
    ./interfaces/IToString.h
    ./interfaces/ITwoDimensionalVector.h
    ./interfaces/IUnaryBitOperator.h
    ./interfaces/IUuid.h
    ./interfaces/IValueIterable.h
    ./interfaces/IValueReverseIterable.h
    ./interfaces/IVisitor.h
    ./interfaces/ReferenceCounter.h
    ./interfaces/ReferenceCounterHolder.h
    ./interfaces/SmartPointers.h
    ./interfaces/TimeUnit.h
    ./interfaces/TimeUtils.h
)

set(BASE_SOURCES_FILES
    ./core/AndBitOperator.cpp
    ./core/Bits.cpp
    ./core/ClassType.cpp
    ./core/ComparatorFactory.cpp
    ./core/DateTime.cpp
    ./core/ErrorCodes.cpp
    ./core/ErrorMessages.cpp
    ./core/NotBitOperator.cpp
    ./core/ReferenceCounter.cpp
    ./core/SkipIterator.cpp
    ./core/StringComparable.cpp
    ./core/StringEquality.cpp
    ./core/StringSearch.cpp
    ./core/StringUtils.cpp
    ./core/Strings.cpp
    ./core/Tests.cpp
    ./core/TimeUnit.cpp
    ./core/TimeUtils.cpp
    ./core/ToString.cpp
    ./core/Uuid.cpp
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
