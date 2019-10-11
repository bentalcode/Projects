#include "FixedMemoryPool.h"
#include "MemoryManagementException.h"

using namespace memory_management;

/**
 * The FixedMemoryPool constructor.
 */
FixedMemoryPool::FixedMemoryPool(
    std::size_t numberOfElements,
    std::size_t elementSizeInBytes,
    std::size_t alignment) :
    m_numberOfElements(numberOfElements),
    m_elementSizeInBytes(elementSizeInBytes),
    m_alignment(alignment),
    m_numberOfAcquiredElements(0),
    m_numberOfAvailableElements(numberOfElements)
{
    //
    // Allocates the pool...
    //
    allocate(elementSizeInBytes, numberOfElements, alignment);
}

/**
 * The FixedMemoryPool destructor.
 */
FixedMemoryPool::~FixedMemoryPool()
{
    release();
}

/**
 * Acquires an element from the pool.
 */
IMemoryPool::MemoryAddress FixedMemoryPool::acquireElement()
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::mutex> guard(m_mutex);

    //
    // Validate that the pool has not reached it's maximum capacity...
    //
    if (m_freeMemoryBlockList.empty())
    {
        std::string errorMessage = "The memory pool has reached it's maximum capacity.";
        throw MemoryManagementException(errorMessage);
    }

    //
    // Retrieve the current element...
    //
    MemoryAddress currElement = m_freeMemoryBlockList.front();

    //
    // Remove the current element from the free memory list...
    //
    MemoryList::size_type before = m_freeMemoryBlockList.size();
    m_freeMemoryBlockList.erase(m_freeMemoryBlockList.begin());
    MemoryList::size_type after = m_freeMemoryBlockList.size();
    assert(before - 1 == after);

    //
    // Update the number of acquired/released elements in the pool...
    //
    bool acquired = true;
    updateElementsCounters(acquired);

    return currElement;
}

/**
 * Release an element and return it to the pool.
 */
void FixedMemoryPool::releaseElement(MemoryAddress elementPtr)
{
    if (elementPtr == nullptr)
    {
        std::string errorMessage = "The memory of the element is not valid.";
        throw MemoryManagementException(errorMessage);
    }

    //
    // Acquire a lock...
    //
    std::lock_guard<std::mutex> guard(m_mutex);

    //
    // Clear the memory of the returned element...
    //
    MemoryAllocator::clearMemory(elementPtr, m_elementAllocationSizeInBytes);

    //
    // Return the element to the end of the free list...
    //
    m_freeMemoryBlockList.push_back(elementPtr);

    //
    // Update the number of acquired/released elements in the pool...
    //
    bool acquired = false;
    updateElementsCounters(acquired);
}

/**
 * Determines whether the memory pool has reached it's capacity.
 */
bool FixedMemoryPool::overCapacity() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::mutex> guard(m_mutex);

    return m_numberOfAvailableElements == 0;
}

/**
 * Gets number of supported elements.
 */
std::size_t FixedMemoryPool::numberOfElements() const
{
    return m_numberOfElements;
}

/**
 * Gets number of acquired elements.
 */
std::size_t FixedMemoryPool::numberOfAcquiredElements() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::mutex> guard(m_mutex);

    return m_numberOfAcquiredElements;
}

/**
 * Gets number of available elements.
 */
std::size_t FixedMemoryPool::numberOfAvailableElements() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::mutex> guard(m_mutex);

    return m_numberOfAvailableElements;
}

/**
 * Gets a size of an element in bytes.
 */
std::size_t FixedMemoryPool::elementSize() const
{
    return m_elementSizeInBytes;
}

/**
 * Gets a size of an allocated element in bytes.
 */
std::size_t FixedMemoryPool::elementAllocationSize() const
{
    return m_elementAllocationSizeInBytes;
}

/**
 * Gets a size of a pool in bytes.
 */
