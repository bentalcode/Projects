#ifndef REFERENCE_COUNT_H_4799394d_e7e2_4d80_9607_a7a75cec5473
#define REFERENCE_COUNT_H_4799394d_e7e2_4d80_9607_a7a75cec5473

#include <iostream>

namespace base
{
    /**
     * The ReferenceCount class defines a generic reference count.
     */
    class ReferenceCount
    {
    public:
        /**
         * The default constructor.
         */
        ReferenceCount();

        /**
         * The destructor.
         */
        ~ReferenceCount();

        /**
         * The copy/move constructors.
         */
        ReferenceCount(const ReferenceCount&) = delete;
        ReferenceCount(ReferenceCount&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ReferenceCount& operator=(const ReferenceCount&) = delete;
        ReferenceCount& operator=(ReferenceCount&&) = delete;

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

#endif // REFERENCE_COUNT_H_4799394d_e7e2_4d80_9607_a7a75cec5473
