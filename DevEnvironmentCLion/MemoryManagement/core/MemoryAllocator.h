#ifndef MEMORY_ALLOCATOR_H_7059c4fc_d7b8_4a6a_81d8_5849edfed11a
#define MEMORY_ALLOCATOR_H_7059c4fc_d7b8_4a6a_81d8_5849edfed11a

#include "IMemoryAllocator.h"
#include <memory>

namespace memory_management
{
    /**
     * The MemoryAllocator class implements a memory allocator.
     */
    class MemoryAllocator final : public IMemoryAllocator
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
        virtual void* allocate(const std::size_t size) override;

        /**
         * Releases memory.
         */
        virtual void release(void* memoryPtr) override;

        /**
         * Allocates aligned memory.
         */
        virtual void* allocateAligned(std::size_t size, const std::size_t alignment) override;

        /**
         * Allocates aligned memory.
         */
        virtual void releaseAligned(void* memoryPtr) override;

        /**
         * Clears the allocated memory.
         */
        virtual void clear(void* memoryPtr, std::size_t size) override;

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

    using MemoryPtr = std::unique_ptr<void, MemoryReleaser>;
    using AlignedMemoryPtr = std::unique_ptr<void, AlignedMemoryReleaser>;
}

#endif /* MEMORY_ALLOCATOR_H_7059c4fc_d7b8_4a6a_81d8_5849edfed11a */
