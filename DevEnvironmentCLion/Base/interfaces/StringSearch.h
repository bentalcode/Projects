#ifndef STRING_SEARCH_H_984abb95_0624_48b1_b5d2_c94d43a98d84
#define STRING_SEARCH_H_984abb95_0624_48b1_b5d2_c94d43a98d84

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
        static size_t firstIndexOf(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            char character);

        /**
         * Gets first index of a character. (Ignore Case)
         * Returns string::npos if the character is not found.
         */
        static size_t firstIndexOfIgnoreCase(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            char character);

        /**
         * Gets last index of a character.
         * Returns string::npos if the character is not found.
         */
        static size_t lastIndexOf(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            char character);

        /**
         * Gets last index of a character. (Ignore Case)
         * Returns string::npos if the character is not found.
         */
        static size_t lastIndexOfIgnoreCase(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            char character);

        /**
         * Checks whether a string starts with a prefix.
         */
        static bool startsWith(
            const std::string& str,
            const std::string& prefix);

        /**
        * Checks whether a string starts with a prefix.
        */
        static bool startsWith(
            const std::string& str,
            size_t startIndex,
            const std::string& prefix);

        /**
         * Checks whether a string ends with a postfix.
         */
        static bool endsWith(
            const std::string& str,
            const std::string& postfix);

        /**
         * Checks whether a string ends with a postfix.
         */
        static bool endsWith(
            const std::string& str,
            size_t endIndex,
            const std::string& postfix);

        /**
         * Counts the number of instances of a substring.
         */
        static unsigned int countSubString(
            const std::string& str,
            const std::string& subString);

        /**
         * Counts the number of instances of a substring.
         */
        static unsigned int countSubString(
            const std::string& str,
            const std::string& subString,
            bool allowOverlapping);

        /**
         * Counts the number of instances of a substring.
         */
        static unsigned int countSubString(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            const std::string& subString,
            size_t subStringStartIndex,
            size_t subStringEndIndex,
            bool allowOverlapping);

        /**
         * Counts the number of instances of a substring from end.
         * Avoid overlapping.
         */
        static unsigned int countSubStringFromEnd(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            const std::string& subString,
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
}

#endif // STRING_SEARCH_H_984abb95_0624_48b1_b5d2_c94d43a98d84
