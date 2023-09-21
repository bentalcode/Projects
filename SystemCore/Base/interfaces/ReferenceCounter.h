#ifndef REFERENCE_COUNTER_H_e61b8af3_7c5c_4ae3_a430_0bd3c77c9dff
#define REFERENCE_COUNTER_H_e61b8af3_7c5c_4ae3_a430_0bd3c77c9dff

namespace base {

    /**
     * The ReferenceCounter class implements a thread-safe reference counter.
     */
    class ReferenceCounter final {
    public:
        /**
         * The ReferenceCounter constructor.
         */
        ReferenceCounter();

        /**
         * The ReferenceCounter constructor.
         */
        explicit ReferenceCounter(unsigned long counter);

        /**
         * The ReferenceCounter destructor.
         */
        ~ReferenceCounter();

        /**
         * Increments the reference counter.
         */
        unsigned long Increment();

        /**
         * Decrements the reference counter.
         */
        unsigned long Decrement();

        /**
         * Gets the reference counter.
         */
        unsigned long GetCounter() const;

    private:
        unsigned long m_counter;
    };

} // namespace base

#endif // REFERENCE_COUNTER_H_e61b8af3_7c5c_4ae3_a430_0bd3c77c9dff
