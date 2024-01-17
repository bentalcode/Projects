#include "TabularRecord.h"
#include <vector>
#include <assert.h>

using namespace tabular_data;

/**
 * Creates a Tabular Record.
 */
ITabularRecordSharedPtr TabularRecord::Make(
    size_t index, 
    const std::wstring& content, 
    const std::vector<std::wstring>& values)
{
    return std::make_shared<TabularRecord>(
        index, 
        content, 
        values);
}

/**
 * The TabularRecord constructor.
 */
TabularRecord::TabularRecord(
    size_t index, 
    const std::wstring& content,
    const std::vector<std::wstring>& values) : 
    m_index(index), 
    m_content(content),
    m_values(values) 
{
}

/**
 * The TabularRecord destructor.
 */
TabularRecord::~TabularRecord() 
{
}

/**
 * Gets an index of a record.
 */
size_t TabularRecord::GetIndex() const
{
    return m_index;
}

/**
 * Gets a content of record.
 */
const std::wstring& TabularRecord::GetContent() const
{
    return m_content;
}

/**
 * Gets a value by index.
 */
const std::wstring& TabularRecord::GetValue(size_t index) const
{
    return m_values[index];
}

/**
 * Gets number of values.
 */
size_t TabularRecord::GetSize() const
{
    return m_values.size();
}

/**
 * Gets all values.
 */
void TabularRecord::GetValues(std::vector<std::wstring>& values) const
{
    assert(values.empty());
    values.insert(values.end(), m_values.begin(), m_values.end());
}
