#ifndef I_MEMORY_POOL_H_496f2c6a_0f62_4d57_b17e_74e0b06c4878
#define I_MEMORY_POOL_H_496f2c6a_0f62_4d57_b17e_74e0b06c4878

namespace memory_management
{
    /**
     * The IMemoryPool interface defines a memory pool.
     */
    class IMemoryPool
    {
    public:
        using MemoryAddress = void*;
        using MemoryRawAddress = std::uintptr_t;

        /**
         * The constructor.
         */
        IMemoryPool() = default;

        /**
         * The destructor.
         */
        virtual ~IMemoryPool() = default;

        /**
         * The copy/move constructors.
         */
        IMemoryPool(const IMemoryPool&) = delete;
        IMemoryPool(IMemoryPool&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMemoryPool& operator=(const IMemoryPool&) = delete;
        IMemoryPool& operator=(IMemoryPool&&) = delete;

        /**
         * Acquires an element from the pool.
         */
        virtual MemoryAddress acquireElement() = 0;

        /**
         * Releases an element and returns it to the pool.
         */
        virtual void releaseElement(MemoryAddress elementPtr) = 0;

        /**
         * Gets number of acquired elements.
         */
        virtual std::size_t numberOfAcquiredElements() const = 0;

        /**
         * Gets a size of a pool in bytes.
         */
        virtual std::size_t size() const = 0;
    };
}

#endif // I_MEMORY_POOL_H_496f2c6a_0f62_4d57_b17e_74e0b06c4878
