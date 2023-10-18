#include "FixedMemoryPool.h"
#include "MemoryManagementException.h"
#include <assert.h>

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
    Allocate(elementSizeInBytes, numberOfElements, alignment);
}

/**
 * The FixedMemoryPool destructor.
 */
FixedMemoryPool::~FixedMemoryPool()
{
    Release();
}

/**
 * Acquires an element from the pool.
 */
IMemoryPool::MemoryAddress FixedMemoryPool::AcquireElement()
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    //
    // Validate that the pool has not reached it's maximum capacity...
    //
    if (m_freeMemoryBlockList.empty())
    {
        long statusCode = base::ErrorCodes::OUT_OF_RANGE;
        std::wstring errorMessage = L"The memory pool has reached it's maximum capacity.";

        throw MemoryManagementException(statusCode, errorMessage);
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
    UpdateElementsCounters(acquired);

    assert(NumberOfAvailableElements() == m_freeMemoryBlockList.size());

    return currElement;
}

/**
 * Release an element and return it to the pool.
 */
void FixedMemoryPool::ReleaseElement(MemoryAddress elementPtr)
{
    if (elementPtr == nullptr)
    {
        long statusCode = base::ErrorCodes::INVALID_ARG;
        std::wstring errorMessage = L"The memory of the Element is not valid.";

        throw MemoryManagementException(statusCode, errorMessage);
    }

    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    //
    // Clear the memory of the returned element...
    //
    MemoryAllocator::ClearMemory(elementPtr, m_elementAllocationSizeInBytes);

    //
    // Return the element to the end of the free list...
    //
    m_freeMemoryBlockList.push_back(elementPtr);

    //
    // Update the number of acquired/released elements in the pool...
    //
    bool acquired = false;
    UpdateElementsCounters(acquired);
}

/**
 * Determines whether the memory pool has reached it's capacity.
 */
bool FixedMemoryPool::OverCapacity() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    return m_numberOfAvailableElements == 0;
}

/**
 * Gets number of supported elements.
 */
std::size_t FixedMemoryPool::NumberOfElements() const
{
    return m_numberOfElements;
}

/**
 * Gets number of acquired elements.
 */
std::size_t FixedMemoryPool::NumberOfAcquiredElements() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    return m_numberOfAcquiredElements;
}

/**
 * Gets number of available elements.
 */
std::size_t FixedMemoryPool::NumberOfAvailableElements() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    return m_numberOfAvailableElements;
}

/**
 * Gets a size of an element in bytes.
 */
std::size_t FixedMemoryPool::ElementSize() const
{
    return m_elementSizeInBytes;
}

/**
 * Gets a size of an allocated element in bytes.
 */
std::size_t FixedMemoryPool::ElementAllocationSize() const
{
    return m_elementAllocationSizeInBytes;
}

/**
 * Gets a size of a pool in bytes.
 */
std::size_t FixedMemoryPool::Size() const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    //
    // Include the size of the pool...
    //
    size_t size = m_poolSizeInBytes;

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
    size += sizeof(m_poolSizeInBytes);
    size += sizeof(m_numberOfAcquiredElements);
    size += sizeof(m_numberOfAvailableElements);
    size += sizeof(m_memoryPtr);
    size += sizeof(m_freeMemoryBlockList);

    return size;
}

/**
 * Allocates the pool.
 */
void FixedMemoryPool::Allocate(
    std::size_t elementSizeInBytes,
    std::size_t numberOfElements,
    std::size_t alignment)
{
    //
    // Calculate the pad size of each element...
    //
    std::size_t padSize = 0;

    if (elementSizeInBytes > alignment)
    {
        std::size_t unalignedSize = elementSizeInBytes % alignment;
        padSize = alignment - unalignedSize;
    }
    else if (elementSizeInBytes < alignment)
    {
        padSize = alignment - elementSizeInBytes;
    }

    m_elementAllocationSizeInBytes = elementSizeInBytes + padSize;

    //
    // Allocate the required size of the memory pool...
    //
    m_poolSizeInBytes = m_elementAllocationSizeInBytes * numberOfElements;
    m_memoryPtr.reset(MemoryAllocator::AllocateAlignedMemory(m_poolSizeInBytes, alignment));

    //
    // Get the address of the end of the memory block...
    //
    MemoryRawAddress startRawAddress = reinterpret_cast<MemoryRawAddress>(m_memoryPtr.get());
    MemoryRawAddress endRawAddress = startRawAddress + m_poolSizeInBytes - 1;

    //
    // Initialize the free list for each element...
    //
    for (std::size_t i = 0; i < numberOfElements; ++i) {
        MemoryRawAddress elementRawAddress = startRawAddress + (i * m_elementAllocationSizeInBytes);

        assert(
            elementRawAddress >= startRawAddress &&
            elementRawAddress + m_elementAllocationSizeInBytes - 1 <= endRawAddress);

        MemoryAddress elementAddress = reinterpret_cast<MemoryAddress>(elementRawAddress);

        m_freeMemoryBlockList.push_back(elementAddress);
    }
}

/**
 * Releases the pool.
 */
void FixedMemoryPool::Release()
{
    //
    // Release the memory by invoking the memory release API...
    //
    m_memoryPtr.reset(nullptr);
}

/**
 * Updates elements counters.
 */
void FixedMemoryPool::UpdateElementsCounters(bool acquired)
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

    assert(m_numberOfAcquiredElements + m_numberOfAvailableElements == m_numberOfElements);
}

/**
 * Gets the information of the pool.
 */
void FixedMemoryPool::GetPoolInformation(std::wostream& stream) const
{
    //
    // Acquire a lock...
    //
    std::lock_guard<std::recursive_mutex> guard(m_mutex);

    stream
            << "NumberOfElements: " << m_numberOfElements << std::endl
            << "NumberOfAcquiredElements: " << m_numberOfAcquiredElements << std::endl
            << "NumberOfAvailableElements: " << m_numberOfAvailableElements << std::endl
            << "ElementSizeInBytes: " << m_elementSizeInBytes << std::endl
            << "ElementAllocationSizeInBytes: " << m_elementAllocationSizeInBytes << std::endl
            << "PoolSizeInBytes: " << Size() << std::endl;
}

/**
 * Gets the information of the pool.
 */
std::wostream& memory_management::operator<<(std::wostream& stream, const FixedMemoryPool& memoryPool)
{
    memoryPool.GetPoolInformation(stream);
    return stream;
}
