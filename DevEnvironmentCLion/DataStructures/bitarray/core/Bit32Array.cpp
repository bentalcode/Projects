#include "PreCompiled.h"
#include "Bit32Array.h"
#include "Bits.h"
#include "Dimensions.h"
#include "Indexes.h"
#include "AndBitOperator.h"
#include "OrBitOperator.h"
#include "XorBitOperator.h"
#include "NotBitOperator.h"
#include "Bit32ArrayIterator.h"
#include "Bit32ArrayReverseIterator.h"

using namespace datastructures::bitarray;

/**
 * The Bit32Array constructor.
 */
Bit32Array::Bit32Array() :
    Bit32Array(0)
{
}

/**
 * The Bit32Array constructor from an integer.
 */
Bit32Array::Bit32Array(unsigned int bits) :
    m_bits(bits)
{
}

/**
 * The Bit32Array destructor.
 */
Bit32Array::~Bit32Array()
{
}

/**
 * Turns on a bit at the specified index.
 */
void Bit32Array::turnOn(size_t index)
{
    set(index, 1);
}

/**
 * Turns off a bit at the specified index.
 */
void Bit32Array::turnOff(size_t index)
{
    set(index, 0);
}

/**
 * Checks whether a bit at the specified index is on.
 */
bool Bit32Array::isOn(size_t index) const
{
    return get(index) != 0;
}

/**
 * Checks whether a bit at the specified index is off.
 */
bool Bit32Array::isOff(size_t index) const
{
    return get(index) == 0;
}

/**
 * Sets a value of a bit at the specified index.
 */
void Bit32Array::set(size_t index, unsigned int value)
{
    validateIndex(index);

    unsigned int mask = 1 << index;

    if (base::Bits::isOn(value))
    {
        m_bits |= mask;
    }
    else
    {
        mask = ~mask;
        m_bits &= mask;
    }
}

/**
 * Gets a value of a bit at the specified index.
 */
unsigned int Bit32Array::get(size_t index) const
{
    validateIndex(index);

    unsigned int mask = 1 << index;

    unsigned int bitValue = base::Bits::bitValue(m_bits & mask);
    assert(base::Bits::isBitValue(bitValue));

    return bitValue;
}

/**
 * Sets the bit at the specified index to the complement of its current value.
 */
void Bit32Array::flip(size_t index)
{
    validateIndex(index);

    unsigned int mask = 1 << index;

    m_bits ^= mask;
}

/**
 * Returns the number of bits set to true.
 */
size_t Bit32Array::cardinality() const
{
    unsigned int numberOfBitsOn = 0;

    unsigned int currValue = m_bits;

    while (currValue != 0)
    {
        currValue = currValue & (currValue - 1);
        ++numberOfBitsOn;
    }

    return numberOfBitsOn;
}

/**
 * Returns the number of bits set to true in the specified range.
 */
size_t Bit32Array::cardinality(size_t startIndex, size_t endIndex) const
{
    validateIndex(startIndex);
    validateIndex(endIndex);

    assert (startIndex <= endIndex);
    size_t length = base::Dimensions::length(startIndex, endIndex);

    if (length == 0)
    {
        return 0;
    }

    size_t numberOfBitsOn = 0;

    unsigned int currValue = m_bits;

    size_t currIndex = startIndex;
    currValue >>= startIndex;

    while (currValue != 0 && currIndex <= endIndex)
    {
        if (base::Bits::isOn(currValue & 1))
        {
            ++numberOfBitsOn;
        }

        ++currIndex;
        currValue >>= 1;
    }

    return numberOfBitsOn;
}

/**
 * Sets all the bits to false.
 */
void Bit32Array::clear()
{
    m_bits = 0;
}

/**
 * Sets all the bits in the specified range to false.
 */
void Bit32Array::clear(size_t startIndex, size_t endIndex)
{
    validateIndex(startIndex);
    validateIndex(endIndex);

    assert(startIndex <= endIndex);
    size_t length = base::Dimensions::length(startIndex, endIndex);

    if (length == 0) {
        return;
    }

    if (length == IBit32Array::sizeInBits) {
        m_bits = 0;
        return;
    }

    unsigned int mask = 1 << length;
    --mask;

    mask <<= startIndex;
    mask = ~mask;

    m_bits &= mask;
}

