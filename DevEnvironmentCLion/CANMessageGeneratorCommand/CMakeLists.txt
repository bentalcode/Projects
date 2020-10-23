cmake_minimum_required(VERSION 3.13)

project(CANMessageGeneratorCommand VERSION 1.0)

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

set(CANMESSAGE_GENERATOR_COMMAND_INCLUDES_FILES
    ./CANMessageGeneratorCommandException.h
    ./core/CANMessageGeneratorCommand.h
    ./core/CANMessageGeneratorCommandParameters.h
    ./core/PreCompiled.h
    ./interfaces/ICANMessageGeneratorCommandParameters.h
)

set(CANMESSAGE_GENERATOR_COMMAND_SOURCES_FILES
    ./core/CANMessageGeneratorCommand.cpp
    ./core/CANMessageGeneratorCommandParameters.cpp
    ./core/PreCompiled.cpp
    ./main.cpp
)

set(CANMESSAGE_GENERATOR_COMMAND_SOURCES
    ${CANMESSAGE_GENERATOR_COMMAND_INCLUDES_FILES}
    ${CANMESSAGE_GENERATOR_COMMAND_SOURCES_FILES}
)

set(CANMESSAGE_GENERATOR_COMMAND_INCLUDES
    .
    ./core
    ./interfaces
)

set(BASE_INCLUDES_FILES
    ../Base/BaseException.h
    ../Base/NotImplementedException.h
    ../Base/WindowsException.h
    ../Base/core/AndBitOperator.h
    ../Base/core/BaseDependencies.h
    ../Base/core/BaseLogic.h
    ../Base/core/ClassType.h
    ../Base/core/ComparableComparator.h
    ../Base/core/Comparator.h
    ../Base/core/Conversion.h
    ../Base/core/DereferenceComparableComparator.h
    ../Base/core/DereferenceComparableComparator2.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/DereferenceEquatableComparator2.h
    ../Base/core/EquatableComparator.h
    ../Base/core/IntervalMap.h
    ../Base/core/IntervalMapIterator.h
    ../Base/core/InvertComparator.h
    ../Base/core/IterableObject.h
    ../Base/core/KmpStringSearch.h
    ../Base/core/List.h
    ../Base/core/ListIterator.h
    ../Base/core/ListReverseIterator.h
    ../Base/core/LocalFreeReleaser.h
    ../Base/core/Matrix.h
    ../Base/core/MessageWriter.h
    ../Base/core/NotBitOperator.h
    ../Base/core/OrBitOperator.h
    ../Base/core/ParsingResult.h
    ../Base/core/Position.h
    ../Base/core/PreCompiled.h
    ../Base/core/RandomGenerator.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
    ../Base/core/SkipIterator.h
    ../Base/core/StringConversion.h
    ../Base/core/StringIterator.h
    ../Base/core/TwoDimensionalVector.h
    ../Base/core/TwoDimensionalVectorIterator.h
    ../Base/core/VectorIterator.h
    ../Base/core/VectorReverseIterator.h
    ../Base/core/WindowsConsoleColorHandler.h
    ../Base/core/WindowsDependecies.h
    ../Base/core/WindowsErrors.h
    ../Base/core/XorBitOperator.h
    ../Base/interfaces/Bits.h
    ../Base/interfaces/ClassTypes.h
    ../Base/interfaces/ComparatorFactory.h
    ../Base/interfaces/CompareToBuilder.h
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/Dimensions.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/EqualBuilder.h
    ../Base/interfaces/IBinaryBitOperator.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/IBitOperator.h
    ../Base/interfaces/IBuilder.h
    ../Base/interfaces/ICalculator.h
    ../Base/interfaces/IClassType.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IComparableComparator.h
    ../Base/interfaces/IConsoleColorHandler.h
    ../Base/interfaces/IEquatableComparator.h
    ../Base/interfaces/IFinder.h
    ../Base/interfaces/IHashCodeProvider.h
    ../Base/interfaces/IIntervalMap.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/IKeyIterable.h
    ../Base/interfaces/IKeyReverseIterable.h
    ../Base/interfaces/IList.h
    ../Base/interfaces/IMainParser.h
    ../Base/interfaces/IMatch.h
    ../Base/interfaces/IMatrix.h
    ../Base/interfaces/IMessageWriter.h
    ../Base/interfaces/IParser.h
    ../Base/interfaces/IParsingResult.h
    ../Base/interfaces/IRandomGenerator.h
    ../Base/interfaces/IReverseIterable.h
    ../Base/interfaces/IReverseIterator.h
    ../Base/interfaces/ISizableCollection.h
    ../Base/interfaces/ISkipIterator.h
    ../Base/interfaces/IStringConversion.h
    ../Base/interfaces/ITwoDimensionalVector.h
    ../Base/interfaces/IUnaryBitOperator.h
    ../Base/interfaces/IValidator.h
    ../Base/interfaces/IValueIterable.h
    ../Base/interfaces/IValueReverseIterable.h
    ../Base/interfaces/IVisitor.h
    ../Base/interfaces/Indexes.h
    ../Base/interfaces/Interval.h
    ../Base/interfaces/Intervals.h
    ../Base/interfaces/IterableComparator.h
    ../Base/interfaces/IteratorComparator.h
    ../Base/interfaces/Pair.h
    ../Base/interfaces/Range.h
    ../Base/interfaces/SharedPtr.h
    ../Base/interfaces/StandardFileDescriptor.h
    ../Base/interfaces/StringComparable.h
    ../Base/interfaces/StringEquality.h
    ../Base/interfaces/StringSearch.h
    ../Base/interfaces/Strings.h
    ../Base/interfaces/Threads.h
    ../Base/interfaces/Triple.h
)

