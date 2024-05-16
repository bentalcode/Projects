cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME
    GuiConfiguration
)

project(GuiConfiguration VERSION 1.0)

set(CMAKE_CXX_STANDARD
    14
)
set(RESOURCES_DIRECTORY_NAME
    resources
)


#
# Open Sources Path...
#
cmake_path(SET OPEN_SOURCES_PATH NORMALIZE "${CMAKE_SOURCE_DIR}/../../../../../../../OpenSources")
message (OPEN_SOURCES_PATH="${OPEN_SOURCES_PATH}")

#
# WX Widgets Path...
#
set (WX_WIDGETS_PATH ${OPEN_SOURCES_PATH}/wxWidgets-github)
message (WX_WIDGETS_PATH="${WX_WIDGETS_PATH}")

#
# OpenGL Path...
#
set(OPEN_GL_PATH ${OPEN_SOURCES_PATH}/openGL)
message (OPEN_GL_PATH="${OPEN_GL_PATH}")

#
# GLFW Path...
#
set(GLFW_PATH ${OPEN_SOURCES_PATH}/glfw)
message (GLFW_PATH="${GLFW_PATH}")

#
# Glew Path...
#
set (GLEW_PATH ${OPEN_SOURCES_PATH}/glew-2.1.0)
message (GLEW_PATH="${GLEW_PATH}")

set (WX_WIDGETS_LIB_PATH ${WX_WIDGETS_PATH}/lib/gcc_lib)
message (WX_WIDGETS_LIB_PATH="${WX_WIDGETS_LIB_PATH}")

set (WX_WIDGETS_DLL_PATH ${WX_WIDGETS_PATH}/lib/gcc_dll)
message (WX_WIDGETS_DLL_PATH="${WX_WIDGETS_DLL_PATH}")

if(DEBUG)
    set (WX_WIDGETS_LIB_INCLUDE_PATH ${WX_WIDGETS_LIB_PATH}/mswud)
else()
    set (WX_WIDGETS_LIB_INCLUDE_PATH ${WX_WIDGETS_LIB_PATH}/mswud)
endif()

message (WX_WIDGETS_LIB_INCLUDE_PATH="${WX_WIDGETS_LIB_INCLUDE_PATH}")

#
# Include Directories...
#
include_directories(
    ${WX_WIDGETS_PATH}/include
    ${WX_WIDGETS_LIB_INCLUDE_PATH}
    ${GLFW_PATH}/include
    ${GLEW_PATH}/include
)


set(GUI_CONFIGURATION_INCLUDES_FILES
    ./core/AppConfiguration.h
    ./core/ClientConfiguration.h
    ./core/ConfigurationItemCatalog.h
    ./core/DialogConfiguration.h
    ./core/DialogsConfiguration.h
    ./core/FrameConfiguration.h
    ./core/FramesConfiguration.h
    ./core/GuiComponentsConfiguration.h
    ./core/GuiConfigurationException.h
    ./core/GuiConfigurationManager.h
    ./core/LabelConfiguration.h
    ./core/LabelsConfiguration.h
    ./core/MenuConfiguration.h
    ./core/MenuItemConfiguration.h
    ./core/MenuItemsConfiguration.h
    ./core/MenusConfiguration.h
    ./core/SliderConfiguration.h
    ./core/SlidersConfiguration.h
    ./interfaces/IAppConfiguration.h
    ./interfaces/IClientConfiguration.h
    ./interfaces/IConfigurationItemCatalog.h
    ./interfaces/IConfigurationItems.h
    ./interfaces/IDialogConfiguration.h
    ./interfaces/IDialogsConfiguration.h
    ./interfaces/IFrameConfiguration.h
    ./interfaces/IFramesConfiguration.h
    ./interfaces/IGuiComponentsConfiguration.h
    ./interfaces/IGuiConfigurationManager.h
    ./interfaces/ILabelConfiguration.h
    ./interfaces/ILabelsConfiguration.h
    ./interfaces/IMenuConfiguration.h
    ./interfaces/IMenuItemConfiguration.h
    ./interfaces/IMenuItemsConfiguration.h
    ./interfaces/IMenusConfiguration.h
    ./interfaces/ISliderConfiguration.h
    ./interfaces/ISlidersConfiguration.h
)

