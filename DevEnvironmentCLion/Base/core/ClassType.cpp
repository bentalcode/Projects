#include "PreCompiled.h"

#include "ClassType.h"
#include "StringComparable.h"

using namespace base;

/**
 * The ClassType constructor.
 */
ClassType::ClassType(const std::string& className) :
    m_className(className)
{
}

/**
 * The ClassType destructor.
 */
ClassType::~ClassType()
{
}

/**
 * Gets the name of a class.
 */
const std::string& ClassType::getClassName() const
{
    return m_className;
}

/**
 * Determines the relative order of two instances.
 *
 * Returns -1 if the left hand side value is less than the right hand side value.
 * Returns 0 if the left hand side value is equal to the right hand side value.
 * Returns 1 if the left hand side value is greater than the right hand side value.
 */
int ClassType::compare(const IClassType& classType) const
{
    return StringComparable::compareIgnoreCase(m_className, 0, classType.getClassName(), 0, m_className.size());
}
