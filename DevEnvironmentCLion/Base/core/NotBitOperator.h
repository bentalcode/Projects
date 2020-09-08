#ifndef NOT_BIT_OPERATOR_H_2088104e_e38a_42d7_9fdd_1f6be831cea4
#define NOT_BIT_OPERATOR_H_2088104e_e38a_42d7_9fdd_1f6be831cea4

#include "IUnaryBitOperator.h"

namespace base
{
    /**
     * The NotBitOperator class implements a not bit operator.
     */
    class NotBitOperator final : public IUnaryBitOperator
    {
    public:
        /**
         * The constructor.
         */
        NotBitOperator();

        /**
         * The destructor.
         */
        virtual ~NotBitOperator();

        /**
         * The copy/move constructors.
         */
        NotBitOperator(const NotBitOperator&) = delete;
        NotBitOperator(NotBitOperator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        NotBitOperator& operator=(const NotBitOperator&) = delete;
        NotBitOperator& operator=(NotBitOperator&&) = delete;

        /**
         * Performs a logical bit operator on the specified value.
         */
        virtual unsigned int evaluate(unsigned int value) const override;

        /**
         * Performs a logical bit operator on the specified bit.
         */
        virtual unsigned int evaluateBit(unsigned int bitValue) const override;
    };
}

#endif // UNARY_BIT_OPERATOR_H_a451140d_ed84_43c9_868a_781a606bcbf5
