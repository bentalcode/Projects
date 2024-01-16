#include "TabularHeader.h"
#include <vector>
#include <assert.h>

using namespace TabularData;

/**
 * Creates a Tabular Header.
 */
ITabularHeaderSharedPtr TabularHeader::Make(const std::vector<std::wstring>& headers)
{
    return std::make_shared<TabularHeader>(headers);
}

/**
 * The TabularHeader constructor.
 */
TabularHeader::TabularHeader(const std::vector<std::wstring>& headers) : 
    m_headers(headers)
{
}

/**
 * The TabularHeader destructor.
 */
TabularHeader::~TabularHeader() 
{
}

/**
 * Gets a header by index.
 */
const std::wstring& TabularHeader::GetHeader(size_t index) const 
{
    return m_headers[index];
}

/**
 * Gets number of headers.
 */
size_t TabularHeader::GetSize() const
{
    return m_headers.size();
}

/**
 * Gets all headers.
 */
void TabularHeader::GetHeaders(std::vector<std::wstring>& headers) const
{
    assert(headers.empty());
    headers.insert(headers.end(), m_headers.begin(), m_headers.end());
}
