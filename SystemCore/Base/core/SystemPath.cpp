#include "SystemPath.h"
#include "NotImplementedException.h"

using namespace base;

/**
 * Creates a new instance of a system path.
 */
ISystemPathSharedPtr SystemPath::Make(const std::wstring& path)
{
    return std::make_shared<SystemPath>(path);
}

/**
 * The SystemPath constructor.
 */
SystemPath::SystemPath(const std::wstring& path) :
    m_path(path)
{  
}

/**
 * The SystemPath destructor.
 */
SystemPath::~SystemPath()
{
}

/**
 * Assigns a new path.
 */
void SystemPath::Assign(const std::wstring& path)
{
    m_path = path;
}

/**
 * Returns the root-name of the path, if present
 */
ISystemPathSharedPtr SystemPath::GetRootName() const
{
    throw NotImplementedException(L"SystemPath::GetRootName()");
}

/**
 * Returns the root directory of the path, if present
 */
ISystemPathSharedPtr SystemPath::GetRootDirectory() const
{
    throw NotImplementedException(L"SystemPath::GetRootDirectory()");
}

/**
 * Returns the root path of the path, if present.
 */
ISystemPathSharedPtr SystemPath::GetRootPath() const
{
    throw NotImplementedException(L"SystemPath::GetRootPath()");
}

/**
 * Returns path relative to the root path.
 */
ISystemPathSharedPtr SystemPath::GetRelativePath() const
{
    throw NotImplementedException(L"SystemPath::GetRelativePath()");
}

/**
 * Returns the path of the parent path.
 */
ISystemPathSharedPtr SystemPath::GetParentPath() const
{
    throw NotImplementedException(L"SystemPath::GetParentPath()");
}

/**
 * Returns the filename path component.
 */
ISystemPathSharedPtr SystemPath::GetFileName() const
{
    throw NotImplementedException(L"SystemPath::GetFileName()");
}

/**
 * Returns the stem path component (filename without the final extension).
 */
ISystemPathSharedPtr SystemPath::GetStem() const
{
    throw NotImplementedException(L"SystemPath::GetStem()");
}

/**
 * Returns the file extension path component.
 */
ISystemPathSharedPtr SystemPath::GetExtension() const
{
    throw NotImplementedException(L"SystemPath::GetExtension()");
}

/**
 * Checks whether a path is empty.
 */
bool SystemPath::Empty() const
{
    return m_path.empty();
}

/**
 * Checks whether a path has a root path.
 */
bool SystemPath::HasRootPath() const
{
    throw NotImplementedException(L"SystemPath::HasRootPath()");
}

/**
 * Checks whether a path has a root name.
 */
bool SystemPath::HasRootName() const
{
    throw NotImplementedException(L"SystemPath::HasRootName()");
}

/**
 * Checks whether a path has a root directory.
 */
bool SystemPath::HasRootDirectory() const
{
    throw NotImplementedException(L"SystemPath::HasRootDirectory()");
}

/**
 * Checks whether a path has a relative path.
 */
bool SystemPath::HasRelativePath() const
{
    throw NotImplementedException(L"SystemPath::HasRelativePath()");
}

/**
 * Checks whether a path has a parent path.
 */
bool SystemPath::HasParentPath() const
{
    throw NotImplementedException(L"SystemPath::HasParentPath()");
}

/**
 * Checks whether a path has a file name.
 */
bool SystemPath::HasFileName() const
{
    throw NotImplementedException(L"SystemPath::HasFileName()");
}

/**
 * Checks whether a path has a stem.
 */
bool SystemPath::HasStem() const
{
    throw NotImplementedException(L"SystemPath::HasStem()");
}

/**
 * Checks whether a path has an extension.
 */
bool SystemPath::HasExtension() const
{
    throw NotImplementedException(L"SystemPath::HasExtension()");
}

/**
 * Checks whether a path is absolute.
 */
bool SystemPath::IsAbsolute() const
{
    throw NotImplementedException(L"SystemPath::IsAbsolute()");
}

/**
 * Checks whether a path is relative.
 */
bool SystemPath::IsRelative() const
{
    throw NotImplementedException(L"SystemPath::IsRelative()");
}

/**
 * Gets a string representation ofthis instance.
 */
std::wstring SystemPath::ToString() const
{
    throw NotImplementedException(L"SystemPath::SystemPath()");
}
