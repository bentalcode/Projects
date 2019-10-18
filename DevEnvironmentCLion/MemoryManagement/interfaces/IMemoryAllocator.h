#ifndef I_MEMORY_ALLOCATOR_H_9a678253_ac7f_46b1_928f_124cde37a2ab
#define I_MEMORY_ALLOCATOR_H_9a678253_ac7f_46b1_928f_124cde37a2ab

namespace memory_management
{
    /**
     * The IMemoryAllocator interface defines a memory allocator.
     */
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

        /**
         * Clears the allocated memory.
         */
        virtual void clear(void* memoryPtr, std::size_t size) = 0;
    };
}

#endif // I_MEMORY_ALLOCATOR_H_9a678253_ac7f_46b1_928f_124cde37a2ab
