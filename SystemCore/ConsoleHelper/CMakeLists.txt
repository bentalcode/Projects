cmake_minimum_required(VERSION 3.6)

project(ConsoleHelper VERSION 1.0)

set(CMAKE_CXX_STANDARD
    14
)
set(RESOURCES_DIRECTORY_NAME
    resources
)

#
# Configure build properties...
#
set(VERSION_MAJOR "1")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")


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


set(CONSOLE_HELPER_INCLUDES_FILES
    ./core/ConsoleHelper.h
    ./core/ConsoleHelperConstants.h
    ./core/ConsoleHelperException.h
    ./core/ConsoleHelperManifest.h
    ./core/ConsoleHelperParameters.h
    ./interfaces/IConsoleHelper.h
    ./interfaces/IConsoleHelperParameters.h
)

set(CONSOLE_HELPER_SOURCES_FILES
    ./core/ConsoleHelper.cpp
    ./core/ConsoleHelperConstants.cpp
    ./core/ConsoleHelperManifest.cpp
    ./core/ConsoleHelperParameters.cpp
    ./main.cpp
)

set(CONSOLE_HELPER_INCLUDES
    ./core
    ./interfaces
)

set(CONSOLE_HELPER_SOURCES
    ${CONSOLE_HELPER_INCLUDES_FILES}
    ${CONSOLE_HELPER_SOURCES_FILES}
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
    ../Base/interfaces/Position.h
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

set(COMMAND_INCLUDES_FILES
    ../Command/core/AbstractCommand.h
    ../Command/core/CommandConstants.h
    ../Command/core/CommandException.h
    ../Command/core/CommandHandler.h
    ../Command/core/CommandHelpMetadata.h
    ../Command/core/CommandManifest.h
    ../Command/core/CommandMessageWriter.h
    ../Command/core/CommandParameters.h
    ../Command/core/CommandParser.h
    ../Command/core/IndexedParameterMetadata.h
    ../Command/core/InputParameters.h
    ../Command/core/NamedParameterMetadata.h
    ../Command/core/NamedParameterParser.h
    ../Command/core/Parameter.h
    ../Command/core/ParameterMetadata.h
    ../Command/core/ParameterSet.h
    ../Command/core/ParameterSetMetadata.h
    ../Command/core/ParameterSetParser.h
    ../Command/core/ParsingResult.h
    ../Command/core/ProcessInformation.h
    ../Command/interfaces/ICommand.h
    ../Command/interfaces/ICommandHandler.h
    ../Command/interfaces/ICommandHelpMetadata.h
    ../Command/interfaces/ICommandManifest.h
    ../Command/interfaces/ICommandMessageWriter.h
    ../Command/interfaces/ICommandParameters.h
    ../Command/interfaces/IIndexedParameterMetadata.h
    ../Command/interfaces/IInputParameters.h
    ../Command/interfaces/IMainParser.h
    ../Command/interfaces/INamedParameterMetadata.h
    ../Command/interfaces/IParameter.h
    ../Command/interfaces/IParameterMetadata.h
    ../Command/interfaces/IParameterSet.h
    ../Command/interfaces/IParameterSetMetadata.h
    ../Command/interfaces/IParameterSetParser.h
    ../Command/interfaces/IParser.h
    ../Command/interfaces/IParsingResult.h
    ../Command/interfaces/IProcessInformation.h
)

set(COMMAND_SOURCES_FILES
    ../Command/core/AbstractCommand.cpp
    ../Command/core/CommandConstants.cpp
    ../Command/core/CommandHandler.cpp
    ../Command/core/CommandHelpMetadata.cpp
    ../Command/core/CommandManifest.cpp
    ../Command/core/CommandMessageWriter.cpp
    ../Command/core/CommandParameters.cpp
    ../Command/core/CommandParser.cpp
    ../Command/core/IndexedParameterMetadata.cpp
    ../Command/core/InputParameters.cpp
    ../Command/core/NamedParameterMetadata.cpp
    ../Command/core/NamedParameterParser.cpp
    ../Command/core/Parameter.cpp
    ../Command/core/ParameterMetadata.cpp
    ../Command/core/ParameterSet.cpp
    ../Command/core/ParameterSetMetadata.cpp
    ../Command/core/ParameterSetParser.cpp
    ../Command/core/ProcessInformation.cpp
    ../Command/core/Tests.cpp
)

set(COMMAND_INCLUDES
    ../Command/core
    ../Command/interfaces
)

set(COMMAND_SOURCES
    ${COMMAND_INCLUDES_FILES}
    ${COMMAND_SOURCES_FILES}
)

add_library(Command STATIC
    ${BASE_SOURCES}
    ${COMMAND_SOURCES}
)

set(CLIENT_SERVER_INCLUDES_FILES
    ../ClientServer/core/AbstractRetryLogic.h
    ../ClientServer/core/ClientServerException.h
    ../ClientServer/core/RetryException.h
    ../ClientServer/core/RetryHandler.h
    ../ClientServer/core/RetryPolicy.h
    ../ClientServer/interfaces/ILogic.h
    ../ClientServer/interfaces/IRetryHandler.h
    ../ClientServer/interfaces/IRetryLogic.h
    ../ClientServer/interfaces/IRetryPolicy.h
)

set(CLIENT_SERVER_SOURCES_FILES
    ../ClientServer/core/AbstractRetryLogic.cpp
    ../ClientServer/core/RetryHandler.cpp
    ../ClientServer/core/RetryPolicy.cpp
)

set(CLIENT_SERVER_INCLUDES
    ../ClientServer/core
    ../ClientServer/interfaces
)

set(CLIENT_SERVER_SOURCES
    ${CLIENT_SERVER_INCLUDES_FILES}
    ${CLIENT_SERVER_SOURCES_FILES}
)

add_library(ClientServer STATIC
    ${BASE_SOURCES}
    ${CLIENT_SERVER_SOURCES}
)

set(CONSOLE_WINDOWS_INCLUDES_FILES
    ../ConsoleWindows/core/ConsolePipe.h
    ../ConsoleWindows/core/ConsoleProcess.h
    ../ConsoleWindows/core/ConsoleStreamBuffer.h
    ../ConsoleWindows/core/ConsoleWindow.h
    ../ConsoleWindows/core/ConsoleWindowsException.h
    ../ConsoleWindows/core/NamedPipes.h
    ../ConsoleWindows/interfaces/IConsolePipe.h
    ../ConsoleWindows/interfaces/IConsoleProcess.h
    ../ConsoleWindows/interfaces/IConsoleStreamBuffer.h
    ../ConsoleWindows/interfaces/IConsoleWindow.h
)

set(CONSOLE_WINDOWS_SOURCES_FILES
    ../ConsoleWindows/core/ConsolePipe.cpp
    ../ConsoleWindows/core/ConsoleProcess.cpp
    ../ConsoleWindows/core/ConsoleStreamBuffer.cpp
    ../ConsoleWindows/core/ConsoleWindow.cpp
    ../ConsoleWindows/core/NamedPipes.cpp
)

set(CONSOLE_WINDOWS_INCLUDES
    ../ConsoleWindows/core
    ../ConsoleWindows/interfaces
)

set(CONSOLE_WINDOWS_SOURCES
    ${CONSOLE_WINDOWS_INCLUDES_FILES}
    ${CONSOLE_WINDOWS_SOURCES_FILES}
)

add_library(ConsoleWindows STATIC
    ${BASE_SOURCES}
    ${CLIENT_SERVER_SOURCES}
    ${CONSOLE_WINDOWS_SOURCES}
)

include_directories(ConsoleHelper
    ${BASE_INCLUDES}
    ${CLIENT_SERVER_INCLUDES}
    ${COMMAND_INCLUDES}
    ${CONSOLE_HELPER_INCLUDES}
    ${CONSOLE_WINDOWS_INCLUDES}
)

add_executable(ConsoleHelper
    ${BASE_SOURCES}
    ${CLIENT_SERVER_SOURCES}
    ${COMMAND_SOURCES}
    ${CONSOLE_HELPER_SOURCES}
    ${CONSOLE_WINDOWS_SOURCES}
)

target_link_libraries(ConsoleHelper
    PRIVATE Base Command ClientServer ConsoleWindows
)

include_directories(
    ${BOOST_PATH}
)
