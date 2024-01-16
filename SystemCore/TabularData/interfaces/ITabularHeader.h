#pragma once

#include <string>
#include <vector>
#include <memory>

namespace tabular_data {

/**
 * The ITabularHeader interface defines a Tabular Header.
 */
class ITabularHeader {
public:
    ITabularHeader() = default;
    virtual ~ITabularHeader() = default;

    /**
     * Gets a header by index.
     */
    virtual const std::wstring& GetHeader(size_t index) const = 0;

    /**
     * Gets number of headers.
     */
    virtual size_t GetSize() const = 0;

    /**
     * Gets all headers.
     */
    virtual void GetHeaders(std::vector<std::wstring>& headers) const = 0;
};

/**
 * Defines the Shared Ptr of Tabular Header.
 */
using ITabularHeaderSharedPtr = std::shared_ptr<ITabularHeader>;

} // namespace tabular_data
