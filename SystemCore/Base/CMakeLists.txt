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
    ./core/BaseException.h
    ./core/ErrorCodes.h
    ./core/ErrorMessages.h
    ./core/Indexes.h
    ./core/NotImplementedException.h
    ./core/ReferenceCounterHolder.h
    ./core/StringUtils.h
    ./core/ToString.h
    ./core/Uuid.h
    ./interfaces/Colors.h
    ./interfaces/DateTime.h
    ./interfaces/Duration.h
    ./interfaces/IBinaryComparator.h
    ./interfaces/IClone.h
    ./interfaces/IComparatorFactory.h
    ./interfaces/IEquatableComparator.h
    ./interfaces/IHashCodeProvider.h
    ./interfaces/IIterable.h
    ./interfaces/IIterator.h
    ./interfaces/IToString.h
    ./interfaces/IUuid.h
    ./interfaces/ReferenceCounter.h
    ./interfaces/ReferenceCounterHolder.h
    ./interfaces/SmartPointers.h
    ./interfaces/TimeUnit.h
    ./interfaces/TimeUtils.h
)

set(BASE_SOURCES_FILES
    ./core/DateTime.cpp
    ./core/ErrorCodes.cpp
    ./core/ErrorMessages.cpp
    ./core/ReferenceCounter.cpp
    ./core/StringUtils.cpp
    ./core/TimeUnit.cpp
    ./core/TimeUtils.cpp
    ./core/ToString.cpp
    ./core/Uuid.cpp
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
