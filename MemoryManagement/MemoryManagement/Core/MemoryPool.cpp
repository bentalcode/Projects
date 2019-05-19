#include "MemoryPool.h"
#include "MemoryManagementException.h"

using namespace memory_management;

/**
 * The MemoryPool constructor.
 */
MemoryPool::MemoryPool(
    std::size_t elementSizeInBytes,
    std::size_t numberOfElements,
    std::size_t alignment) :
    m_numberOfElements(numberOfElements),
    m_numberOfAcquiredElements(0),
    m_numberOfAvailableElements(numberOfElements),
    m_elementSizeInBytes(elementSizeInBytes),
    m_alignment(alignment)
{
    //
    // Allocates the pool...
    //
    allocate(elementSizeInBytes, numberOfElements, alignment);
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
    void* currElement = m_freeMemoryBlockList.front();

    //
    // Remove the current element from the free memory list...
    //
    m_freeMemoryBlockList.erase(m_freeMemoryBlockList.begin());

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
void MemoryPool::releaseElement(void* elementPtr)
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
    MemoryAllocator::clearMemory(elementPtr, m_elementSizeInBytes);

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
bool MemoryPool::overCapacity() const
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
std::size_t MemoryPool::numberOfElements() const
{
    return m_numberOfElements;
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

    return m_numberOfAcquiredElements;
}

/**
 * Gets number of available elements.
 */
std::size_t MemoryPool::numberOfAvailableElements() const
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
std::size_t MemoryPool::elementSize() const
{
    return m_elementSizeInBytes;
}

/**
 * Allocates the pool.
 */
void MemoryPool::allocate(
    std::size_t elementSizeInBytes,
    std::size_t numberOfElements,
    std::size_t alignment)
{
    //
    // Allocate the required size of the memory pool...
    //
    std::size_t poolSizeInBytes = elementSizeInBytes * numberOfElements;
    m_memoryPtr.reset(MemoryAllocator::allocateAlignedMemory(poolSizeInBytes, alignment));

    //
    // Get the address of the end of the memory block...
    //
    std::uintptr_t startRawAddress = reinterpret_cast<std::uintptr_t>(m_memoryPtr.get());
    std::uintptr_t endRawAddress = startRawAddress + poolSizeInBytes;

    //
    // Initialize the free list for each element...
    //
    for (std::size_t i = 0; i < numberOfElements; ++i) {

        std::uintptr_t elementRawAddress = startRawAddress + (i * elementSizeInBytes);
        assert(elementRawAddress < endRawAddress);

        void* elementAddress = reinterpret_cast<void*>(elementRawAddress);

        m_freeMemoryBlockList.push_back(elementAddress);
    }
}

/**
 * Releases the pool.
 */
void MemoryPool::release()
{
    //
    // Release the memory by invoking the memory release API...
    //
    m_memoryPtr.reset(nullptr);
}

/**
 * Updates elements counters.
 */
void MemoryPool::updateElementsCounters(bool acquired)
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

    assert(m_numberOfAvailableElements + m_numberOfAcquiredElements == m_numberOfElements);
}

std::ostream& operator<<(std::ostream& stream, const MemoryPool& memoryPool)
{
    stream
        << "NumberOfElements: " << memoryPool.numberOfElements() << std::endl
        << "NumberOfAcquiredElements: " << memoryPool.numberOfAcquiredElements() << std::endl
        << "NumberOfReleasedElements: " << memoryPool.numberOfAvailableElements() << std::endl;

    return stream;
}
