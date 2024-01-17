#include "AbstractRetryLogic.h"

using namespace client_server;

/**
 * The AbstractRetryLogic constructor.
 */
AbstractRetryLogic::AbstractRetryLogic(const std::wstring& name) :
    m_name(name)
{
}

/**
 * The AbstractRetryLogic constructor.
 */
AbstractRetryLogic::AbstractRetryLogic(
    const std::wstring& name,
    const std::vector<base::IClassTypeSharedPtr>& absorbedException) :
    m_name(name),
    m_absorbedException(absorbedException)
{
}

AbstractRetryLogic::~AbstractRetryLogic()
{
}

/**
 * Gets the name of the logic.
 */
const std::wstring& AbstractRetryLogic::GetName() const
{
    return m_name;
}

/**
 * Gets the set of the absorbed exception types.
 */
const std::vector<base::IClassTypeSharedPtr>& AbstractRetryLogic::GetAbsorbedExceptions() const
{
    return m_absorbedException;
}
