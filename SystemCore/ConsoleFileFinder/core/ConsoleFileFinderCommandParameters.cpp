#include "ConsoleFileFinderCommandParameters.h"

using namespace consolefilefinder;

/**
 * Creates a console file finder command parameters.
 */
IConsoleFileFinderCommandParametersSharedPtr ConsoleFileFinderCommandParameters::Make(
    const Command::ICommandParameters& parameters)
{
    return std::make_shared<ConsoleFileFinderCommandParameters>(parameters);
}

/**
 * The ConsoleFileFinderCommandParameters constructor.
 */
ConsoleFileFinderCommandParameters::ConsoleFileFinderCommandParameters(const Command::ICommandParameters& parameters)
{
    const Command::IParameterSet& parameterSet = parameters.GetParameterSet();
    Command::IParameterSharedPtr pathParameter = parameterSet.GetParameter(L"dirPath");
    m_path = pathParameter->GetStringValue();

    Command::IParameterSharedPtr filePatternsParameter = parameterSet.GetParameter(L"fileNamePatterns");

    if (parameters.GetParameterSet().GetIndex() == 0) {
        std::wstring filePattern = filePatternsParameter->GetStringValue();
        m_filePatterns.push_back(filePattern);
    }
    else {
        filePatternsParameter->GetStringArrayValue(m_filePatterns);
    }
}

/**
 * The ConsoleFileFinderCommandParameters destructor.
 */
ConsoleFileFinderCommandParameters::~ConsoleFileFinderCommandParameters()
{
}

/**
 * Gets path of the directory to search.
 */
const std::wstring& ConsoleFileFinderCommandParameters::GetPath() const
{
    return m_path;
}

/**
 * Gets file patterns.
 */
const std::vector<std::wstring>& ConsoleFileFinderCommandParameters::GetFilePatterns() const
{
    return m_filePatterns;
}