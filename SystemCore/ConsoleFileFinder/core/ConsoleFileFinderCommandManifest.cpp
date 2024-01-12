#include "ConsoleFileFinderCommandManifest.h"
#include "CommandHelpMetadata.h"
#include "ParameterSetMetadata.h"
#include "IndexedParameterMetadata.h"
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
void ConsoleFileFinderCommandManifest::GetParameterSets(
    std::vector<command::IParameterSetMetadataSharedPtr>& parameterSets) const
{
    assert(parameterSets.empty());
    parameterSets.insert(parameterSets.end(), m_parameterSets.begin(), m_parameterSets.end());
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
    command::IParameterSetMetadataSharedPtr defaultSet = CreateDefaultParameterSet();
    parameterSets.push_back(defaultSet);
}

/**
 * Creates a default parameter set.
 */
command::IParameterSetMetadataSharedPtr ConsoleFileFinderCommandManifest::CreateDefaultParameterSet()
{
    std::vector<command::IIndexedParameterMetadataSharedPtr> indexedParameters;

    command::IIndexedParameterMetadataSharedPtr pathParameter =
        command::IndexedParameterMetadata::Make(L"path", L"The path of directory for searching.");

    command::IIndexedParameterMetadataSharedPtr fileNamePatternParameter =
        command::IndexedParameterMetadata::Make(L"fileNamePattern", L"The pattern of file name.");

    std::vector<command::INamedParameterMetadataSharedPtr> namedParameters;

    return command::ParameterSetMetadata::Make(
        indexedParameters,
        namedParameters);
}
