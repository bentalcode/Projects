#include "PreCompiled.h"

#include "CompareToBuilder.h"

using namespace base;

/**
 * The CompareToBuilder default constructor.
 */
CompareToBuilder::CompareToBuilder() :
    m_compareStatus(0)
{
}

/**
 * The CompareToBuilder destructor.
 */
CompareToBuilder::~CompareToBuilder()
{
}

/**
 * With a compare status.
 */
CompareToBuilder& CompareToBuilder::withStatus(int status)
{
    if (m_compareStatus != 0)
    {
        return *this;
    }

    m_compareStatus = status;

    return *this;
}

/**
 * Builds the resultant equality status.
 */
int CompareToBuilder::build()
{
    return m_compareStatus;
}
