#include "WindowsSystemPath.h"
#include "StringSearch.h"
#include "Strings.h"
#include "InvalidArgumentException.h"
#include <assert.h>

using namespace base;
using namespace base::environment::windows;

const std::vector<std::wstring> WindowsSystemPath::DEVICE_PATH_PREFIXES1 = {L"\\\\?"};
const std::vector<std::wstring> WindowsSystemPath::DEVICE_PATH_PREFIXES2 = {L"\\\\."};
const std::wstring WindowsSystemPath::UNC_PATH_PREFIX = L"\\\\";
const std::wstring WindowsSystemPath::DOS_ROOT_NAME_POSTFIX = L":\\";
const std::wstring WindowsSystemPath::LEGACY_DEVICE_PATH_PREFIX = L"\\\\. \\";
const std::wstring WindowsSystemPath::RELATIVE_TO_ROOT_OF_CURRENT_DRIVE_PREFIX = L"\\";
const std::wstring WindowsSystemPath::RELATIVE_TO_CURRENT_DIRECTORY_OF_SPECIFIED_DRIVE_POSTFIX = L":";

/**
 * The WindowsSystemPath constructor.
 */
WindowsSystemPath::WindowsSystemPath()
{
}

/**
 * The WindowsSystemPath destructor.
 */
WindowsSystemPath::~WindowsSystemPath()
{
}

/**
 * Gets type of a path.
 */
WindowsSystemPathType WindowsSystemPath::GetPathType(const std::wstring& path)
{
    if (IsLegacyDevicePath(path))
    {
        return WindowsSystemPathType::LEGACY_DEVICE_PATH;
    }
    else if (IsDevicePath(path))
    {
        return WindowsSystemPathType::DEVICE_PATH;
    }
    else if (IsUncPath(path))
    {
        return WindowsSystemPathType::UNC_PATH;
    }
    else if (IsRelativeToRootOfCurrentDrivePath(path))
    {
        return WindowsSystemPathType::RELATIVE_TO_ROOT_CURRENT_DRIVE;
    }
    else if (IsDosPath(path))
    {
        return WindowsSystemPathType::DOS_PATH;
    }
    else if (IsRelativeToCurrentDirectoryOfSpecifiedDrivePath(path))
    {
        return WindowsSystemPathType::RELATIVE_TO_CURRENT_DIRECTORY_OF_SPECIFIED_DRIVE;
    }
    else
    {
        return WindowsSystemPathType::RELATIVE_TO_CURRENT_DIRECTORY;
    }
}

/**
 * Checks whether a path is a device path.
 */
bool WindowsSystemPath::IsDevicePath(const std::wstring& path)
{
    std::wstring formattedPath = FormatPath(path);

    return
        InternalIsDevice1Path(formattedPath) ||
        (InternalIsDevice2Path(formattedPath) && !InternalIsLegacyDevicePath(formattedPath));
}

/**
 * Checks whether a path is a UNC path.
 */
bool WindowsSystemPath::IsUncPath(const std::wstring& path)
{
    std::wstring formattedPath = FormatPath(path);

    return
        InternalIsUncPath(formattedPath) &&
        !InternalIsDevicePath(formattedPath) &&
        !InternalIsLegacyDevicePath(formattedPath);
}

/**
 * Checks whether a path is a DOS path.
 */
bool WindowsSystemPath::IsDosPath(const std::wstring& path)
{
    std::wstring formattedPath = FormatPath(path);
    return InternalIsDosPath(formattedPath);
}

/**
 * Checks whether a path is a legacy device path.
 */
bool WindowsSystemPath::IsLegacyDevicePath(const std::wstring& path)
{
    std::wstring formattedPath = FormatPath(path);
    return InternalIsLegacyDevicePath(formattedPath);
}

/**
 * Checks whether a path is a Relative to Root of Current Drive path.
 */
bool WindowsSystemPath::IsRelativeToRootOfCurrentDrivePath(const std::wstring& path)
{
    std::wstring formattedPath = FormatPath(path);

    return
        InternalIsRelativeToRootOfCurrentDrivePath(formattedPath) &&
        !InternalIsDevicePath(formattedPath) &&
        !InternalIsUncPath(formattedPath) &&
        !InternalIsLegacyDevicePath(formattedPath);
}

/**
 * Checks whether a path is a Relative to Current Directory of Specified Drive path.
 */
