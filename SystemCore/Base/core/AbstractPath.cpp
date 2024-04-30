#include "AbstractPath.h"

using namespace base;

/**
 * The AbstractPath default constructor.
 */
AbstractPath::AbstractPath(const std::wstring& path)
{
    Initialize(path);
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
 * Initializes a path.
 */
void AbstractPath::Initialize(const std::wstring& path)
{
    ValidatePath(path);
    m_path = path;
}