/**
 * Sets all the bits to true.
 */
void Bit32Array::enable()
{
    m_bits = allBitsMask;
}

/**
 * Sets all the bits in the specified range to true.
 */
void Bit32Array::enable(size_t startIndex, size_t endIndex)
{
    validateIndex(startIndex);
    validateIndex(endIndex);

    assert(startIndex <= endIndex);
    size_t length = base::Dimensions::length(startIndex, endIndex);

    if (length == 0)
    {
        return;
    }

    if (length == IBit32Array::sizeInBits)
    {
        m_bits = allBitsMask;
        return;
    }

    int mask = 1 << length;
    --mask;

    mask <<= startIndex;

    m_bits |= mask;
}

/**
 * Gets the size of the bit array.
 */
size_t Bit32Array::size() const
{
    return IBit32Array::sizeInBits;
}

/**
 * Checks whether the bit array is empty.
 */
bool Bit32Array::empty() const
{
    return false;
}

/**
 * Performs a logical AND.
 */
void Bit32Array::andOperator(const IBit32Array& other)
{
    base::AndBitOperator bitOperator;
    operate(bitOperator, other);
}

/**
 * Performs a logical OR.
 */
void Bit32Array::orOperator(const IBit32Array& other)
{
    base::OrBitOperator bitOperator;
    operate(bitOperator, other);
}

/**
 * Performs a logical XOR.
 */
void Bit32Array::xorOperator(const IBit32Array& other)
{
    base::XorBitOperator bitOperator;
    operate(bitOperator, other);
}

/**
 * Performs a logical NOT.
 */
void Bit32Array::notOperator()
{
    base::NotBitOperator bitOperator;
    operate(bitOperator);
}

/**
 * Performs a logical bit operator.
 */
void Bit32Array::operate(
    const base::IBinaryBitOperator& bitOperator,
    const IBit32Array& other)
{
    m_bits = bitOperator.evaluate(m_bits, other.toInteger());
}

/**
 * Performs a logical bit operator.
 */
void Bit32Array::operate(const base::IUnaryBitOperator& bitOperator)
{
    m_bits = bitOperator.evaluate(m_bits);
}

/**
 * Performs a logical AND on the specified index.
 */
void Bit32Array::andOperator(size_t index, unsigned int value)
{
    base::AndBitOperator bitOperator;
    operate(bitOperator, index, value);
}

/**
 * Performs a logical OR on the specified index.
 */
void Bit32Array::orOperator(size_t index, unsigned int value)
{
    base::OrBitOperator bitOperator;
    operate(bitOperator, index, value);
}

/**
 * Performs a logical XOR on the specified index.
 */
void Bit32Array::xorOperator(size_t index, unsigned int value)
{
    base::XorBitOperator bitOperator;
    operate(bitOperator, index, value);
}

/**
 * Performs a logical NOT on the specified index.
 */
void Bit32Array::notOperator(size_t index)
{
    base::NotBitOperator bitOperator;
    operate(bitOperator, index);
}

/**
 * Performs a logical bit operator on the specified index.
 */
void Bit32Array::operate(
    const base::IBinaryBitOperator& bitOperator,
    size_t index,
    unsigned int value)
{
    unsigned int currValue = get(index);
    unsigned int newValue = bitOperator.evaluate(currValue, value);
    set(index, newValue);
}

/**
 * Performs a logical bit operator on the specified index.
 */
void Bit32Array::operate(
    const base::IUnaryBitOperator& bitOperator,
    size_t index)
{
    int currValue = get(index);
    int newValue = bitOperator.evaluateBit(currValue);
    set(index, newValue);
}

/**
 * Converts the bits to an integer.
 */
unsigned int Bit32Array::toInteger() const
{
    return m_bits;
}

/**
 * Validates an index.
 */
void Bit32Array::validateIndex(size_t index) const
{
    base::Indexes::validateIndex<size_t>(index, 0, IBit32Array::sizeInBits - 1);
}

/**
 * Gets the iterator.
 */
base::IIteratorPtr<bool> Bit32Array::getIterator() const
{
    return Bit32ArrayIterator::make(*this);
}

/**
 * Gets the reverse iterator.
 */
base::IReverseIteratorPtr<bool> Bit32Array::getReverseIterator() const
{
    return Bit32ArrayReverseIterator::make(*this);
}