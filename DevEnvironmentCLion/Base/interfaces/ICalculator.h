#ifndef I_CALCULATOR_H_5886a100_53fb_4ebc_84fe_5bf86daaa448
#define I_CALCULATOR_H_5886a100_53fb_4ebc_84fe_5bf86daaa448

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

#endif // I_CALCULATOR_H_5886a100_53fb_4ebc_84fe_5bf86daaa448
