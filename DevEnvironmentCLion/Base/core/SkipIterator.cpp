#include "PreCompiled.h"

#include "SkipIterator.h"

using namespace base;

/**
 * The SkipIterator constructor.
 */
SkipIterator::SkipIterator()
{
}

/**
 * The SkipIterator destructor.
 */
SkipIterator::~SkipIterator()
{
}

/*
 * Registers the class type of a generic skip element.
 */
void SkipIterator::registerGenericSkipElement(const std::type_index& classTypeToSkip)
{
    m_elementsToSkip.push_back(classTypeToSkip);
}

/*
 * Configures the iterator for skipping over the registered elements.
 * Returns the previous configured status.
 */
bool SkipIterator::enableSkipElements()
{
    return setSkipElementsStatus(true);
}

/*
 * Configures the iterator for including the registered skip elements.
 * Returns the previous configured status.
 */
bool SkipIterator::disableSkipElements()
{
    return setSkipElementsStatus(false);
}

/*
 * Configures the status of skip elements.
 * Returns the previous configured status.
 */
bool SkipIterator::setSkipElementsStatus(bool status)
{
    bool previousStatus = m_skipElements;
    m_skipElements = status;
    return previousStatus;
}

/*
 * Gets the current status of skip elements.
 */
bool SkipIterator::getSkipElementsStatus()
{
    return m_skipElements;
}

/*
 * Checks whether this is a skip element.
 */
bool SkipIterator::isSkipElement(const std::type_index& classType)
{
    for (const std::type_index& typeIndex : m_elementsToSkip)
    {
        if (typeIndex == classType)
        {
            return true;
        }
    }

    return false;
}
