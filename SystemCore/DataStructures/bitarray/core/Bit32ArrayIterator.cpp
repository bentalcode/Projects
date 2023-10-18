#include "Bit32ArrayIterator.h"
#include "IBit32Array.h"
#include <assert.h>

using namespace datastructures::bitarray;

/**
 * Creates an iterator of a bit 32 array.
 */
base::IIteratorSharedPtr<bool> Bit32ArrayIterator::Make(const IBit32Array& bitArray)
{
    return std::make_shared<Bit32ArrayIterator>(bitArray);
}

/**
 * The Bit32ArrayIterator constructor.
 */
Bit32ArrayIterator::Bit32ArrayIterator(const IBit32Array& bitArray) :
    m_bitArray(bitArray)
{
    Reset();
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
bool Bit32ArrayIterator::HasNext() const
{
    return m_currIndex < m_bitArray.Size();
}

/**
 * Gets the next element.
 */
bool Bit32ArrayIterator::Next()
{
    assert(HasNext());

    bool currElement = m_bitArray.IsOn(m_currIndex);
    ++m_currIndex;

    return currElement;
}

/**
 * Resets the iterator.
 */
void Bit32ArrayIterator::Reset()
{
    m_currIndex = 0;
}