std::size_t FixedMemoryPool::size() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::mutex> guard(m_mutex);

    //
    // Include the size of the pool...
    //
    size_t size = m_numberOfAcquiredElements * m_elementAllocationSizeInBytes;

    //
    // Include the size of the free list...
    //
    size += m_freeMemoryBlockList.size() * sizeof(MemoryList::value_type);

    //
    // Include the size of the data members...
    //
    size += sizeof(m_mutex);
    size += sizeof(m_numberOfElements);
    size += sizeof(m_elementSizeInBytes);
    size += sizeof(m_alignment);
    size += sizeof(m_elementAllocationSizeInBytes);
    size += sizeof(m_numberOfAcquiredElements);
    size += sizeof(m_numberOfAvailableElements);
    size += sizeof(m_memoryPtr);
    size += sizeof(m_freeMemoryBlockList);

    return size;
}

/**
 * Allocates the pool.
 */
void FixedMemoryPool::allocate(
    std::size_t elementSizeInBytes,
    std::size_t numberOfElements,
    std::size_t alignment)
{
    //
    // Calculate the pad size of each element...
    //
    std::size_t unalignedSize = 0;

    if (elementSizeInBytes > alignment)
    {
        unalignedSize = elementSizeInBytes % alignment;
    }
    else if (elementSizeInBytes < alignment)
    {
        unalignedSize = alignment - elementSizeInBytes;

    }

    std::size_t padSize = alignment - unalignedSize;
    m_elementAllocationSizeInBytes = elementSizeInBytes + padSize;

    //
    // Allocate the required size of the memory pool...
    //
    std::size_t poolSizeInBytes = m_elementAllocationSizeInBytes * numberOfElements;
    m_memoryPtr.reset(MemoryAllocator::allocateAlignedMemory(poolSizeInBytes, alignment));

    //
    // Get the address of the end of the memory block...
    //
    MemoryRawAddress startRawAddress = reinterpret_cast<MemoryRawAddress>(m_memoryPtr.get());
    MemoryRawAddress endRawAddress = startRawAddress + poolSizeInBytes;

    //
    // Initialize the free list for each element...
    //
    for (std::size_t i = 0; i < numberOfElements; ++i) {

        MemoryRawAddress elementRawAddress = startRawAddress + (i * m_elementAllocationSizeInBytes);
        assert(elementRawAddress < endRawAddress);

        MemoryAddress elementAddress = reinterpret_cast<MemoryAddress>(elementRawAddress);

        m_freeMemoryBlockList.push_back(elementAddress);
    }
}

/**
 * Releases the pool.
 */
void FixedMemoryPool::release()
{
    //
    // Release the memory by invoking the memory release API...
    //
    m_memoryPtr.reset(nullptr);
}

/**
 * Updates elements counters.
 */
void FixedMemoryPool::updateElementsCounters(bool acquired)
{
    if (acquired)
    {
        ++m_numberOfAcquiredElements;
        --m_numberOfAvailableElements;
    }
    else
    {
        --m_numberOfAcquiredElements;
        ++m_numberOfAvailableElements;
    }

    assert(m_numberOfAvailableElements == m_freeMemoryBlockList.size());
    assert(m_numberOfAvailableElements + m_numberOfAcquiredElements == m_numberOfElements);
}

std::ostream& memory_management::operator<<(std::ostream& stream, const FixedMemoryPool& memoryPool)
{
    stream
        << "OverCapacity: " << memoryPool.overCapacity() << std::endl
        << "NumberOfElements: " << memoryPool.numberOfElements() << std::endl
        << "NumberOfAcquiredElements: " << memoryPool.numberOfAcquiredElements() << std::endl
        << "NumberOfAvailableElements: " << memoryPool.numberOfAvailableElements() << std::endl
        << "ElementSizeInBytes: " << memoryPool.elementSize() << std::endl
        << "ElementAllocationSizeInBytes: " << memoryPool.elementAllocationSize() << std::endl
        << "PoolSizeInBytes: " << memoryPool.size() << std::endl;

    return stream;
}
