#ifndef STRINGS_H_51629563_c6b5_4a79_9ddf_27072fa886cb
#define STRINGS_H_51629563_c6b5_4a79_9ddf_27072fa886cb

#include <string>
#include <vector>

namespace base
{
    /**
     * The Strings class implements complementary APIs for strings.
     */
    class Strings final
    {
    public:
        /**
         * Trims from start (in place).
         */
        static void LeftTrim(std::wstring& str);

        /**
         * Trims from End (in place).
         */
        static void RightTrim(std::wstring& str);

        /**
         * Trims from both ends (in place).
         */
        static void Trim(std::wstring& str);

        /**
         * Trims from start (copying).
         */
        static std::wstring GetLeftTrimed(const std::wstring& str);

        /**
         * Trims from End (copying).
         */
        static std::wstring GetRightTrimed(const std::wstring& str);

        /**
         * Trims from both ends (copying).
         */
        static std::wstring GetTrimed(const std::wstring& str);

        /**
         * Splits a string with a separator.
         */
        static void SplitString(
            const std::wstring& str,
            const std::wstring& separator,
            std::vector<std::wstring>& result);

        /**
         * Splits a string with a separator.
         */
        static void SplitString(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            const std::wstring& separator,
            std::vector<std::wstring>& result);

        /**
         * Splits a string with a regex separator.
         */
        static void SplitStringWithRegex(
            const std::wstring& str,
            const std::wstring& separatorRegex,
            std::vector<std::wstring>& result);

        /**
         * Splits a string with a regex separator.
         */
        static void SplitStringWithRegex(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            const std::wstring& separatorRegex,
            std::vector<std::wstring>& result);

        /**
         * Wraps a string.
         */
        static std::wstring Wrap(const std::wstring& str, std::wstring::value_type start, std::wstring::value_type end);

        /**
         * Wraps a string.
         */
        static std::wstring Wrap(const std::wstring& str, const std::wstring& start, const std::wstring& end);

        /**
         * Wraps a string with parentheses.
         */
        static std::wstring WrapWithParentheses(const std::wstring& str);

        /**
         * Wraps a string with curly brackets.
         */
        static std::wstring WrapWithCurlyBracket(const std::wstring& str);

        /**
         * Wraps a string with square brackets.
         */
        static std::wstring WrapWithSquareBracket(const std::wstring& str);

        /**
         * Wraps a string with quotes.
         */
        static std::wstring WrapWithQuotes(const std::wstring& str);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Strings() = delete;
        ~Strings() = delete;
    };

} // namespace base

#endif // STRINGS_H_51629563_c6b5_4a79_9ddf_27072fa886cb
