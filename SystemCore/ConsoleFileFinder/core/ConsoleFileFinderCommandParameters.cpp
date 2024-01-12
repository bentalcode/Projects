#include "ConsoleFileFinderCommandParameters.h"

using namespace consolefilefinder;

/**
 * Creates a console file finder command parameters.
 */
IConsoleFileFinderCommandParametersSharedPtr ConsoleFileFinderCommandParameters::Make(
    const command::ICommandParameters& parameters)
{
    return std::make_shared<ConsoleFileFinderCommandParameters>(parameters);
}

/**
 * The ConsoleFileFinderCommandParameters constructor.
 */
ConsoleFileFinderCommandParameters::ConsoleFileFinderCommandParameters(const command::ICommandParameters& parameters)
{
    const command::IParameterSet& parameterSet = parameters.GetParameterSet();
    command::IParameterSharedPtr pathParameter = parameterSet.GetParameter(L"path");
    m_path = pathParameter->GetStringValue();

    command::IParameterSharedPtr filePatternsParameter = parameterSet.GetParameter(L"filePatterns");
    filePatternsParameter->GetStringArrayValue(m_filePatterns);
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