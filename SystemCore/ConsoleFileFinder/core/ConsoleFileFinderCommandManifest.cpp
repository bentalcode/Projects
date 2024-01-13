#include "ConsoleFileFinderCommandManifest.h"
#include "CommandHelpMetadata.h"
#include "ParameterSetMetadata.h"
#include "IndexedParameterMetadata.h"
#include "NamedParameterMetadata.h"
#include <assert.h>

using namespace consolefilefinder;

/**
 * Creates a manifest.
 */
command::ICommandManifestSharedPtr ConsoleFileFinderCommandManifest::Make()
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
const command::ICommandHelpMetadata& ConsoleFileFinderCommandManifest::GetHelpMetadata() const
{
    return *m_helpMetadata;
}

/**
 * Gets parameter-sets metadata of a command.
 */
void ConsoleFileFinderCommandManifest::GetParameterSetsMetadata(
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
command::ICommandHelpMetadataSharedPtr ConsoleFileFinderCommandManifest::CreateHelpMetadata()
{
    std::wstring usageMessage = L"file-finder <dirPath> <filePatterns: pattern1, pattern2 ... patternN>";
    std::wstring shortName = L"file-finder";
    std::wstring longName = L"console-file-finder";

    return command::CommandHelpMetadata::Make(
        usageMessage,
        shortName,
        longName);
}

/**
 * Creates parameter sets.
 */
void ConsoleFileFinderCommandManifest::CreateParameterSets(
    std::vector<command::IParameterSetMetadataSharedPtr>& parameterSets)
{
    assert(parameterSets.empty());
    command::IParameterSetMetadataSharedPtr defaultParameterSet = CreateDefaultParameterSet();
    command::IParameterSetMetadataSharedPtr parameterSet1 = CreateParameterSet1();
    parameterSets.push_back(defaultParameterSet);
    parameterSets.push_back(parameterSet1);
}

/**
 * Creates a default parameter set.
 */
command::IParameterSetMetadataSharedPtr ConsoleFileFinderCommandManifest::CreateDefaultParameterSet()
{
    std::vector<command::IParameterMetadataSharedPtr> indexedParameters;
    std::vector<command::IParameterMetadataSharedPtr> namedParameters;

    command::IParameterMetadataSharedPtr pathParameter = command::IndexedParameterMetadata::Make(
        L"dirPath",
        L"The path of directory for searching.");

    command::IParameterMetadataSharedPtr fileNamePatternParameter = command::IndexedParameterMetadata::Make(
        L"fileNamePatterns",
        L"The pattern of file name.");

    indexedParameters.push_back(pathParameter);
    indexedParameters.push_back(fileNamePatternParameter);

    return command::ParameterSetMetadata::Make(
        indexedParameters,
        namedParameters);
}

/**
 * Creates parameter set1.
 */
command::IParameterSetMetadataSharedPtr ConsoleFileFinderCommandManifest::CreateParameterSet1()
{
    std::vector<command::IParameterMetadataSharedPtr> indexedParameters;
    std::vector<command::IParameterMetadataSharedPtr> namedParameters;

    command::IParameterMetadataSharedPtr pathParameter = command::NamedParameterMetadata::Make(
        L"dirPath",
        L"path",
        L"dirPath",
        L"The path of directory for searching.");

    command::IParameterMetadataSharedPtr fileNamePatternParameter = command::NamedParameterMetadata::Make(
        L"fileNamePatterns",
        L"filePatterns",
        L"fileNamePatterns",
        L"The pattern of file names.");

    namedParameters.push_back(pathParameter);
    namedParameters.push_back(fileNamePatternParameter);

    return command::ParameterSetMetadata::Make(
        indexedParameters,
        namedParameters);
}
