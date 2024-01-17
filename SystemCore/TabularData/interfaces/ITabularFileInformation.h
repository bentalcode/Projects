#ifndef I_TABULAR_FILE_INFORMATION_H_35a784e3_e02c_41a7_8767_f1b69c796c20
#define I_TABULAR_FILE_INFORMATION_H_35a784e3_e02c_41a7_8767_f1b69c796c20

#include <memory>

namespace tabular_data {

class IFileInformation;

/**
 * The ITabularFileInformation interface defines information of a tabular file.
 */
class ITabularFileInformation {
public:
    ITabularFileInformation() = default;
    virtual ~ITabularFileInformation() = default;

    /**
     * Gets information of file.
     */
    virtual const IFileInformation& GetFileInformation() const = 0;

    /**
     * Gets number of tabular records of file.
     */
    virtual size_t GetNumberOfTabularRecords() const = 0;
};

/**
 * Defines the Shared Ptr of Tabular File Information.
 */
using ITabularFileInformationSharedPtr = std::shared_ptr<ITabularFileInformation>;

} // namespace tabular_data

#endif // I_TABULAR_FILE_INFORMATION_H_35a784e3_e02c_41a7_8767_f1b69c796c20
