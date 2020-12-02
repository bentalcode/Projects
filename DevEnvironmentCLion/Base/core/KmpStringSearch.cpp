#include "PreCompiled.h"

#include "KmpStringSearch.h"
#include "Indexes.h"

using namespace base;

/**
 * Finds an index of a substring in a string with KMP Algorithm.
 * Returns true if the subString is found.
 */
bool KmpStringSearch::findSubString(
    const std::string& str,
    const std::string& subString,
    size_t& resultIndex)
{
    if (str.empty() || subString.empty())
    {
        resultIndex = 0;
        return false;
    }

    return findSubString(
        str, 0, str.length() - 1,
        subString, 0, subString.length() - 1,
        resultIndex);
}

/**
 * Finds an index of a substring in a string with KMP Algorithm.
 * Returns true if the subString is found.
 */
bool KmpStringSearch::findSubString(
    const std::string& str, size_t strStartIndex, size_t strEndIndex,
    const std::string& subString, size_t subStringStartIndex, size_t subStringEndIndex,
    size_t& resultIndex)
{
    assert(strStartIndex >= 0 && strStartIndex < str.size());
    assert(strEndIndex >= strStartIndex && strEndIndex < str.size());
    assert(subStringStartIndex >= 0 && subStringStartIndex < subString.size());
    assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.size());

    resultIndex = 0;

    size_t strLength = Indexes::size(strStartIndex, strEndIndex);
    size_t subStringLength = Indexes::size(subStringStartIndex, subStringEndIndex);

    if (subStringLength > strLength) {
        return false;
    }

    //
    // Create the longest prefix suffix...
    //
    std::vector<unsigned int> lps;
    createLongestPrefixSuffix(
        subString,
        subStringStartIndex,
        subStringEndIndex,
        lps);

    size_t strIndex = strStartIndex;
    size_t subStringIndex = subStringStartIndex;

    while (strIndex <= strEndIndex && subStringIndex <= subStringEndIndex) {
        std::string::value_type strCharacter = str[strIndex];
        std::string::value_type subStringCharacter = subString[subStringIndex];

        if (strCharacter == subStringCharacter) {
            if (subStringIndex == subStringEndIndex) {
                resultIndex = strIndex - subStringLength + 1;
                return true;
            }

            ++strIndex;
            ++subStringIndex;
        }
        else {
            if (subStringIndex == subStringStartIndex) {
                ++strIndex;
            }
            else {
                size_t lpsIndex = subStringIndex - subStringStartIndex;
                subStringIndex = subStringStartIndex + lps[lpsIndex - 1];
            }
        }
    }

    return false;
}

/**
 * Finds an index of a substring in a string with KMP Algorithm.
 * Returns an empty array if the subString is not found.
 */
void KmpStringSearch::findAllSubString(
    const std::string& str,
    const std::string& subString,
    std::vector<size_t>& resultIndexes)
{
    if (str.empty() || subString.empty())
    {
        return;
    }

    findAllSubString(
        str, 0, str.size() - 1,
        subString, 0, subString.size() - 1,
        resultIndexes);
}

/**
 * Finds an index of a substring in a string with KMP Algorithm.
 * Returns an empty array if the subString is not found.
 */
void KmpStringSearch::findAllSubString(
    const std::string& str, size_t strStartIndex, size_t strEndIndex,
    const std::string& subString, size_t subStringStartIndex, size_t subStringEndIndex,
    std::vector<size_t>& resultIndexes)
{
    assert(strStartIndex >= 0 && strStartIndex < str.size());
    assert(strEndIndex >= strStartIndex && strEndIndex < str.size());
    assert(subStringStartIndex >= 0 && subStringStartIndex < subString.size());
    assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.size());
    assert(resultIndexes.empty());

    size_t strLength = Indexes::size(strStartIndex, strEndIndex);
    size_t subStringLength = Indexes::size(subStringStartIndex, subStringEndIndex);

    if (subStringLength > strLength) {
        return;
    }

    //
    // Create the longest prefix suffix...
    //
    std::vector<unsigned int> lps;
    createLongestPrefixSuffix(
        subString,
        subStringStartIndex,
        subStringEndIndex,
        lps);

    size_t strIndex = strStartIndex;
    size_t subStringIndex = subStringStartIndex;

    while (strIndex <= strEndIndex && subStringIndex <= subStringEndIndex) {
        std::string::value_type strCharacter = str[strIndex];
        std::string::value_type subStringCharacter = subString[subStringIndex];

        if (strCharacter == subStringCharacter)
        {
            if (subStringIndex == subStringEndIndex)
            {
                size_t resultIndex = strIndex - subStringLength + 1;
                resultIndexes.push_back(resultIndex);

                size_t lpsIndex = subStringIndex - subStringStartIndex;
                subStringIndex = subStringStartIndex + lps[lpsIndex];
            }
            else
            {
                ++subStringIndex;
            }

            ++strIndex;
        }
        else
        {
            if (subStringIndex == subStringStartIndex)
            {
                ++strIndex;
            }
            else
            {
                size_t lpsIndex = subStringIndex - subStringStartIndex;
                subStringIndex = subStringStartIndex + lps[lpsIndex - 1];
            }
        }
    }
}

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
void KmpStringSearch::createLongestPrefixSuffix(
    const std::string& str,
    size_t startIndex, size_t endIndex,
    std::vector<unsigned int>& lps)
 {
    assert(startIndex >= 0 && startIndex < str.size());
    assert(endIndex >= startIndex && endIndex < str.size());
    assert(lps.empty());

    size_t strLength = Indexes::size(startIndex, endIndex);

    lps.resize(strLength);
    lps[0] = 0;

    size_t index = 1;
    unsigned int length = 0;

    while (index < strLength)
    {
        char currCharacter = str[startIndex + index];
        char patternCharacter = str[startIndex + length];

        if (currCharacter == patternCharacter)
        {
            ++length;
            lps[index] = length;
            ++index;
        }
        else {
            if (length == 0)
            {
                lps[index] = 0;
                ++index;
            }
            else
            {
                length = lps[length - 1];
            }
        }
    }
}
