#ifndef I_CALCULATOR_H_2026be97_e589_4b76_95eb_5bb7726d79c5
#define I_CALCULATOR_H_2026be97_e589_4b76_95eb_5bb7726d79c5

#include <memory>

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

    //
    // Defines the SharedPtr of Calculator...
    //
    template <typename T>
    using ICalculatorSharedPtr = std::shared_ptr<ICalculator<T>>;

} // namespace base

#endif // I_CALCULATOR_H_2026be97_e589_4b76_95eb_5bb7726d79c5
