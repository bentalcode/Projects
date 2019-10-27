#include "PreCompiled.h"

#include "MemoryPool.h"
#include "MemoryManagementException.h"

using namespace memory_management;

/**
 * The MemoryPool constructor.
 */
MemoryPool::MemoryPool(
    std::size_t initialNumberOfElements,
    std::size_t elementSizeInBytes,
    std::size_t alignment,
    bool dynamicAllocation) :
    m_initialNumberOfElements(initialNumberOfElements),
    m_elementSizeInBytes(elementSizeInBytes),
    m_alignment(alignment),
    m_dynamicAllocation(dynamicAllocation)
{
    addPool();
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
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    //
    // First, try to find a pool with an available element...
    //
    FixedMemoryPoolPtr availablePool;

    for (FixedMemoryPoolPtr pool : m_poolList)
    {
        if (!pool->overCapacity())
        {
            availablePool = pool;
            break;
        }
    }

    //
    // If no pool has an availability, then add a new one...
    //
    if (availablePool == nullptr)
    {
        if (!m_dynamicAllocation)
        {
            std::string errorMessage = "The Memory Pool has reached it's limits.";
            throw MemoryManagementException(errorMessage);
        }

        availablePool = addPool();
    }

    MemoryAddress elementPtr = availablePool->acquireElement();
    setElementPool(elementPtr, availablePool);

    return elementPtr;
}

/**
 * Release an element and return it to the pool.
 */
void MemoryPool::releaseElement(MemoryAddress elementPtr)
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

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
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    return m_elementToPoolMap.size();
}

/**
 * Gets the initial number of elements.
 */
std::size_t MemoryPool::initialNumberOfElements() const
{
    return m_initialNumberOfElements;
}

/**
 * Gets a size of an element in bytes.
 */
std::size_t MemoryPool::elementSize() const
{
    return m_elementSizeInBytes;
}

/**
 * Gets a size of a pool in bytes.
 */
std::size_t MemoryPool::size() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    size_t size = 0;

    //
    // Include the size of each pool...
    //
    for (FixedMemoryPoolPtr pool : m_poolList)
    {
        size += pool->size();
    }

    //
    // Include the size of the data members...
    //
    size += sizeof(m_mutex);
    size += sizeof(m_dynamicAllocation);
    size += sizeof(m_initialNumberOfElements);
    size += sizeof(m_elementSizeInBytes);
    size += sizeof(m_alignment);
    size += sizeof(m_poolList);
    size += sizeof(m_elementToPoolMap);

    //
    // Include the size of the pool list...
    //
    size_t poolListSize = m_poolList.size() * sizeof(FixedMemoryPoolPtr);
    size += sizeof(poolListSize);

    //
    // Include the size of the element-pool lookup...
    //
    size_t poolMapEntry = sizeof(MemoryRawAddress) + sizeof(FixedMemoryPoolPtr);
    size_t poolMapSize = m_elementToPoolMap.size() * poolMapEntry;

    size += poolMapSize;

    return size;
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
bool MemoryPool::hasElement(MemoryAddress elementPtr) const
{
    MemoryRawAddress elementRawPtr = reinterpret_cast<MemoryRawAddress>(elementPtr);
    ElementAddressToPoolMap::const_iterator i = m_elementToPoolMap.find(elementRawPtr);

    return i != m_elementToPoolMap.end();
}

/**
 * Gets the corresponding pool of an element.
 */
FixedMemoryPoolPtr MemoryPool::getElementPool(MemoryAddress elementPtr) const
{
    MemoryRawAddress elementRawPtr = reinterpret_cast<MemoryRawAddress>(elementPtr);
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
void MemoryPool::setElementPool(MemoryAddress elementPtr, FixedMemoryPoolPtr poolPtr)
{
    MemoryRawAddress elementRawPtr = reinterpret_cast<MemoryRawAddress>(elementPtr);
    m_elementToPoolMap[elementRawPtr] = poolPtr;
}

/**
 * Removes the corresponding pool of an element.
 */
void MemoryPool::removeElementPool(MemoryAddress elementPtr)
{
    MemoryRawAddress elementRawPtr = reinterpret_cast<MemoryRawAddress>(elementPtr);
    m_elementToPoolMap.erase(elementRawPtr);
}

/**
 * Gets the information of the pool.
 */
void MemoryPool::getPoolInformation(std::ostream& stream) const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    stream
        << "NumberOfAcquiredElements: " << numberOfAcquiredElements() << std::endl
        << "initialNumberOfElements: " << initialNumberOfElements() << std::endl
        << "ElementSizeInBytes: " << elementSize() << std::endl
        << "PoolSizeInBytes: " << size() << std::endl;

    stream << std::endl << "Sub Pools:" << std::endl;

    int index = 0;
    for (FixedMemoryPoolPtr pool : m_poolList)
    {
        ++index;

        stream << std::endl << "Pool" << index << std::endl;
        stream << *pool;
        stream << std::endl;
    }
}

/**
 * Gets the information of the pool.
 */
std::ostream& memory_management::operator<<(std::ostream& stream, const MemoryPool& memoryPool)
{
    memoryPool.getPoolInformation(stream);
    return stream;
}
