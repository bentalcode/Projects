#include "NotBitOperator.h"

using namespace base;

/**
 * The NotBitOperator constructor.
 */
NotBitOperator::NotBitOperator()
{
}

/**
 * The NotBitOperator destructor.
 */
NotBitOperator::~NotBitOperator()
{
}

/**
 * Performs a logical bit operator on the specified value.
 */
unsigned int NotBitOperator::Evaluate(unsigned int value) const
{
    return ~value;
}

/**
 * Performs a logical bit operator on the specified bit.
 */
unsigned int NotBitOperator::EvaluateBit(unsigned int bitValue) const
{
    return (bitValue == 0) ? 1 : 0;
}
