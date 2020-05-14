cmake_minimum_required(VERSION 3.13)
project(Base VERSION 1.0)

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
    ./interfaces/Interval.h
    ./interfaces/Intervals.h
    ./interfaces/ISizebleCollection.h
    ./interfaces/IterableComparator.h
    ./interfaces/IteratorComparator.h
    ./interfaces/ITwoDimensionalList.h
    ./interfaces/IValidator.h
    ./interfaces/LogStreamWriter.h
    ./interfaces/Pair.h
    ./interfaces/SharedPtr.h
    ./interfaces/Strings.h
    ./interfaces/Triple.h
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
    ./BaseException.h)

set(BASE_SOURCES_FILES
    ./core/CompareToBuilder.cpp
    ./core/DateTime.cpp
    ./core/EqualBuilder.cpp
    ./core/LogStreamWriter.cpp
    ./core/Position.cpp
    ./core/PreCompiled.cpp)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES})

set(BASE_INCLUDES
    .
    interfaces
    core)

include_directories(
    ${BASE_INCLUDES}
    ${BOOT_ROOT})

add_library(Base ${BASE_SOURCES})
