#ifndef I_MEMORY_ALLOCATOR_H_0bac5ff1_be2d_4f1f_9670_662028049f8f
#define I_MEMORY_ALLOCATOR_H_0bac5ff1_be2d_4f1f_9670_662028049f8f

namespace memory_management
{
    /**
     * The IMemoryAllocator interface defines a memory allocator.
     */
    class IMemoryAllocator
    {
    public :
        /**
         * The constructor.
         */
        IMemoryAllocator() = default;

        /**
         * The destructor.
         */
        virtual ~IMemoryAllocator() = default;

        /**
         * The copy/move constructors.
         */
        IMemoryAllocator(const IMemoryAllocator&) = delete;
        IMemoryAllocator(IMemoryAllocator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMemoryAllocator& operator=(const IMemoryAllocator&) = delete;
        IMemoryAllocator& operator=(IMemoryAllocator&&) = delete;

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

        /**
         * Clears the allocated memory.
         */
        virtual void clear(void* memoryPtr, std::size_t size) = 0;
    };
}

#endif // I_MEMORY_ALLOCATOR_H_0bac5ff1_be2d_4f1f_9670_662028049f8f
