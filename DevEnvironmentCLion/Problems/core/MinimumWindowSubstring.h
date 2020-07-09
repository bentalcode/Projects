#ifndef MINIMUM_WINDOW_SUBSTRING_H_dd8f8fb7_c531_4223_902a_6cf63b98cdcf
#define MINIMUM_WINDOW_SUBSTRING_H_dd8f8fb7_c531_4223_902a_6cf63b98cdcf

#include "IMinimumWindowSubstring.h"

namespace problems
{
    /**
     * The MinimumWindowSubstring class implements a minimum window substring.
     */
    class MinimumWindowSubstring final : public IMinimumWindowSubstring
    {
    public:
        /**
         * The constructor.
         */
        MinimumWindowSubstring(const std::string& s, const std::string& t);

        /**
         * The destructor.
         */
        virtual ~MinimumWindowSubstring() = default;

        /**
         * The copy/move constructors.
         */
        MinimumWindowSubstring(const MinimumWindowSubstring&) = delete;
        MinimumWindowSubstring(MinimumWindowSubstring&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MinimumWindowSubstring& operator=(const MinimumWindowSubstring&) = delete;
        MinimumWindowSubstring& operator=(MinimumWindowSubstring&&) = delete;

        /**
         * Given a string S and a string T, find the minimum window in S,
         * which will contain all the characters in T in complexity O(n).
         */
        virtual bool findMinimumWindow(std::string& result) override;

    private:
        typedef std::map<std::string::value_type, std::size_t> CharacterCounterMap;

        /**
         * Covers the source string.
         * Returns -1 if the string is not able to be covered.
         */
        bool coverSourceString(
            const std::string::value_type* str,
            std::size_t startIndex,
            std::size_t endIndex,
            std::size_t& coveredStringEndIndex,
            CharacterCounterMap& characterCounter);

        /**
         * Shrinks the sub string.
         */
        std::size_t shrinkSubString(
            const std::string::value_type* str,
            std::size_t startIndex,
            std::size_t endIndex,
            CharacterCounterMap& characterCounter);

        /**
         * Updates the character counter.
         */
        static void updateCharacterCounter(
            CharacterCounterMap& characterCounter,
            std::string::value_type characterType,
            int delta);

        /**
         * Creates a character set.
         */
        static std::set<std::string::value_type> createCharacterSet(const std::string& str);

        std::string m_src;
        std::set<std::string::value_type> m_characters;
    };
}

#endif // MINIMUM_WINDOW_SUBSTRING_H_dd8f8fb7_c531_4223_902a_6cf63b98cdcf
