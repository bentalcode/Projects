#include "ConsoleFileFinderCommandManifest.h"
#include "ConsoleFileFinderCommandConstants.h"
#include "CommandHelpMetadata.h"
#include "ParameterSetMetadata.h"
#include "IndexedParameterMetadata.h"
#include "NamedParameterMetadata.h"
#include <sstream>
#include <assert.h>

using namespace consolefilefinder;

/**
 * Creates a manifest.
 */
Command::ICommandManifestSharedPtr ConsoleFileFinderCommandManifest::Make()
{
    return std::make_shared<ConsoleFileFinderCommandManifest>();
}

ConsoleFileFinderCommandManifest::ConsoleFileFinderCommandManifest()
{
    Initialize();
}

ConsoleFileFinderCommandManifest::~ConsoleFileFinderCommandManifest()
{
}

/**
 * Gets name of a command.
 */
const std::wstring& ConsoleFileFinderCommandManifest::GetName() const
{
    return m_name;
}

/**
 * Gets description of a command.
 */
const std::wstring& ConsoleFileFinderCommandManifest::GetDescription() const
{
    return m_description;
}

/**
 * Gets help metadata of a command.
 */
const Command::ICommandHelpMetadata& ConsoleFileFinderCommandManifest::GetHelpMetadata() const
{
    return *m_helpMetadata;
}

/**
 * Gets parameter-sets metadata of a command.
 */
void ConsoleFileFinderCommandManifest::GetParameterSetsMetadata(
    std::vector<Command::IParameterSetMetadataSharedPtr>& parameterSets) const
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
void ConsoleFileFinderCommandManifest::Initialize()
{
    m_name = L"file-finder";
    m_description = L"file-finder cmd finds and display content of files in console.";
    m_helpMetadata = CreateHelpMetadata();
    CreateParameterSets(m_parameterSets);
}

/**
 * Creates a help metadata.
 */
Command::ICommandHelpMetadataSharedPtr ConsoleFileFinderCommandManifest::CreateHelpMetadata()
{
    std::wstring usageMessage = CreateUsageMessage();
    L"file-finder <dirPath> <filePatterns: pattern1, pattern2 ... patternN>";
    std::wstring shortName = L"file-finder";
    std::wstring longName = L"console-file-finder";

    return Command::CommandHelpMetadata::Make(
        usageMessage,
        shortName,
        longName);
}

/**
 * Creates parameter sets.
 */
void ConsoleFileFinderCommandManifest::CreateParameterSets(
    std::vector<Command::IParameterSetMetadataSharedPtr>& parameterSets)
{
    assert(parameterSets.empty());
    Command::IParameterSetMetadataSharedPtr defaultParameterSet = CreateDefaultParameterSet();
    Command::IParameterSetMetadataSharedPtr parameterSet1 = CreateParameterSet1();
    Command::IParameterSetMetadataSharedPtr parameterSet2 = CreateParameterSet2();
    parameterSets.push_back(defaultParameterSet);
    parameterSets.push_back(parameterSet1);
    parameterSets.push_back(parameterSet2);
}

std::wstring ConsoleFileFinderCommandManifest::CreateUsageMessage()
{
    std::wstringstream usageMessageStream;
    usageMessageStream
        << L"file-finder --help" << std::endl
        << L"file-finder <path> <filePattern>" << std::endl
        << L"file-finder <path> --filePatters:=<pattern1, pattern2, ... patternN>" << std::endl
        << L"file-finder --path:=<path> --filePatters:=<pattern1, pattern2, ... patternN>" << std::endl;

    return usageMessageStream.str();
}

/**
 * Creates a default parameter set.
 */
Command::IParameterSetMetadataSharedPtr ConsoleFileFinderCommandManifest::CreateDefaultParameterSet()
{
    std::vector<Command::IParameterMetadataSharedPtr> indexedParameters;
    std::vector<Command::IParameterMetadataSharedPtr> namedParameters;

    Command::IParameterMetadataSharedPtr pathParameter = Command::IndexedParameterMetadata::Make(
        ConsoleFileFinderCommandConstants::PARAMETER_PATH_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_PATH_DESCRIPTION);

    Command::IParameterMetadataSharedPtr fileNamePatternParameter = Command::IndexedParameterMetadata::Make(
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_DESCRIPTION);

    indexedParameters.push_back(pathParameter);
    indexedParameters.push_back(fileNamePatternParameter);

    return Command::ParameterSetMetadata::Make(
        indexedParameters,
        namedParameters);
}

/**
 * Creates parameter set1.
 */
Command::IParameterSetMetadataSharedPtr ConsoleFileFinderCommandManifest::CreateParameterSet1()
{
    std::vector<Command::IParameterMetadataSharedPtr> indexedParameters;
    std::vector<Command::IParameterMetadataSharedPtr> namedParameters;

    Command::IParameterMetadataSharedPtr pathParameter = Command::IndexedParameterMetadata::Make(
        ConsoleFileFinderCommandConstants::PARAMETER_PATH_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_PATH_DESCRIPTION);

    Command::IParameterMetadataSharedPtr fileNamePatternParameter = Command::NamedParameterMetadata::Make(
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_SHORT_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_LONG_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_DESCRIPTION);

    indexedParameters.push_back(pathParameter);
    namedParameters.push_back(fileNamePatternParameter);

    return Command::ParameterSetMetadata::Make(
        indexedParameters,
        namedParameters);
}

/**
 * Creates parameter set2.
 */
Command::IParameterSetMetadataSharedPtr ConsoleFileFinderCommandManifest::CreateParameterSet2()
{
    std::vector<Command::IParameterMetadataSharedPtr> indexedParameters;
    std::vector<Command::IParameterMetadataSharedPtr> namedParameters;

    Command::IParameterMetadataSharedPtr pathParameter = Command::NamedParameterMetadata::Make(
        ConsoleFileFinderCommandConstants::PARAMETER_PATH_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_PATH_SHORT_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_PATH_LONG_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_PATH_DESCRIPTION);

    Command::IParameterMetadataSharedPtr fileNamePatternParameter = Command::NamedParameterMetadata::Make(
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_SHORT_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_LONG_NAME,
        ConsoleFileFinderCommandConstants::PARAMETER_FILE_PATTERNS_DESCRIPTION);

    namedParameters.push_back(pathParameter);
    namedParameters.push_back(fileNamePatternParameter);

    return Command::ParameterSetMetadata::Make(
        indexedParameters,
        namedParameters);
}
