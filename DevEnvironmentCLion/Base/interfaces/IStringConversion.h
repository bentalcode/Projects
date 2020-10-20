#ifndef I_STRING_CONVERSION_H_99302900_37c0_4384_a1df_5e21ac8ca51e
#define I_STRING_CONVERSION_H_99302900_37c0_4384_a1df_5e21ac8ca51e

#include "Duration.h"

namespace base
{
    /**
     * The IStringConversion interface defines conversions for a string.
     */
    class IStringConversion
    {
    public:
        /**
         * The constructor.
         */
        IStringConversion() = default;

        /**
         * The destructor.
         */
        virtual ~IStringConversion() = default;

        /**
         * The copy/move constructors.
         */
        IStringConversion(const IStringConversion&) = delete;
        IStringConversion(IStringConversion&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IStringConversion& operator=(const IStringConversion&) = delete;
        IStringConversion& operator=(IStringConversion&&) = delete;

        /**
         * Converts a string to a boolean.
         */
        virtual bool toBoolean(const std::string& value) const = 0;

        /**
         * Converts a string to a short.
         */
        virtual short toShort(const std::string& value) const = 0;

        /**
         * Converts a string to an integer.
         */
        virtual int toInteger(const std::string& value) const = 0;

        /**
         * Converts a string to a long.
         */
        virtual long toLong(const std::string& value) const = 0;

        /**
         * Converts a string to a size_t.
         */
        virtual size_t toSizeT(const std::string& value) const = 0;

        /**
         * Converts a string to a float.
         */
        virtual float toFloat(const std::string& value) const = 0;

        /**
         * Converts a string to a double.
         */
        virtual double toDouble(const std::string& value) const = 0;

        /**
         * Converts a string to a character.
         */
        virtual char toCharacter(const std::string& value) const = 0;

        /**
         * Converts a string to a duration.
         */
        virtual DurationPtr toDuration(const std::string& value) const = 0;
    };
}

#endif // I_STRING_CONVERSION_H_99302900_37c0_4384_a1df_5e21ac8ca51e
