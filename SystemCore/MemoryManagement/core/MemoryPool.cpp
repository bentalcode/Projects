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
    AddPool();
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
void* MemoryPool::AcquireElement()
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    //
    // First, try to find a pool with an available element...
    //
    FixedMemoryPoolSharedPtr availablePool;

    for (FixedMemoryPoolSharedPtr pool : m_poolList)
    {
        if (!pool->OverCapacity())
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
            long statusCode = base::ErrorCodes::OUT_OF_RANGE;
            std::wstring errorMessage = L"The Memory Pool has reached it's limits.";

            throw MemoryManagementException(statusCode, errorMessage);
        }

        availablePool = AddPool();
    }

    MemoryAddress elementPtr = availablePool->AcquireElement();
    SetElementPool(elementPtr, availablePool);

    return elementPtr;
}

/**
 * Release an element and return it to the pool.
 */
void MemoryPool::ReleaseElement(MemoryAddress elementPtr)
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    FixedMemoryPoolSharedPtr elementPool = GetElementPool(elementPtr);

    elementPool->ReleaseElement(elementPtr);
    RemoveElementPool(elementPtr);
}

/**
 * Gets number of acquired elements.
 */
std::size_t MemoryPool::NumberOfAcquiredElements() const
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
std::size_t MemoryPool::InitialNumberOfElements() const
{
    return m_initialNumberOfElements;
}

/**
 * Gets a size of an element in bytes.
 */
std::size_t MemoryPool::ElementSize() const
{
    return m_elementSizeInBytes;
}

/**
 * Gets a size of a pool in bytes.
 */
std::size_t MemoryPool::Size() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    size_t size = 0;

    //
    // Include the size of each pool...
    //
    for (FixedMemoryPoolSharedPtr pool : m_poolList)
    {
        size += pool->Size();
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
    size_t poolListSize = m_poolList.size() * sizeof(FixedMemoryPoolSharedPtr);
    size += sizeof(poolListSize);

    //
    // Include the size of the element-pool lookup...
    //
    size_t poolMapEntry = sizeof(MemoryRawAddress) + sizeof(FixedMemoryPoolSharedPtr);
    size_t poolMapSize = m_elementToPoolMap.size() * poolMapEntry;

    size += poolMapSize;

    return size;
}

/**
 * Adds a new pool.
 */
FixedMemoryPoolSharedPtr MemoryPool::AddPool()
{
    FixedMemoryPoolSharedPtr poolPtr(new FixedMemoryPool(
        m_initialNumberOfElements,
        m_elementSizeInBytes,
        m_alignment));

    m_poolList.push_back(poolPtr);

    return poolPtr;
}

/**
 * Checks whether an element is in the pool.
 */
bool MemoryPool::HasElement(MemoryAddress elementPtr) const
{
    MemoryRawAddress elementRawPtr = reinterpret_cast<MemoryRawAddress>(elementPtr);
    ElementAddressToPoolMap::const_iterator i = m_elementToPoolMap.find(elementRawPtr);

    return i != m_elementToPoolMap.end();
}

/**
 * Gets the corresponding pool of an element.
 */
FixedMemoryPoolSharedPtr MemoryPool::GetElementPool(MemoryAddress elementPtr) const
{
    MemoryRawAddress elementRawPtr = reinterpret_cast<MemoryRawAddress>(elementPtr);
    ElementAddressToPoolMap::const_iterator i = m_elementToPoolMap.find(elementRawPtr);

    if (i == m_elementToPoolMap.end())
    {
        long statusCode = base::ErrorCodes::RESOURCE_NOT_FOUND;
        std::wstring errorMessage = L"The pool does not own the specified Element.";

        throw MemoryManagementException(statusCode, errorMessage);
    }

    return i->second;
}

/**
 * Sets the corresponding pool of an element.
 */
void MemoryPool::SetElementPool(MemoryAddress elementPtr, FixedMemoryPoolSharedPtr poolPtr)
{
    MemoryRawAddress elementRawPtr = reinterpret_cast<MemoryRawAddress>(elementPtr);
    m_elementToPoolMap[elementRawPtr] = poolPtr;
}

/**
 * Removes the corresponding pool of an element.
 */
void MemoryPool::RemoveElementPool(MemoryAddress elementPtr)
{
    MemoryRawAddress elementRawPtr = reinterpret_cast<MemoryRawAddress>(elementPtr);
    m_elementToPoolMap.erase(elementRawPtr);
}

/**
 * Gets the information of the pool.
 */
void MemoryPool::GetPoolInformation(std::wostream& stream) const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    stream
        << L"NumberOfAcquiredElements: " << NumberOfAcquiredElements() << std::endl
        << L"InitialNumberOfElements: " << InitialNumberOfElements() << std::endl
        << L"ElementSizeInBytes: " << ElementSize() << std::endl
        << L"PoolSizeInBytes: " << Size() << std::endl;

    stream << std::endl << L"Sub Pools:" << std::endl;

    int index = 0;
    for (FixedMemoryPoolSharedPtr pool : m_poolList)
    {
        ++index;

        stream << std::endl << L"Pool" << index << std::endl;
        stream << *pool;
        stream << std::endl;
    }
}

/**
 * Gets the information of the pool.
 */
std::wostream& memory_management::operator<<(std::wostream& stream, const MemoryPool& memoryPool)
{
    memoryPool.GetPoolInformation(stream);
    return stream;
}
