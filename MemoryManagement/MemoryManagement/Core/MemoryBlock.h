#ifndef MEMORY_BLOCK_H
#define MEMORY_BLOCK_H

#include <iostream>

namespace memory_management {

    template<typename ObjectType> class MemoryBlock;

    template <typename ObjectType>
    class MemoryBlock
    {
    public:
        MemoryBlock();
        ~MemoryBlock();

        inline ObjectType getElement() const {
            return this->slot.m_element;
        }

        inline void setElement(MemoryBlock* element) const {
            this->m_slot.m_element = element;
        }

        inline MemoryBlock* getNext() const {
            return this->m_slot.m_next;
        }

        inline void setNext(MemoryBlock* next) {
            this->m_slot.m_next = next;
        }

        static MemoryBlock* pad(MemoryBlock* memoryBlock);

    private:
        size_t padPointer(void* ptr, std::size_t alignment);

        union Slot {
            ObjectType m_element;
            MemoryBlock* m_next;
        };

        Slot m_slot;
    };
}

#endif // MEMORY_BLOCK_H
