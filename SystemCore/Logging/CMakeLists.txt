cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME
    Logging
)

project(Logging VERSION 1.0)

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
# CMAKE source Directory...
#
message (CMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}")

#
# Configure operating systems...
#
add_compile_definitions(WINDOWS=1)

#
# Configure boost library...
#
if (NOT $ENV{BOOST_ROOT})
    set(BOOST_PATH $ENV{BOOST_ROOT})
else()
    set(BOOST_PATH "c:\\Boost\\boost_1_78_0")
endif()


set(LOGGING_INCLUDES_FILES
    ./core/DateTimeTransformer.h
    ./core/Log.h
    ./core/LogHeader.h
    ./core/LogInformation.h
    ./core/LogLevelTransformer.h
    ./core/LogRecord.h
    ./core/LogRecordIterator.h
    ./core/LogStatistics.h
    ./core/LogTokensParser.h
    ./core/LogWriter.h
    ./core/Logger.h
    ./core/LoggerFactory.h
    ./core/LoggerImpl.h
    ./core/Loggers.h
    ./core/LoggingException.h
    ./core/SizeTTransformer.h
    ./core/StringTransformer.h
    ./core/UnsignedIntegerTransformer.h
    ./core/UnsignedLongTransformer.h
    ./interfaces/ILog.h
    ./interfaces/ILogHeader.h
    ./interfaces/ILogInformation.h
    ./interfaces/ILogRecord.h
    ./interfaces/ILogStatistics.h
    ./interfaces/ILogWriter.h
    ./interfaces/ILogger.h
    ./interfaces/ILoggerFactory.h
    ./interfaces/ILoggerImpl.h
    ./interfaces/ILoggers.h
    ./interfaces/LogLevel.h
    ./interfaces/LogParsingErrorType.h
)

set(LOGGING_SOURCES_FILES
    ./core/DateTimeTransformer.cpp
    ./core/Log.cpp
    ./core/LogHeader.cpp
    ./core/LogInformation.cpp
    ./core/LogLevelTransformer.cpp
    ./core/LogRecord.cpp
    ./core/LogRecordIterator.cpp
    ./core/LogStatistics.cpp
    ./core/LogTokensParser.cpp
    ./core/LogWriter.cpp
    ./core/Logger.cpp
    ./core/LoggerFactory.cpp
    ./core/LoggerImpl.cpp
    ./core/Loggers.cpp
    ./core/SizeTTransformer.cpp
    ./core/StringTransformer.cpp
    ./core/UnsignedIntegerTransformer.cpp
    ./core/UnsignedLongTransformer.cpp
)

set(LOGGING_INCLUDES
    ./core
    ./interfaces
)

set(LOGGING_SOURCES
    ${LOGGING_INCLUDES_FILES}
    ${LOGGING_SOURCES_FILES}
)

