#include "Bit32ArrayReverseIterator.h"
#include "Bit32Array.h"
#include <assert.h>

using namespace datastructures::bitarray;

/**
 * Creates a reverse iterator of a bit 32 array.
 */
base::IReverseIteratorSharedPtr<bool> Bit32ArrayReverseIterator::make(const IBit32Array& bitArray)
{
    return std::make_shared<Bit32ArrayReverseIterator>(bitArray);
}

/**
 * The Bit32ArrayReverseIterator constructor.
 */
Bit32ArrayReverseIterator::Bit32ArrayReverseIterator(const IBit32Array& bitArray) :
    m_bitArray(bitArray)
{
    Reset();
}

/**
 * The Bit32ArrayReverseIterator destructor.
 */
Bit32ArrayReverseIterator::~Bit32ArrayReverseIterator()
{
}

/**
 * Checks whether there is a Next element.
 */
bool Bit32ArrayReverseIterator::HasNext() const
{
    return !m_end;
}

/**
 * Gets the Next element.
 */
bool Bit32ArrayReverseIterator::Next()
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
void Bit32ArrayReverseIterator::Reset()
{
    m_currIndex = m_bitArray.Size() - 1;
    m_end = false;
}
