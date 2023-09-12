#include "PreCompiled.h"
#include "BitArrayIterator.h"
#include "IBitArray.h"

using namespace datastructures::bitarray;

/**
 * Creates an iterator of a bit array.
 */
base::IIteratorSharedPtr<bool> BitArrayIterator::make(const IBitArray& bitArray)
{
    return std::make_shared<BitArrayIterator>(bitArray);
}

/**
 * The BitArrayIterator constructor.
 */
BitArrayIterator::BitArrayIterator(const IBitArray& bitArray) :
    m_bitArray(bitArray)
{
    reset();
}

/**
 * The BitArrayIterator destructor.
 */
BitArrayIterator::~BitArrayIterator()
{
}

/**
 * Checks whether there is a next element.
 */
bool BitArrayIterator::hasNext() const
{
    return m_currIndex < m_bitArray.size();
}

/**
 * Gets the next element.
 */
bool BitArrayIterator::next()
{
    assert(hasNext());

    bool currElement = m_bitArray.isOn(m_currIndex);
    ++m_currIndex;

    return currElement;
}

/**
 * Resets the iterator.
 */
void BitArrayIterator::reset()
{
    m_currIndex = 0;
}
