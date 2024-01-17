#ifndef I_TABULAR_FILE_H_6d812873_e439_4f2e_8c08_dfbd2cc6bb1b
#define I_TABULAR_FILE_H_6d812873_e439_4f2e_8c08_dfbd2cc6bb1b

#include <memory>

namespace tabular_data {

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

} // namespace tabular_data

#endif // I_TABULAR_FILE_H_6d812873_e439_4f2e_8c08_dfbd2cc6bb1b
