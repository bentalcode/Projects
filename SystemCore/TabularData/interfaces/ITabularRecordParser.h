#pragma once

#include "ITabularRecord.h"

namespace tabular_data {

/**
 * The ITabularRecordParser interface defines a parser of a Tabular Record.
 */
class ITabularRecordParser {
public:
    ITabularRecordParser() = default;
    virtual ~ITabularRecordParser() = default;

    /**
     * Parses a record.
     */
    virtual ITabularRecordSharedPtr Parse(
        size_t recordIndex,
        const std::wstring& content) const = 0;
};

/**
 * Defines the Shared Ptr of Tabular Record Parser.
 */
using ITabularRecordParserSharedPtr = std::shared_ptr<ITabularRecordParser>;

}  // namespace tabular_data

