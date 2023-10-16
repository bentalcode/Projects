#ifndef KMP_STRING_SEARCH_H_6c47cac1_59c3_4c54_a33c_2ffae8f57e02
#define KMP_STRING_SEARCH_H_6c47cac1_59c3_4c54_a33c_2ffae8f57e02

#include <string>
#include <vector>

namespace base
{
    /**
     * The KmpStringSearch class implements string search by using an algorithm
     * for KMP (Knuth Morris Pratt) Pattern Searching.
     */
    class KmpStringSearch final
    {
    public:
        /**
         * Finds an index of a substring in a string with KMP Algorithm.
         * Returns true if the subString is found.
         */
        static bool FindSubString(
            const std::wstring& str,
            const std::wstring& subString,
            size_t& resultIndex);

        /**
         * Finds an index of a substring in a string with KMP Algorithm.
         * Returns true if the subString is found.
         */
        static bool FindSubString(
            const std::wstring& str, size_t strStartIndex, size_t strEndIndex,
            const std::wstring& subString, size_t subStringStartIndex, size_t subStringEndIndex,
            size_t& resultIndex);

        /**
         * Finds an index of a substring in a string with KMP Algorithm.
         * Returns an Empty array if the subString is not found.
         */
        static void FindAllSubString(
            const std::wstring& str,
            const std::wstring& subString,
            std::vector<size_t>& resultIndexes);

        /**
         * Finds an index of a substring in a string with KMP Algorithm.
         * Returns an Empty array if the subString is not found.
         */
        static void FindAllSubString(
            const std::wstring& str, size_t strStartIndex, size_t strEndIndex,
            const std::wstring& subString, size_t subStringStartIndex, size_t subStringEndIndex,
            std::vector<size_t>& resultIndexes);

    private:
        /**
         * Creates the longest prefix suffix (lps) of a string.
         *
         * For instance,
         * String str = "AAACAAAAAC";
         * Prefixes = {{}, {A}, {AA}, {AAA}, {AAAC}, {AAACA}, {AAACAA}, {AAACAAA}, {AAACAAAA}, {AAACAAAAA}, {AAACAAAAAC}};
         * Postfixes = {{}, {C}, {AC}, {AAC}, {AAAC}, {AAAAC}, {AAAAAC}, {CAAAAAC}, {ACAAAAAC}, {AACAAAAAC}, {AAACAAAAAC}};
         *
         * In this case, Prefix{AAAC} == Postfix{AAAC}, Therefore, lps[9] = 4;
         *
         * lps = {0, 1, 2, 0, 1, 2, 3, 3, 3, 4}
         */
        static void CreateLongestPrefixSuffix(
            const std::wstring& str,
            size_t startIndex, size_t endIndex,
            std::vector<unsigned int>& lps);

        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        KmpStringSearch() = delete;
        ~KmpStringSearch() = delete;
    };
}

#endif // KMP_STRING_SEARCH_H_6c47cac1_59c3_4c54_a33c_2ffae8f57e02