set(GUI_CONFIGURATION_SOURCES_FILES
    ./core/AppConfiguration.cpp
    ./core/ClientConfiguration.cpp
    ./core/ConfigurationItemCatalog.cpp
    ./core/DialogConfiguration.cpp
    ./core/DialogsConfiguration.cpp
    ./core/FrameConfiguration.cpp
    ./core/FramesConfiguration.cpp
    ./core/GuiConfigurationManager.cpp
    ./core/LabelConfiguration.cpp
    ./core/LabelsConfiguration.cpp
    ./core/MenuConfiguration.cpp
    ./core/MenuItemConfiguration.cpp
    ./core/MenuItemsConfiguration.cpp
    ./core/MenusConfiguration.cpp
    ./core/SliderConfiguration.cpp
    ./core/SlidersConfiguration.cpp
)

set(GUI_CONFIGURATION_INCLUDES
    ./core
    ./interfaces
)

set(GUI_CONFIGURATION_SOURCES
    ${GUI_CONFIGURATION_INCLUDES_FILES}
    ${GUI_CONFIGURATION_SOURCES_FILES}
)

set(BASE_INCLUDES_FILES
    ../../Base/core/AbstractPath.h
    ../../Base/core/AbstractPathBuilder.h
    ../../Base/core/AlmostComparator.h
    ../../Base/core/AndBitOperator.h
    ../../Base/core/BaseException.h
    ../../Base/core/BaseLogic.h
    ../../Base/core/Bits.h
    ../../Base/core/ClassType.h
    ../../Base/core/ClassTypes.h
    ../../Base/core/CollectionComparator.h
    ../../Base/core/Collections.h
    ../../Base/core/ComparableComparator.h
    ../../Base/core/Comparator.h
    ../../Base/core/ComparatorFactory.h
    ../../Base/core/CompareToBuilder.h
    ../../Base/core/ConsoleColorSetter.h
    ../../Base/core/DereferenceComparableComparator.h
    ../../Base/core/DereferenceComparableComparator2.h
    ../../Base/core/DereferenceEquatableComparator.h
    ../../Base/core/DereferenceEquatableComparator2.h
    ../../Base/core/Environment.h
    ../../Base/core/EqualBuilder.h
    ../../Base/core/EquatableComparator.h
    ../../Base/core/ErrorCodes.h
    ../../Base/core/ErrorMessages.h
    ../../Base/core/Indexes.h
    ../../Base/core/Interval.h
    ../../Base/core/IntervalMap.h
    ../../Base/core/IntervalMapIterator.h
    ../../Base/core/InvalidArgumentException.h
    ../../Base/core/InvertComparator.h
    ../../Base/core/IterableComparator.h
    ../../Base/core/IterableObject.h
    ../../Base/core/IteratorComparator.h
    ../../Base/core/KmpStringSearch.h
    ../../Base/core/List.h
    ../../Base/core/ListIterator.h
    ../../Base/core/ListReverseIterator.h
    ../../Base/core/MapComparator.h
    ../../Base/core/Matrix.h
    ../../Base/core/MessageWriter.h
    ../../Base/core/NotBitOperator.h
    ../../Base/core/NotImplementedException.h
    ../../Base/core/OperatingSystemControlSettings.h
    ../../Base/core/OperatingSystemType.h
    ../../Base/core/OrBitOperator.h
    ../../Base/core/Pair.h
    ../../Base/core/PathBuilder.h
    ../../Base/core/PathDecomposition.h
    ../../Base/core/Position.h
    ../../Base/core/RandomGenerator.h
    ../../Base/core/Range.h
    ../../Base/core/ReferenceCounterHolder.h
    ../../Base/core/SetIterator.h
    ../../Base/core/SharedPtr.h
    ../../Base/core/SkipIterator.h
    ../../Base/core/Sorting.h
    ../../Base/core/StringComparable.h
    ../../Base/core/StringConversion.h
    ../../Base/core/StringEquality.h
    ../../Base/core/StringSearch.h
    ../../Base/core/StringUtils.h
    ../../Base/core/Strings.h
    ../../Base/core/Thread.h
    ../../Base/core/ToString.h
    ../../Base/core/Triple.h
    ../../Base/core/TwoDimensionalVector.h
    ../../Base/core/TwoDimensionalVectorIterator.h
    ../../Base/core/UnexpectedException.h
    ../../Base/core/UnixPath.h
    ../../Base/core/UnixPathBuilder.h
    ../../Base/core/Uuid.h
    ../../Base/core/VectorIterator.h
    ../../Base/core/VectorReverseIterator.h
    ../../Base/core/WindowsConsoleColorHandler.h
    ../../Base/core/WindowsDefinitions.h
    ../../Base/core/WindowsOperatingSystemType.h
    ../../Base/core/WindowsPath.h
    ../../Base/core/WindowsPathSettings.h
    ../../Base/core/WindowsSystemPath.h
    ../../Base/core/XorBitOperator.h
    ../../Base/interfaces/ColorType.h
    ../../Base/interfaces/Colors.h
    ../../Base/interfaces/DateTime.h
    ../../Base/interfaces/DateTimeInterval.h
    ../../Base/interfaces/Duration.h
    ../../Base/interfaces/Handle.h
    ../../Base/interfaces/IBinaryBitOperator.h
    ../../Base/interfaces/IBinaryComparator.h
    ../../Base/interfaces/IBitOperator.h
    ../../Base/interfaces/IBuilder.h
    ../../Base/interfaces/ICalculator.h
    ../../Base/interfaces/IClassType.h
    ../../Base/interfaces/IClone.h
    ../../Base/interfaces/ICollection.h
    ../../Base/interfaces/IComparableComparator.h
    ../../Base/interfaces/IComparatorFactory.h
    ../../Base/interfaces/IConsoleColorHandler.h
    ../../Base/interfaces/IEquatableComparator.h
    ../../Base/interfaces/IFromString.h
    ../../Base/interfaces/IHashCodeProvider.h
    ../../Base/interfaces/IIntervalMap.h
    ../../Base/interfaces/IIterable.h
    ../../Base/interfaces/IIterator.h
    ../../Base/interfaces/IKeyIterable.h
    ../../Base/interfaces/IKeyReverseIterable.h
    ../../Base/interfaces/IList.h
    ../../Base/interfaces/IMatch.h
    ../../Base/interfaces/IMatrix.h
    ../../Base/interfaces/IMessageWriter.h
    ../../Base/interfaces/IOperatingSystemControlSettings.h
    ../../Base/interfaces/IOperatingSystemPathSettings.h
    ../../Base/interfaces/IOperatingSystemType.h
    ../../Base/interfaces/IPath.h
    ../../Base/interfaces/IPathBuilder.h
    ../../Base/interfaces/IPathDecomposition.h
    ../../Base/interfaces/IPosition.h
    ../../Base/interfaces/IRandomGenerator.h
    ../../Base/interfaces/IResourceReader.h
    ../../Base/interfaces/IReverseIterable.h
    ../../Base/interfaces/IReverseIterator.h
    ../../Base/interfaces/ISizableCollection.h
    ../../Base/interfaces/ISkipIterator.h
    ../../Base/interfaces/IStringConversion.h
    ../../Base/interfaces/IThread.h
    ../../Base/interfaces/IToString.h
    ../../Base/interfaces/ITwoDimensionalVector.h
    ../../Base/interfaces/IUnaryBitOperator.h
    ../../Base/interfaces/IUuid.h
    ../../Base/interfaces/IValidator.h
    ../../Base/interfaces/IValueIterable.h
    ../../Base/interfaces/IValueReverseIterable.h
    ../../Base/interfaces/IVisitor.h
    ../../Base/interfaces/OperatingSystemType.h
    ../../Base/interfaces/ReferenceCounter.h
    ../../Base/interfaces/ReferenceCounterHolder.h
    ../../Base/interfaces/SmartPointers.h
    ../../Base/interfaces/StandardFileDescriptor.h
    ../../Base/interfaces/StringComparisonType.h
    ../../Base/interfaces/TimeUnit.h
    ../../Base/interfaces/TimeUtils.h
    ../../Base/interfaces/WinHandle.h
    ../../Base/interfaces/WindowsSystemPathType.h
)

