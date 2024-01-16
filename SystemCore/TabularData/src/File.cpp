#include "File.h"
#include "FileLineIterator.h"
#include <fileapi.h>
#include <errhandlingapi.h>
#include <sstream>
#include "TabularDataException.h"
#include "Handle.h"
#include <stdio.h>

using namespace TabularData;

namespace windows {

    /**
     * The File Handle Releaser releases a windows file handle.
     */
    class FileHandleReleaser final {
    public:
        /**
         * Releases the handle.
         */
        static void Release(FILE* handle)
        {
            ::fclose(handle);
        }
    };

    using FileHandle = base::Handle<FILE*, FileHandleReleaser>;

}  // namespace windows

/**
 * Creates a File.
 */
IFileSharedPtr File::Make(const std::wstring& path) 
{
    return std::make_shared<File>(path);
}

/**
 * The File constructor.
 */
File::File(const std::wstring& path) : 
    m_path(path)
{
}

/**
 * The File destructor.
 */
File::~File() 
{
}

/**
 * Gets path of file.
 */
const std::wstring& File::GetPath() const
{
    return m_path;
}

/**
 * Gets size of file in bytes.
 */
size_t File::GetSize() const
{
    std::wstring mode = L"r";
    FILE* hFile = ::_wfopen(m_path.c_str(), mode.c_str());

    if (hFile == nullptr) {
        long errorCode = GetLastError();

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"File::GetSize() has failed calculating file size of file: " << m_path
            << L"; ErrorCode: " << errorCode;

        std::wstring errorMessage = errorMessageStream.str();
        throw TabularDataException(errorCode, errorMessage);
    }

    windows::FileHandle fileHandle(hFile);

    DWORD fileSizeHigh = 0;
    DWORD sizeInBytes = ::GetFileSize(fileHandle, &fileSizeHigh);

    if (sizeInBytes == INVALID_FILE_SIZE) {
        long errorCode = GetLastError();

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"File::GetSize() has failed calculating file size of file: " << m_path
            << L"; ErrorCode: " << errorCode;

        std::wstring errorMessage = errorMessageStream.str();
        throw TabularDataException(errorCode, errorMessage);
    }

    return sizeInBytes;
}

/**
 * Gets number of records of file.
 */
size_t File::GetNumberOfRecords() const
{
    size_t numberOfRecords = 0;

    base::IIteratorSharedPtr<TabularData::IRecordSharedPtr> recordIterator = GetIterator();

    while (recordIterator->HasNext()) {
        ++numberOfRecords;
    }

    return numberOfRecords;
}

/**
 * Gets an iterator of records of file.
 */
base::IIteratorSharedPtr<TabularData::IRecordSharedPtr> File::GetIterator() const
{
    return TabularData::FileLineIterator::Make(m_path);
}
