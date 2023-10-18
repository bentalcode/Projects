#include "Bit32Array.h"
#include "Bits.h"
#include "Indexes.h"
#include "Indexes.h"
#include "AndBitOperator.h"
#include "OrBitOperator.h"
#include "XorBitOperator.h"
#include "NotBitOperator.h"
#include "Bit32ArrayIterator.h"
#include "Bit32ArrayReverseIterator.h"
#include <assert.h>

using namespace datastructures::bitarray;

/**
 * Creates a bit 32 array.
 */
IBit32ArraySharedPtr Bit32Array::Make(unsigned int bits)
{
    return std::make_shared<Bit32Array>(bits);
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
void Bit32Array::TurnOn(size_t index)
{
    Set(index, 1);
}

/**
 * Turns off a bit at the specified index.
 */
void Bit32Array::TurnOff(size_t index)
{
    Set(index, 0);
}

/**
 * Checks whether a bit at the specified index is on.
 */
bool Bit32Array::IsOn(size_t index) const
{
    return Get(index) != 0;
}

/**
 * Checks whether a bit at the specified index is off.
 */
bool Bit32Array::IsOff(size_t index) const
{
    return Get(index) == 0;
}

/**
 * Sets a value of a bit at the specified index.
 */
void Bit32Array::Set(size_t index, unsigned int value)
{
    ValidateIndex(index);

    unsigned int mask = 1 << index;

    if (base::Bits::IsOn(value))
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
unsigned int Bit32Array::Get(size_t index) const
{
    ValidateIndex(index);

    unsigned int mask = 1 << index;

    unsigned int bitValue = base::Bits::BitValue(m_bits & mask);
    assert(base::Bits::IsBitValue(bitValue));

    return bitValue;
}

/**
 * Sets the bit at the specified index to the complement ofits current value.
 */
void Bit32Array::Flip(size_t index)
{
    ValidateIndex(index);

    unsigned int mask = 1 << index;

    m_bits ^= mask;
}

/**
 * Returns the number ofbits Set to true.
 */
size_t Bit32Array::Cardinality() const
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
 * Returns the number ofbits Set to true in the specified range.
 */
size_t Bit32Array::Cardinality(size_t startIndex, size_t endIndex) const
{
    ValidateIndex(startIndex);
    ValidateIndex(endIndex);

    assert (startIndex <= endIndex);
    size_t length = base::Indexes::Size(startIndex, endIndex);

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
        if (base::Bits::IsOn(currValue & 1))
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
void Bit32Array::Clear()
{
    m_bits = 0;
}

/**
 * Sets all the bits in the specified range to false.
 */
void Bit32Array::Clear(size_t startIndex, size_t endIndex)
{
    ValidateIndex(startIndex);
    ValidateIndex(endIndex);

    assert(startIndex <= endIndex);
    size_t length = base::Indexes::Size(startIndex, endIndex);

    if (length == 0) {
        return;
    }

    if (length == IBit32Array::SIZE_IN_BITS) {
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
void Bit32Array::Enable()
{
    m_bits = allBitsMask;
}

/**
 * Sets all the bits in the specified range to true.
 */
void Bit32Array::Enable(size_t startIndex, size_t endIndex)
{
    ValidateIndex(startIndex);
    ValidateIndex(endIndex);

    assert(startIndex <= endIndex);
    size_t length = base::Indexes::Size(startIndex, endIndex);

    if (length == 0)
    {
        return;
    }

    if (length == IBit32Array::SIZE_IN_BITS)
    {
        m_bits = allBitsMask;
        return;
    }

    unsigned int mask = 1 << length;
    --mask;

    mask <<= startIndex;

    m_bits |= mask;
}

/**
 * Gets the size of the bit array.
 */
size_t Bit32Array::Size() const
{
    return IBit32Array::SIZE_IN_BITS;
}

/**
 * Checks whether the bit array is Empty.
 */
bool Bit32Array::Empty() const
{
    return false;
}

/**
 * Performs a logical AND.
 */
void Bit32Array::AndOperator(const IBit32Array& other)
{
    base::AndBitOperator bitOperator;
    Operate(bitOperator, other);
}

/**
 * Performs a logical OR.
 */
void Bit32Array::OrOperator(const IBit32Array& other)
{
    base::OrBitOperator bitOperator;
    Operate(bitOperator, other);
}

/**
 * Performs a logical XOR.
 */
void Bit32Array::XorOperator(const IBit32Array& other)
{
    base::XorBitOperator bitOperator;
    Operate(bitOperator, other);
}

/**
 * Performs a logical NOT.
 */
void Bit32Array::NotOperator()
{
    base::NotBitOperator bitOperator;
    Operate(bitOperator);
}

/**
 * Performs a logical bit operator.
 */
void Bit32Array::Operate(
    const base::IBinaryBitOperator& bitOperator,
    const IBit32Array& other)
{
    m_bits = bitOperator.Evaluate(m_bits, other.ToInteger());
}

/**
 * Performs a logical bit operator.
 */
void Bit32Array::Operate(const base::IUnaryBitOperator& bitOperator)
{
    m_bits = bitOperator.Evaluate(m_bits);
}

/**
 * Performs a logical AND on the specified index.
 */
void Bit32Array::AndOperator(size_t index, unsigned int value)
{
    base::AndBitOperator bitOperator;
    Operate(bitOperator, index, value);
}

/**
 * Performs a logical OR on the specified index.
 */
void Bit32Array::OrOperator(size_t index, unsigned int value)
{
    base::OrBitOperator bitOperator;
    Operate(bitOperator, index, value);
}

/**
 * Performs a logical XOR on the specified index.
 */
void Bit32Array::XorOperator(size_t index, unsigned int value)
{
    base::XorBitOperator bitOperator;
    Operate(bitOperator, index, value);
}

/**
 * Performs a logical NOT on the specified index.
 */
void Bit32Array::NotOperator(size_t index)
{
    base::NotBitOperator bitOperator;
    Operate(bitOperator, index);
}

/**
 * Performs a logical bit operator on the specified index.
 */
void Bit32Array::Operate(
    const base::IBinaryBitOperator& bitOperator,
    size_t index,
    unsigned int value)
{
    unsigned int currValue = Get(index);
    unsigned int newValue = bitOperator.Evaluate(currValue, value);
    Set(index, newValue);
}

/**
 * Performs a logical bit operator on the specified index.
 */
void Bit32Array::Operate(
    const base::IUnaryBitOperator& bitOperator,
    size_t index)
{
    unsigned int currValue = Get(index);
    unsigned int newValue = bitOperator.EvaluateBit(currValue);
    Set(index, newValue);
}

/**
 * Converts the bits to an integer.
 */
unsigned int Bit32Array::ToInteger() const
{
    return m_bits;
}

/**
 * Validates an index.
 */
void Bit32Array::ValidateIndex(size_t index) const
{
    base::Indexes::ValidateIndex<size_t>(index, 0, IBit32Array::SIZE_IN_BITS - 1);
}

/**
 * Gets the iterator.
 */
base::IIteratorSharedPtr<bool> Bit32Array::GetIterator() const
{
    return Bit32ArrayIterator::Make(*this);
}

/**
 * Gets the reverse iterator.
 */
base::IReverseIteratorSharedPtr<bool> Bit32Array::GetReverseIterator() const
{
    return Bit32ArrayReverseIterator::Make(*this);
}
