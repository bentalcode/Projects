#pragma once

#include <memory>

namespace TabularData {

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

} // namespace TabularData
