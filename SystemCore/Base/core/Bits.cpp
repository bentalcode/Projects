#include "Bits.h"
#include "Indexes.h"
#include <assert.h>

using namespace base;

/**
 * Converts an integer to a bit value: one or zero.
 */
unsigned int Bits::BitValue(unsigned int bitValue)
{
    return (bitValue != 0) ? 1 : 0;
}

/**
 * Checks whether the bit is on.
 */
bool Bits::IsOn(unsigned int bitValue)
{
    return bitValue != 0;
}

/**
 * Checks whether the bit is off.
 */
bool Bits::IsOff(unsigned int bitValue)
{
    return bitValue == 0;
}

/**
 * Verifies that value of a bit is valid: one or zero.
 */
bool Bits::IsBitValue(unsigned int bitValue)
{
    return bitValue == 0 || bitValue == 1;
}

/**
 * Turns on a bit at the specified index.
 */
unsigned int Bits::TurnOn(unsigned int value, size_t index)
{
    ValidateIndex(index);

    unsigned int mask = 1 << index;
    return value | mask;
}

/**
 * Turns off a bit at the specified index.
 */
unsigned int Bits::TurnOff(unsigned int value, size_t index)
{
    ValidateIndex(index);

    int mask = ~(1 << index);
    return value & mask;
}

/**
 * Checks whether a bit at the specified index is on.
 */
bool Bits::IsOn(unsigned int value, size_t index)
{
    return Get(value, index) != 0;
}

/**
 * Checks whether a bit at the specified index is off.
 */
bool Bits::IsOff(unsigned int value, size_t index)
{
    return Get(value, index) == 0;
}

/**
 * Sets a value of a bit at the specified index.
 */
unsigned int Bits::Set(unsigned int value, size_t index, unsigned int bitValue)
{
    return IsOn(bitValue) ? TurnOn(value, index) : TurnOff(value, index);
}

/**
 * Gets a value of a bit at the specified index.
 */
unsigned int Bits::Get(unsigned int value, size_t index)
{
    ValidateIndex(index);

    unsigned int mask = 1 << index;
    return (value & mask) != 0 ? 1 : 0;
}

/**
 * Flips the value of a bit.
 */
unsigned int Bits::Flip(unsigned int bit)
{
    assert(IsBitValue(bit));
    return bit ^ 1;
}

/**
 * Sets the bit at the specified index to the complement Of its current value.
 */
unsigned int Bits::Flip(unsigned int value, size_t index)
{
    ValidateIndex(index);

    int mask = 1 << index;
    return value ^ mask;
}

/**
 * Validates the index.
 */
void Bits::ValidateIndex(size_t index)
{
    Indexes::ValidateIndex<size_t>(index, 0, sizeof(unsigned int) * 8 - 1);
}
