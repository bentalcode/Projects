#ifndef STRING_COMPARABLE_H_cd6a2531_df89_4586_b222_ca729dc66093
#define STRING_COMPARABLE_H_cd6a2531_df89_4586_b222_ca729dc66093

namespace base
{
    /**
     * The StringComparable class implements complementary APIs for comparing string.
     */
    class StringComparable final
    {
    public:
        /**
         * Compares strings with start and end indexes.
         */
        static int compare(
            const std::string& left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Compares strings with start and end indexes. (Ignore case)
         */
        static int compareIgnoreCase(
            const std::string& left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Compares strings with start index and length.
         */
        static int compare(
            const std::string& left,
            size_t leftStartIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t length);

        /**
         * Compares strings with start index and length. (Ignore case)
         */
        static int compareIgnoreCase(
            const std::string& left,
            size_t leftStartIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t length);

        /**
         * Compares strings with start and end indexes.
         */
        static int compare(
            char left[],
            size_t leftStartIndex,
            size_t leftEndIndex,
            char right[],
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Compares buffer strings with start and end indexes. (Ignore case)
         */
        static int compareIgnoreCase(
            char left[],
            size_t leftStartIndex,
            size_t leftEndIndex,
            char right[],
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Compares buffer strings with start index and length.
         */
        static int compare(
            char left[],
            size_t leftStartIndex,
            char right[],
            size_t rightStartIndex,
            size_t length);

        /**
         * Compares buffer strings with start index and length. (Ignore case)
         */
        static int compareIgnoreCase(
            char left[],
            size_t leftStartIndex,
            char right[],
            size_t rightStartIndex,
            size_t length);

        /**
         * Compares strings with start and end indexes.
         */
        static int compare(
            const std::string& left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t rightEndIndex,
            bool ignoreCase);

        /**
         * Compares strings with start index and length.
         */
        static int compare(
            const std::string& left,
            size_t leftStartIndex,
            const std::string& right,
            size_t rightStartIndex,
            size_t length,
            bool ignoreCase);

        /**
         * Compares buffer strings with start and end indexes.
         */
        static int compare(
            char left[],
            size_t leftStartIndex,
            size_t leftEndIndex,
            char right[],
            size_t rightStartIndex,
            size_t rightEndIndex,
            bool ignoreCase);

        /**
         * Compares buffer strings with start index and length.
         */
        static int compare(
            char left[],
            size_t leftStartIndex,
            char right[],
            size_t rightStartIndex,
            size_t length,
            bool ignoreCase);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        StringComparable() = delete;
        ~StringComparable() = delete;
    };
}

#endif // STRING_COMPARABLE_H_cd6a2531_df89_4586_b222_ca729dc66093
