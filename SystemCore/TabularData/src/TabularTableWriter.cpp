#include "TabularTableWriter.h"
#include "FileWriter.h"
#include <sstream>

using namespace tabular_data;

/**
 * Creates a Tabular Table Writer.
 */
ITabularTableWriterSharedPtr TabularTableWriter::Make(
    const std::wstring& path,
    const std::wstring& separator)
{
    return std::make_shared<TabularTableWriter>(path, separator);
}

/**
 * The TabularTableWriter constructor.
 */
TabularTableWriter::TabularTableWriter(
    const std::wstring& path,
    const std::wstring& separator) : 
    m_writer(FileWriter::Make(path)), 
    m_separator(separator)
{
}

/**
 * The TabularTableWriter destructor.
 */
TabularTableWriter::~TabularTableWriter() 
{
}

/**
 * Writes a header.
 */
void TabularTableWriter::WriteHeader(const ITabularHeader& header)
{
    std::vector<std::wstring> tokens;
    header.GetHeaders(tokens);
    
    std::wstring line = CreateLine(tokens, m_separator);
    m_writer->WriteLine(line);
}

/**
 * Writes a record.
 */
void TabularTableWriter::WriteRecord(const ITabularRecord& record)
{
    std::vector<std::wstring> tokens;
    record.GetValues(tokens);

    std::wstring line = CreateLine(tokens, m_separator);
    m_writer->WriteLine(line);
}

/**
 * Writes a new line.
 */
void TabularTableWriter::NewLine()
{
    m_writer->NewLine();
}

/**
 * Creates a line.
 */
std::wstring TabularTableWriter::CreateLine(
    const std::vector<std::wstring>& tokens, 
    const std::wstring& separator)
{
    std::wstringstream stream;
    
    size_t numOfTokens = tokens.size();

    for (size_t index = 0; index < numOfTokens; ++index) {
        stream << tokens[index];
        
        if (index < numOfTokens - 1) {
            stream << separator;
        }
    }

    return stream.str();
}
