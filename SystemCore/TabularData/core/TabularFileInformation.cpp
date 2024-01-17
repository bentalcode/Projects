#include "TabularFileInformation.h"
#include "SmartPointers.h"

using namespace tabular_data;

/**
 * Creates Tabular File Information.
 */
ITabularFileInformationSharedPtr TabularFileInformation::Make(
    const IFileInformationSharedPtr fileInformation,
    size_t numberOfTabularRecords)
{
    return std::make_shared<TabularFileInformation>(
        fileInformation, 
        numberOfTabularRecords);
}

/**
 * The TabularFileInformation constructor.
 */
TabularFileInformation::TabularFileInformation(
    const IFileInformationSharedPtr fileInformation, 
    size_t numberOfTabularRecords) : 
    m_numberOfTabularRecords(numberOfTabularRecords)
{
    base::SmartPointers::Validate<IFileInformation>(fileInformation);
    m_fileInformation = fileInformation;
}

/**
 * The TabularFileInformation destructor.
 */
TabularFileInformation::~TabularFileInformation() 
{
}

/**
 * Gets information of file.
 */
const IFileInformation& TabularFileInformation::GetFileInformation() const 
{
    return *m_fileInformation;
}

/**
 * Gets number of tabular records of file.
 */
size_t TabularFileInformation::GetNumberOfTabularRecords() const 
{
    return m_numberOfTabularRecords;
}
