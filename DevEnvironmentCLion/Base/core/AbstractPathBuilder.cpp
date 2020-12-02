#include "PreCompiled.h"
#include "AbstractPathBuilder.h"
#include "StringSearch.h"
#include "Indexes.h"

using namespace base;

/**
 * The AbstractPathBuilder Constructor.
 */
AbstractPathBuilder::AbstractPathBuilder(
    const std::string& rootDirectory,
    const std::string& separator) :
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
const std::string& AbstractPathBuilder::getRootDirectory() const
{
    return m_rootDirectory;
}

/**
 * Gets a separator of a path.
 */
const std::string& AbstractPathBuilder::getSeparator() const
{
    return m_separator;
}

/**
 * Adds a new component to a path.
 */
IPathBuilder& AbstractPathBuilder::addComponent(const std::string& component)
{
    size_t startIndex = 0;
    size_t endIndex = component.size() - 1;

    if (StringSearch::startsWith(component, m_separator))
    {
        startIndex += m_separator.size();
    }

    if (StringSearch::endsWith(component, m_separator)) {
        endIndex -= m_separator.size();
    }

    size_t effectiveComponentLength = Indexes::size(startIndex, endIndex);

    if (effectiveComponentLength > 0) {
        std::string effectiveComponent = component.substr(startIndex, effectiveComponentLength);
        m_components.push_back(effectiveComponent);
    }

    return *this;
}

/**
 * Sets an extension of a path.
 */
IPathBuilder& AbstractPathBuilder::setExtension(const std::string& extension)
{
    m_extension = extension;
    return *this;
}

/**
 * Builds the resultant path.
 */
std::string AbstractPathBuilder::build()
{
    std::stringstream result;

    if (!m_rootDirectory.empty())
    {
        result << m_rootDirectory;
    }

    bool addSeparator = false;
    for (const std::string& component : m_components)
    {
        if (addSeparator)
        {
            result << m_separator;
        }

        result << component;
        addSeparator = true;
    }

    if (!m_extension.empty())
    {
        result << m_extension;
    }

    return result.str();
}
