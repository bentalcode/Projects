#include "PreCompiled.h"
#include "AndBitOperator.h"

using namespace base;

/**
 * The AndBitOperator constructor.
 */
AndBitOperator::AndBitOperator()
{
}

/**
 * The AndBitOperator destructor.
 */
AndBitOperator::~AndBitOperator()
{
}

/**
 * Performs a logical bit operator on the specified value.
 */
unsigned int AndBitOperator::evaluate(unsigned int lhs, unsigned int rhs) const
{
    return lhs & rhs;
}
