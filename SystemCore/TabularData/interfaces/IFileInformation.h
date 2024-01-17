#ifndef I_FILE_INFORMATION_H_f8aef637_a7b6_4eef_b323_bf912555959e
#define I_FILE_INFORMATION_H_f8aef637_a7b6_4eef_b323_bf912555959e

#include "IRecord.h"

namespace tabular_data {

/**
 * The IFileInformation interface defines information of a file.
 */
class IFileInformation {
public:
    IFileInformation() = default;
    virtual ~IFileInformation() = default;

    /**
     * Gets path of file.
     */
    virtual const std::wstring& GetPath() const = 0;

    /**
     * Gets size of file in bytes.
     */
    virtual size_t GetSize() const = 0;

    /**
     * Gets number of records of file.
     */
    virtual size_t GetNumberOfRecords() const = 0;
};

/**
 * Defines the Shared Ptr of File Information.
 */
using IFileInformationSharedPtr = std::shared_ptr<IFileInformation>;

} // namespace tabular_data

#endif // I_FILE_INFORMATION_H_f8aef637_a7b6_4eef_b323_bf912555959e

