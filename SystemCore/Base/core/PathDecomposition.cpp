#include "PathDecomposition.h"

#include "Indexes.h"
#include "NotImplementedException.h"
#include "StringSearch.h"

using namespace base;

/**
 * Creates a new instance of a path decomposition.
 */
IPathDecompositionSharedPtr PathDecomposition::Make(
    const std::wstring& path,
    const std::wstring& separator,
    std::wstring::value_type extensionSeparator)
{
    return std::make_shared<PathDecomposition>(
        path,
        separator,
        extensionSeparator);
}

/**
 * The PathDecomposition constructor.
 */
PathDecomposition::PathDecomposition(
    const std::wstring& path,
    const std::wstring& separator,
    std::wstring::value_type extensionSeparator) :
    m_path(path),
    m_separator(separator),
    m_extensionSeparator(extensionSeparator)
{  
}

/**
 * The PathDecomposition destructor.
 */
PathDecomposition::~PathDecomposition()
{
}

/**
 * Returns the root-name of the path, if present.
 */
std::wstring PathDecomposition::GetRootName() const
{
    if (m_path.empty())
    {
        return L"";
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t separatorIndex = StringSearch::FirstIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex == m_path.npos || separatorIndex == 0)
    {
        return L"";
    }

    size_t componentStartIndex = 0;
    size_t componentEndIndex = separatorIndex - 1;

    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0 ? m_path.substr(componentStartIndex, componentLength) : L"";
}

/**
 * Returns the root directory of the path, if present.
 */
std::wstring PathDecomposition::GetRootDirectory() const
{
    return HasRootDirectory() ? m_separator : L"";
}

/**
 * Returns the root path of the path, if present.
 */
std::wstring PathDecomposition::GetRootPath() const
{
    if (m_path.empty())
    {
        return L"";
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t separatorIndex = StringSearch::FirstIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex == m_path.npos)
    {
        return L"";
    }

    size_t componentStartIndex = 0;
    size_t componentEndIndex = separatorIndex;
    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0 ? m_path.substr(componentStartIndex, componentLength) : L"";
}

/**
 * Returns path relative to the root path.
 */
std::wstring PathDecomposition::GetRelativePath() const
{
    if (m_path.empty())
    {
        return L"";
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t separatorIndex = StringSearch::FirstIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex == m_path.npos)
    {
        return m_path;
    }

    size_t componentStartIndex = separatorIndex + m_separator.size();
    size_t componentEndIndex = endIndex;
    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0 ? m_path.substr(componentStartIndex, componentLength) : L"";
}

/**
 * Returns the path of the parent path.
 */
std::wstring PathDecomposition::GetParentPath() const
{
    if (m_path.empty())
    {
        return L"";
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t separatorIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex == m_path.npos || separatorIndex == 0)
    {
        return L"";
    }

    size_t componentStartIndex = 0;
    size_t componentEndIndex = separatorIndex - 1;
    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0 ? m_path.substr(componentStartIndex, componentLength) : L"";
}

/**
 * Returns the filename path component.
 */
std::wstring PathDecomposition::GetFileName() const
{
    if (m_path.empty())
    {
        return L"";
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t componentStartIndex = startIndex;
    size_t componentEndIndex = endIndex;

    size_t separatorIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex != std::wstring::npos)
    {
        componentStartIndex = separatorIndex + m_separator.size();
    }

    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0 ? m_path.substr(componentStartIndex, componentLength) : L"";
}

/**
 * Returns the stem path component (filename without the final extension).
 */
std::wstring PathDecomposition::GetStem() const
{
    if (m_path.empty())
    {
        return L"";
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t componentStartIndex = startIndex;
    size_t componentEndIndex = endIndex;

    size_t separatorIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex != std::wstring::npos)
    {
        componentStartIndex = separatorIndex + m_separator.size();
    }

    size_t dotIndex = StringSearch::LastIndexOf(
        m_path,
        componentStartIndex,
        componentEndIndex,
        m_extensionSeparator);

    if (dotIndex != std::wstring::npos)
    {
        if (dotIndex == componentStartIndex)
        {
            return L"";
        }

        componentEndIndex = dotIndex - 1;
    }

    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0 ? m_path.substr(componentStartIndex, componentLength) : L"";
}

