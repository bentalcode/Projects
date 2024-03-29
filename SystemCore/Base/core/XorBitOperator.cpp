#include "XorBitOperator.h"

using namespace base;

/**
 * The XorBitOperator constructor.
 */
XorBitOperator::XorBitOperator()
{
}

/**
 * The XorBitOperator destructor.
 */
XorBitOperator::~XorBitOperator()
{
}

/**
 * Performs a logical bit operator on the specified values.
 */
unsigned int XorBitOperator::Evaluate(unsigned int lhs, unsigned int rhs) const
{
    return lhs ^ rhs;
}