set(BASE_INCLUDES_FILES
    ../Base/core/AbstractPath.h
    ../Base/core/AbstractPathBuilder.h
    ../Base/core/AlmostComparator.h
    ../Base/core/AndBitOperator.h
    ../Base/core/BaseException.h
    ../Base/core/BaseLogic.h
    ../Base/core/Bits.h
    ../Base/core/ClassType.h
    ../Base/core/ClassTypes.h
    ../Base/core/CollectionComparator.h
    ../Base/core/Collections.h
    ../Base/core/ComparableComparator.h
    ../Base/core/Comparator.h
    ../Base/core/ComparatorFactory.h
    ../Base/core/CompareToBuilder.h
    ../Base/core/ConsoleColorSetter.h
    ../Base/core/DereferenceComparableComparator.h
    ../Base/core/DereferenceComparableComparator2.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/DereferenceEquatableComparator2.h
    ../Base/core/Environment.h
    ../Base/core/EqualBuilder.h
    ../Base/core/EquatableComparator.h
    ../Base/core/ErrorCodes.h
    ../Base/core/ErrorMessages.h
    ../Base/core/Indexes.h
    ../Base/core/Interval.h
    ../Base/core/IntervalMap.h
    ../Base/core/IntervalMapIterator.h
    ../Base/core/InvalidArgumentException.h
    ../Base/core/InvertComparator.h
    ../Base/core/IterableComparator.h
    ../Base/core/IterableObject.h
    ../Base/core/IteratorComparator.h
    ../Base/core/KmpStringSearch.h
    ../Base/core/List.h
    ../Base/core/ListIterator.h
    ../Base/core/ListReverseIterator.h
    ../Base/core/MapComparator.h
    ../Base/core/Matrix.h
    ../Base/core/MessageWriter.h
    ../Base/core/NotBitOperator.h
    ../Base/core/NotImplementedException.h
    ../Base/core/OperatingSystemControlSettings.h
    ../Base/core/OperatingSystemType.h
    ../Base/core/OrBitOperator.h
    ../Base/core/Pair.h
    ../Base/core/PathBuilder.h
    ../Base/core/PathDecomposition.h
    ../Base/core/Position.h
    ../Base/core/RandomGenerator.h
    ../Base/core/Range.h
    ../Base/core/ReferenceCounterHolder.h
    ../Base/core/SetIterator.h
    ../Base/core/SharedPtr.h
    ../Base/core/SkipIterator.h
    ../Base/core/Sorting.h
    ../Base/core/StringComparable.h
    ../Base/core/StringConversion.h
    ../Base/core/StringEquality.h
    ../Base/core/StringSearch.h
    ../Base/core/StringUtils.h
    ../Base/core/Strings.h
    ../Base/core/Thread.h
    ../Base/core/ToString.h
    ../Base/core/Triple.h
    ../Base/core/TwoDimensionalVector.h
    ../Base/core/TwoDimensionalVectorIterator.h
    ../Base/core/UnexpectedException.h
    ../Base/core/UnixPath.h
    ../Base/core/UnixPathBuilder.h
    ../Base/core/Uuid.h
    ../Base/core/VectorIterator.h
    ../Base/core/VectorReverseIterator.h
    ../Base/core/WindowsConsoleColorHandler.h
    ../Base/core/WindowsDefinitions.h
    ../Base/core/WindowsOperatingSystemType.h
    ../Base/core/WindowsPath.h
    ../Base/core/WindowsPathSettings.h
    ../Base/core/WindowsSystemPath.h
    ../Base/core/XorBitOperator.h
    ../Base/interfaces/ColorType.h
    ../Base/interfaces/Colors.h
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/DateTimeInterval.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/Handle.h
    ../Base/interfaces/IBinaryBitOperator.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/IBitOperator.h
    ../Base/interfaces/IBuilder.h
    ../Base/interfaces/ICalculator.h
    ../Base/interfaces/IClassType.h
    ../Base/interfaces/IClone.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IComparableComparator.h
    ../Base/interfaces/IComparatorFactory.h
    ../Base/interfaces/IConsoleColorHandler.h
    ../Base/interfaces/IEquatableComparator.h
    ../Base/interfaces/IFromString.h
    ../Base/interfaces/IHashCodeProvider.h
    ../Base/interfaces/IIntervalMap.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/IKeyIterable.h
    ../Base/interfaces/IKeyReverseIterable.h
    ../Base/interfaces/IList.h
    ../Base/interfaces/IMatch.h
    ../Base/interfaces/IMatrix.h
    ../Base/interfaces/IMessageWriter.h
    ../Base/interfaces/IOperatingSystemControlSettings.h
    ../Base/interfaces/IOperatingSystemPathSettings.h
    ../Base/interfaces/IOperatingSystemType.h
    ../Base/interfaces/IPath.h
    ../Base/interfaces/IPathBuilder.h
    ../Base/interfaces/IPathDecomposition.h
    ../Base/interfaces/IPosition.h
    ../Base/interfaces/IRandomGenerator.h
    ../Base/interfaces/IResourceReader.h
    ../Base/interfaces/IReverseIterable.h
    ../Base/interfaces/IReverseIterator.h
    ../Base/interfaces/ISizableCollection.h
    ../Base/interfaces/ISkipIterator.h
    ../Base/interfaces/IStringConversion.h
    ../Base/interfaces/IThread.h
    ../Base/interfaces/IToString.h
    ../Base/interfaces/ITwoDimensionalVector.h
    ../Base/interfaces/IUnaryBitOperator.h
    ../Base/interfaces/IUuid.h
    ../Base/interfaces/IValidator.h
    ../Base/interfaces/IValueIterable.h
    ../Base/interfaces/IValueReverseIterable.h
    ../Base/interfaces/IVisitor.h
    ../Base/interfaces/OperatingSystemType.h
    ../Base/interfaces/ReferenceCounter.h
    ../Base/interfaces/ReferenceCounterHolder.h
    ../Base/interfaces/SmartPointers.h
    ../Base/interfaces/StandardFileDescriptor.h
    ../Base/interfaces/StringComparisonType.h
    ../Base/interfaces/TimeUnit.h
    ../Base/interfaces/TimeUtils.h
    ../Base/interfaces/WinHandle.h
    ../Base/interfaces/WindowsSystemPathType.h
)

