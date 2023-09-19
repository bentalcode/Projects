#include "ReferenceCounter.h"

using namespace base;

/**
 * The ReferenceCounter constructor.
 */
ReferenceCounter::ReferenceCounter() : 
    m_counter(0) 
{
}

/**
 * The ReferenceCounter constructor.
 */
ReferenceCounter::ReferenceCounter(unsigned long counter) : 
    m_counter(counter) 
{
}

/**
 * The ReferenceCounter destructor.
 */
ReferenceCounter::~ReferenceCounter() 
{
}

/**
 * Increments the reference counter.
 */
unsigned long ReferenceCounter::Increment()
{
    ++m_counter;
    return m_counter;
}

/**
 * Decrements the reference counter.
 */
unsigned long ReferenceCounter::Decrement()
{
    --m_counter;
    return m_counter;
}

/**
 * Gets the reference counter.
 */
unsigned long ReferenceCounter::GetCounter() const
{
    return m_counter;
}
