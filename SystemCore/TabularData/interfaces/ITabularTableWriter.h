#ifndef I_TABULAR_TABLE_WRITER_H_c268de2c_748b_4b8d_b180_65203d4ca380
#define I_TABULAR_TABLE_WRITER_H_c268de2c_748b_4b8d_b180_65203d4ca380

#include "ITabularHeader.h"
#include "ITabularRecord.h"

namespace tabular_data {

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

} // namespace tabular_data

#endif // I_TABULAR_TABLE_WRITER_H_c268de2c_748b_4b8d_b180_65203d4ca380
