#ifndef I_UNARY_BIT_OPERATOR_H_06a79415_6497_4355_8219_75b6d151a6a3
#define I_UNARY_BIT_OPERATOR_H_06a79415_6497_4355_8219_75b6d151a6a3

#include "IBitOperator.h"

namespace base
{
    /**
     * The IUnaryBitOperator interface defines an unary bit operator.
     */
    class IUnaryBitOperator : public IBitOperator
    {
    public:
        /**
         * The constructor.
         */
        IUnaryBitOperator() = default;

        /**
         * The destructor.
         */
        virtual ~IUnaryBitOperator() = default;

        /**
         * The copy/move constructors.
         */
        IUnaryBitOperator(const IUnaryBitOperator&) = delete;
        IUnaryBitOperator(IUnaryBitOperator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IUnaryBitOperator& operator=(const IUnaryBitOperator&) = delete;
        IUnaryBitOperator& operator=(IUnaryBitOperator&&) = delete;

        /**
         * Performs a logical bit operator on the specified value.
         */
        virtual unsigned int Evaluate(unsigned int value) const = 0;

        /**
         * Performs a logical bit operator on the specified bit.
         */
        virtual unsigned int EvaluateBit(unsigned int bitValue) const = 0;
    };

    //
    // Defines the SharedPtr of Unary Bit Operator...
    //
    using IUnaryBitOperatorSharedPtr = std::shared_ptr<IUnaryBitOperator>;

} // namespace base

#endif // I_UNARY_BIT_OPERATOR_H_06a79415_6497_4355_8219_75b6d151a6a3