set(BASE_SOURCES_FILES
    ../Base/core/AndBitOperator.cpp
    ../Base/core/Bits.cpp
    ../Base/core/ClassType.cpp
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/Conversion.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/EqualBuilder.cpp
    ../Base/core/Indexes.cpp
    ../Base/core/KmpStringSearch.cpp
    ../Base/core/MessageWriter.cpp
    ../Base/core/NotBitOperator.cpp
    ../Base/core/OrBitOperator.cpp
    ../Base/core/Position.cpp
    ../Base/core/PreCompiled.cpp
    ../Base/core/RandomGenerator.cpp
    ../Base/core/SkipIterator.cpp
    ../Base/core/StringComparable.cpp
    ../Base/core/StringConversion.cpp
    ../Base/core/StringEquality.cpp
    ../Base/core/StringSearch.cpp
    ../Base/core/Strings.cpp
    ../Base/core/Threads.cpp
    ../Base/core/WindowsConsoleColorHandler.cpp
    ../Base/core/WindowsErrors.cpp
    ../Base/core/XorBitOperator.cpp
)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES}
)

set(BASE_INCLUDES
    ../Base
    ../Base/core
    ../Base/interfaces
)

add_library(Base STATIC
    ${BASE_SOURCES}
)

set(COMMAND_INCLUDES_FILES
    ../Command/CommandException.h
    ../Command/core/AbstractCommand.h
    ../Command/core/CommandConstants.h
    ../Command/core/CommandHandler.h
    ../Command/core/CommandManifest.h
    ../Command/core/CommandMessageWriter.h
    ../Command/core/CommandParameters.h
    ../Command/core/CommandParser.h
    ../Command/core/InputParameters.h
    ../Command/core/NamedParameterParser.h
    ../Command/core/Parameter.h
    ../Command/core/ParameterSet.h
    ../Command/interfaces/ICommand.h
    ../Command/interfaces/ICommandHandler.h
    ../Command/interfaces/ICommandManifest.h
    ../Command/interfaces/ICommandMessageWriter.h
    ../Command/interfaces/ICommandParameters.h
    ../Command/interfaces/IInputParameters.h
    ../Command/interfaces/IParameter.h
    ../Command/interfaces/IParameterSet.h
)

set(COMMAND_SOURCES_FILES
    ../Command/core/AbstractCommand.cpp
    ../Command/core/CommandConstants.cpp
    ../Command/core/CommandHandler.cpp
    ../Command/core/CommandManifest.cpp
    ../Command/core/CommandMessageWriter.cpp
    ../Command/core/CommandParameters.cpp
    ../Command/core/CommandParser.cpp
    ../Command/core/InputParameters.cpp
    ../Command/core/NamedParameterParser.cpp
    ../Command/core/Parameter.cpp
    ../Command/core/ParameterSet.cpp
)

