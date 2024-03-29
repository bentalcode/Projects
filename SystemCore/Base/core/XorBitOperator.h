#ifndef XOR_BIT_OPERATOR_H_1a462c56_d465_4d0c_9547_6b6f6b73e60d
#define XOR_BIT_OPERATOR_H_1a462c56_d465_4d0c_9547_6b6f6b73e60d

#include "IBinaryBitOperator.h"

namespace base
{
    /**
     * The XorBitOperator class implements a xor bit operator.
     */
    class XorBitOperator : public IBinaryBitOperator
    {
    public:
        /**
         * The constructor.
         */
        XorBitOperator();

        /**
         * The destructor.
         */
        virtual ~XorBitOperator();

        /**
         * The Copy/move constructors.
         */
        XorBitOperator(const XorBitOperator&) = delete;
        XorBitOperator(XorBitOperator&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        XorBitOperator& operator=(const XorBitOperator&) = delete;
        XorBitOperator& operator=(XorBitOperator&&) = delete;

        /**
         * Performs a logical bit operator on the specified values.
         */
        virtual unsigned int Evaluate(unsigned int lhs, unsigned int rhs) const override;
    };

} // namespace base

#endif // XOR_BIT_OPERATOR_H_1a462c56_d465_4d0c_9547_6b6f6b73e60d
