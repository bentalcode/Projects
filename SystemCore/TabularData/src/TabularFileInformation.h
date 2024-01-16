#pragma once

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
