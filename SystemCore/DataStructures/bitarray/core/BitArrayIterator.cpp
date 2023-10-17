#include "BitArrayIterator.h"
#include "IBitArray.h"
#include <assert.h>

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
    Reset();
}

/**
 * The BitArrayIterator destructor.
 */
BitArrayIterator::~BitArrayIterator()
{
}

/**
 * Checks whether there is a Next element.
 */
bool BitArrayIterator::HasNext() const
{
    return m_currIndex < m_bitArray.Size();
}

/**
 * Gets the Next element.
 */
bool BitArrayIterator::Next()
{
    assert(HasNext());

    bool currElement = m_bitArray.IsOn(m_currIndex);
    ++m_currIndex;

    return currElement;
}

/**
 * Resets the iterator.
 */
void BitArrayIterator::Reset()
{
    m_currIndex = 0;
}
