#ifndef AND_BIT_OPERATOR_H_1e506d82_76d8_4f53_b4ce_b9573cfc8ad3
#define AND_BIT_OPERATOR_H_1e506d82_76d8_4f53_b4ce_b9573cfc8ad3

#include "IBinaryBitOperator.h"

namespace base
{
    /**
     * The AndBitOperator class implements an and bit operator.
     */
    class AndBitOperator final : public IBinaryBitOperator
    {
    public:
        /**
         * The constructor.
         */
        AndBitOperator();

        /**
         * The destructor.
         */
        virtual ~AndBitOperator();

        /**
         * The copy/move constructors.
         */
        AndBitOperator(const AndBitOperator&) = delete;
        AndBitOperator(AndBitOperator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        AndBitOperator& operator=(const AndBitOperator&) = delete;
        AndBitOperator& operator=(AndBitOperator&&) = delete;

        /**
         * Performs a logical bit operator on the specified values.
         */
        virtual unsigned int Evaluate(unsigned int lhs, unsigned int rhs) const override;
    };

} // namespace base

#endif // AND_BIT_OPERATOR_H_1e506d82_76d8_4f53_b4ce_b9573cfc8ad3
