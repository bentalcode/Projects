#include "MemoryPool.h"
#include "MemoryManagementException.h"

using namespace memory_management;

/**
 * The MemoryPool constructor.
 */
MemoryPool::MemoryPool(
    std::size_t initialNumberOfElements,
    std::size_t elementSizeInBytes,
    std::size_t alignment) :
    m_elementSizeInBytes(elementSizeInBytes),
    m_alignment(alignment)
{
}

/**
 * The MemoryPool destructor.
 */
MemoryPool::~MemoryPool()
{
}

/**
 * Acquires an element from the pool.
 */
void* MemoryPool::acquireElement()
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::mutex> guard(m_mutex);

    //
    // First, try to find a pool with an available element...
    //
    FixedMemoryPoolPtr availablePool;

    for (MemoryPoolList::iterator i = m_poolList.begin(); i != m_poolList.end(); ++i)
    {
        FixedMemoryPoolPtr currPool = *i;

        if (!currPool->overCapacity())
        {
            availablePool = currPool;
            break;
        }
    }

    //
    // If no pool has an availability, then add a new one...
    //
    if (availablePool == nullptr)
    {
        availablePool = addPool();
    }

    ElementPtr elementPtr = availablePool->acquireElement();
    setElementPool(elementPtr, availablePool);

    return elementPtr;
}

/**
 * Release an element and return it to the pool.
 */
void MemoryPool::releaseElement(ElementPtr elementPtr)
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::mutex> guard(m_mutex);

    FixedMemoryPoolPtr elementPool = getElementPool(elementPtr);

    elementPool->releaseElement(elementPtr);
    removeElementPool(elementPtr);
}

/**
 * Gets number of acquired elements.
 */
std::size_t MemoryPool::numberOfAcquiredElements() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::mutex> guard(m_mutex);

    return m_elementToPoolMap.size();
}

/**
 * Adds a new pool.
 */
FixedMemoryPoolPtr MemoryPool::addPool()
{
    FixedMemoryPoolPtr poolPtr(new FixedMemoryPool(
        m_initialNumberOfElements,
        m_elementSizeInBytes,
        m_alignment));

    m_poolList.push_back(poolPtr);

    return poolPtr;
}

/**
 * Checks whether an element is in the pool.
 */
bool MemoryPool::hasElement(ElementPtr elementPtr) const
{
    ElementRawPtr elementRawPtr = reinterpret_cast<ElementRawPtr>(elementPtr);
    ElementAddressToPoolMap::const_iterator i = m_elementToPoolMap.find(elementRawPtr);

    return i != m_elementToPoolMap.end();
}

/**
 * Gets the corresponding pool of an element.
 */
FixedMemoryPoolPtr MemoryPool::getElementPool(ElementPtr elementPtr) const
{
    ElementRawPtr elementRawPtr = reinterpret_cast<ElementRawPtr>(elementPtr);
    ElementAddressToPoolMap::const_iterator i = m_elementToPoolMap.find(elementRawPtr);

    if (i == m_elementToPoolMap.end())
    {
        std::string errorMessage = "The pool does not own the specified element.";
        throw MemoryManagementException(errorMessage);
    }

    return i->second;
}

/**
 * Sets the corresponding pool of an element.
 */
void MemoryPool::setElementPool(ElementPtr elementPtr, FixedMemoryPoolPtr poolPtr)
{
    ElementRawPtr elementRawPtr = reinterpret_cast<ElementRawPtr>(elementPtr);
    m_elementToPoolMap[elementRawPtr] = poolPtr;
}

/**
 * Removes the corresponding pool of an element.
 */
void MemoryPool::removeElementPool(ElementPtr elementPtr)
{
    ElementRawPtr elementRawPtr = reinterpret_cast<ElementRawPtr>(elementPtr);
    m_elementToPoolMap.erase(elementRawPtr);
}

std::ostream& memory_management::operator<<(std::ostream& stream, const MemoryPool& memoryPool)
{
    stream
        << "NumberOfAcquiredElements: " << memoryPool.numberOfAcquiredElements() << std::endl
        << "ElementSizeInBytes: " << memoryPool.elementSize() << std::endl;

    return stream;
}
