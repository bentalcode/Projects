#ifndef I_TABULAR_RECORD_H_d9fd7cb1_431d_4af7_ba33_d50488e5a125
#define I_TABULAR_RECORD_H_d9fd7cb1_431d_4af7_ba33_d50488e5a125

#include "IRecord.h"
#include <vector>

namespace tabular_data {

/**
 * The ITabularRecord interface defines a Tabular Record.
 */
class ITabularRecord : public IRecord {
public:
    ITabularRecord() = default;
    virtual ~ITabularRecord() = default;

    /**
     * Gets a value by index.
     */
    virtual const std::wstring& GetValue(size_t index) const = 0;

    /**
     * Gets number of values.
     */
    virtual size_t GetSize() const = 0;

    /**
     * Gets all values.
     */
    virtual void GetValues(std::vector<std::wstring>& values) const = 0;
};

/**
 * Defines the Shared Ptr of Tabular Record.
 */
using ITabularRecordSharedPtr = std::shared_ptr<ITabularRecord>;

} // namespace tabular_data

#endif // I_TABULAR_RECORD_H_d9fd7cb1_431d_4af7_ba33_d50488e5a125