set(BASE_SOURCES_FILES
    ../../Base/core/AbstractPath.cpp
    ../../Base/core/AbstractPathBuilder.cpp
    ../../Base/core/AndBitOperator.cpp
    ../../Base/core/Bits.cpp
    ../../Base/core/ClassType.cpp
    ../../Base/core/Collections.cpp
    ../../Base/core/ComparatorFactory.cpp
    ../../Base/core/CompareToBuilder.cpp
    ../../Base/core/ConsoleColorSetter.cpp
    ../../Base/core/DateTime.cpp
    ../../Base/core/DateTimeInterval.cpp
    ../../Base/core/Environment.cpp
    ../../Base/core/EqualBuilder.cpp
    ../../Base/core/ErrorCodes.cpp
    ../../Base/core/ErrorMessages.cpp
    ../../Base/core/KmpStringSearch.cpp
    ../../Base/core/MessageWriter.cpp
    ../../Base/core/NotBitOperator.cpp
    ../../Base/core/OperatingSystemControlSettings.cpp
    ../../Base/core/OrBitOperator.cpp
    ../../Base/core/PathBuilder.cpp
    ../../Base/core/PathDecomposition.cpp
    ../../Base/core/RandomGenerator.cpp
    ../../Base/core/ReferenceCounter.cpp
    ../../Base/core/SkipIterator.cpp
    ../../Base/core/StringComparable.cpp
    ../../Base/core/StringConversion.cpp
    ../../Base/core/StringEquality.cpp
    ../../Base/core/StringSearch.cpp
    ../../Base/core/StringUtils.cpp
    ../../Base/core/Strings.cpp
    ../../Base/core/Tests.cpp
    ../../Base/core/Thread.cpp
    ../../Base/core/TimeUnit.cpp
    ../../Base/core/TimeUtils.cpp
    ../../Base/core/ToString.cpp
    ../../Base/core/UnixPath.cpp
    ../../Base/core/UnixPathBuilder.cpp
    ../../Base/core/Uuid.cpp
    ../../Base/core/WindowsConsoleColorHandler.cpp
    ../../Base/core/WindowsOperatingSystemType.cpp
    ../../Base/core/WindowsPath.cpp
    ../../Base/core/WindowsPathSettings.cpp
    ../../Base/core/WindowsSystemPath.cpp
    ../../Base/core/XorBitOperator.cpp
)

