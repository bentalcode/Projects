#ifndef FILE_H_63616acb_4e57_4c35_8e8f_29fb0b3d1e01
#define FILE_H_63616acb_4e57_4c35_8e8f_29fb0b3d1e01

#include "IFile.h"

namespace tabular_data {

/**
 * The LogFile class implements a File.
 */
class File final : public IFile {
public:
    /**
     * Creates a File.
     */
    static IFileSharedPtr Make(const std::wstring& path);

    /**
     * The File constructor.
     */
    explicit File(const std::wstring& path);

    /**
     * The File destructor.
     */
    virtual ~File();

    /**
     * Gets path of file.
     */
    virtual const std::wstring& GetPath() const override;

    /**
     * Gets size of file in bytes.
     */
    virtual size_t GetSize() const override;

    /**
     * Gets number of records of file.
     */
    virtual size_t GetNumberOfRecords() const override;

    /**
     * Gets an iterator of records of file.
     */
    virtual base::IIteratorSharedPtr<IRecordSharedPtr> GetIterator() const override;

private:
    std::wstring m_path;
};

} // namespace tabular_data

#endif // FILE_H_63616acb_4e57_4c35_8e8f_29fb0b3d1e01

