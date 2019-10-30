#ifndef REFERENCE_COUNT_H_8269acd0_e2db_4e53_a6e0_bd02196d8c57
#define REFERENCE_COUNT_H_8269acd0_e2db_4e53_a6e0_bd02196d8c57

#include <iostream>

namespace base
{
    /**
     * The ReferenceCount class defines a generic reference count.
     */
    class ReferenceCount
    {
    public:
        ReferenceCount();
        ~ReferenceCount();

        void addReference();
        void removeReference();

        inline int getCounter() const;

    private:
        int m_counter;
    };

    ReferenceCount::ReferenceCount() :
        m_counter(0)
    {
    }

    ReferenceCount::~ReferenceCount()
    {
    }

    void ReferenceCount::addReference()
    {
        ++m_counter;
    }

    void ReferenceCount::removeReference()
    {
        --m_counter;
    }

    int ReferenceCount::getCounter() const
    {
        return m_counter;
    }
}

#endif // REFERENCE_COUNT_H_8269acd0_e2db_4e53_a6e0_bd02196d8c57