set(BASE_INCLUDES
    ../../Base/core
    ../../Base/interfaces
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
    ../../TabularData/core/Event.h
    ../../TabularData/core/EventLog.h
    ../../TabularData/core/File.h
    ../../TabularData/core/FileInformation.h
    ../../TabularData/core/FileLineIterator.h
    ../../TabularData/core/FileWriter.h
    ../../TabularData/core/Record.h
    ../../TabularData/core/TabularDataException.h
    ../../TabularData/core/TabularFile.h
    ../../TabularData/core/TabularFileInformation.h
    ../../TabularData/core/TabularHeader.h
    ../../TabularData/core/TabularHeaderParser.h
    ../../TabularData/core/TabularRecord.h
    ../../TabularData/core/TabularRecordIterator.h
    ../../TabularData/core/TabularRecordParser.h
    ../../TabularData/core/TabularTable.h
    ../../TabularData/core/TabularTableWriter.h
    ../../TabularData/core/TokensParser.h
    ../../TabularData/interfaces/EventType.h
    ../../TabularData/interfaces/IEvent.h
    ../../TabularData/interfaces/IEventLog.h
    ../../TabularData/interfaces/IFile.h
    ../../TabularData/interfaces/IFileInformation.h
    ../../TabularData/interfaces/IRecord.h
    ../../TabularData/interfaces/ITabularFile.h
    ../../TabularData/interfaces/ITabularFileInformation.h
    ../../TabularData/interfaces/ITabularHeader.h
    ../../TabularData/interfaces/ITabularHeaderParser.h
    ../../TabularData/interfaces/ITabularRecord.h
    ../../TabularData/interfaces/ITabularRecordIterator.h
    ../../TabularData/interfaces/ITabularRecordParser.h
    ../../TabularData/interfaces/ITabularTable.h
    ../../TabularData/interfaces/ITabularTableWriter.h
    ../../TabularData/interfaces/ITokensParser.h
    ../../TabularData/interfaces/IValueTransformer.h
    ../../TabularData/interfaces/IWriter.h
    ../../TabularData/interfaces/ParsingPolicyType.h
)

