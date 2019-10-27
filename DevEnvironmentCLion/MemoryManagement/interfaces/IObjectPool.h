#ifndef I_OBJECT_POOL_H_1398b81a_2b89_4410_957b_1ca9fe8f1fc7
#define I_OBJECT_POOL_H_1398b81a_2b89_4410_957b_1ca9fe8f1fc7

#include "boost/core/noncopyable.hpp"

namespace memory_management
{
    /**
     * The IObjectPool interface defines an object pool.
     */
    template <typename T>
    class IObjectPool : private boost::noncopyable
    {
    public:
        /**
         * The IObjectPool constructor.
         */
        IObjectPool() = default;

        /**
         * The IObjectPool destructor.
         */
        virtual ~IObjectPool()  = default;

        /**
         * Disables the copy constructor and assignment operator.
         */
        IObjectPool(const IObjectPool& rhs) = delete;
        IObjectPool& operator=(const IObjectPool& rhs) = delete;

        /**
         * Acquires an element from the pool.
         */
        virtual T* acquireElement() = 0;

        /**
         * Releases an element and returns it to the pool.
         */
        virtual void releaseElement(T* objectPtr) = 0;

        /**
         * Gets number of acquired elements.
         */
        virtual std::size_t numberOfAcquiredElements() const = 0;

        /**
         * Gets size of the pool in bytes.
         */
        virtual std::size_t size() const = 0;
    };
}


#endif // I_OBJECT_POOL_H_1398b81a_2b89_4410_957b_1ca9fe8f1fc7
