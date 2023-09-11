#include "PreCompiled.h"
#include "Bit32ArrayReverseIterator.h"
#include "Bit32Array.h"

using namespace datastructures::bitarray;

/**
 * Creates a reverse iterator of a bit 32 array.
 */
base::IReverseIteratorPtr<bool> Bit32ArrayReverseIterator::make(const IBit32Array& bitArray)
{
    return std::make_shared<Bit32ArrayReverseIterator>(bitArray);
}

/**
 * The Bit32ArrayReverseIterator constructor.
 */
Bit32ArrayReverseIterator::Bit32ArrayReverseIterator(const IBit32Array& bitArray) :
    m_bitArray(bitArray)
{
    reset();
}

/**
 * The Bit32ArrayReverseIterator destructor.
 */
Bit32ArrayReverseIterator::~Bit32ArrayReverseIterator()
{
}

/**
 * Checks whether there is a next element.
 */
bool Bit32ArrayReverseIterator::hasNext() const
{
    return !m_end;
}

/**
 * Gets the next element.
 */
bool Bit32ArrayReverseIterator::next()
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
void Bit32ArrayReverseIterator::reset()
{
    m_currIndex = m_bitArray.size() - 1;
    m_end = false;
}
