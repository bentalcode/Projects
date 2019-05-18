#include "MemoryPool.h"

using namespace memory_management;

template <typename ObjectType, size_t BlockSize>
MemoryPool<ObjectType, BlockSize>::MemoryPool()
{
}

template <typename ObjectType, size_t BlockSize>
MemoryPool<ObjectType, BlockSize>::MemoryPool(const MemoryPool& memoryPool)
{
    MemoryPool();
}

template <typename ObjectType, size_t BlockSize>
MemoryPool<ObjectType, BlockSize>::~MemoryPool()
{
}
