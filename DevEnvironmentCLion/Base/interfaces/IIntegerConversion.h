#ifndef I_INTEGER_CONVERSION_H_aded1c8c_f8bc_4543_a9f2_4cc8a355064e
#define I_INTEGER_CONVERSION_H_aded1c8c_f8bc_4543_a9f2_4cc8a355064e

namespace base
{
    /**
     * The IIntegerConversion interface defines conversions for an integer.
     */
    class IIntegerConversion
    {
    public:
        /**
         * The constructor.
         */
        IIntegerConversion() = default;

        /**
         * The destructor.
         */
        virtual ~IIntegerConversion() = default;

        /**
         * The copy/move constructors.
         */
        IIntegerConversion(const IIntegerConversion&) = delete;
        IIntegerConversion(IIntegerConversion&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IIntegerConversion& operator=(const IIntegerConversion&) = delete;
        IIntegerConversion& operator=(IIntegerConversion&&) = delete;

        /**
         * Converts an integer to a character.
         */
        virtual char toCharacter(int value) const = 0;
    };
}

#endif // I_INTEGER_CONVERSION_H_aded1c8c_f8bc_4543_a9f2_4cc8a355064e
