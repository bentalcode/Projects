#ifndef STRING_EQUALITY_H_b6cafaa7_daf3_4ca6_a41b_0ebb172d2f81
#define STRING_EQUALITY_H_b6cafaa7_daf3_4ca6_a41b_0ebb172d2f81

namespace base
{
    /**
     * The StringEquality class implements complementary APIs for string equality.
     */
    class StringEquality final
    {
    public:
        /**
         * Checks whether strings are equals. (Ignore case)
         */
        static bool equalsIgnoreCase(
            const std::string& left,
            const std::string& right);

        /**
         * Checks whether strings are equals with start and end indexes.
         */
        static bool equals(
            const std::string& left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Checks whether strings are equals with start and end indexes. (Ignore case)
         */
        static bool equalsIgnoreCase(
            const std::string& left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Checks whether strings are equals with start index and length.
         */
        static bool equals(
            const std::string& left,
            size_t leftStartIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t length);

        /**
         * Checks whether strings are equals with start index and length. (Ignore case)
         */
        static bool equalsIgnoreCase(
            const std::string& left,
            size_t leftStartIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t length);

        /**
         * Checks whether buffer strings are equals with start and end indexes.
         */
        static bool equals(
            const std::string::value_type* left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::string::value_type* right,
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Checks whether buffer strings are equals with start and end indexes. (Ignore case)
         */
        static bool equalsIgnoreCase(
            const std::string::value_type* left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::string::value_type* right,
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Checks whether buffer strings are equals with start index and length.
         */
        static bool equals(
            const std::string::value_type* left,
            size_t leftStartIndex,
            const std::string::value_type* right,
            size_t rightStartIndex,
            size_t length);

        /**
         * Checks whether buffer strings are equals with start index and length. (Ignore case)
         */
        static bool equalsIgnoreCase(
            const std::string::value_type* left,
            size_t leftStartIndex,
            const std::string::value_type* right,
            size_t rightStartIndex,
            size_t length);

        /**
         * Checks whether strings are equals with start and end indexes.
         */
        static bool equals(
            const std::string& left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t rightEndIndex,
            bool ignoreCase);

        /**
         * Checks whether strings are equals with start index and length.
         */
        static bool equals(
            const std::string& left,
            size_t leftStartIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t length,
            bool ignoreCase);

        /**
         * Checks whether buffer strings are equals with start and end indexes.
         */
        static bool equals(
            const std::string::value_type* left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::string::value_type* right,
            size_t rightStartIndex,
            size_t rightEndIndex,
            bool ignoreCase);

        /**
         * Checks whether buffer strings are equals with start index and length.
         */
        static bool equals(
            const std::string::value_type* left,
            size_t leftStartIndex,
            const std::string::value_type* right,
            size_t rightStartIndex,
            size_t length,
            bool ignoreCase);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        StringEquality() = delete;
        ~StringEquality() = delete;
    };
}

#endif // STRING_EQUALITY_H_b6cafaa7_daf3_4ca6_a41b_0ebb172d2f81
