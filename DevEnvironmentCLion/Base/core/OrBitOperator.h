#ifndef OR_BIT_OPERATOR_H_9d9479f3_a35d_44c8_a531_a1b40756d85d
#define OR_BIT_OPERATOR_H_9d9479f3_a35d_44c8_a531_a1b40756d85d

#include "IBinaryBitOperator.h"

namespace base
{
    /**
     * The OrBitOperator class implements an or bit operator.
     */
    class OrBitOperator : public IBinaryBitOperator
    {
    public:
        /**
         * The constructor.
         */
        OrBitOperator();

        /**
         * The destructor.
         */
        virtual ~OrBitOperator();

        /**
         * The copy/move constructors.
         */
        OrBitOperator(const OrBitOperator&) = delete;
        OrBitOperator(OrBitOperator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        OrBitOperator& operator=(const OrBitOperator&) = delete;
        OrBitOperator& operator=(OrBitOperator&&) = delete;

        /**
         * Performs a logical bit operator on the specified values.
         */
        virtual unsigned int evaluate(unsigned int lhs, unsigned int rhs) const override;
    };
}

#endif // OR_BIT_OPERATOR_H_9d9479f3_a35d_44c8_a531_a1b40756d85d
