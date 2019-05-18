#ifndef I_MEMORY_ALLOCATOR_H
#define I_MEMORY_ALLOCATOR_H

#include <iostream>

namespace memory_management
{
    class IMemoryAllocator
    {
    public :
        virtual ~IMemoryAllocator() {};

        /**
         * Allocates memory.
         */
        virtual void* allocate(const std::size_t size) = 0;

        /**
         * Releases memory.
         */
        virtual void release(void* memoryPtr) = 0;

        /**
         * Allocates aligned memory.
         */
        virtual void* allocateAligned(std::size_t size, const std::size_t alignment) = 0;

        /**
         * Allocates aligned memory.
         */
        virtual void releaseAligned(void* memoryPtr) = 0;
    };
}

#endif // I_MEMORY_ALLOCATOR_H
