#include "FileInformation.h"

using namespace TabularData;

/**
 * Creates File Information.
 */
IFileInformationSharedPtr FileInformation::Make(
    const std::wstring& path, 
    size_t size,
    size_t numberOfRecords)
{
    return std::make_shared<FileInformation>(
        path, 
        size,
        numberOfRecords);
}

/**
 * The File Information constructor.
 */
FileInformation::FileInformation(
    const std::wstring& path, 
    size_t size,
    size_t numberOfRecords) : 
    m_path(path), 
    m_size(size),
    m_numberOfRecords(numberOfRecords)
{
}

/**
 * The FileInformation destructor.
 */
FileInformation::~FileInformation() 
{
}

/**
 * Gets path of file.
 */
const std::wstring& FileInformation::GetPath() const
{
    return m_path;
}

/**
 * Gets size of file in bytes.
 */
size_t FileInformation::GetSize() const
{
    return m_size;
}

/**
 * Gets number of records of file.
 */
size_t FileInformation::GetNumberOfRecords() const
{
    return m_numberOfRecords;
}
