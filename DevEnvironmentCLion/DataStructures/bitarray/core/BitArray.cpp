#include "PreCompiled.h"
#include "BitArray.h"
#include "Bit32Array.h"
#include "Bits.h"
#include "AndBitOperator.h"
#include "OrBitOperator.h"
#include "XorBitOperator.h"
#include "NotBitOperator.h"
#include "BitArrayException.h"
#include "Dimensions.h"
#include "Indexes.h"
#include "BitArrayIterator.h"
#include "BitArrayReverseIterator.h"

using namespace datastructures::bitarray;

/**
 * Creates a bit array.
 */
IBitArrayPtr BitArray::make(size_t numberOfBits)
{
    return std::make_shared<BitArray>(numberOfBits);
}

/**
 * Copies a bit array.
 */
IBitArrayPtr BitArray::copy(const IBitArray& bitArray)
{
    return std::make_shared<BitArray>(bitArray);
}

/**
 * The BitArray constructor.
 */
BitArray::BitArray(size_t numberOfBits) :
    m_data(createBitArray(numberOfBits)),
    m_size(numberOfBits)
{
    if (m_size == 0)
    {
        std::string errorMessage = "The number of bits has to be positive.";
        throw BitArrayException(errorMessage);
    }
}

/**
 * The BitArray copy constructor.
 */
BitArray::BitArray(const IBitArray& bitArray) :
    m_data(bitArray.toBit32Array()),
    m_size(bitArray.size())
{
}

/**
 * The BitArray destructor.
 */
BitArray::~BitArray()
{
}

/**
 * Turns on a bit at the specified index.
 */
void BitArray::turnOn(size_t index)
{
    set(index, 1);
}

/**
 * Turns off a bit at the specified index.
 */
void BitArray::turnOff(size_t index)
{
    set(index, 0);
}

/**
 * Checks whether a bit at the specified index is on.
 */
bool BitArray::isOn(size_t index) const
{
    return get(index) != 0;
}

/**
 * Checks whether a bit at the specified index is off.
 */
bool BitArray::isOff(size_t index) const
{
    return get(index) == 0;
}

/**
 * Sets a value of a bit at the specified index.
 */
void BitArray::set(size_t index, unsigned int value)
{
    validateIndex(index);

    size_t unitIndex = unitIndexOf(index);
    size_t bitIndex = bitIndexOf(index);

    m_data[unitIndex]->set(bitIndex, value);
}

/**
 * Gets a value of a bit at the specified index.
 */
size_t BitArray::get(size_t index) const
{
    validateIndex(index);

    size_t unitIndex = unitIndexOf(index);
    size_t bitIndex = bitIndexOf(index);

    unsigned int bitValue = m_data[unitIndex]->get(bitIndex);
    assert(base::Bits::isBitValue(bitValue));

    return bitValue;
}

/**
 * Sets the bits to the complement of its current value.
 */
void BitArray::flip()
{
    base::NotBitOperator bitOperator;
    operate(bitOperator);
}

/**
 * Sets the bit at the specified index to the complement of its current value.
 */
void BitArray::flip(size_t index)
{
    validateIndex(index);

    size_t unitIndex = unitIndexOf(index);
    size_t bitIndex = bitIndexOf(index);

    m_data[unitIndex]->flip(bitIndex);
}

/**
 * Returns the number of bits set to true.
 */
size_t BitArray::cardinality() const
{
    size_t numberOfBitsOn = 0;

    size_t numberOfUnits = getNumberOfUnits();
    size_t unitIndex = 0;

    //
    // Operate on the unit level from unit {0...N-1}...
    //
    while (unitIndex < numberOfUnits - 1)
    {
        numberOfBitsOn += m_data[unitIndex]->cardinality();

        ++unitIndex;
    }

    //
    // Operate on the last unit either as a whole or bit by bit...
    //
    size_t lastUnitBitStartIndex = 0;
    size_t lastUnitBitEndIndex = bitIndexOf(m_size - 1);

    numberOfBitsOn += m_data[unitIndex]->cardinality(lastUnitBitStartIndex, lastUnitBitEndIndex);

    return numberOfBitsOn;
}

/**
 * Sets all the bits to false.
 */
void BitArray::clear()
{
    size_t numberOfUnits = getNumberOfUnits();

    //
    // Operate on the unit level from unit {0...N-1}...
    //
    size_t unitIndex = 0;

    while (unitIndex < numberOfUnits - 1)
    {
        m_data[unitIndex]->clear();
        ++unitIndex;
    }

    //
    // Operate on the last unit either as a whole or bit by bit...
    //
    size_t lastUnitBitStartIndex = 0;
    size_t lastUnitBitEndIndex = bitIndexOf(m_size - 1);

    m_data[unitIndex]->clear(lastUnitBitStartIndex, lastUnitBitEndIndex);
}

/**
 * Sets all the bits at the specified range to false.
 */
