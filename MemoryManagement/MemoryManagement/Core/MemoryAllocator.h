#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

#include "IMemoryAllocator.h"

namespace memory_management
{
    /**
     * The MemoryAllocator class.
     */
    class MemoryAllocator : public IMemoryAllocator
    {
    public:
        /**
         * The MemoryAllocator constructor.
         */
        MemoryAllocator();

        /**
         * The MemoryAllocator destructor.
         */
        virtual ~MemoryAllocator();

        /**
         * Allocates memory.
         */
        virtual void* allocate(const std::size_t size);

        /**
         * Releases memory.
         */
        virtual void release(void* memoryPtr);

        /**
         * Allocates aligned memory.
         */
        virtual void* allocateAligned(std::size_t size, const std::size_t alignment);

        /**
         * Allocates aligned memory.
         */
        virtual void releaseAligned(void* memoryPtr);

    private:
        static bool isAlignmentValid(size_t alignment);

        static bool powOfTwo(size_t number);
    };

}

#endif /* MEMORY_ALLOCATOR_H */
