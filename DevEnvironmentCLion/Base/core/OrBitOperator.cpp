#include "PreCompiled.h"
#include "OrBitOperator.h"

using namespace base;

/**
 * The OrBitOperator constructor.
 */
OrBitOperator::OrBitOperator()
{
}

/**
 * The OrBitOperator destructor.
 */
OrBitOperator::~OrBitOperator()
{
}

/**
 * Performs a logical bit operator on the specified values.
 */
unsigned int OrBitOperator::evaluate(unsigned int lhs, unsigned int rhs) const
{
    return lhs | rhs;
}
