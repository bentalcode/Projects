#pragma once

#include "IRecord.h"

namespace TabularData {

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

} // namespace TabularData
