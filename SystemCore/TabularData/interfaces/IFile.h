#pragma once

#include "IIterator.h"
#include "IRecord.h"

namespace tabular_data {

/**
 * The IFile interface defines a File.
 */
class IFile {
public:
    IFile() = default;
    virtual ~IFile() = default;

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

    /**
     * Gets an iterator of records of file.
     */
    virtual base::IIteratorSharedPtr<IRecordSharedPtr> GetIterator() const = 0;
};

/**
 * Defines the Shared Ptr of File.
 */
using IFileSharedPtr = std::shared_ptr<IFile>;

} // namespace tabular_data
