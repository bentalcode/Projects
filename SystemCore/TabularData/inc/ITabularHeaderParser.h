#pragma once

#include "ITabularHeader.h"

namespace TabularData {

/**
 * The ITabularHeaderParser interface defines a parser of a Tabular Header.
 */
class ITabularHeaderParser {
public:
    ITabularHeaderParser() = default;
    virtual ~ITabularHeaderParser() = default;

    /**
     * Parses a header.
     */
    virtual ITabularHeaderSharedPtr Parse(const std::wstring& content) const = 0;
};

/**
 * Defines the Shared Ptr of Tabular Header Parser.
 */
using ITabularHeaderParserSharedPtr = std::shared_ptr<ITabularHeaderParser>;

}  // namespace TabularData

