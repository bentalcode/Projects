#ifndef I_CALCULATOR_H_a961ca1f_baa9_4758_b1b4_78c7d4044b7d
#define I_CALCULATOR_H_a961ca1f_baa9_4758_b1b4_78c7d4044b7d

namespace base
{
    /**
     * The ICalculator interface defines a calculator.
     */
    template <typename T>
    class ICalculator
    {
    public:
        /**
         * The constructor.
         */
        ICalculator() = default;

        /**
         * The destructor.
         */
        virtual ~ICalculator() = default;

        /**
         * The copy/move constructors.
         */
        ICalculator(const ICalculator&) = delete;
        ICalculator(ICalculator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ICalculator& operator=(const ICalculator&) = delete;
        ICalculator& operator=(ICalculator&&) = delete;

        /**
         * Calculates the logic.
         */
        virtual T calculate() = 0;
    };

    template <typename T>
    using ICalculatorPtr = std::shared_ptr<ICalculator<T>>;
}

#endif // I_CALCULATOR_H_a961ca1f_baa9_4758_b1b4_78c7d4044b7d