void BitArray::clear(size_t startIndex, size_t endIndex)
{
    validateIndex(startIndex);
    validateIndex(endIndex);

    assert(startIndex <= endIndex);

    if (startIndex > endIndex)
    {
        return;
    }

    size_t startUnitIndex = unitIndexOf(startIndex);
    size_t startBitIndex = bitIndexOf(startIndex);

    size_t endUnitIndex = unitIndexOf(endIndex);
    size_t endBitIndex = bitIndexOf(endIndex);

    size_t numberOfUnits = base::Dimensions::length(startUnitIndex, endUnitIndex);

    if (numberOfUnits == 0)
    {
        return;
    }

    if (numberOfUnits == 1)
    {
        //
        // Update the single unit either as a whole or bit by bit...
        //
        m_data[startUnitIndex]->clear(startBitIndex, endBitIndex);
    }
    else
    {
        //
        // Update the start unit either as a whole or bit by bit...
        //
        m_data[startUnitIndex]->clear(startBitIndex, BitArray::unitSizeInBits - 1);

        //
        // Update the middle units as a whole...
        //
        for (int unitIndex = startUnitIndex + 1; unitIndex <= endUnitIndex - 1; ++unitIndex)
        {
            m_data[unitIndex]->clear();
        }

        //
        // Update the end unit either as a whole or bit by bit...
        //
        m_data[endUnitIndex]->clear(0, endBitIndex);
    }
}

/**
 * Sets all the bits to true.
 */
void BitArray::enable()
{
    size_t numberOfUnits = getNumberOfUnits();

    //
    // Operate on the unit level from unit {0...N-1}...
    //
    size_t unitIndex = 0;

    while (unitIndex < numberOfUnits - 1)
    {
        m_data[unitIndex]->enable();
        ++unitIndex;
    }

    //
    // Operate on the last unit either as a whole or bit by bit...
    //
    size_t lastUnitBitStartIndex = 0;
    size_t lastUnitBitEndIndex = bitIndexOf(m_size - 1);

    m_data[unitIndex]->enable(lastUnitBitStartIndex, lastUnitBitEndIndex);
}

/**
 * Sets all the bits at the specified range to true.
 */
void BitArray::enable(size_t startIndex, size_t endIndex)
{
    validateIndex(startIndex);
    validateIndex(endIndex);

    assert(startIndex <= endIndex);

    if (startIndex > endIndex)
    {
        return;
    }

    size_t startUnitIndex = unitIndexOf(startIndex);
    size_t startBitIndex = bitIndexOf(startIndex);

    size_t endUnitIndex = unitIndexOf(endIndex);
    size_t endBitIndex = bitIndexOf(endIndex);

    size_t numberOfUnits = base::Dimensions::length(startUnitIndex, endUnitIndex);

    if (numberOfUnits == 0)
    {
        return;
    }

    if (numberOfUnits == 1)
    {
        //
        // Update the single unit either as a whole or bit by bit...
        //
        m_data[startUnitIndex]->enable(startBitIndex, endBitIndex);
    }
    else
    {
        //
        // Update the start unit either as a whole or bit by bit...
        //
        m_data[startUnitIndex]->enable(startBitIndex, BitArray::unitSizeInBits - 1);

        //
        // Update the middle units as a whole...
        //
        for (size_t unitIndex = startUnitIndex + 1; unitIndex <= endUnitIndex - 1; ++unitIndex)
        {
            m_data[unitIndex]->enable();
        }

        //
        // Update the end unit either as a whole or bit by bit...
        //
        m_data[endUnitIndex]->enable(0, endBitIndex);
    }
}

/**
 * Gets the size of the collection.
 */
size_t BitArray::size() const
{
    return m_size;
}

/**
 * Checks whether the collection is empty.
 */
bool BitArray::empty() const
{
    return m_size == 0;
}

/**
 * Performs a logical AND on this bit array with the other bit array.
 */
void BitArray::andOperator(const IBitArray& other)
{
    base::AndBitOperator bitOperator;
    operate(bitOperator, other);
}

/**
 * Performs a logical OR on this bit array with the other bit array.
 */
void BitArray::orOperator(const IBitArray& other)
{
    base::OrBitOperator bitOperator;
    operate(bitOperator, other);
}

/**
 * Performs a logical XOR on this bit array with the other bit array.
 */
void BitArray::xorOperator(const IBitArray& other)
{
    base::XorBitOperator bitOperator;
    operate(bitOperator, other);
}

/**
 * Performs a logical NOT on this bit array.
 */
void BitArray::notOperator()
{
    base::NotBitOperator bitOperator;
    operate(bitOperator);
}

/**
 * Performs a logical bit operator on this bit array with the other bit array.
 */
