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
unsigned int AndBitOperator::Evaluate(unsigned int lhs, unsigned int rhs) const
{
    return lhs & rhs;
}
