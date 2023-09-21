#ifndef STRING_CONVERSION_H_acb057f7_cd8c_445c_a075_75fe6590e8ea
#define STRING_CONVERSION_H_acb057f7_cd8c_445c_a075_75fe6590e8ea

#include "IStringConversion.h"

namespace base {

    /**
     * The StringConversion class implements conversions for a string.
     */
    class StringConversion final : public IStringConversion
    {
    public:
        /**
         * The StringConversion constructor.
         */
        StringConversion();

        /**
         * The StringConversion destructor.
         */
        virtual ~StringConversion();

        /**
         * The copy/move constructors.
         */
        StringConversion(const StringConversion&) = delete;
        StringConversion(StringConversion&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        StringConversion& operator=(const StringConversion&) = delete;
        StringConversion& operator=(StringConversion&&) = delete;

        /**
         * Converts a string to a boolean.
         */
        virtual bool ToBoolean(const std::wstring& value) const override;

        /**
         * Converts a string to a short.
         */
        virtual short ToShort(const std::wstring& value) const override;

        /**
         * Converts a string to an integer.
         */
        virtual int ToInteger(const std::wstring& value) const override;

        /**
         * Converts a string to a long.
         */
        virtual long ToLong(const std::wstring& value) const override;

        /**
         * Converts a string to a size_t.
         */
        virtual size_t ToSizeT(const std::wstring& value) const override;

        /**
         * Converts a string to a float.
         */
        virtual float ToFloat(const std::wstring& value) const override;

        /**
         * Converts a string to a double.
         */
        virtual double ToDouble(const std::wstring& value) const override;

        /**
         * Converts a string to a character.
         */
        virtual char ToCharacter(const std::wstring& value) const override;

        /**
         * Converts a string to a duration.
         */
        virtual DurationSharedPtr ToDuration(const std::wstring& value) const override;
    };
}

#endif // STRING_CONVERSION_H_acb057f7_cd8c_445c_a075_75fe6590e8ea
