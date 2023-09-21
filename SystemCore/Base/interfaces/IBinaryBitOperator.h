#ifndef I_BINARY_BIT_OPERATOR_H_44a03ef1_d410_4aef_bc5f_8cedbe314a8b
#define I_BINARY_BIT_OPERATOR_H_44a03ef1_d410_4aef_bc5f_8cedbe314a8b

#include "IBitOperator.h"

namespace base
{
    /**
     * The IBinaryBitOperator class implements a binary bit operator.
     */
    class IBinaryBitOperator : public IBitOperator
    {
    public:
        /**
         * The constructor.
         */
        IBinaryBitOperator() = default;

        /**
         * The destructor.
         */
        virtual ~IBinaryBitOperator() = default;

        /**
         * The copy/move constructors.
         */
        IBinaryBitOperator(const IBinaryBitOperator&) = delete;
        IBinaryBitOperator(IBinaryBitOperator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IBinaryBitOperator& operator=(const IBinaryBitOperator&) = delete;
        IBinaryBitOperator& operator=(IBinaryBitOperator&&) = delete;

        /**
         * Performs a logical bit operator on the specified values.
         */
        virtual unsigned int Evaluate(unsigned int lhs, unsigned int rhs) const = 0;
    };

    //
    // Defines the SharedPtr of Binary Bit Operator...
    //
    using IBinaryBitOperatorSharedPtr = std::shared_ptr<IBinaryBitOperator>;

} // namespace base

#endif // I_BINARY_BIT_OPERATOR_H_44a03ef1_d410_4aef_bc5f_8cedbe314a8b
