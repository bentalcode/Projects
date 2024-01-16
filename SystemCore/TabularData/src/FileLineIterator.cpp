#include "FileLineIterator.h"
#include "Record.h"
#include "ErrorCodes.h"
#include <fstream>
#include "TabularDataException.h"
#include <filesystem>

using namespace TabularData;

/**
 * Creates a File Line Iterator.
 */
base::IIteratorSharedPtr<IRecordSharedPtr> FileLineIterator::Make(const std::wstring& path)
{
    return std::make_shared<FileLineIterator>(path);
}

/**
 * The FileLineIterator constructor.
 */
FileLineIterator::FileLineIterator(const std::wstring& path) : 
    m_path(path), 
    m_currLineIndex(0) 
{
    Reset();
}

/**
 * The FileLineIterator destructor.
 */
FileLineIterator::~FileLineIterator() 
{
}

/**
 * Checks whether there is a next element.
 */
bool FileLineIterator::HasNext() const
{
    return !m_fileStream->eof();
}

/**
 * Gets the next element.
 */
IRecordSharedPtr FileLineIterator::Next()
{
    std::wstring m_currLineContent;
    std::getline(*m_fileStream, m_currLineContent);
    
    ++m_currLineIndex;

    return Record::Make(m_currLineIndex, m_currLineContent);
}

/**
 * Resets the iterator.
 */
void FileLineIterator::Reset()
{
    m_currLineIndex = 0;
    m_currLineContent = L"";
    
    m_fileStream = std::make_unique<std::wifstream>(m_path.c_str());

    if (!m_fileStream->is_open()) {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The File Line Iterator has failed openning file at path: " << m_path 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw TabularDataException(errorCode, errorMessage);
    }
}
