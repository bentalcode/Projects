#include "PreCompiled.h"
#include "StringSearch.h"
#include "StringEquality.h"
#include "Dimensions.h"

using namespace base;

/**
 * The CaseInsensitiveCompare class implements a case insensitive character comparison.
 */
class CaseInsensitiveCompare : public std::binary_function<char, char, bool>
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
size_t StringSearch::firstIndexOf(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    char character)
{
    if (startIndex > endIndex)
    {
        return std::string::npos;
    }

    std::string stringToSearch(1, character);
    size_t length = Dimensions::indexes(startIndex, endIndex);

    std::string::const_iterator resultIterator = std::find_first_of(
        str.begin(),
        str.begin() + length,
        stringToSearch.begin(),
        stringToSearch.end());

    if (resultIterator == str.end())
    {
        return std::string::npos;
    }

    return resultIterator - str.begin();
}

/**
 * Gets first index of a character ignore case. (Ignore Case)
 * Returns string::npos if the character is not found.
 */
size_t StringSearch::firstIndexOfIgnoreCase(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    char character)
{
    if (startIndex > endIndex)
    {
        return std::string::npos;
    }

    std::string stringToSearch(1, character);
    size_t length = Dimensions::indexes(startIndex, endIndex);

    std::string::const_iterator resultIterator = std::find_first_of(
        str.begin(),
        str.begin() + length,
        stringToSearch.begin(),
        stringToSearch.end(),
        CaseInsensitiveCompare());

    if (resultIterator == str.end())
    {
        return std::string::npos;
    }

    return resultIterator - str.begin();
}

/**
 * Gets last index of a character.
 * Returns string::npos if the character is not found.
 */
size_t StringSearch::lastIndexOf(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    char character)
{
    if (startIndex > endIndex)
    {
        return std::string::npos;
    }

    std::string stringToSearch(1, character);
    size_t length = endIndex - startIndex + 1;

    std::string::const_iterator resultIterator = std::find_end(
        str.begin(),
        str.begin() + length,
        stringToSearch.begin(),
        stringToSearch.end());

    if (resultIterator == str.end())
    {
        return std::string::npos;
    }

    return resultIterator - str.begin();
}

/**
* Gets last index of a character. (Ignore Case)
* Returns string::npos if the character is not found.
*/
size_t StringSearch::lastIndexOfIgnoreCase(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    char character)
{
    if (startIndex > endIndex)
    {
        return std::string::npos;
    }

    std::string stringToSearch(1, character);
    size_t length = endIndex - startIndex + 1;

    std::string::const_iterator resultIterator = std::find_end(
        str.begin(),
        str.begin() + length,
        stringToSearch.begin(),
        stringToSearch.end(),
        CaseInsensitiveCompare());

    if (resultIterator == str.end())
    {
        return std::string::npos;
    }

    return resultIterator - str.begin();
}

/**
 * Checks whether a string starts with a prefix.
 */
bool StringSearch::startsWith(
    const std::string& str,
    const std::string& prefix)
{
    return startsWith(str, 0, prefix);
}

/**
 * Checks whether a string starts with a prefix.
 */
bool StringSearch::startsWith(
    const std::string& str,
    size_t startIndex,
    const std::string& prefix)
{
    if (str.empty() || prefix.empty() || prefix.size() > str.size() - startIndex)
    {
        return std::string::npos;
    }

    size_t prefixStartIndex = str.find(prefix.c_str(), startIndex);
    return prefixStartIndex != std::string::npos && prefixStartIndex == startIndex;
}

/**
 * Checks whether a string ends with a postfix.
 */
bool StringSearch::endsWith(
    const std::string& str,
    const std::string& postfix)
{
    if (str.empty())
    {
        return std::string::npos;
    }

    return endsWith(str, str.size() - 1, postfix);
}

/**
 * Checks whether a string ends with a postfix.
 */
bool StringSearch::endsWith(
    const std::string& str,
    size_t endIndex,
    const std::string& postfix)
{
    if (str.empty() || postfix.empty() || postfix.size() > endIndex + 1)
    {
        return std::string::npos;
    }

    size_t postfixStartIndex = str.rfind(postfix.c_str(), endIndex);
    return postfixStartIndex != std::string::npos && postfixStartIndex == endIndex - postfix.size() + 1;
}

/**
 * Counts the number of instances of a substring.
 */
unsigned int StringSearch::countSubString(
    const std::string& str,
    const std::string& subString)
{
    bool allowOverlapping = true;
    return countSubString(str, subString, allowOverlapping);
}

/**
 * Counts the number of instances of a substring.
 */
unsigned int StringSearch::countSubString(
    const std::string& str,
    const std::string& subString,
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

    return countSubString(
        str,
        startIndex,
        endIndex,
        subString,
        subStringStartIndex,
        subStringEndIndex,
        allowOverlapping);
}

/**
 * Counts the number of instances of a substring.
 */
unsigned int StringSearch::countSubString(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    const std::string& subString,
    size_t subStringStartIndex,
    size_t subStringEndIndex,
    bool allowOverlapping)
{
    assert(startIndex >= 0 && startIndex < str.size());
    assert(endIndex >= startIndex && endIndex < str.size());

    assert(subStringStartIndex >= 0 && subStringStartIndex < subString.size());
    assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.size());

    size_t stringLength = Dimensions::indexes(startIndex, endIndex);
    size_t subStringLength = Dimensions::indexes(subStringStartIndex, subStringEndIndex);

    if (subStringLength == 0 || subStringLength > stringLength) {
        return 0;
    }

    unsigned int counter = 0;

    size_t currIndex = startIndex;
    size_t effectiveEndIndex = endIndex - subStringLength + 1;

    while (currIndex <= effectiveEndIndex) {
        if (StringEquality::equals(str, currIndex, subString, subStringStartIndex, subStringLength)) {
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
 * Counts the number of instances of a substring from end.
 * Avoid overlapping.
 */
unsigned int StringSearch::countSubStringFromEnd(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    const std::string& subString,
    size_t subStringStartIndex,
    size_t subStringEndIndex,
    bool allowOverlapping)
{
    assert(startIndex >= 0 && startIndex < str.size());
    assert(endIndex >= startIndex && endIndex < str.size());

    assert(subStringStartIndex >= 0 && subStringStartIndex < subString.size());
    assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.size());

    size_t stringLength = Dimensions::indexes(startIndex, endIndex);
    size_t subStringLength = Dimensions::indexes(subStringStartIndex, subStringEndIndex);

    if (subStringLength == 0 || subStringLength > stringLength) {
        return 0;
    }

    unsigned int counter = 0;

    size_t currIndex = endIndex - subStringLength + 1;

    while (currIndex >= startIndex) {
        if (StringEquality::equals(str, currIndex, subString, subStringStartIndex, subStringLength)) {
            ++counter;

            currIndex = (allowOverlapping) ? currIndex - 1 : currIndex - subStringLength;
        }
        else {
            --currIndex;
        }
    }

    return counter;
}
