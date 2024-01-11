#include "AbstractPathBuilder.h"
#include "StringSearch.h"
#include "Indexes.h"

using namespace base;

/**
 * The AbstractPathBuilder default constructor.
 */
AbstractPathBuilder::AbstractPathBuilder(
    const std::wstring& rootDirectory,
    const std::wstring& separator) :
    m_rootDirectory(rootDirectory),
    m_separator(separator)
{
}

/**
 * The AbstractPathBuilder destructor.
 */
AbstractPathBuilder::~AbstractPathBuilder()
{
}

/**
 * Gets a root directory.
 */
const std::wstring& AbstractPathBuilder::GetRootDirectory() const
{
    return m_rootDirectory;
}

/**
 * Gets a separator of a path.
 */
const std::wstring& AbstractPathBuilder::GetSeparator() const
{
    return m_separator;
}

/**
 * Adds a new component to a path.
 */
void AbstractPathBuilder::AddComponent(const std::wstring& component)
{
    size_t startIndex = 0;
    size_t endIndex = component.size() - 1;

    if (StringSearch::StartsWith(component, m_separator)) {
        startIndex += m_separator.size();
    }

    if (StringSearch::EndsWith(component, m_separator)) {
        endIndex -= m_separator.size();
    }

    size_t effectiveComponentLength = Indexes::Size(startIndex, endIndex);

    if (effectiveComponentLength > 0) {
        std::wstring effectiveComponent = component.substr(startIndex, effectiveComponentLength);
        m_components.push_back(effectiveComponent);
    }
}

/**
 * Sets an extension of a path.
 */
void AbstractPathBuilder::SetExtension(const std::wstring& extension)
{
    m_extension = extension;
}

/**
 * Builds the resultant path.
 */
std::wstring AbstractPathBuilder::Build()
{
    std::wstringstream pathStream;

    if (!m_rootDirectory.empty()) {
        pathStream << m_rootDirectory;
    }

    bool addDirectorySeparator = !m_rootDirectory.empty();
    for (const std::wstring& component : m_components) {
        if (addDirectorySeparator) {
            pathStream << m_separator;
        }

        pathStream << component;
        addDirectorySeparator = true;
    }

    if (!m_extension.empty()) {
        pathStream << "." << m_extension;
    }

    return pathStream.str();
}

/**
 * Gets a builder of path.
 */
const IBuilder<std::wstring>& AbstractPathBuilder::GetBuilder() const
{
    return *this;
}
