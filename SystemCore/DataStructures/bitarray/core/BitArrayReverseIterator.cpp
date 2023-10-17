#include "BitArrayReverseIterator.h"
#include "IBitArray.h"
#include <assert.h>

using namespace datastructures::bitarray;

/**
 * Creates a reverse iterator of a bit array.
 */
base::IReverseIteratorSharedPtr<bool> BitArrayReverseIterator::make(const IBitArray& bitArray)
{
    return std::make_shared<BitArrayReverseIterator>(bitArray);
}

/**
 * The BitArrayReverseIterator constructor.
 */
BitArrayReverseIterator::BitArrayReverseIterator(const IBitArray& bitArray) :
    m_bitArray(bitArray)
{
    Reset();
}

/**
 * The BitArrayReverseIterator destructor.
 */
BitArrayReverseIterator::~BitArrayReverseIterator()
{
}

/**
 * Checks whether there is a Next element.
 */
bool BitArrayReverseIterator::HasNext() const
{
    return !m_end;
}

/**
 * Gets the Next element.
 */
bool BitArrayReverseIterator::Next()
{
    assert(HasNext());

    bool currElement = m_bitArray.IsOn(m_currIndex);

    if (m_currIndex == 0)
    {
        m_end = true;
    }
    else
    {
        --m_currIndex;
    }

    return currElement;
}

/**
 * Resets the iterator.
 */
void BitArrayReverseIterator::Reset()
{
    m_currIndex = m_bitArray.Size() - 1;
    m_end = false;
}
