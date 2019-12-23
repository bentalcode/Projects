cmake_minimum_required(VERSION 3.13)
project(Problems VERSION 1.0)

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
    ../Base/interfaces/ComparatorFactory.h
    ../Base/interfaces/CompareToBuilder.h
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/EqualBuilder.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IComparableComparator.h
    ../Base/interfaces/IEquatableComparator.h
    ../Base/interfaces/IHashCodeProvider.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/ISizebleCollection.h
    ../Base/interfaces/IterableComparator.h
    ../Base/interfaces/IteratorComparator.h
    ../Base/interfaces/ITwoDimensionalList.h
    ../Base/interfaces/LogStreamWriter.h
    ../Base/interfaces/Pair.h
    ../Base/interfaces/SharedPtr.h
    ../Base/interfaces/Triple.h
    ../Base/core/BaseDependencies.h
    ../Base/core/BaseLogic.h
    ../Base/core/ComparableComparator.h
    ../Base/core/EquatableComparator.h
    ../Base/core/PreCompiled.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
    ../Base/core/TwoDimensionalList.h
    ../Base/BaseException.h)

set(BASE_SOURCES_FILES
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/EqualBuilder.cpp
    ../Base/core/LogStreamWriter.cpp
    ../Base/core/PreCompiled.cpp)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES})

set(BASE_INCLUDES
    ../Base
    ../Base/interfaces
    ../Base/core)

#
# Problems Library...
#
set(PROBLEMS_INCLUDES_FILES
    ./interfaces/ICombinationSum.h
    ./interfaces/IMatchingTriplets.h
    ./interface/IPositionQueens.h
    ./core/CombinationSum.h
    ./core/MatchingTriplets.h
    ./core/PreCompiled.h
    ./ProblemException.h)

set(PROBLEMS_SOURCES_FILES
    ./core/PositionQueens.cpp
    ./core/PreCompiled.cpp)

set(PROBLEMS_SOURCES
    ${PROBLEMS_INCLUDES_FILES}
    ${PROBLEMS_SOURCES_FILES})

set(PROBLEMS_INCLUDES
    .
    interfaces
    core)

include_directories(
    ${PROBLEMS_INCLUDES}
    ${BASE_INCLUDES}
    ${BOOT_ROOT})

add_library(Problems ${PROBLEMS_SOURCES} ${BASE_SOURCES})
