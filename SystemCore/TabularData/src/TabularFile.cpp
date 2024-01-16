#include "TabularFile.h"
#include "TabularTable.h"
#include "TabularRecordIterator.h"
#include "File.h"
#include "ErrorCodes.h"
#include "SmartPointers.h"
#include "TabularDataException.h"

using namespace TabularData;

/**
 * Creates a Tabular File.
 */
ITabularFileSharedPtr TabularFile::Make(
    const std::wstring& path, 
    ITabularHeaderParserSharedPtr headerParser,
    ITabularRecordParserSharedPtr recordParser)
{
    return std::make_shared<TabularFile>(
        path, 
        headerParser, 
        recordParser);
}

/**
 * The TabularFile constructor.
 */
TabularFile::TabularFile(
    const std::wstring& path, 
    ITabularHeaderParserSharedPtr headerParser, 
    ITabularRecordParserSharedPtr recordParser) : 
    m_file(TabularData::File::Make(path))
{
    base::SmartPointers::Validate<ITabularHeaderParser>(headerParser);
    base::SmartPointers::Validate<ITabularRecordParser>(recordParser);

    m_headerParser = headerParser;
    m_recordParser = recordParser;

    m_tabularTable = CreateTabularTable();
}

/**
 * The TabularFile destructor.
 */
TabularFile::~TabularFile() 
{
}

/**
 * Gets file.
 */
const IFile& TabularFile::GetFile() const 
{
    return *m_file;
}

/**
 * Gets tabular table.
 */
const ITabularTable& TabularFile::GetTabularTable() const 
{
    return *m_tabularTable;
}

/**
 * Creates a tabular table.
 */
ITabularTableSharedPtr TabularFile::CreateTabularTable()
{
    base::IIteratorSharedPtr<IRecordSharedPtr> recordIterator = m_file->GetIterator();

    ITabularHeaderSharedPtr tabularHeader = ParseTabularHeader(*recordIterator);
    base::IIteratorSharedPtr<ITabularRecordSharedPtr> tabularRecordIterator =
        TabularRecordIterator::Make(
            recordIterator,
            m_recordParser);

    ITabularTableSharedPtr tabularTable = TabularTable::Make(
        tabularHeader, 
        tabularRecordIterator);

    return tabularTable;
}

/**
 * Parses a tabular header.
 */
ITabularHeaderSharedPtr TabularFile::ParseTabularHeader(base::IIterator<IRecordSharedPtr>& recordIterator)
{
    //
    // Retrieve the record of a header...
    //
    if (!recordIterator.HasNext()) {
        long errorCode = base::ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The Tabular File: " << m_file->GetPath() << " does not contain a header."
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw TabularDataException(errorCode, errorMessage);
    }

    //
    // Parse header...
    //
    IRecordSharedPtr record = recordIterator.Next();
    const std::wstring& content = record->GetContent();

    ITabularHeaderSharedPtr header = m_headerParser->Parse(content);

    return header;
}
