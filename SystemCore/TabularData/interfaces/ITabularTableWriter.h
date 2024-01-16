#pragma once

#include "ITabularHeader.h"
#include "ITabularRecord.h"

namespace TabularData {

/**
 * The ITabularTableWriter interface defines a writer of a Tabular Table.
 */
class ITabularTableWriter {
public:
    ITabularTableWriter() = default;
    virtual ~ITabularTableWriter() = default;

    /**
     * Writes a header.
     */
    virtual void WriteHeader(const ITabularHeader& header) = 0;

    /**
     * Writes a record.
     */
    virtual void WriteRecord(const ITabularRecord& record) = 0;

    /**
     * Writes a new line.
     */
    virtual void NewLine() = 0;
};

/**
 * Defines the Shared Ptr of ITabularTableWriter.
 */
using ITabularTableWriterSharedPtr = std::shared_ptr<ITabularTableWriter>;

} // namespace TabularData
