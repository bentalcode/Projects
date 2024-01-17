#ifndef TABULAR_FILE_INFORMATION_H_8f454215_b6f0_498a_b9e5_2c07cc97a8b0
#define TABULAR_FILE_INFORMATION_H_8f454215_b6f0_498a_b9e5_2c07cc97a8b0

#include "ITabularFileInformation.h"
#include "IFileInformation.h"

namespace tabular_data {

/**
 * The TabularFileInformation class implements information of a tabular file.
 */
class TabularFileInformation final : public ITabularFileInformation {
public:
    /**
     * Creates Tabular File Information.
     */
    static ITabularFileInformationSharedPtr Make(
        const IFileInformationSharedPtr fileInformation,
        size_t numberOfTabularRecords);

    /**
     * The TabularFileInformation constructor.
     */
    TabularFileInformation(
        const IFileInformationSharedPtr fileInformation, 
        size_t numberOfTabularRecords);

    /**
     * The TabularFileInformation destructor.
     */
    virtual ~TabularFileInformation();

    /**
     * Gets information of file.
     */
    virtual const IFileInformation& GetFileInformation() const override;

    /**
     * Gets number of tabular records of file.
     */
    virtual size_t GetNumberOfTabularRecords() const override;

private:
    IFileInformationSharedPtr m_fileInformation;
    size_t m_numberOfTabularRecords;
};

} // namespace tabular_data

#endif // TABULAR_FILE_INFORMATION_H_8f454215_b6f0_498a_b9e5_2c07cc97a8b0