bool WindowsSystemPath::IsRelativeToCurrentDirectoryOfSpecifiedDrivePath(const std::wstring& path)
{
    std::wstring formattedPath = FormatPath(path);

    return
        InternalIsRelativeToCurrentDirectoryOfSpecifiedDrivePath(formattedPath) &&
        !InternalIsDosPath(formattedPath);
}

/**
 * Checks whether a path is a Relative to Current Directory.
 */
bool WindowsSystemPath::IsRelativeToCurrentDirectory(const std::wstring& path)
{
    std::wstring formattedPath = FormatPath(path);

    return
        !InternalIsDevicePath(formattedPath) &&
        !InternalIsUncPath(formattedPath) &&
        !InternalIsDosPath(formattedPath) &&
        !InternalIsLegacyDevicePath(formattedPath) &&
        !InternalIsRelativeToRootOfCurrentDrivePath(formattedPath) &&
        !InternalIsRelativeToCurrentDirectoryOfSpecifiedDrivePath(formattedPath);
}

/**
 * Checks whether a path is valid.
 */
bool WindowsSystemPath::IsPathValid(const std::wstring& path)
{
    return true;
}

/**
 * Validates path.
 */
void WindowsSystemPath::ValidatePath(const std::wstring& path)
{
    if (!IsPathValid(path))
    {
        throw InvalidArgumentException(L"The input path is not valid.");
    }
}

/**
 * Formats a path.
 */
std::wstring WindowsSystemPath::FormatPath(const std::wstring& path)
{
    ValidatePath(path);

    std::wstring formattedPath(path);
    Strings::Trim(formattedPath);
    return formattedPath;
}

/**
 * Checks whether a path is a device path.
 */
bool WindowsSystemPath::InternalIsDevicePath(const std::wstring& path)
{
    return
        InternalIsDevice1Path(path) ||
        InternalIsDevice2Path(path);
}

/**
 * Checks whether a path is a device1 path.
 */
bool WindowsSystemPath::InternalIsDevice1Path(const std::wstring& path)
{
    std::vector<std::wstring> prefixes;
    GetDevicePathPrefixes1(prefixes);
    return IsDevicePath(path);
}

/**
 * Checks whether a path is a device2 path.
 */
bool WindowsSystemPath::InternalIsDevice2Path(const std::wstring& path)
{
    std::vector<std::wstring> prefixes;
    GetDevicePathPrefixes2(prefixes);
    return IsDevicePath(path);
}

/**
 * Checks whether a path is a UNC path.
 */
bool WindowsSystemPath::InternalIsUncPath(const std::wstring& path)
{
    std::vector<std::wstring> prefixes;
    GetUncPathPrefixes(prefixes);
    return IsPathMatch(path, prefixes);
}

/**
 * Checks whether a path is a DOS path.
 */
bool WindowsSystemPath::InternalIsDosPath(const std::wstring& path)
{
    std::vector<std::wstring> prefixes;
    GetDosPathPrefixes(prefixes);
    return IsPathMatch(path, prefixes);
}

/**
 * Checks whether a path is a legacy device path.
 */
bool WindowsSystemPath::InternalIsLegacyDevicePath(const std::wstring& path)
{
    std::vector<std::wstring> prefixes;
    GetLegacyDevicePathPrefixes(prefixes);
    return IsPathMatch(path, prefixes);
}

/**
 * Checks whether a path is a Relative to Root of Current Drive path.
 */
bool WindowsSystemPath::InternalIsRelativeToRootOfCurrentDrivePath(const std::wstring& path)
{
    std::vector<std::wstring> prefixes;
    GetRelativeToRootOfCurrentDrivePathPrefixes(prefixes);
    return IsPathMatch(path, prefixes);
}

/**
 * Checks whether a path is a Relative to Current Directory of Specified Drive path.
 */
bool WindowsSystemPath::InternalIsRelativeToCurrentDirectoryOfSpecifiedDrivePath(const std::wstring& path)
{
    std::vector<std::wstring> prefixes;
    GetRelativeToCurrentDirectoryOfSpecifiedDrivePathPrefixes(prefixes);
    return IsPathMatch(path, prefixes);
}

/**
 * Checks whether a path is mataching to specified properties.
 */
bool WindowsSystemPath::IsPathMatch(
    const std::wstring& path,
    const std::vector<std::wstring>& prefixes)
{
    for (const std::wstring& prefix : prefixes)
    {
        if (StringSearch::StartsWith(path, prefix))
        {
            return true;
        }
    }

    return false;
}

