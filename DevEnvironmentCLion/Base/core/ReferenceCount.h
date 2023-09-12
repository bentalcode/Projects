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

        /**
         * Increments reference.
         */
        inline void incrementReference();

        /**
         * Decrements reference.
         */
        inline void decrementReference();

        /**
         * Gets counter.
         */
        inline int getCounter() const;

    private:
        int m_counter;
    };

    /**
     * The ReferenceCount constructor.
     */
    ReferenceCount::ReferenceCount() :
        m_counter(0)
    {
    }

    /**
     * The ReferenceCount destructor.
     */
    ReferenceCount::~ReferenceCount()
    {
    }

    /**
     * Increments reference.
     */
    void ReferenceCount::incrementReference()
    {
        ++m_counter;
    }

    /**
     * Decrements reference.
     */
    void ReferenceCount::decrementReference()
    {
        --m_counter;
    }

    /**
     * Gets counter.
     */
    int ReferenceCount::getCounter() const
    {
        return m_counter;
    }
}

#endif // REFERENCE_COUNT_H_4799394d_e7e2_4d80_9607_a7a75cec5473
