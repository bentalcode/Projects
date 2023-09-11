#include "PreCompiled.h"

#include "EqualBuilder.h"

using namespace base;

/**
 * The EqualBuilder default constructor.
 */
EqualBuilder::EqualBuilder() :
    m_equalityStatus(true)
{
}

/**
 * The EqualBuilder destructor.
 */
EqualBuilder::~EqualBuilder()
{
}

/**
 * With an equality status.
 */
EqualBuilder& EqualBuilder::withStatus(bool status)
{
    if (!m_equalityStatus) {
        return *this;
    }

    m_equalityStatus = status;

    return *this;
}

/**
 * Builds the resultant equality status.
 */
bool EqualBuilder::build()
{
    return m_equalityStatus;
}
