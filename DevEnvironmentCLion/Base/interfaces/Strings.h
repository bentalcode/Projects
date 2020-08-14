#ifndef STRINGS_H_51629563_c6b5_4a79_9ddf_27072fa886cb
#define STRINGS_H_51629563_c6b5_4a79_9ddf_27072fa886cb

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
        static void leftTrim(std::string& str);

        /**
         * Trims from end (in place).
         */
        static void rightTrim(std::string& str);

        /**
         * Trims from both ends (in place).
         */
        static void trim(std::string& str);

        /**
         * Trims from start (copying).
         */
        static std::string leftTrimCopy(const std::string& str);

        /**
         * Trims from end (copying).
         */
        static std::string rightTrimCopy(const std::string& str);

        /**
         * Trims from both ends (copying).
         */
        static std::string trimCopy(const std::string& str);

        /**
         * Splits a string with a character separator.
         */
        static void splitString(
            const std::string& str,
            char separator,
            std::vector<std::string>& result);

        /**
         * Splits a string with a character separator.
         */
        static void splitString(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            char separator,
            std::vector<std::string>& result);

        /**
         * Splits a string with a regex separator.
         */
        static void splitString(
            const std::string& str,
            const std::string& separatorRegex,
            std::vector<std::string>& result);

        /**
         * Splits a string with a regex separator.
         */
        static void splitString(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            const std::string& separatorRegex,
            std::vector<std::string>& result);

    private:
        /**
         * Finds the start index of a token.
         */
        static bool findTokenStartIndex(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            char characterToSplit,
            size_t& result);

        /**
         * Finds the end index of a token.
         */
        static bool findTokenEndIndex(
            const std::string& str,
            size_t startIndex,
            size_t endIndex,
            char characterToSplit,
            size_t& result);

        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Strings() = delete;
        ~Strings() = delete;
    };
}

#endif // STRINGS_H_51629563_c6b5_4a79_9ddf_27072fa886cb
