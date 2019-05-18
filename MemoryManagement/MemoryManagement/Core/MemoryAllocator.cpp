#include "MemoryAllocator.h"
#include <cassert>

using namespace memory_management;

/**
 * The MemoryAllocator constructor.
 */
MemoryAllocator::MemoryAllocator()
{
}

/**
 * The MemoryAllocator destructor.
 */
MemoryAllocator::~MemoryAllocator()
{
}

/**
 * Allocates memory.
 */
void* MemoryAllocator::allocate(const std::size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    unsigned char* allocatedMemory = new unsigned char[size];
    return static_cast<void*>(allocatedMemory);
}

/**
 * Releases memory.
 */
void MemoryAllocator::release(void* memoryPtr)
{
    if (memoryPtr == nullptr)
    {
        return;
    }

    unsigned char* allocatedMemory = static_cast<unsigned char*>(memoryPtr);

    delete[] allocatedMemory;
}

/**
 * Allocates aligned memory.
 */
void* MemoryAllocator::allocateAligned(std::size_t size, const std::size_t alignment)
{
    assert(MemoryAllocator::isAlignmentValid(alignment));

    if (size == 0)
    {
        return nullptr;
    }

    std::size_t offset = sizeof(void*) + alignment - 1;
    std::size_t totalSize = size + offset;

    void* allocatedAddress = allocate(totalSize);

    std::uintptr_t rawAddress = reinterpret_cast<std::uintptr_t>(allocatedAddress);
    std::uintptr_t alignedRawAddress = (rawAddress + offset) & (~(alignment - 1));

    void* returnedAddress = reinterpret_cast<void*>(alignedRawAddress);
    void** pReturnedAddress = &returnedAddress;
    pReturnedAddress[-1] = allocatedAddress;

    return returnedAddress;
}

/**
 * Allocates aligned memory.
 */
void MemoryAllocator::releaseAligned(void* memoryPtr)
{
    if (memoryPtr == nullptr)
    {
        return;
    }

    void** pReturnedAddress = &memoryPtr;
    void* allocatedAddress = pReturnedAddress[-1];

    release(allocatedAddress);
}

bool MemoryAllocator::isAlignmentValid(size_t alignment)
{
    return (alignment > 1 && alignment <= 128 && MemoryAllocator::powOfTwo(alignment));
}

bool MemoryAllocator::powOfTwo(size_t number)
{
    return (number & (number - 1)) == 0;
}
