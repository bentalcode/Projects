#pragma once

#include <string>
#include <memory>

namespace TabularData {

/**
 * The IRecord interface defines a Record.
 */
class IRecord {
public:
    IRecord() = default;
    virtual ~IRecord() = default;

    /**
     * Gets an index of a record.
     */
    virtual size_t GetIndex() const = 0;

    /**
     * Gets a content of record.
     */
    virtual const std::wstring& GetContent() const = 0;
};

/**
 * Defines the Shared Ptr of Record.
 */
using IRecordSharedPtr = std::shared_ptr<IRecord>;

} // namespace TabularData