#ifndef STRING_COMPARABLE_H_cd6a2531_df89_4586_b222_ca729dc66093
#define STRING_COMPARABLE_H_cd6a2531_df89_4586_b222_ca729dc66093

#include <string>

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
        static int Compare(
            const std::wstring& left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::wstring& right,
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Compares strings with start and end indexes. (Ignore case)
         */
        static int CompareIgnoreCase(
            const std::wstring& left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::wstring& right,
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Compares strings with start index and length.
         */
        static int Compare(
            const std::wstring& left,
            size_t leftStartIndex,
            const std::wstring& right,
            size_t rightStartIndex,
            size_t length);

        /**
         * Compares strings with start index and length. (Ignore case)
         */
        static int CompareIgnoreCase(
            const std::wstring& left,
            size_t leftStartIndex,
            const std::wstring& right,
            size_t rightStartIndex,
            size_t length);

        /**
         * Compares strings with start and end indexes.
         */
        static int Compare(
            wchar_t left[],
            size_t leftStartIndex,
            size_t leftEndIndex,
            wchar_t right[],
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Compares buffer strings with start and end indexes. (Ignore case)
         */
        static int CompareIgnoreCase(
            wchar_t left[],
            size_t leftStartIndex,
            size_t leftEndIndex,
            wchar_t right[],
            size_t rightStartIndex,
            size_t rightEndIndex);

        /**
         * Compares buffer strings with start index and length.
         */
        static int Compare(
            wchar_t left[],
            size_t leftStartIndex,
            wchar_t right[],
            size_t rightStartIndex,
            size_t length);

        /**
         * Compares buffer strings with start index and length. (Ignore case)
         */
        static int CompareIgnoreCase(
            wchar_t left[],
            size_t leftStartIndex,
            wchar_t right[],
            size_t rightStartIndex,
            size_t length);

        /**
         * Compares strings with start and end indexes.
         */
        static int Compare(
            const std::wstring& left,
            size_t leftStartIndex,
            size_t leftEndIndex,
            const std::wstring& right,
            size_t rightStartIndex,
            size_t rightEndIndex,
            bool ignoreCase);

        /**
         * Compares strings with start index and length.
         */
        static int Compare(
            const std::wstring& left,
            size_t leftStartIndex,
            const std::wstring& right,
            size_t rightStartIndex,
            size_t length,
            bool ignoreCase);

        /**
         * Compares buffer strings with start and end indexes.
         */
        static int Compare(
            wchar_t left[],
            size_t leftStartIndex,
            size_t leftEndIndex,
            wchar_t right[],
            size_t rightStartIndex,
            size_t rightEndIndex,
            bool ignoreCase);

        /**
         * Compares buffer strings with start index and length.
         */
        static int Compare(
            wchar_t left[],
            size_t leftStartIndex,
            wchar_t right[],
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

} // namespace base

#endif // STRING_COMPARABLE_H_cd6a2531_df89_4586_b222_ca729dc66093
