#ifndef I_BIT_OPERATOR_H_a487a0ee_6ac8_4f07_b7fa_6e399359b497
#define I_BIT_OPERATOR_H_a487a0ee_6ac8_4f07_b7fa_6e399359b497

namespace base
{
    /**
     * The IBitOperator interface defines a bit operator.
     */
    class IBitOperator
    {
    public:
        /**
         * The constructor.
         */
        IBitOperator() = default;

        /**
         * The destructor.
         */
        virtual ~IBitOperator() = default;

        /**
         * The copy/move constructors.
         */
        IBitOperator(const IBitOperator&) = delete;
        IBitOperator(IBitOperator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IBitOperator& operator=(const IBitOperator&) = delete;
        IBitOperator& operator=(IBitOperator&&) = delete;
    };

}

#endif // I_BIT_OPERATOR_H_a487a0ee_6ac8_4f07_b7fa_6e399359b497
