#include "Record.h"

using namespace tabular_data;

/**
 * Creates a Record.
 */
IRecordSharedPtr Record::Make(
    size_t index, 
    const std::wstring& content)
{
    return std::make_shared<Record>(
        index, 
        content);
}

/**
 * The Record constructor.
 */
Record::Record(
    size_t index, 
    const std::wstring& content) : 
    m_index(index), 
    m_content(content)
{
}

/**
 * The Record destructor.
 */
Record::~Record() 
{
}

/**
 * Gets an index of a record.
 */
size_t Record::GetIndex() const 
{
    return m_index;
}

/**
 * Gets a content of record.
 */
const std::wstring& Record::GetContent() const
{
    return m_content;
}
