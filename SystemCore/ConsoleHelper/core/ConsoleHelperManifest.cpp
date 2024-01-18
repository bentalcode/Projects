#include "ConsoleHelperManifest.h"
#include "CommandHelpMetadata.h"
#include "ParameterSetMetadata.h"
#include "IndexedParameterMetadata.h"
#include "NamedParameterMetadata.h"
#include "ConsoleHelperConstants.h"
#include <sstream>
#include <assert.h>

using namespace console_helper;

/**
 * Creates a manifest.
 */
command::ICommandManifestSharedPtr ConsoleHelperManifest::Make()
{
    return std::make_shared<ConsoleHelperManifest>();
}

ConsoleHelperManifest::ConsoleHelperManifest()
{
    Initialize();
}

ConsoleHelperManifest::~ConsoleHelperManifest()
{
}

/**
 * Gets name of a command.
 */
const std::wstring& ConsoleHelperManifest::GetName() const
{
    return m_name;
}

/**
 * Gets description of a command.
 */
const std::wstring& ConsoleHelperManifest::GetDescription() const
{
    return m_description;
}

/**
 * Gets help metadata of a command.
 */
const command::ICommandHelpMetadata& ConsoleHelperManifest::GetHelpMetadata() const
{
    return *m_helpMetadata;
}

/**
 * Gets parameter-sets metadata of a command.
 */
void ConsoleHelperManifest::GetParameterSetsMetadata(
    std::vector<command::IParameterSetMetadataSharedPtr>& parameterSets) const
{
    assert(parameterSets.empty());

    parameterSets.insert(
        parameterSets.end(),
        m_parameterSets.begin(),
        m_parameterSets.end());
}

/**
 * Initializes manifest.
 */
void ConsoleHelperManifest::Initialize()
{
    m_name = L"console-helper";
    m_description = L"console-helper updates a console window in the background.";
    m_helpMetadata = CreateHelpMetadata();
    CreateParameterSets(m_parameterSets);
}

/**
 * Creates a help metadata.
 */
command::ICommandHelpMetadataSharedPtr ConsoleHelperManifest::CreateHelpMetadata()
{
    std::wstring usageMessage = CreateUsageMessage();
    std::wstring shortName = L"console-helper";
    std::wstring longName = L"console-window-helper";

    return command::CommandHelpMetadata::Make(
        usageMessage,
        shortName,
        longName);
}

/**
 * Creates parameter sets.
 */
void ConsoleHelperManifest::CreateParameterSets(
    std::vector<command::IParameterSetMetadataSharedPtr>& parameterSets)
{
    assert(parameterSets.empty());
    command::IParameterSetMetadataSharedPtr parameterSet1 = CreateParameterSet1();
    command::IParameterSetMetadataSharedPtr parameterSet2 = CreateParameterSet2();
    parameterSets.push_back(parameterSet1);
    parameterSets.push_back(parameterSet2);
}

/**
 * Creates usage message.
 */
std::wstring ConsoleHelperManifest::CreateUsageMessage()
{
    std::wstringstream usageMessageStream;
    usageMessageStream
        << L"console-helper --help" << std::endl
        << L"console-helper <title> <pipeName>" << std::endl
        << L"console-helper --title:=<title> --pipeName:=<pipeName>" << std::endl;

    return usageMessageStream.str();
}

/**
 * Creates parameter set1.
 */
command::IParameterSetMetadataSharedPtr ConsoleHelperManifest::CreateParameterSet1()
{
    std::vector<command::IParameterMetadataSharedPtr> indexedParameters;
    std::vector<command::IParameterMetadataSharedPtr> namedParameters;

    command::IParameterMetadataSharedPtr titleParameter = command::IndexedParameterMetadata::Make(
        ConsoleHelperConstants::CONSOLE_TITLE,
        ConsoleHelperConstants::CONSOLE_TITLE_DESCRIPTION);

    command::IParameterMetadataSharedPtr pipeNameParameter = command::IndexedParameterMetadata::Make(
        ConsoleHelperConstants::PIPE_NAME,
        ConsoleHelperConstants::PIPE_NAME_DESCRIPTION);

    indexedParameters.push_back(titleParameter);
    indexedParameters.push_back(pipeNameParameter);

    return command::ParameterSetMetadata::Make(
        indexedParameters,
        namedParameters);
}

/**
 * Creates parameter set2.
 */
command::IParameterSetMetadataSharedPtr ConsoleHelperManifest::CreateParameterSet2()
{
    std::vector<command::IParameterMetadataSharedPtr> indexedParameters;
    std::vector<command::IParameterMetadataSharedPtr> namedParameters;

    command::IParameterMetadataSharedPtr titleParameter = command::NamedParameterMetadata::Make(
        ConsoleHelperConstants::CONSOLE_TITLE,
        ConsoleHelperConstants::CONSOLE_TITLE_SHORT_NAME,
        ConsoleHelperConstants::CONSOLE_TITLE_LONG_NAME,
        ConsoleHelperConstants::CONSOLE_TITLE_DESCRIPTION);

    command::IParameterMetadataSharedPtr pipeNameParameter = command::NamedParameterMetadata::Make(
        ConsoleHelperConstants::PIPE_NAME,
        ConsoleHelperConstants::PIPE_NAME_SHORT_NAME,
        ConsoleHelperConstants::PIPE_NAME_LONG_NAME,
        ConsoleHelperConstants::PIPE_NAME_DESCRIPTION);

    namedParameters.push_back(titleParameter);
    namedParameters.push_back(pipeNameParameter);

    return command::ParameterSetMetadata::Make(
        indexedParameters,
        namedParameters);
}
