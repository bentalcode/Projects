#include "AbstractPath.h"
#include "PathDecomposition.h"

using namespace base;

/**
 * The AbstractPath default constructor.
 */
AbstractPath::AbstractPath(
    const std::wstring& path,
    const std::wstring& seperator,
    std::wstring::value_type extensionSeperator)
{
    Initialize(
        path,
        seperator,
        extensionSeperator);
}

/**
 * The AbstractPath destructor.
 */
AbstractPath::~AbstractPath()
{
}

/**
 * Gets a path.
 */
const std::wstring& AbstractPath::GetPath() const
{
    return m_path;
}

/**
 * Checks whether a path is empty.
 */
bool AbstractPath::Empty() const
{
    return m_path.empty();
}

/**
 * Gets an absolute path.
 */
std::wstring AbstractPath::GetAbsolutePath() const
{
    return MakeAbsolutePath(m_path);
}

/**
 * Gets a canonical path.
 */
std::wstring AbstractPath::GetCanonicalPath() const
{
    return MakeCanonicalPath(m_path);
}

/**
 * Checks whether a path is absolute.
 */
bool AbstractPath::IsAbsolute() const
{
    return IsAbsolute(m_path);
}

/**
 * Checks whether a path is relative.
 */
bool AbstractPath::IsRelative(const std::wstring& path) const
{
    return IsRelative(m_path);
}

/**
 * Gets a path decomposition.
 */
const IPathDecomposition& AbstractPath::PathDecomposition() const
{
    if (!m_pathDecomposition)
    {
        m_pathDecomposition = PathDecomposition::Make(
            m_path,
            m_seperator,
            m_extensionSeparator);
    }

    return *m_pathDecomposition;
}

/**
 * Initializes a path.
 */
void AbstractPath::Initialize(
    const std::wstring& path,
    const std::wstring& seperator,
    const std::wstring::value_type extensionSeperator)
{
    ValidatePath(path);

    m_path = path;
    m_seperator = seperator;
    m_extensionSeparator = extensionSeperator;
}
