#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include "MemoryBlock.h"
#include <iostream>

namespace memory_management
{
    /**
     * The MemoryPool class.
     */
    template <typename ObjectType, std::size_t BlockSize = 4096>
    class MemoryPool
    {
    public:
        /**
         * The MemoryPool constructor.
         */
        MemoryPool();

        /**
         * The MemoryPool copy constructor.
         */
        MemoryPool(const MemoryPool& memoryPool);

        /**
         * The MemoryPool destructor.
         */
        ~MemoryPool();

    private:
    };

}

#endif /* MEMORY_POOL_H */