set(COMMAND_SOURCES
    ${COMMAND_INCLUDES_FILES}
    ${COMMAND_SOURCES_FILES}
)

set(COMMAND_INCLUDES
    ../Command
    ../Command/core
    ../Command/interfaces
)

add_library(Command STATIC
    ${BASE_SOURCES}
    ${COMMAND_SOURCES}
)

set(CANMESSAGE_GENERATOR_INCLUDES_FILES
    ../CANMessageGenerator/CANMessageGeneratorException.h
    ../CANMessageGenerator/JitterMessageHandlerException.h
    ../CANMessageGenerator/core/CANMessageId.h
    ../CANMessageGenerator/core/CANMessageName.h
    ../CANMessageGenerator/core/CANMessageRule.h
    ../CANMessageGenerator/core/CANMessageRuleGenerator.h
    ../CANMessageGenerator/core/CANRuleGenerator.h
    ../CANMessageGenerator/core/CANSignalRule.h
    ../CANMessageGenerator/core/CANSignalRuleGenerator.h
    ../CANMessageGenerator/core/JitterMessageData.h
    ../CANMessageGenerator/core/JitterMessageHandler.h
    ../CANMessageGenerator/core/PreCompiled.h
    ../CANMessageGenerator/interfaces/ICANMessageId.h
    ../CANMessageGenerator/interfaces/ICANMessageName.h
    ../CANMessageGenerator/interfaces/ICANMessageRule.h
    ../CANMessageGenerator/interfaces/ICANRule.h
    ../CANMessageGenerator/interfaces/ICANRuleGenerator.h
    ../CANMessageGenerator/interfaces/ICANSignalRule.h
    ../CANMessageGenerator/interfaces/IJitterMessageData.h
    ../CANMessageGenerator/interfaces/IJitterMessageHandler.h
)

set(CANMESSAGE_GENERATOR_SOURCES_FILES
    ../CANMessageGenerator/core/CANMessageId.cpp
    ../CANMessageGenerator/core/CANMessageName.cpp
    ../CANMessageGenerator/core/CANMessageRule.cpp
    ../CANMessageGenerator/core/CANMessageRuleGenerator.cpp
    ../CANMessageGenerator/core/CANRuleGenerator.cpp
    ../CANMessageGenerator/core/CANSignalRule.cpp
    ../CANMessageGenerator/core/CANSignalRuleGenerator.cpp
    ../CANMessageGenerator/core/JitterMessageData.cpp
    ../CANMessageGenerator/core/JitterMessageHandler.cpp
    ../CANMessageGenerator/core/PreCompiled.cpp
)

set(CANMESSAGE_GENERATOR_SOURCES
    ${CANMESSAGE_GENERATOR_INCLUDES_FILES}
    ${CANMESSAGE_GENERATOR_SOURCES_FILES}
)

set(CANMESSAGE_GENERATOR_INCLUDES
    ../CANMessageGenerator
    ../CANMessageGenerator/core
    ../CANMessageGenerator/interfaces
)

add_library(CANMessageGenerator STATIC
    ${BASE_SOURCES}
    ${CANMESSAGE_GENERATOR_SOURCES}
)

include_directories(CANMessageGeneratorCommand
    ${BASE_INCLUDES}
    ${CANMESSAGE_GENERATOR_COMMAND_INCLUDES}
    ${CANMESSAGE_GENERATOR_INCLUDES}
    ${COMMAND_INCLUDES}
)

add_executable(CANMessageGeneratorCommand
    ${BASE_SOURCES}
    ${CANMESSAGE_GENERATOR_COMMAND_SOURCES}
    ${CANMESSAGE_GENERATOR_SOURCES}
    ${COMMAND_SOURCES}
)

target_link_libraries(CANMessageGeneratorCommand
    PRIVATE Base Command CANMessageGenerator
)

include_directories(
    ${BOOST_PATH}
)
