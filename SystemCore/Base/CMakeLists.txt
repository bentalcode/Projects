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
    ./core/BaseException.h
    ./core/ErrorCodes.h
    ./core/ErrorMessages.h
    ./core/NotImplementedException.h
)

set(BASE_SOURCES_FILES
    ./core/ErrorCodes.cpp
    ./core/ErrorMessages.cpp
)

set(BASE_INCLUDES
    ./core
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
