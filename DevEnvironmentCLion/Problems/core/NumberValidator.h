#ifndef NUMBER_VALIDATOR_H_e21c364d_e115_431d_9510_cbe8ff2a8ecc
#define NUMBER_VALIDATOR_H_e21c364d_e115_431d_9510_cbe8ff2a8ecc

#include "IValidator.h"

namespace problems
{
    /**
     * The NumberValidator class implements a validator of a number.
     */
    class NumberValidator final : public base::IValidator
    {
    public:
        /**
         * The constructor.
         */
        explicit NumberValidator(const std::string& str);

        /**
         * The destructor.
         */
        virtual ~NumberValidator() = default;

        /**
         * The copy/move constructors.
         */
        NumberValidator(const NumberValidator&) = delete;
        NumberValidator(NumberValidator&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        NumberValidator& operator=(const NumberValidator&) = delete;
        NumberValidator& operator=(NumberValidator&&) = delete;

        /**
         * Validates a number.
         *
         * Numbers 0-9
         * Exponent - "e"
         * Positive/negative sign - "+"/"-"
         * Decimal point - "."
         */
        virtual bool validate() const override;

    private:
        /**
         * Validates that a number component is valid.
         */
        bool validateNumberComponent(
            const std::string& data,
            std::string::size_type startIndex,
            std::string::size_type endIndex,
            bool componentAfterExponent) const;

        /**
         * Checks whether a character is valid.
         */
        bool isCharacterValid(char value) const;

        /**
         * Checks whether a character is a digit.
         */
        bool isDigit(char value) const;

        /**
         * Checks whether a character is a plus.
         */
        bool isPlus(char value) const;

        /**
         * Checks whether a character is a minus.
         */
        bool isMinus(char value) const;

        /**
         * Checks whether a character is an exponent.
         */
        bool isExponent(char value) const;

        /**
         * Checks whether a character is a decimal point.
         */
        bool isDecimalPoint(char value) const;

        std::string m_str;
    };
}

#endif // NUMBER_VALIDATOR_H_e21c364d_e115_431d_9510_cbe8ff2a8ecc
