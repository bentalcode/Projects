#pragma once

#include "ITabularHeader.h"

namespace tabular_data {

/**
 * The TabularHeader class implements a Tabular Header.
 */
class TabularHeader final : public ITabularHeader {
public:
    /**
     * Creates a Tabular Header.
     */
    static ITabularHeaderSharedPtr Make(const std::vector<std::wstring>& headers);

    /**
     * The TabularHeader constructor.
     */
    TabularHeader(const std::vector<std::wstring>& headers);

    /**
     * The TabularHeader destructor.
     */
    virtual ~TabularHeader();

    /**
     * Gets a header by index.
     */
    virtual const std::wstring& GetHeader(size_t index) const override;

    /**
     * Gets number of headers.
     */
    virtual size_t GetSize() const override;

    /**
     * Gets all headers.
     */
    virtual void GetHeaders(std::vector<std::wstring>& headers) const override;

private:
    std::vector<std::wstring> m_headers;
};

} // namespace tabular_data
