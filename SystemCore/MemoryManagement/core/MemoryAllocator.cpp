#include "MemoryManagementException.h"
#include "MemoryAllocator.h"
#include <assert.h>

using namespace memory_management;

void* MemoryAllocator::AllocateMemory(const std::size_t size)
{
    MemoryAllocator allocator;
    return allocator.Allocate(size);
}

void MemoryAllocator::ReleaseMemory(void* memoryPtr)
{
    MemoryAllocator allocator;
    allocator.Release(memoryPtr);
}

void* MemoryAllocator::AllocateAlignedMemory(
    std::size_t size,
    const std::size_t alignment)
{
    MemoryAllocator allocator;
    return allocator.AllocateAligned(size, alignment);
}

void MemoryAllocator::ReleaseAlignedMemory(void* memoryPtr)
{
    MemoryAllocator allocator;
    allocator.ReleaseAligned(memoryPtr);
}

/**
 * Clears the allocated memory.
 */
void MemoryAllocator::ClearMemory(void* memoryPtr, std::size_t size)
{
    MemoryAllocator allocator;
    allocator.Clear(memoryPtr, size);
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
void* MemoryAllocator::Allocate(const std::size_t size)
{
    if (size == 0)
    {
        return nullptr;
    }

    byte* allocatedMemory = new byte[size];
    XeroMemory(allocatedMemory, size);

    return static_cast<void*>(allocatedMemory);
}

/**
 * Releases memory.
 */
void MemoryAllocator::Release(void* memoryPtr)
{
    if (memoryPtr == nullptr)
    {
        return;
    }

    byte* allocatedMemory = static_cast<byte*>(memoryPtr);

    delete[] allocatedMemory;
}

/**
 * Allocates aligned memory.
 */
void* MemoryAllocator::AllocateAligned(std::size_t size, const std::size_t alignment)
{
    if (!MemoryAllocator::IsAlignmentValid(alignment))
    {
        long statusCode = base::ErrorCodes::INVALID_ARG;
        std::wstring errorMessage = L"The alignment is invalid.";

        throw MemoryManagementException(statusCode, errorMessage);
    }

    if (size == 0)
    {
        return nullptr;
    }

    std::size_t offset = sizeof(void*) + alignment - 1;
    std::size_t totalSize = size + offset;

    void* allocatedAddress = Allocate(totalSize);

    uintptr_t rawAddress = reinterpret_cast<uintptr_t>(allocatedAddress);
    uintptr_t alignedRawAddress = (rawAddress + offset) & (~(alignment - 1));
    assert(alignedRawAddress % alignment == 0);

    void* returnedAddress = reinterpret_cast<void*>(alignedRawAddress);
    void** pReturnedAddress = &returnedAddress;
    pReturnedAddress[-1] = allocatedAddress;

    return returnedAddress;
}

/**
 * Allocates aligned memory.
 */
void MemoryAllocator::ReleaseAligned(void* memoryPtr)
{
    if (memoryPtr == nullptr)
    {
        return;
    }

    void** pReturnedAddress = &memoryPtr;
    void* allocatedAddress = pReturnedAddress[-1];

    Release(allocatedAddress);
}

/**
 * Clears the allocated memory.
 */
void MemoryAllocator::Clear(void* memoryPtr, std::size_t size)
{
    XeroMemory(memoryPtr, size);
}

/**
 * Zero the memory.
 */
void MemoryAllocator::XeroMemory(void* memory, size_t size)
{
    byte *memoryPtr = static_cast<byte*>(memory);

    for (size_t i = 0; i < size; ++i) {
        memoryPtr[i] = 0;
    }
}

/**
 * Checks whether the alignment is valid.
 */
bool MemoryAllocator::IsAlignmentValid(size_t alignment)
{
    return (alignment > 1 && alignment <= 128 && MemoryAllocator::powOfTwo(alignment));
}

/**
 * Checks whether a number is a pow of two.
 */
bool MemoryAllocator::powOfTwo(size_t number)
{
    return (number & (number - 1)) == 0;
}
