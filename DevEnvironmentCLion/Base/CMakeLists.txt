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
    ./core/BaseDependencies.h
    ./core/BaseLogic.h
    ./core/ComparableComparator.h
    ./core/DereferenceEquatableComparator.h
    ./core/EquatableComparator.h
    ./core/List.h
    ./core/ListIterator.h
    ./core/Matrix.h
    ./core/Position.h
    ./core/PreCompiled.h
    ./core/ReferenceCount.h
    ./core/ReferenceCountHolder.h
    ./core/StringIterator.h
    ./core/TwoDimensionalList.h
    ./core/TwoDimensionalListIterator.h
    ./interfaces/ComparatorFactory.h
    ./interfaces/CompareToBuilder.h
    ./interfaces/DateTime.h
    ./interfaces/Duration.h
    ./interfaces/EqualBuilder.h
    ./interfaces/IBinaryComparator.h
    ./interfaces/ICalculator.h
    ./interfaces/ICollection.h
    ./interfaces/IComparableComparator.h
    ./interfaces/IEquatableComparator.h
    ./interfaces/IFinder.h
    ./interfaces/IHashCodeProvider.h
    ./interfaces/IIterable.h
    ./interfaces/IIterator.h
    ./interfaces/IList.h
    ./interfaces/IMatrix.h
    ./interfaces/ISizebleCollection.h
    ./interfaces/ITwoDimensionalList.h
    ./interfaces/IValidator.h
    ./interfaces/Interval.h
    ./interfaces/Intervals.h
    ./interfaces/IterableComparator.h
    ./interfaces/IteratorComparator.h
    ./interfaces/LogStreamWriter.h
    ./interfaces/Pair.h
    ./interfaces/SharedPtr.h
    ./interfaces/Strings.h
    ./interfaces/Triple.h
)

set(BASE_SOURCES_FILES
    ./core/CompareToBuilder.cpp
    ./core/DateTime.cpp
    ./core/EqualBuilder.cpp
    ./core/LogStreamWriter.cpp
    ./core/Position.cpp
    ./core/PreCompiled.cpp
)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES}
)

set(BASE_INCLUDES
    ./core
    ./interfaces
    .
)

include_directories(
    ${BASE_INCLUDES}
)

add_library(Base ${BASE_SOURCES})

include_directories(
    ${BOOST_PATH}
)

