#ifndef I_RECORD_H_d07c37f6_5172_4aec_9726_f43760119770
#define I_RECORD_H_d07c37f6_5172_4aec_9726_f43760119770

#include <string>
#include <memory>

namespace tabular_data {

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

} // namespace tabular_data

#endif // I_RECORD_H_d07c37f6_5172_4aec_9726_f43760119770
