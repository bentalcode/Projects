#ifndef I_VALIDATOR_H_827ca24c_230f_4ed3_bc43_e510d4638c77
#define I_VALIDATOR_H_827ca24c_230f_4ed3_bc43_e510d4638c77

namespace base
{
    /**
     * The IValidator interface defines a validator.
     */
    class IValidator
    {
    public:
        /**
         * The constructor.
         */
        IValidator() = default;

        /**
         * The destructor.
         */
        virtual ~IValidator() = default;

        /**
         * The copy/move constructors.
         */
        IValidator(const IValidator&) = delete;
        IValidator(IValidator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IValidator& operator=(const IValidator&) = delete;
        IValidator& operator=(IValidator&&) = delete;

        /**
         * Validates the logic.
         */
        virtual bool validate() const = 0;
    };

    using IValidatorPtr = std::shared_ptr<IValidator>;
}

#endif // I_VALIDATOR_H_827ca24c_230f_4ed3_bc43_e510d4638c77
