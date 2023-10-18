#include "BitArray.h"
#include "Bit32Array.h"
#include "Bits.h"
#include "AndBitOperator.h"
#include "OrBitOperator.h"
#include "XorBitOperator.h"
#include "NotBitOperator.h"
#include "BitArrayException.h"
#include "Indexes.h"
#include "Indexes.h"
#include "BitArrayIterator.h"
#include "BitArrayReverseIterator.h"
#include <assert.h>

using namespace datastructures::bitarray;

/**
 * Creates a bit array.
 */
IBitArraySharedPtr BitArray::Make(size_t numberOfBits)
{
    return std::make_shared<BitArray>(numberOfBits);
}

/**
 * Copies a bit array.
 */
IBitArraySharedPtr BitArray::Copy(const IBitArray& bitArray)
{
    return std::make_shared<BitArray>(bitArray);
}

/**
 * The BitArray constructor.
 */
BitArray::BitArray(size_t numberOfBits) :
    m_data(CreateBitArray(numberOfBits)),
    m_size(numberOfBits)
{
    if (m_size == 0)
    {
        long statusCode = base::ErrorCodes::INVALID_ARG;
        std::wstring errorMessage = L"The number ofbits Has to be positive.";

        throw BitArrayException(statusCode, errorMessage);
    }
}

/**
 * The BitArray Copy constructor.
 */
BitArray::BitArray(const IBitArray& bitArray) :
    m_data(bitArray.ToBit32Array()),
    m_size(bitArray.Size())
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
void BitArray::TurnOn(size_t index)
{
    Set(index, 1);
}

/**
 * Turns off a bit at the specified index.
 */
void BitArray::TurnOff(size_t index)
{
    Set(index, 0);
}

/**
 * Checks whether a bit at the specified index is on.
 */
bool BitArray::IsOn(size_t index) const
{
    return Get(index) != 0;
}

/**
 * Checks whether a bit at the specified index is off.
 */
bool BitArray::IsOff(size_t index) const
{
    return Get(index) == 0;
}

/**
 * Sets a value of a bit at the specified index.
 */
void BitArray::Set(size_t index, unsigned int value)
{
    ValidateIndex(index);

    size_t unitIndex = UnitIndexOf(index);
    size_t bitIndex = BitIndexOf(index);

    m_data[unitIndex]->Set(bitIndex, value);
}

/**
 * Gets a value of a bit at the specified index.
 */
size_t BitArray::Get(size_t index) const
{
    ValidateIndex(index);

    size_t unitIndex = UnitIndexOf(index);
    size_t bitIndex = BitIndexOf(index);

    unsigned int bitValue = m_data[unitIndex]->Get(bitIndex);
    assert(base::Bits::IsBitValue(bitValue));

    return bitValue;
}

/**
 * Sets the bits to the complement ofits current value.
 */
void BitArray::Flip()
{
    base::NotBitOperator bitOperator;
    Operate(bitOperator);
}

/**
 * Sets the bit at the specified index to the complement ofits current value.
 */
void BitArray::Flip(size_t index)
{
    ValidateIndex(index);

    size_t unitIndex = UnitIndexOf(index);
    size_t bitIndex = BitIndexOf(index);

    m_data[unitIndex]->Flip(bitIndex);
}

/**
 * Returns the number ofbits Set to true.
 */
size_t BitArray::Cardinality() const
{
    size_t numberOfBitsOn = 0;

    size_t numberOfUnits = GetNumberOfUnits();
    size_t unitIndex = 0;

    //
    // Operate on the unit level from unit {0...N-1}...
    //
    while (unitIndex < numberOfUnits - 1)
    {
        numberOfBitsOn += m_data[unitIndex]->Cardinality();

        ++unitIndex;
    }

    //
    // Operate on the last unit either as a whole or bit by bit...
    //
    size_t lastUnitBitStartIndex = 0;
    size_t lastUnitBitEndIndex = BitIndexOf(m_size - 1);

    numberOfBitsOn += m_data[unitIndex]->Cardinality(lastUnitBitStartIndex, lastUnitBitEndIndex);

    return numberOfBitsOn;
}

/**
 * Sets all the bits to false.
 */
void BitArray::Clear()
{
    size_t numberOfUnits = GetNumberOfUnits();

    //
    // Operate on the unit level from unit {0...N-1}...
    //
    size_t unitIndex = 0;

    while (unitIndex < numberOfUnits - 1)
    {
        m_data[unitIndex]->Clear();
        ++unitIndex;
    }

    //
    // Operate on the last unit either as a whole or bit by bit...
    //
    size_t lastUnitBitStartIndex = 0;
    size_t lastUnitBitEndIndex = BitIndexOf(m_size - 1);

    m_data[unitIndex]->Clear(lastUnitBitStartIndex, lastUnitBitEndIndex);
}

