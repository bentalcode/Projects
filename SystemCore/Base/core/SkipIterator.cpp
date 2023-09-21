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
 * Registers the class type of generic skip element.
 */
void SkipIterator::RegisterGenericSkipElement(const std::type_index& classTypeToSkip)
{
    m_elementsToSkip.push_back(classTypeToSkip);
}

/*
 * Configures the iterator for skipping over the registered elements.
 * Returns the previous configured status.
 */
bool SkipIterator::EnableSkipElements()
{
    return SetSkipElementsStatus(true);
}

/*
 * Configures the iterator for including the registered skip elements.
 * Returns the previous configured status.
 */
bool SkipIterator::DisableSkipElements()
{
    return SetSkipElementsStatus(false);
}

/*
 * Configures the status of skip elements.
 * Returns the previous configured status.
 */
bool SkipIterator::SetSkipElementsStatus(bool status)
{
    bool previousStatus = m_skipElements;
    m_skipElements = status;
    return previousStatus;
}

/*
 * Gets the current status of skip elements.
 */
bool SkipIterator::GetSkipElementsStatus()
{
    return m_skipElements;
}

/*
 * Checks whether this is a skip element.
 */
bool SkipIterator::IsSkipElement(const std::type_index& classType)
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