set(BASE_SOURCES_FILES
    ../Base/core/AbstractPath.cpp
    ../Base/core/AbstractPathBuilder.cpp
    ../Base/core/AndBitOperator.cpp
    ../Base/core/Bits.cpp
    ../Base/core/ClassType.cpp
    ../Base/core/Collections.cpp
    ../Base/core/ComparatorFactory.cpp
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/ConsoleColorSetter.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/DateTimeInterval.cpp
    ../Base/core/Environment.cpp
    ../Base/core/EqualBuilder.cpp
    ../Base/core/ErrorCodes.cpp
    ../Base/core/ErrorMessages.cpp
    ../Base/core/KmpStringSearch.cpp
    ../Base/core/MessageWriter.cpp
    ../Base/core/NotBitOperator.cpp
    ../Base/core/OperatingSystemControlSettings.cpp
    ../Base/core/OrBitOperator.cpp
    ../Base/core/PathBuilder.cpp
    ../Base/core/PathDecomposition.cpp
    ../Base/core/RandomGenerator.cpp
    ../Base/core/ReferenceCounter.cpp
    ../Base/core/SkipIterator.cpp
    ../Base/core/StringComparable.cpp
    ../Base/core/StringConversion.cpp
    ../Base/core/StringEquality.cpp
    ../Base/core/StringSearch.cpp
    ../Base/core/StringUtils.cpp
    ../Base/core/Strings.cpp
    ../Base/core/Tests.cpp
    ../Base/core/Thread.cpp
    ../Base/core/TimeUnit.cpp
    ../Base/core/TimeUtils.cpp
    ../Base/core/ToString.cpp
    ../Base/core/UnixPath.cpp
    ../Base/core/UnixPathBuilder.cpp
    ../Base/core/Uuid.cpp
    ../Base/core/WindowsConsoleColorHandler.cpp
    ../Base/core/WindowsOperatingSystemType.cpp
    ../Base/core/WindowsPath.cpp
    ../Base/core/WindowsPathSettings.cpp
    ../Base/core/WindowsSystemPath.cpp
    ../Base/core/XorBitOperator.cpp
)

set(BASE_INCLUDES
    ../Base/core
    ../Base/interfaces
)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES}
)

add_library(Base STATIC
    ${BASE_SOURCES}
)

target_link_libraries(Base
    PRIVATE 
)

set(TABULAR_DATA_INCLUDES_FILES
    ../TabularData/core/Event.h
    ../TabularData/core/EventLog.h
    ../TabularData/core/File.h
    ../TabularData/core/FileInformation.h
    ../TabularData/core/FileLineIterator.h
    ../TabularData/core/FileWriter.h
    ../TabularData/core/Record.h
    ../TabularData/core/TabularDataException.h
    ../TabularData/core/TabularFile.h
    ../TabularData/core/TabularFileInformation.h
    ../TabularData/core/TabularHeader.h
    ../TabularData/core/TabularHeaderParser.h
    ../TabularData/core/TabularRecord.h
    ../TabularData/core/TabularRecordIterator.h
    ../TabularData/core/TabularRecordParser.h
    ../TabularData/core/TabularTable.h
    ../TabularData/core/TabularTableWriter.h
    ../TabularData/core/TokensParser.h
    ../TabularData/interfaces/EventType.h
    ../TabularData/interfaces/IEvent.h
    ../TabularData/interfaces/IEventLog.h
    ../TabularData/interfaces/IFile.h
    ../TabularData/interfaces/IFileInformation.h
    ../TabularData/interfaces/IRecord.h
    ../TabularData/interfaces/ITabularFile.h
    ../TabularData/interfaces/ITabularFileInformation.h
    ../TabularData/interfaces/ITabularHeader.h
    ../TabularData/interfaces/ITabularHeaderParser.h
    ../TabularData/interfaces/ITabularRecord.h
    ../TabularData/interfaces/ITabularRecordIterator.h
    ../TabularData/interfaces/ITabularRecordParser.h
    ../TabularData/interfaces/ITabularTable.h
    ../TabularData/interfaces/ITabularTableWriter.h
    ../TabularData/interfaces/ITokensParser.h
    ../TabularData/interfaces/IValueTransformer.h
    ../TabularData/interfaces/IWriter.h
    ../TabularData/interfaces/ParsingPolicyType.h
)

set(TABULAR_DATA_SOURCES_FILES
    ../TabularData/core/Event.cpp
    ../TabularData/core/EventLog.cpp
    ../TabularData/core/File.cpp
    ../TabularData/core/FileInformation.cpp
    ../TabularData/core/FileLineIterator.cpp
    ../TabularData/core/FileWriter.cpp
    ../TabularData/core/Record.cpp
    ../TabularData/core/TabularFile.cpp
    ../TabularData/core/TabularFileInformation.cpp
    ../TabularData/core/TabularHeader.cpp
    ../TabularData/core/TabularHeaderParser.cpp
    ../TabularData/core/TabularRecord.cpp
    ../TabularData/core/TabularRecordIterator.cpp
    ../TabularData/core/TabularRecordParser.cpp
    ../TabularData/core/TabularTable.cpp
    ../TabularData/core/TabularTableWriter.cpp
    ../TabularData/core/TokensParser.cpp
)

set(TABULAR_DATA_INCLUDES
    ../TabularData/core
    ../TabularData/interfaces
)

set(TABULAR_DATA_SOURCES
    ${TABULAR_DATA_INCLUDES_FILES}
    ${TABULAR_DATA_SOURCES_FILES}
)

add_library(TabularData STATIC
    ${TABULAR_DATA_SOURCES}
)

target_link_libraries(TabularData
    PRIVATE Base
)

include_directories(Logging
    ${BASE_INCLUDES}
    ${LOGGING_INCLUDES}
    ${TABULAR_DATA_INCLUDES}
)

add_library(Logging STATIC
    ${LOGGING_SOURCES}
)

target_link_libraries(Logging
    PRIVATE Base TabularData
)

include_directories(
    ${BOOST_PATH}
)

#
# Configure file system dependencies...
#
target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    stdc++fs)

