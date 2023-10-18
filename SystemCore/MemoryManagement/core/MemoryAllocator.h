#ifndef MEMORY_ALLOCATOR_H_ed234889_dafa_4a99_ae93_d86b69156b54
#define MEMORY_ALLOCATOR_H_ed234889_dafa_4a99_ae93_d86b69156b54

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
        static void* AllocateMemory(const std::size_t size);

        /**
         * Releases memory.
         */
        static void ReleaseMemory(void* memoryPtr);

        /**
         * Allocates aligned memory.
         */
        static void* AllocateAlignedMemory(std::size_t size, const std::size_t alignment);

        /**
         * Releases aligned memory.
         */
        static void ReleaseAlignedMemory(void* memoryPtr);

        /**
         * Clears the allocated memory.
         */
        static void ClearMemory(void* memoryPtr, std::size_t size);
        
        /**
         * The constructor.
         */
        MemoryAllocator();

        /**
         * The destructor.
         */
        virtual ~MemoryAllocator();

        /**
         * The copy/move constructors.
         */
        MemoryAllocator(const MemoryAllocator&) = delete;
        MemoryAllocator(MemoryAllocator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MemoryAllocator& operator=(const MemoryAllocator&) = delete;
        MemoryAllocator& operator=(MemoryAllocator&&) = delete;

        /**
         * Allocates memory.
         */
        virtual void* Allocate(const std::size_t size) override;

        /**
         * Releases memory.
         */
        virtual void Release(void* memoryPtr) override;

        /**
         * Allocates aligned memory.
         */
        virtual void* AllocateAligned(std::size_t size, const std::size_t alignment) override;

        /**
         * Releases aligned memory.
         */
        virtual void ReleaseAligned(void* memoryPtr) override;

        /**
         * Clears the allocated memory.
         */
        virtual void Clear(void* memoryPtr, std::size_t size) override;

    private:
        /**
         * Zeroes memory.
         */
        static void XeroMemory(void* memoryPtr, size_t size);

        /**
         * Checks whether alignment is valid.
         */
        static bool IsAlignmentValid(size_t alignment);

        /**
         * Checks whether a number is a pow of two.
         */
        static bool powOfTwo(size_t number);
    };

    /**
     * The memory releaser functor.
     */
    struct MemoryReleaser {
        void operator()(void* memoryPtr)
        {
            MemoryAllocator::ReleaseMemory(memoryPtr);
        }
    };

    /**
     * The memory releaser functor.
     */
    struct AlignedMemoryReleaser {
        void operator()(void* memoryPtr)
        {
            MemoryAllocator::ReleaseAlignedMemory(memoryPtr);
        }
    };

    using MemoryPtr = std::unique_ptr<void, MemoryReleaser>;
    using AlignedMemoryPtr = std::unique_ptr<void, AlignedMemoryReleaser>;
}

#endif // MEMORY_ALLOCATOR_H_ed234889_dafa_4a99_ae93_d86b69156b54
