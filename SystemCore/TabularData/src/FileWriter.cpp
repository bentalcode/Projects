#include "FileWriter.h"
#include "ErrorCodes.h"
#include "TabularDataException.h"
#include <sstream>

using namespace TabularData;

/**
 * Creates a File Writer.
 */
IWriterSharedPtr FileWriter::Make(const std::wstring& path)
{
    return std::make_shared<FileWriter>(path);
}

/**
 * The FileWriter constructor.
 */
FileWriter::FileWriter(const std::wstring& path)
{
    OpenFileStream(path, m_stream);
}

/**
 * The FileWriter destructor.
 */
FileWriter::~FileWriter() 
{
    CloseFileStream(m_stream);
}

/**
 * Writes a line.
 */
void FileWriter::WriteLine(const std::wstring& line) 
{
    m_stream << line << std::endl;
}

/**
 * Writes a new line.
 */
void FileWriter::NewLine()
{
    m_stream << std::endl;
}
    
/**
 * Opens file stream.
 */
void FileWriter::OpenFileStream(
    const std::wstring& path,
    std::wofstream& stream)
{
    stream.open(path.c_str(), std::ofstream::out);

    if (!stream.is_open() || !stream.good()) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        stream 
            << L"The File Writer has failed opening stream successfully at path: " << path
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw TabularDataException(errorCode, errorMessage);
    }
}

/**
 * Closes file stream.
 */
void FileWriter::CloseFileStream(std::wofstream& stream) 
{
    stream.close();
}
