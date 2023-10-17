#include "StringSearch.h"
#include "StringEquality.h"
#include "Indexes.h"
#include <algorithm>
#include <assert.h>

using namespace base;

/**
 * The CaseInsensitiveCompare class implements a case insensitive character comparison.
 */
class CaseInsensitiveCompare final
{
public:
    bool operator()(char left, char right) const
    {
        return std::tolower(left) == std::tolower(right);
    }
};

/**
 * Gets first index of a character.
 * Returns string::npos if the character is not found.
 */
size_t StringSearch::FirstIndexOf(
    const std::wstring& str,
    size_t startIndex,
    size_t endIndex,
    char character)
{
    if (startIndex > endIndex)
    {
        return std::wstring::npos;
    }

    std::wstring stringToSearch(1, character);
    size_t length = Indexes::Size(startIndex, endIndex);

    std::wstring::const_iterator resultIterator = std::find_first_of(
        str.begin(),
        str.begin() + length,
        stringToSearch.begin(),
        stringToSearch.end());

    if (resultIterator == str.end())
    {
        return std::wstring::npos;
    }

    return resultIterator - str.begin();
}

/**
 * Gets first index of a character ignore case. (Ignore Case)
 * Returns string::npos if the character is not found.
 */
size_t StringSearch::FirstIndexOfIgnoreCase(
    const std::wstring& str,
    size_t startIndex,
    size_t endIndex,
    char character)
{
    if (startIndex > endIndex)
    {
        return std::wstring::npos;
    }

    std::wstring stringToSearch(1, character);
    size_t length = Indexes::Size(startIndex, endIndex);

    std::wstring::const_iterator resultIterator = std::find_first_of(
        str.begin(),
        str.begin() + length,
        stringToSearch.begin(),
        stringToSearch.end(),
        CaseInsensitiveCompare());

    if (resultIterator == str.end())
    {
        return std::wstring::npos;
    }

    return resultIterator - str.begin();
}

/**
 * Gets last index of a character.
 * Returns string::npos if the character is not found.
 */
size_t StringSearch::LastIndexOf(
    const std::wstring& str,
    size_t startIndex,
    size_t endIndex,
    char character)
{
    if (startIndex > endIndex)
    {
        return std::wstring::npos;
    }

    std::wstring stringToSearch(1, character);
    size_t length = endIndex - startIndex + 1;

    std::wstring::const_iterator resultIterator = std::find_end(
        str.begin(),
        str.begin() + length,
        stringToSearch.begin(),
        stringToSearch.end());

    if (resultIterator == str.end())
    {
        return std::wstring::npos;
    }

    return resultIterator - str.begin();
}

/**
* Gets last index of a character. (Ignore Case)
* Returns string::npos if the character is not found.
*/
size_t StringSearch::LastIndexOfIgnoreCase(
    const std::wstring& str,
    size_t startIndex,
    size_t endIndex,
    char character)
{
    if (startIndex > endIndex)
    {
        return std::wstring::npos;
    }

    std::wstring stringToSearch(1, character);
    size_t length = endIndex - startIndex + 1;

    std::wstring::const_iterator resultIterator = std::find_end(
        str.begin(),
        str.begin() + length,
        stringToSearch.begin(),
        stringToSearch.end(),
        CaseInsensitiveCompare());

    if (resultIterator == str.end())
    {
        return std::wstring::npos;
    }

    return resultIterator - str.begin();
}

/**
 * Checks whether a string starts with a prefix.
 */
bool StringSearch::StartsWith(
    const std::wstring& str,
    const std::wstring& prefix)
{
    return StartsWith(str, 0, prefix);
}

/**
 * Checks whether a string starts with a prefix.
 */
bool StringSearch::StartsWith(
    const std::wstring& str,
    size_t startIndex,
    const std::wstring& prefix)
{
    if (str.empty() || prefix.empty() || prefix.size() > str.size() - startIndex)
    {
        return std::wstring::npos;
    }

    size_t prefixStartIndex = str.find(prefix.c_str(), startIndex);
    return prefixStartIndex != std::wstring::npos && prefixStartIndex == startIndex;
}

/**
 * Checks whether a string ends with a postfix.
 */