/**
 * Sets all the bits at the specified range to false.
 */
void BitArray::Clear(size_t startIndex, size_t endIndex)
{
    ValidateIndex(startIndex);
    ValidateIndex(endIndex);

    assert(startIndex <= endIndex);

    if (startIndex > endIndex)
    {
        return;
    }

    size_t startUnitIndex = UnitIndexOf(startIndex);
    size_t startBitIndex = BitIndexOf(startIndex);

    size_t endUnitIndex = UnitIndexOf(endIndex);
    size_t endBitIndex = BitIndexOf(endIndex);

    size_t numberOfUnits = base::Indexes::Size(startUnitIndex, endUnitIndex);

    if (numberOfUnits == 0)
    {
        return;
    }

    if (numberOfUnits == 1)
    {
        //
        // Update the single unit either as a whole or bit by bit...
        //
        m_data[startUnitIndex]->Clear(startBitIndex, endBitIndex);
    }
    else
    {
        //
        // Update the start unit either as a whole or bit by bit...
        //
        m_data[startUnitIndex]->Clear(startBitIndex, BitArray::unitSizeInBits - 1);

        //
        // Update the middle units as a whole...
        //
        for (int unitIndex = startUnitIndex + 1; unitIndex <= endUnitIndex - 1; ++unitIndex)
        {
            m_data[unitIndex]->Clear();
        }

        //
        // Update the end unit either as a whole or bit by bit...
        //
        m_data[endUnitIndex]->Clear(0, endBitIndex);
    }
}

/**
 * Sets all the bits to true.
 */
void BitArray::Enable()
{
    size_t numberOfUnits = GetNumberOfUnits();

    //
    // Operate on the unit level from unit {0...N-1}...
    //
    size_t unitIndex = 0;

    while (unitIndex < numberOfUnits - 1)
    {
        m_data[unitIndex]->Enable();
        ++unitIndex;
    }

    //
    // Operate on the last unit either as a whole or bit by bit...
    //
    size_t lastUnitBitStartIndex = 0;
    size_t lastUnitBitEndIndex = BitIndexOf(m_size - 1);

    m_data[unitIndex]->Enable(lastUnitBitStartIndex, lastUnitBitEndIndex);
}

/**
 * Sets all the bits at the specified range to true.
 */
void BitArray::Enable(size_t startIndex, size_t endIndex)
{
    ValidateIndex(startIndex);
    ValidateIndex(endIndex);

    assert(startIndex <= endIndex);

    if (startIndex > endIndex)
    {
        return;
    }

    size_t startUnitIndex = UnitIndexOf(startIndex);
    size_t startBitIndex = BitIndexOf(startIndex);

    size_t endUnitIndex = UnitIndexOf(endIndex);
    size_t endBitIndex = BitIndexOf(endIndex);

    size_t numberOfUnits = base::Indexes::Size(startUnitIndex, endUnitIndex);

    if (numberOfUnits == 0)
    {
        return;
    }

    if (numberOfUnits == 1)
    {
        //
        // Update the single unit either as a whole or bit by bit...
        //
        m_data[startUnitIndex]->Enable(startBitIndex, endBitIndex);
    }
    else
    {
        //
        // Update the start unit either as a whole or bit by bit...
        //
        m_data[startUnitIndex]->Enable(startBitIndex, BitArray::unitSizeInBits - 1);

        //
        // Update the middle units as a whole...
        //
        for (size_t unitIndex = startUnitIndex + 1; unitIndex <= endUnitIndex - 1; ++unitIndex)
        {
            m_data[unitIndex]->Enable();
        }

        //
        // Update the end unit either as a whole or bit by bit...
        //
        m_data[endUnitIndex]->Enable(0, endBitIndex);
    }
}

/**
 * Gets the Size of the collection.
 */
size_t BitArray::Size() const
{
    return m_size;
}

/**
 * Checks whether the collection is Empty.
 */
bool BitArray::Empty() const
{
    return m_size == 0;
}

/**
 * Performs a logical AND on this bit array with the other bit array.
 */
void BitArray::AndOperator(const IBitArray& other)
{
    base::AndBitOperator bitOperator;
    Operate(bitOperator, other);
}

/**
 * Performs a logical OR on this bit array with the other bit array.
 */
void BitArray::OrOperator(const IBitArray& other)
{
    base::OrBitOperator bitOperator;
    Operate(bitOperator, other);
}

/**
 * Performs a logical XOR on this bit array with the other bit array.
 */
void BitArray::XorOperator(const IBitArray& other)
{
    base::XorBitOperator bitOperator;
    Operate(bitOperator, other);
}

