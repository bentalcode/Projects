#ifndef I_VALIDATOR_H_2cd7456a_8634_4763_9c53_005d626e836c
#define I_VALIDATOR_H_2cd7456a_8634_4763_9c53_005d626e836c

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

#endif // I_VALIDATOR_H_2cd7456a_8634_4763_9c53_005d626e836c