/**
 * Gets Device path prefixes1.
 *
 * [They are device paths;
 *  that is, they begin with two separators and a question mark or period (\\? or \\.)]
 */
void WindowsSystemPath::GetDevicePathPrefixes1(std::vector<std::wstring>& prefixes)
{
    assert(prefixes.empty());

    prefixes.insert(
        prefixes.end(),
        DEVICE_PATH_PREFIXES1.begin(),
        DEVICE_PATH_PREFIXES1.end());
}

/**
 * Gets Device path prefixes2.
 *
 * [They are device paths;
 *  that is, they begin with two separators and a question mark or period (\\? or \\.)]
 */
void WindowsSystemPath::GetDevicePathPrefixes2(std::vector<std::wstring>& prefixes)
{
    assert(prefixes.empty());

    prefixes.insert(
        prefixes.end(),
        DEVICE_PATH_PREFIXES2.begin(),
        DEVICE_PATH_PREFIXES2.end());
}

/**
 * Gets UNC path prefixes.
 *
 * [They are UNC paths; that is, they begin with two separators without a question mark or period.]
 */
void WindowsSystemPath::GetUncPathPrefixes(std::vector<std::wstring>& prefixes)
{
    assert(prefixes.empty());

    prefixes.reserve(1);
    prefixes.push_back(UNC_PATH_PREFIX);
}

/**
 * Gets DOS path prefixes.
 *
 * [ They are fully qualified DOS paths;
 *   that is, they begin with a drive letter, a volume separator, and a component separator (C:\).]
 */
void WindowsSystemPath::GetDosPathPrefixes(std::vector<std::wstring>& prefixes)
{
    assert(prefixes.empty());

    RootNamesSharedPtr rootNames = GetRootNames();
    prefixes.reserve(rootNames->size());

    for (std::wstring::value_type rootName : *rootNames) {
        std::wstring prefix(1, rootName);
        prefix += DOS_ROOT_NAME_POSTFIX;

        prefixes.push_back(prefix);
    }
}

/**
 * Gets Legacy Device path prefixes.
 *
 * [They designate a legacy device (CON, LPT1).
 *  A legacy device path is a path that starts with a legacy device name, such as COM1, CON, or LPT1.
 *  COM1 => \\. \COM1
 *  CON => \\. \CON
 *  LPT1 => \\. \LPT1 ]
 */
void WindowsSystemPath::GetLegacyDevicePathPrefixes(std::vector<std::wstring>& prefixes)
{
    assert(prefixes.empty());

    prefixes.reserve(1);
    prefixes.push_back(LEGACY_DEVICE_PATH_PREFIX);
}

/**
 * Gets Relative Root of Current Drive path prefixes.
 *
 * [They are relative to the root of the current drive; that is, they begin with a single component separator (\).]
 */
void WindowsSystemPath::GetRelativeToRootOfCurrentDrivePathPrefixes(std::vector<std::wstring>& prefixes)
{
    assert(prefixes.empty());

    prefixes.reserve(1);
    prefixes.push_back(RELATIVE_TO_ROOT_OF_CURRENT_DRIVE_PREFIX);
}

/**
 * Gets relative to Current Directory of a Specified Drive path prefixes.
 *
 * [They are relative to the current directory of a specified drive;
 *  that is, they begin with a drive letter, a volume separator, and no component separator (C:).]
 */
void WindowsSystemPath::GetRelativeToCurrentDirectoryOfSpecifiedDrivePathPrefixes(
    std::vector<std::wstring>& prefixes)
{
    assert(prefixes.empty());

    prefixes.reserve(1);
    prefixes.push_back(RELATIVE_TO_CURRENT_DIRECTORY_OF_SPECIFIED_DRIVE_POSTFIX);
}

/**
 * Gets root names.
 */
WindowsSystemPath::RootNamesSharedPtr WindowsSystemPath::GetRootNames()
{
    static RootNamesSharedPtr rootNames(CreateRootNames());
    return rootNames;
}

/**
 * Initializes root names.
 */
WindowsSystemPath::RootNamesSharedPtr WindowsSystemPath::CreateRootNames()
{
    RootNamesSharedPtr rootNames = std::make_shared<RootNames>();

    for (std::wstring::value_type rootName = 'A'; rootName <= 'Z'; ++rootName) {
        rootNames->push_back(rootName);
    }

    return rootNames;
}
