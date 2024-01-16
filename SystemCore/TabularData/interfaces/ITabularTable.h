#pragma once

#include "ITabularHeader.h"
#include "ITabularRecord.h"
#include "IIterator.h"

namespace tabular_data {

/**
 * The ITabularTable interface defines a Tabular Table.
 */
class ITabularTable {
public:
    ITabularTable() = default;
    virtual ~ITabularTable() = default;

    /**
     * Gets a header of tabular table.
     */
    virtual const ITabularHeaderSharedPtr GetHeader() const = 0;

    /**
     * Gets an iterator of records of tabular table.
     */
    virtual base::IIteratorSharedPtr<ITabularRecordSharedPtr> GetRecordIterator() const = 0;
};

/**
 * Defines the Shared Ptr of Tabular Table.
 */
using ITabularTableSharedPtr = std::shared_ptr<ITabularTable>;

} // namespace tabular_data
