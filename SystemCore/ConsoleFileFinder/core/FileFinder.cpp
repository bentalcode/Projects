#include "FileFinder.h"
#include "ConsoleFileFinderException.h"
#include <iostream>
#include <dirent.h>
#include <vector>
#include <fileapi.h>
#include "WinHandle.h"
#include "PathBuilder.h"

using namespace consolefilefinder;

namespace FileFinderFunctors {
    /**
     * The FindHandleReleaserFunctor class implements a functor for releasing a find handle.
     */
    class FindHandleReleaserFunctor final {
    public:
        void operator()(HANDLE value) {
            ::FindClose(value);
        }
    };
}

/**
 * The FileFinder constructor.
 */
FileFinder::FileFinder()
{
}

/**
 * The FileFinder destructor.
 */
FileFinder::~FileFinder()
{
}

/**
 * Finds matching files based on patterns.
 */
void FileFinder::FindFiles(
    const std::wstring& path,
    const std::vector<std::wstring>& filePatterns,
    std::list<std::wstring>& resultantPaths) {

    //
    // Finds matching files and subdirectories in current directory...
    //
    std::list<std::wstring> filePaths;
    std::list<std::wstring> subDirectories;

    FindFilesAndSubDirectories(
        path,
        filePatterns,
        subDirectories,
        filePaths);

    resultantPaths.insert(resultantPaths.end(), filePaths.begin(), filePaths.end());

    //
    // Continue the search recursively at subdirectories...
    //
    for (const std::wstring& subDirectory : subDirectories) {
        FindFiles(
            subDirectory,
            filePatterns,
            resultantPaths);
    }
}

/**
 * Finds matching files based on patterns and sub directories.
 */
void FileFinder::FindFilesAndSubDirectories(
    const std::wstring& path,
    const std::vector<std::wstring>& filePatterns,
    std::list<std::wstring>& subDirectories,
    std::list<std::wstring>& resultantPaths)
{
    std::wstring dirPattern = CreatePath(path, L"*");

    WIN32_FIND_DATAW findDirData;
    HANDLE hSearch = ::FindFirstFileW(dirPattern.c_str(), &findDirData);

    base::Handle<HANDLE>::IReleaserFunctorSharedPtr releaserFunctor =
        std::make_shared<base::Handle<HANDLE>::IReleaserFunctor>(
            FileFinderFunctors::FindHandleReleaserFunctor{});

    base::windows::WinHandle findHandle(
        hSearch,
        releaserFunctor);

    while (true) {
        WIN32_FIND_DATAW findFileData;
        BOOL status = ::FindNextFileW(findHandle.get(), &findFileData);

        if (!status) {
            long errorCode = GetLastError();

            if (errorCode == ERROR_NO_MORE_FILES) {
                break;
            }

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"File Finder has failed finding next file at directory: " << path
                << L"; ErrorCode: " << errorCode;

            std::wstring errorMessage = errorMessageStream.str();
            throw ConsoleFileFinderException(errorCode, errorMessage);
        }

        std::wstring fileName(&findFileData.cFileName[0]);

        if (!IsFileUpperDirectory(fileName)) {
            std::wstring filePath = CreatePath(path, fileName);

            if (IsDirectory(filePath)) {
                subDirectories.push_back(filePath);
            } else if (isMatchingFileName(fileName, filePatterns)) {
                resultantPaths.push_back(filePath);
            }
        }
    }
}

/**
 * Checks whether a file name is matching specified patterns.
 */
bool FileFinder::isMatchingFileName(
    const std::wstring& name,
    const std::vector<std::wstring>& patterns) {

    if (patterns.empty()) {
        return true;
    }

    for (const std::wstring& pattern : patterns) {
        if (name.find(pattern) != std::wstring::npos) {
            return true;
        }
    }

    return false;
}

/**
 * Checks whether a path is a directory.
 */
bool FileFinder::IsDirectory(const std::wstring& path)
{
    DWORD attrib = ::GetFileAttributesW(path.c_str());

    if (attrib == INVALID_FILE_ATTRIBUTES) {
        long errorCode = GetLastError();

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"File Finder has failed reading attributes of file: " << path.c_str()
            << L"; ErrorCode: " << errorCode;

        std::wstring errorMessage = errorMessageStream.str();
        throw ConsoleFileFinderException(errorCode, errorMessage);
    }

    return (attrib & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

/**
 * Checks whether a file name is an upper directory.
 */
bool FileFinder::IsFileUpperDirectory(const std::wstring& name) {
    return name == L"..";
}

/**
 * Creates a path.
 */
std::wstring FileFinder::CreatePath(
    const std::wstring& left,
    const std::wstring& right)
{
    base::PathBuilder builder(left);
    builder.AddComponent(right);
    return builder.Build();
}
