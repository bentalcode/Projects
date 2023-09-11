#include "PreCompiled.h"
#include "Bits.h"
#include "Indexes.h"

using namespace base;

/**
 * Converts an integer to a bit value: one or zero.
 */
unsigned int Bits::bitValue(unsigned int bitValue)
{
    return (bitValue != 0) ? 1 : 0;
}

/**
 * Checks whether the bit is on.
 */
bool Bits::isOn(unsigned int bitValue)
{
    return bitValue != 0;
}

/**
 * Checks whether the bit is off.
 */
bool Bits::isOff(unsigned int bitValue)
{
    return bitValue == 0;
}

/**
 * Verifies that value of a bit is valid: one or zero.
 */
bool Bits::isBitValue(unsigned int bitValue)
{
    return bitValue == 0 || bitValue == 1;
}

/**
 * Turns on a bit at the specified index.
 */
unsigned int Bits::turnOn(unsigned int value, size_t index)
{
    validateIndex(index);

    unsigned int mask = 1 << index;
    return value | mask;
}

/**
 * Turns off a bit at the specified index.
 */
unsigned int Bits::turnOff(unsigned int value, size_t index)
{
    validateIndex(index);

    int mask = ~(1 << index);
    return value & mask;
}

/**
 * Checks whether a bit at the specified index is on.
 */
bool Bits::isOn(unsigned int value, size_t index)
{
    return get(value, index) != 0;
}

/**
 * Checks whether a bit at the specified index is off.
 */
bool Bits::isOff(unsigned int value, size_t index)
{
    return get(value, index) == 0;
}

/**
 * Sets a value of a bit at the specified index.
 */
unsigned int Bits::set(unsigned int value, size_t index, unsigned int bitValue)
{
    return isOn(bitValue) ? turnOn(value, index) : turnOff(value, index);
}

/**
 * Gets a value of a bit at the specified index.
 */
unsigned int Bits::get(unsigned int value, size_t index)
{
    validateIndex(index);

    unsigned int mask = 1 << index;
    return (value & mask) != 0 ? 1 : 0;
}

/**
 * Flips the value of a bit.
 */
unsigned int Bits::flip(unsigned int bit)
{
    assert(isBitValue(bit));
    return bit ^ 1;
}

/**
 * Sets the bit at the specified index to the complement of its current value.
 */
unsigned int Bits::flip(unsigned int value, size_t index)
{
    validateIndex(index);

    int mask = 1 << index;

    return value ^ mask;
}

/**
 * Validates the index.
 */
void Bits::validateIndex(size_t index)
{
    Indexes::validateIndex<size_t>(index, 0, sizeof(unsigned int) * 8 - 1);
}