/**
 * Performs a logical NOT on this bit array.
 */
void BitArray::NotOperator()
{
    base::NotBitOperator bitOperator;
    Operate(bitOperator);
}

/**
 * Performs a logical bit operator on this bit array with the other bit array.
 */
void BitArray::Operate(const base::IBinaryBitOperator& bitOperator, const IBitArray& other)
{
    size_t lhsSize = Size();
    size_t rhsSize = other.Size();

    std::vector<IBit32ArraySharedPtr>& lhsData = m_data;
    const std::vector<IBit32ArraySharedPtr>& rhsData = other.ToBit32Array();

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
    size_t lastUnitBitEndIndex = BitIndexOf(numberOfBits - 1);

    if (lastUnitBitEndIndex == BitArray::unitSizeInBits -1)
    {
        //lhsData[unitIndex]->operate(bitOperator, rhsData[unitIndex]);
    }
    else
    {
        for (size_t bitIndex = lastUnitBitStartIndex; bitIndex <= lastUnitBitEndIndex; ++bitIndex)
        {
            lhsData[unitIndex]->Operate(bitOperator, bitIndex, rhsData[unitIndex]->Get(bitIndex));
        }
    }
}

/**
 * Performs a logical bit operator on this bit array.
 */
void BitArray::Operate(const base::IUnaryBitOperator& bitOperator)
{
    size_t numberOfUnits = GetNumberOfUnits();

    //
    // Operate on the unit level from unit {0...N-1}...
    //
    size_t unitIndex = 0;

    while (unitIndex < numberOfUnits - 1) {
        m_data[unitIndex]->Operate(bitOperator);
        ++unitIndex;
    }

    //
    // Operate on the last unit either as a whole or bit by bit...
    //
    size_t lastUnitBitStartIndex = 0;
    size_t lastUnitBitEndIndex = BitIndexOf(m_size - 1);

    if (lastUnitBitEndIndex == BitArray::unitSizeInBits -1)
    {
        m_data[unitIndex]->Operate(bitOperator);
    }
    else
    {
        for (size_t bitIndex = lastUnitBitStartIndex; bitIndex <= lastUnitBitEndIndex; ++bitIndex)
        {
            m_data[unitIndex]->Operate(bitOperator, bitIndex);
        }
    }
}

/**
 * Converts the bits to a native array.
 */
std::vector<unsigned int> BitArray::ToArray() const
{
    std::vector<unsigned int> array(m_size);

    for (size_t unitIndex = 0; unitIndex < m_size; ++unitIndex)
    {
        array[unitIndex] = m_data[unitIndex]->ToInteger();
    }

    return array;
}

/**
 * Converts the bits to a 32 bit array.
 */
const std::vector<IBit32ArraySharedPtr>& BitArray::ToBit32Array() const
{
    return m_data;
}

/**
 * Creates a bit array.
 */
std::vector<IBit32ArraySharedPtr> BitArray::CreateBitArray(size_t numberOfBits) const
{
    size_t numberOfUnits = GetNumberOfUnits(numberOfBits);
    std::vector<IBit32ArraySharedPtr> data(numberOfUnits);

    for (size_t i = 0; i < data.size(); ++i)
    {
        data[i] = Bit32Array::Make();
    }

    return data;
}

/**
 * Gets the number ofunits.
 */
size_t BitArray::GetNumberOfUnits() const
{
    return m_data.size();
}

/**
 * Calculates the number ofunits.
 */
size_t BitArray::GetNumberOfUnits(size_t numberOfBits) const
{
    return (numberOfBits % unitSizeInBits) == 0 ?
       (numberOfBits / unitSizeInBits) :
       (numberOfBits / unitSizeInBits) + 1;
}

/**
 * Calculates the index of a unit.
 */
size_t BitArray::UnitIndexOf(size_t index) const
{
    return index / unitSizeInBits;
}

/**
 * Calculates the index of a bit in a unit.
 */
size_t BitArray::BitIndexOf(size_t index) const
{
    return index % BitArray::unitSizeInBits;
}

/**
 * Validates an index.
 */
void BitArray::ValidateIndex(size_t index) const
{
    size_t startIndex = 0;
    size_t endIndex = m_size - 1;
    base::Indexes::ValidateIndex(index, startIndex, endIndex);
}

/**
 * Gets the iterator.
 */
base::IIteratorSharedPtr<bool> BitArray::GetIterator() const
{
    return BitArrayIterator::Make(*this);
}

/**
 * Gets the reverse iterator.
 */
base::IReverseIteratorSharedPtr<bool> BitArray::GetReverseIterator() const
{
    return BitArrayReverseIterator::Make(*this);
}