bool StringSearch::EndsWith(
    const std::wstring& str,
    const std::wstring& postfix)
{
    if (str.empty())
    {
        return std::wstring::npos;
    }

    return EndsWith(str, str.size() - 1, postfix);
}

/**
 * Checks whether a string ends with a postfix.
 */
bool StringSearch::EndsWith(
    const std::wstring& str,
    size_t endIndex,
    const std::wstring& postfix)
{
    if (str.empty() || postfix.empty() || postfix.size() > endIndex + 1)
    {
        return std::wstring::npos;
    }

    size_t postfixStartIndex = str.rfind(postfix.c_str(), endIndex);
    return postfixStartIndex != std::wstring::npos && postfixStartIndex == endIndex - postfix.size() + 1;
}

/**
 * Counts the number Of instances of a substring.
 */
unsigned int StringSearch::CountSubString(
    const std::wstring& str,
    const std::wstring& subString)
{
    bool allowOverlapping = true;
    return CountSubString(str, subString, allowOverlapping);
}

/**
 * Counts the number of instances of a substring.
 */
unsigned int StringSearch::CountSubString(
    const std::wstring& str,
    const std::wstring& subString,
    bool allowOverlapping)
{
    if (str.empty() || subString.empty())
    {
        return 0;
    }

    size_t startIndex = 0;
    size_t endIndex = str.length() - 1;
    size_t subStringStartIndex = 0;
    size_t subStringEndIndex = subString.length() - 1;

    return CountSubString(
            str,
            startIndex,
            endIndex,
            subString,
            subStringStartIndex,
            subStringEndIndex,
            allowOverlapping);
}

/**
 * Counts the number Of instances of a substring.
 */
unsigned int StringSearch::CountSubString(
    const std::wstring& str,
    size_t startIndex,
    size_t endIndex,
    const std::wstring& subString,
    size_t subStringStartIndex,
    size_t subStringEndIndex,
    bool allowOverlapping)
{
    assert(startIndex >= 0 && startIndex < str.size());
    assert(endIndex >= startIndex && endIndex < str.size());

    assert(subStringStartIndex >= 0 && subStringStartIndex < subString.size());
    assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.size());

    size_t stringLength = Indexes::Size(startIndex, endIndex);
    size_t subStringLength = Indexes::Size(subStringStartIndex, subStringEndIndex);

    if (subStringLength == 0 || subStringLength > stringLength) {
        return 0;
    }

    unsigned int counter = 0;

    size_t currIndex = startIndex;
    size_t effectiveEndIndex = endIndex - subStringLength + 1;

    while (currIndex <= effectiveEndIndex) {
        if (StringEquality::AreEqual(str, currIndex, subString, subStringStartIndex, subStringLength)) {
            ++counter;

            currIndex = (allowOverlapping) ? currIndex + 1 : currIndex + subStringLength;
        }
        else {
            ++currIndex;
        }
    }

    return counter;
}

/**
 * Counts the number Of instances of a substring from end.
 * Avoid overlapping.
 */
unsigned int StringSearch::CountSubStringFromEnd(
    const std::wstring& str,
    size_t startIndex,
    size_t endIndex,
    const std::wstring& subString,
    size_t subStringStartIndex,
    size_t subStringEndIndex,
    bool allowOverlapping)
{
    assert(startIndex >= 0 && startIndex < str.size());
    assert(endIndex >= startIndex && endIndex < str.size());

    assert(subStringStartIndex >= 0 && subStringStartIndex < subString.size());
    assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.size());

    size_t stringLength = Indexes::Size(startIndex, endIndex);
    size_t subStringLength = Indexes::Size(subStringStartIndex, subStringEndIndex);

    if (subStringLength == 0 || subStringLength > stringLength) {
        return 0;
    }

    unsigned int counter = 0;

    size_t currIndex = endIndex - subStringLength + 1;

    while (currIndex >= startIndex) {
        if (StringEquality::AreEqual(str, currIndex, subString, subStringStartIndex, subStringLength)) {
            ++counter;

            currIndex = (allowOverlapping) ? currIndex - 1 : currIndex - subStringLength;
        }
        else {
            --currIndex;
        }
    }

    return counter;
}