/**
 * Returns the file extension path component.
 */
std::wstring PathDecomposition::GetExtension() const
{
    if (m_path.empty())
    {
        return L"";
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t separatorIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex != std::wstring::npos)
    {
        startIndex = separatorIndex + m_separator.size();
    }

    size_t dotIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_extensionSeparator);

    if (dotIndex == std::wstring::npos || dotIndex == endIndex)
    {
        return L"";
    }

    size_t componentStartIndex = dotIndex + 1;
    size_t componentEndIndex = endIndex;

    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0 ? m_path.substr(componentStartIndex, componentLength) : L"";
}

/**
 * Checks whether a path has a root path.
 */
bool PathDecomposition::HasRootPath() const
{
    if (m_path.empty())
    {
        return false;
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t separatorIndex = StringSearch::FirstIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    return separatorIndex != m_path.npos && separatorIndex > startIndex;
}

/**
 * Checks whether a path has a root name.
 */
bool PathDecomposition::HasRootName() const
{
    return HasRootPath();
}

/**
 * Checks whether a path has a root directory.
 */
bool PathDecomposition::HasRootDirectory() const
{
    return HasRootPath();
}

/**
 * Checks whether a path has a relative path.
 */
bool PathDecomposition::HasRelativePath() const
{
    if (m_path.empty())
    {
        return false;
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t separatorIndex = StringSearch::FirstIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex == m_path.npos)
    {
        return true;
    }

    size_t componentStartIndex = separatorIndex + m_separator.size();
    size_t componentEndIndex = endIndex;
    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0;
}

/**
 * Checks whether a path has a parent path.
 */
bool PathDecomposition::HasParentPath() const
{
    if (m_path.empty())
    {
        return false;
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t separatorIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex == m_path.npos || separatorIndex == 0)
    {
        return false;
    }

    size_t componentStartIndex = 0;
    size_t componentEndIndex = separatorIndex - 1;
    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0;
}

/**
 * Checks whether a path has a file name.
 */
bool PathDecomposition::HasFileName() const
{
    if (m_path.empty())
    {
        return false;
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t componentStartIndex = startIndex;
    size_t componentEndIndex = endIndex;

    size_t separatorIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex != std::wstring::npos)
    {
        componentStartIndex = separatorIndex + m_separator.size();
    }

    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0;
}

/**
 * Checks whether a path has a stem.
 */
bool PathDecomposition::HasStem() const
{
    if (m_path.empty())
    {
        return false;
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t componentStartIndex = startIndex;
    size_t componentEndIndex = endIndex;

    size_t separatorIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex != std::wstring::npos)
    {
        componentStartIndex = separatorIndex + m_separator.size();
    }

    size_t dotIndex = StringSearch::LastIndexOf(
        m_path,
        componentStartIndex,
        componentEndIndex,
        m_extensionSeparator);

    if (dotIndex != std::wstring::npos)
    {
        if (dotIndex == componentStartIndex)
        {
            return false;
        }

        componentEndIndex = dotIndex - 1;
    }

    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0;
}

/**
 * Checks whether a path has an extension.
 */
bool PathDecomposition::HasExtension() const
{
    if (m_path.empty())
    {
        return false;
    }

    size_t length = m_path.size();
    size_t startIndex = 0;
    size_t endIndex = length - 1;

    size_t separatorIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_separator);

    if (separatorIndex != std::wstring::npos)
    {
        startIndex = separatorIndex + m_separator.size();
    }

    size_t dotIndex = StringSearch::LastIndexOf(
        m_path,
        startIndex,
        endIndex,
        m_extensionSeparator);

    if (dotIndex == std::wstring::npos || dotIndex == endIndex)
    {
        return false;
    }

    size_t componentStartIndex = dotIndex + 1;
    size_t componentEndIndex = endIndex;

    size_t componentLength = Indexes::Size(componentStartIndex, componentEndIndex);

    return componentLength > 0;
}
