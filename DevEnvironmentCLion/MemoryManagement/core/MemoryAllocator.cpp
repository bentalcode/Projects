#include "PreCompiled.h"

#include "MemoryManagementException.h"
#include "MemoryAllocator.h"

using namespace memory_management;

void* MemoryAllocator::allocateMemory(const std::size_t size)
{
    MemoryAllocator allocator;
    return allocator.allocate(size);
}

void MemoryAllocator::releaseMemory(void* memoryPtr)
{
    MemoryAllocator allocator;
    allocator.release(memoryPtr);
}

void* MemoryAllocator::allocateAlignedMemory(
        std::size_t size,
        const std::size_t alignment)
{
    MemoryAllocator allocator;
    return allocator.allocateAligned(size, alignment);
}

void MemoryAllocator::releaseAlignedMemory(void* memoryPtr)
{
    MemoryAllocator allocator;
    allocator.releaseAligned(memoryPtr);
}

/**
 * Clears the allocated memory.
 */
void MemoryAllocator::clearMemory(void* memoryPtr, std::size_t size)
{
    MemoryAllocator allocator;
    allocator.clear(memoryPtr, size);
}

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
    if (!MemoryAllocator::isAlignmentValid(alignment))
    {
        std::string errorMessage = "The alignment is invalid.";
        throw MemoryManagementException(errorMessage);
    }

    if (size == 0)
    {
        return nullptr;
    }

    std::size_t offset = sizeof(void*) + alignment - 1;
    std::size_t totalSize = size + offset;

    void* allocatedAddress = allocate(totalSize);

    std::uintptr_t rawAddress = reinterpret_cast<std::uintptr_t>(allocatedAddress);
    std::uintptr_t alignedRawAddress = (rawAddress + offset) & (~(alignment - 1));
    assert(alignedRawAddress % alignment == 0);

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

/**
 * Clears the allocated memory.
 */
void MemoryAllocator::clear(void* memoryPtr, std::size_t size)
{
    std::uintptr_t rawAddress = reinterpret_cast<std::uintptr_t>(memoryPtr);

    for (std::size_t i = 0; i < size; ++i)
    {
        rawAddress = 0;
    }
}

bool MemoryAllocator::isAlignmentValid(size_t alignment)
{
    return (alignment > 1 && alignment <= 128 && MemoryAllocator::powOfTwo(alignment));
}

bool MemoryAllocator::powOfTwo(size_t number)
{
    return (number & (number - 1)) == 0;
}