set(TABULAR_DATA_SOURCES_FILES
    ../../TabularData/core/Event.cpp
    ../../TabularData/core/EventLog.cpp
    ../../TabularData/core/File.cpp
    ../../TabularData/core/FileInformation.cpp
    ../../TabularData/core/FileLineIterator.cpp
    ../../TabularData/core/FileWriter.cpp
    ../../TabularData/core/Record.cpp
    ../../TabularData/core/TabularFile.cpp
    ../../TabularData/core/TabularFileInformation.cpp
    ../../TabularData/core/TabularHeader.cpp
    ../../TabularData/core/TabularHeaderParser.cpp
    ../../TabularData/core/TabularRecord.cpp
    ../../TabularData/core/TabularRecordIterator.cpp
    ../../TabularData/core/TabularRecordParser.cpp
    ../../TabularData/core/TabularTable.cpp
    ../../TabularData/core/TabularTableWriter.cpp
    ../../TabularData/core/TokensParser.cpp
)

set(TABULAR_DATA_INCLUDES
    ../../TabularData/core
    ../../TabularData/interfaces
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

set(DATA_CONTAINER_MANAGEMENT_INCLUDES_FILES
    ../../DataContainerManagement/core/AbstractDataItemValue.h
    ../../DataContainerManagement/core/BooleanDataItemValue.h
    ../../DataContainerManagement/core/DataCatalog.h
    ../../DataContainerManagement/core/DataContainer.h
    ../../DataContainerManagement/core/DataContainerException.h
    ../../DataContainerManagement/core/DataContainerUpdateFunctors.h
    ../../DataContainerManagement/core/DataItem.h
    ../../DataContainerManagement/core/DateTimeDataItemValue.h
    ../../DataContainerManagement/core/DoubleDataItemValue.h
    ../../DataContainerManagement/core/DurationDataItemValue.h
    ../../DataContainerManagement/core/IntegerDataItemValue.h
    ../../DataContainerManagement/core/LongDataItemValue.h
    ../../DataContainerManagement/core/StringArrayArrayDataItemValue.h
    ../../DataContainerManagement/core/StringArrayDataItemValue.h
    ../../DataContainerManagement/core/StringDataItemValue.h
    ../../DataContainerManagement/interfaces/IDataCatalog.h
    ../../DataContainerManagement/interfaces/IDataContainer.h
    ../../DataContainerManagement/interfaces/IDataContainerUpdateFunctors.h
    ../../DataContainerManagement/interfaces/IDataItem.h
    ../../DataContainerManagement/interfaces/IDataItemValue.h
)

set(DATA_CONTAINER_MANAGEMENT_SOURCES_FILES
    ../../DataContainerManagement/core/AbstractDataItemValue.cpp
    ../../DataContainerManagement/core/BooleanDataItemValue.cpp
    ../../DataContainerManagement/core/DataCatalog.cpp
    ../../DataContainerManagement/core/DataContainer.cpp
    ../../DataContainerManagement/core/DataContainerUpdateFunctors.cpp
    ../../DataContainerManagement/core/DataItem.cpp
    ../../DataContainerManagement/core/DateTimeDataItemValue.cpp
    ../../DataContainerManagement/core/DoubleDataItemValue.cpp
    ../../DataContainerManagement/core/DurationDataItemValue.cpp
    ../../DataContainerManagement/core/IntegerDataItemValue.cpp
    ../../DataContainerManagement/core/LongDataItemValue.cpp
    ../../DataContainerManagement/core/StringArrayArrayDataItemValue.cpp
    ../../DataContainerManagement/core/StringArrayDataItemValue.cpp
    ../../DataContainerManagement/core/StringDataItemValue.cpp
)

set(DATA_CONTAINER_MANAGEMENT_INCLUDES
    ../../DataContainerManagement/core
    ../../DataContainerManagement/interfaces
)

set(DATA_CONTAINER_MANAGEMENT_SOURCES
    ${DATA_CONTAINER_MANAGEMENT_INCLUDES_FILES}
    ${DATA_CONTAINER_MANAGEMENT_SOURCES_FILES}
)

add_library(DataContainerManagement STATIC
    ${DATA_CONTAINER_MANAGEMENT_SOURCES}
)

target_link_libraries(DataContainerManagement
    PRIVATE Base TabularData Logging
)

set(LOGGING_INCLUDES_FILES
    ../../Logging/core/DateTimeTransformer.h
    ../../Logging/core/Log.h
    ../../Logging/core/LogHeader.h
    ../../Logging/core/LogInformation.h
    ../../Logging/core/LogLevelTransformer.h
    ../../Logging/core/LogRecord.h
    ../../Logging/core/LogRecordIterator.h
    ../../Logging/core/LogStatistics.h
    ../../Logging/core/LogTokensParser.h
    ../../Logging/core/LogWriter.h
    ../../Logging/core/Logger.h
    ../../Logging/core/LoggerFactory.h
    ../../Logging/core/LoggerImpl.h
    ../../Logging/core/Loggers.h
    ../../Logging/core/LoggingException.h
    ../../Logging/core/SizeTTransformer.h
    ../../Logging/core/StringTransformer.h
    ../../Logging/core/UnsignedIntegerTransformer.h
    ../../Logging/core/UnsignedLongTransformer.h
    ../../Logging/interfaces/ILog.h
    ../../Logging/interfaces/ILogHeader.h
    ../../Logging/interfaces/ILogInformation.h
    ../../Logging/interfaces/ILogRecord.h
    ../../Logging/interfaces/ILogStatistics.h
    ../../Logging/interfaces/ILogWriter.h
    ../../Logging/interfaces/ILogger.h
    ../../Logging/interfaces/ILoggerFactory.h
    ../../Logging/interfaces/ILoggerImpl.h
    ../../Logging/interfaces/ILoggers.h
    ../../Logging/interfaces/LogLevel.h
    ../../Logging/interfaces/LogParsingErrorType.h
)

set(LOGGING_SOURCES_FILES
    ../../Logging/core/DateTimeTransformer.cpp
    ../../Logging/core/Log.cpp
    ../../Logging/core/LogHeader.cpp
    ../../Logging/core/LogInformation.cpp
    ../../Logging/core/LogLevelTransformer.cpp
    ../../Logging/core/LogRecord.cpp
    ../../Logging/core/LogRecordIterator.cpp
    ../../Logging/core/LogStatistics.cpp
    ../../Logging/core/LogTokensParser.cpp
    ../../Logging/core/LogWriter.cpp
    ../../Logging/core/Logger.cpp
    ../../Logging/core/LoggerFactory.cpp
    ../../Logging/core/LoggerImpl.cpp
    ../../Logging/core/Loggers.cpp
    ../../Logging/core/SizeTTransformer.cpp
    ../../Logging/core/StringTransformer.cpp
    ../../Logging/core/UnsignedIntegerTransformer.cpp
    ../../Logging/core/UnsignedLongTransformer.cpp
)

set(LOGGING_INCLUDES
    ../../Logging/core
    ../../Logging/interfaces
)

set(LOGGING_SOURCES
    ${LOGGING_INCLUDES_FILES}
    ${LOGGING_SOURCES_FILES}
)

add_library(Logging STATIC
    ${LOGGING_SOURCES}
)

target_link_libraries(Logging
    PRIVATE Base TabularData
)

include_directories(GuiConfiguration
    ${BASE_INCLUDES}
    ${DATA_CONTAINER_MANAGEMENT_INCLUDES}
    ${GUI_CONFIGURATION_INCLUDES}
    ${LOGGING_INCLUDES}
    ${TABULAR_DATA_INCLUDES}
)

add_library(GuiConfiguration STATIC
    ${GUI_CONFIGURATION_SOURCES}
)

target_link_libraries(GuiConfiguration
    PRIVATE Base TabularData DataContainerManagement Logging
)


