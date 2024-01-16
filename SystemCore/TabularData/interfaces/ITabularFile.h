#pragma once

#include <memory>

namespace TabularData {

class IFile;
class ITabularTable;

/**
 * The ITabularFile interface defines a Tabular File.
 */
class ITabularFile {
public:
    ITabularFile() = default;
    virtual ~ITabularFile() = default;

    /**
     * Gets file.
     */
    virtual const IFile& GetFile() const = 0;

    /**
     * Gets tabular table.
     */
    virtual const ITabularTable& GetTabularTable() const = 0;
};

/**
 * Defines the Shared Ptr of Tabular File.
 */
using ITabularFileSharedPtr = std::shared_ptr<ITabularFile>;

} // namespace TabularData
