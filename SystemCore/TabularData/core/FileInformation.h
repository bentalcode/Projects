#ifndef FILE_INFORMATION_H_6bccdba5_94c1_4abb_ab89_adf682f10fb3
#define FILE_INFORMATION_H_6bccdba5_94c1_4abb_ab89_adf682f10fb3

#include "IFileInformation.h"

namespace tabular_data {

/**
 * The FileInformation class implements information of a file.
 */
class FileInformation final : public IFileInformation {
public:
    /**
     * Creates File Information.
     */
    static IFileInformationSharedPtr Make(
        const std::wstring& path, 
        size_t size,
        size_t numberOfRecords);

    /**
     * The FileInformation constructor.
     */
    FileInformation(
        const std::wstring& path, 
        size_t size,
        size_t numberOfRecords);

    /**
     * The FileInformation destructor.
     */
    virtual ~FileInformation();

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

private:
    std::wstring m_path;
    size_t m_size;
    size_t m_numberOfRecords;
};

} // namespace tabular_data

#endif // FILE_INFORMATION_H_6bccdba5_94c1_4abb_ab89_adf682f10fb3
