#ifndef STRING_SEARCH_H_984abb95_0624_48b1_b5d2_c94d43a98d84
#define STRING_SEARCH_H_984abb95_0624_48b1_b5d2_c94d43a98d84

#include <string>

namespace base
{
    /**
     * The StringSearch class implements complementary APIs for string search.
     */
    class StringSearch final
    {
    public:
        /**
         * Gets first index of a character.
         * Returns string::npos if the character is not found.
         */
        static size_t FirstIndexOf(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            char character);

        /**
         * Gets first index of a character. (Ignore Case)
         * Returns string::npos if the character is not found.
         */
        static size_t FirstIndexOfIgnoreCase(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            char character);

        /**
         * Gets first index of a sub string.
         * Returns string::npos if the character is not found.
         */
        static size_t FirstIndexOf(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            const std::wstring& substr);

        /**
         * Gets first index of a sub string. (Ignore Case)
         * Returns string::npos if the character is not found.
         */
        static size_t FirstIndexOfIgnoreCase(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            const std::wstring& substr);

        /**
         * Gets last index of a character.
         * Returns string::npos if the character is not found.
         */
        static size_t LastIndexOf(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            char character);

        /**
         * Gets last index of a sub string.
         * Returns string::npos if the sub string is not found.
         */
        static size_t LastIndexOf(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            const std::wstring& substr);

        /**
         * Gets last index of a character. (Ignore Case)
         * Returns string::npos if the character is not found.
         */
        static size_t LastIndexOfIgnoreCase(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            char character);

        /**
         * Gets last index of a sub string. (Ignore Case)
         * Returns string::npos if the sub string is not found.
         */
        static size_t LastIndexOfIgnoreCase(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            const std::wstring& substr);

        /**
         * Checks whether a string starts with a prefix.
         */
        static bool StartsWith(
            const std::wstring& str,
            const std::wstring& prefix);

        /**
        * Checks whether a string starts with a prefix.
        */
        static bool StartsWith(
            const std::wstring& str,
            size_t startIndex,
            const std::wstring& prefix);

        /**
         * Checks whether a string ends with a postfix.
         */
        static bool EndsWith(
            const std::wstring& str,
            const std::wstring& postfix);

        /**
         * Checks whether a string ends with a postfix.
         */
        static bool EndsWith(
            const std::wstring& str,
            size_t endIndex,
            const std::wstring& postfix);

        /**
         * Counts the number of instances of a substring.
         */
        static unsigned int CountSubString(
            const std::wstring& str,
            const std::wstring& subString);

        /**
         * Counts the number of instances of a substring.
         */
        static unsigned int CountSubString(
            const std::wstring& str,
            const std::wstring& subString,
            bool allowOverlapping);

        /**
         * Counts the number ofinstances of a substring.
         */
        static unsigned int CountSubString(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            const std::wstring& subString,
            size_t subStringStartIndex,
            size_t subStringEndIndex,
            bool allowOverlapping);

        /**
         * Counts the number of instances of a substring from End.
         * Avoid overlapping.
         */
        static unsigned int CountSubStringFromEnd(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            const std::wstring& subString,
            size_t subStringStartIndex,
            size_t subStringEndIndex,
            bool allowOverlapping);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        StringSearch() = delete;
        ~StringSearch() = delete;
    };

} // namespace base

#endif // STRING_SEARCH_H_984abb95_0624_48b1_b5d2_c94d43a98d84