void BitArray::operate(const base::IBinaryBitOperator& bitOperator, const IBitArray& other)
{
    size_t lhsSize = size();
    size_t rhsSize = other.size();

    std::vector<IBit32ArrayPtr>& lhsData = m_data;
    const std::vector<IBit32ArrayPtr>& rhsData = other.toBit32Array();

    size_t lhsNumOfUnits = lhsData.size();
    size_t rhsNumOfUnits = rhsData.size();

    size_t numberOfBits = std::min<size_t>(lhsSize, rhsSize);
    size_t numberOfUnits = std::min<size_t>(lhsNumOfUnits, rhsNumOfUnits);

    //
    // Operate on the unit level from unit {0...N-1}...
    //
    size_t unitIndex = 0;

    while (unitIndex < numberOfUnits - 1)
    {
        //lhsData[unitIndex]->operate(bitOperator, rhsData[unitIndex]);
        ++unitIndex;
    }

    //
    // Operate on the last unit either as a whole or bit by bit...
    //
    size_t lastUnitBitStartIndex = 0;
    size_t lastUnitBitEndIndex = bitIndexOf(numberOfBits - 1);

    if (lastUnitBitEndIndex == BitArray::unitSizeInBits -1)
    {
        //lhsData[unitIndex]->operate(bitOperator, rhsData[unitIndex]);
    }
    else
    {
        for (size_t bitIndex = lastUnitBitStartIndex; bitIndex <= lastUnitBitEndIndex; ++bitIndex)
        {
            lhsData[unitIndex]->operate(bitOperator, bitIndex, rhsData[unitIndex]->get(bitIndex));
        }
    }
}

/**
 * Performs a logical bit operator on this bit array.
 */
void BitArray::operate(const base::IUnaryBitOperator& bitOperator)
{
    size_t numberOfUnits = getNumberOfUnits();

    //
    // Operate on the unit level from unit {0...N-1}...
    //
    size_t unitIndex = 0;

    while (unitIndex < numberOfUnits - 1) {
        m_data[unitIndex]->operate(bitOperator);
        ++unitIndex;
    }

    //
    // Operate on the last unit either as a whole or bit by bit...
    //
    size_t lastUnitBitStartIndex = 0;
    size_t lastUnitBitEndIndex = bitIndexOf(m_size - 1);

    if (lastUnitBitEndIndex == BitArray::unitSizeInBits -1)
    {
        m_data[unitIndex]->operate(bitOperator);
    }
    else
    {
        for (size_t bitIndex = lastUnitBitStartIndex; bitIndex <= lastUnitBitEndIndex; ++bitIndex)
        {
            m_data[unitIndex]->operate(bitOperator, bitIndex);
        }
    }
}

/**
 * Converts the bits to a native array.
 */
std::vector<unsigned int> BitArray::toArray() const
{
    std::vector<unsigned int> array(m_size);

    for (size_t unitIndex = 0; unitIndex < m_size; ++unitIndex)
    {
        array[unitIndex] = m_data[unitIndex]->toInteger();
    }

    return array;
}

/**
 * Converts the bits to a 32 bit array.
 */
const std::vector<IBit32ArrayPtr>& BitArray::toBit32Array() const
{
    return m_data;
}

/**
 * Creates a bit array.
 */
std::vector<IBit32ArrayPtr> BitArray::createBitArray(size_t numberOfBits) const
{
    size_t numberOfUnits = getNumberOfUnits(numberOfBits);
    std::vector<IBit32ArrayPtr> data(numberOfUnits);

    for (size_t i = 0; i < data.size(); ++i)
    {
        data[i] = Bit32Array::make();
    }

    return data;
}

/**
 * Gets the number of units.
 */
size_t BitArray::getNumberOfUnits() const
{
    return m_data.size();
}

/**
 * Calculates the number of units.
 */
size_t BitArray::getNumberOfUnits(size_t numberOfBits) const
{
    return (numberOfBits % unitSizeInBits) == 0 ?
       (numberOfBits / unitSizeInBits) :
       (numberOfBits / unitSizeInBits) + 1;
}

/**
 * Calculates the index of a unit.
 */
size_t BitArray::unitIndexOf(size_t index) const
{
    return index / unitSizeInBits;
}

/**
 * Calculates the index of a bit in a unit.
 */
size_t BitArray::bitIndexOf(size_t index) const
{
    return index % BitArray::unitSizeInBits;
}

/**
 * Validates an index.
 */
void BitArray::validateIndex(size_t index) const
{
    size_t startIndex = 0;
    size_t endIndex = m_size - 1;
    base::Indexes::validateIndex(index, startIndex, endIndex);
}

/**
 * Gets the iterator.
 */
base::IIteratorPtr<bool> BitArray::getIterator() const
{
    return BitArrayIterator::make(*this);
}

/**
 * Gets the reverse iterator.
 */
base::IReverseIteratorPtr<bool> BitArray::getReverseIterator() const
{
    return BitArrayReverseIterator::make(*this);
}