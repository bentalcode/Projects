#include "PreCompiled.h"
#include "BitArrayReverseIterator.h"
#include "IBitArray.h"

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
    reset();
}

/**
 * The BitArrayReverseIterator destructor.
 */
BitArrayReverseIterator::~BitArrayReverseIterator()
{
}

/**
 * Checks whether there is a next element.
 */
bool BitArrayReverseIterator::hasNext() const
{
    return !m_end;
}

/**
 * Gets the next element.
 */
bool BitArrayReverseIterator::next()
{
    assert(hasNext());

    bool currElement = m_bitArray.isOn(m_currIndex);

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
void BitArrayReverseIterator::reset()
{
    m_currIndex = m_bitArray.size() - 1;
    m_end = false;
}
