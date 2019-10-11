#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

#include "PreCompiled.h"
#include "IMemoryAllocator.h"

namespace memory_management
{
    /**
     * The MemoryAllocator class implements a memory allocator.
     */
    class MemoryAllocator : public IMemoryAllocator
    {
    public:
        /**
         * Allocates memory.
         */
        static void* allocateMemory(const std::size_t size);

        /**
         * Releases memory.
         */
        static void releaseMemory(void* memoryPtr);

        /**
         * Allocates aligned memory.
         */
        static void* allocateAlignedMemory(std::size_t size, const std::size_t alignment);

        /**
         * Allocates aligned memory.
         */
        static void releaseAlignedMemory(void* memoryPtr);

        /**
         * Clears the allocated memory.
         */
        static void clearMemory(void* memoryPtr, std::size_t size);
        
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

        /**
         * Clears the allocated memory.
         */
        virtual void clear(void* memoryPtr, std::size_t size);

    private:
        static bool isAlignmentValid(size_t alignment);

        static bool powOfTwo(size_t number);
    };

    /**
     * The memory releaser functor.
     */
    struct MemoryReleaser {
        void operator()(void* memoryPtr)
        {
            MemoryAllocator::releaseMemory(memoryPtr);
        }
    };

    /**
     * The memory releaser functor.
     */
    struct AlignedMemoryReleaser {
        void operator()(void* memoryPtr)
        {
            MemoryAllocator::releaseAlignedMemory(memoryPtr);
        }
    };

    typedef std::unique_ptr<void, MemoryReleaser> MemoryPtr;
    typedef std::unique_ptr<void, AlignedMemoryReleaser> AlignedMemoryPtr;
}

#endif /* MEMORY_ALLOCATOR_H */
