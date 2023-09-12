#include "PreCompiled.h"
#include "Bit32ArrayIterator.h"
#include "IBit32Array.h"

using namespace datastructures::bitarray;

/**
 * Creates an iterator of a bit 32 array.
 */
base::IIteratorSharedPtr<bool> Bit32ArrayIterator::make(const IBit32Array& bitArray)
{
    return std::make_shared<Bit32ArrayIterator>(bitArray);
}

/**
 * The Bit32ArrayIterator constructor.
 */
Bit32ArrayIterator::Bit32ArrayIterator(const IBit32Array& bitArray) :
    m_bitArray(bitArray)
{
    reset();
}

/**
 * The Bit32ArrayIterator destructor.
 */
Bit32ArrayIterator::~Bit32ArrayIterator()
{
}

/**
 * Checks whether there is a next element.
 */
bool Bit32ArrayIterator::hasNext() const
{
    return m_currIndex < m_bitArray.size();
}

/**
 * Gets the next element.
 */
bool Bit32ArrayIterator::next()
{
    assert(hasNext());

    bool currElement = m_bitArray.isOn(m_currIndex);
    ++m_currIndex;

    return currElement;
}

/**
 * Resets the iterator.
 */
void Bit32ArrayIterator::reset()
{
    m_currIndex = 0;
}
