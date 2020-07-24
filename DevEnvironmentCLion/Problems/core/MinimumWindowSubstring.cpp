#include "PreCompiled.h"

#include "MinimumWindowSubstring.h"
#include "Dimensions.h"

using namespace problems;

/**
 * The MinimumWindowSubstring constructor.
 */
MinimumWindowSubstring::MinimumWindowSubstring(const std::string& s, const std::string& t) :
    m_src(s),
    m_characters(MinimumWindowSubstring::createCharacterSet(t))
{
}

/**
 * Given a string S and a string T, find the minimum window in S,
 * which will contain all the characters in T in complexity O(n).
 */
bool MinimumWindowSubstring::findMinimumWindow(std::string& result)
{
    if (m_characters.empty() || m_src.size() < m_characters.size()) {
        return false;
    }

    const std::string::value_type* srcStr = m_src.c_str();

    std::map<std::string::value_type, std::size_t> characterCounter;

    std::size_t endIndex;
    bool status = coverSourceString(
        srcStr,
        0,
        m_src.size() - 1,
        endIndex,
        characterCounter);

    if (!status)
    {
        return false;
    }

    std::size_t startIndex = shrinkSubString(
        srcStr,
        0,
        endIndex,
        characterCounter);

    std::size_t minStartIndex = startIndex;
    std::size_t minEndIndex = endIndex;

    std::size_t currIndex = endIndex + 1;

    while (currIndex < m_src.size())
    {
        std::string::value_type currValue = srcStr[currIndex];
        std::size_t endIndex = currIndex;

        if (m_characters.find(currValue) != m_characters.end())
        {
            MinimumWindowSubstring::updateCharacterCounter(
                characterCounter,
                currValue,
                1);

            startIndex = shrinkSubString(
                srcStr,
                startIndex,
                endIndex,
                characterCounter);

            std::size_t currLength = base::Dimensions::length(startIndex, endIndex);
            std::size_t minLength = base::Dimensions::length(minStartIndex, minEndIndex);

            if (currLength < minLength)
            {
                minStartIndex = startIndex;
                minEndIndex = endIndex;
            }
        }

        ++currIndex;
    }

    std::size_t minLength = base::Dimensions::length(minStartIndex, minEndIndex);
    result = m_src.substr(minStartIndex, minLength);

    return true;
}

/**
 * Covers the source string.
 * Returns -1 if the string is not able to be covered.
 */
bool MinimumWindowSubstring::coverSourceString(
    const std::string::value_type* str,
    std::size_t startIndex,
    std::size_t endIndex,
    std::size_t& coveredStringEndIndex,
    CharacterCounterMap& characterCounter)
{
    std::size_t currIndex = startIndex;

    while (currIndex <= endIndex)
    {
        std::string::value_type currValue = str[currIndex];

        if (m_characters.find(currValue) != m_characters.end())
        {
            MinimumWindowSubstring::updateCharacterCounter(characterCounter, currValue, 1);

            if (characterCounter.size() == m_characters.size())
            {
                coveredStringEndIndex = currIndex;
                return true;
            }
        }

        ++currIndex;
    }

    return false;
}

/**
 * Shrinks a sub string.
 */
 std::size_t MinimumWindowSubstring::shrinkSubString(
     const std::string::value_type* str,
     std::size_t startIndex,
     std::size_t endIndex,
     CharacterCounterMap& characterCounter)
 {
     std::size_t currIndex = startIndex;

     while (currIndex <= endIndex)
     {
         std::string::value_type currValue = str[currIndex];

         if (m_characters.find(currValue) != m_characters.end())
         {
             if (characterCounter[currValue] == 1)
             {
                 return currIndex;
             }
             else
             {
                MinimumWindowSubstring::updateCharacterCounter(characterCounter, currValue, -1);
             }
         }

         ++currIndex;
     }

     return currIndex;
 }

/**
 * Updates the character counter.
 */
void MinimumWindowSubstring::updateCharacterCounter(
    CharacterCounterMap& characterCounter,
    std::string::value_type character,
    int delta)
{
    std::size_t currCount = 0;
    CharacterCounterMap::const_iterator i = characterCounter.find(character);

    if (i != characterCounter.end()) {
        currCount = i->second;
    }

    currCount += delta;

    characterCounter[character] = currCount;
}

/**
 * Creates a character set.
 */
std::set<std::string::value_type> MinimumWindowSubstring::createCharacterSet(const std::string& str) {
    std::set<std::string::value_type> characterSet;

    for (std::string::value_type character : str) {
        characterSet.insert(character);
    }

    return characterSet;
}
