#include "Strings.h"
#include "Indexes.h"
#include <regex>

using namespace base;

/**
 * Trims from start (in place).
 */
void Strings::LeftTrim(std::wstring& str)
{
    str.erase(
        str.begin(),
        std::find_if(str.begin(), str.end(), [](std::string::value_type ch)
        {
            return !std::isspace(ch);
        })
    );
}

/**
 * Trims from End (in place).
 */
void Strings::RightTrim(std::wstring& str)
{
    str.erase(
        std::find_if(str.rbegin(), str.rend(), [](std::string::value_type ch)
        {
            return !std::isspace(ch);
        }).base(),
        str.end()
    );
}

/**
 * Trims from both ends (in place).
 */
void Strings::Trim(std::wstring& str)
{
    LeftTrim(str);
    RightTrim(str);
}

/**
 * Trims from start (copying).
 */
std::wstring Strings::GetLeftTrimed(const std::wstring& str)
{
    std::wstring copiedStr(str);
    LeftTrim(copiedStr);
    return copiedStr;
}

/**
 * Trims from End (copying).
 */
std::wstring Strings::GetRightTrimed(const std::wstring& str)
{
    std::wstring copiedStr(str);
    RightTrim(copiedStr);
    return copiedStr;
}

/**
 * Trims from both ends (copying).
 */
std::wstring Strings::GetTrimed(const std::wstring& str)
{
    std::wstring copiedStr(str);
    Trim(copiedStr);
    return copiedStr;
}

/**
 * Splits the string with a separator.
 */
void Strings::SplitString(
    const std::wstring& str,
    const std::wstring& separator,
    std::vector<std::wstring>& result)
{
    size_t startIndex = 0;
    size_t endIndex = str.size() - 1;
    SplitString(str, startIndex, endIndex, separator, result);
}

/**
 * Splits the string with a separator.
 */
void Strings::SplitString(
    const std::wstring& str,
    size_t startIndex,
    size_t endIndex,
    const std::wstring& separator,
    std::vector<std::wstring>& result)
{
    size_t currIndex = startIndex;
    while (currIndex <= endIndex)
    {
        size_t currSeparatorStartIndex = str.find(separator, currIndex);

        if (currSeparatorStartIndex == std::string::npos)
        {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = endIndex;
            size_t tokenLength = Indexes::Size(tokenStartIndex, tokenEndIndex);

            std::wstring token = str.substr(tokenStartIndex, tokenLength);

            result.push_back(token);

            break;
        }

        std::wstring token;

        if (currSeparatorStartIndex > 0)
        {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = currSeparatorStartIndex - 1;
            size_t tokenLength = Indexes::Size(tokenStartIndex, tokenEndIndex);
            token = str.substr(tokenStartIndex, tokenLength);
        }

        result.push_back(token);

        if (currSeparatorStartIndex + separator.size() - 1 == endIndex)
        {
            token = L"";
            result.push_back(token);
        }

        currIndex = currSeparatorStartIndex + separator.size();
    }
}

/**
 * Splits a string with a regex separator.
 */
void Strings::SplitStringWithRegex(
    const std::wstring& str,
    const std::wstring& separatorRegex,
    std::vector<std::wstring>& result)
{
    size_t startIndex = 0;
    size_t endIndex = str.size() - 1;

    SplitStringWithRegex(
        str,
        startIndex,
        endIndex,
        separatorRegex,
        result);
}

/**
 * Splits a string with a regex separator.
 */
void Strings::SplitStringWithRegex(
    const std::wstring& str,
    size_t startIndex,
    size_t endIndex,
    const std::wstring& separatorRegex,
    std::vector<std::wstring>& result) {
    std::wregex regexExpression(separatorRegex);

    size_t currIndex = startIndex;

    while (currIndex <= endIndex) {
        std::wsmatch match;
        bool status = regex_search(
            str.begin() + currIndex,
            str.end(),
            match,
            regexExpression);

        if (!status) {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = endIndex;
            size_t tokenLength = Indexes::Size(tokenStartIndex, tokenEndIndex);

            std::wstring token = str.substr(tokenStartIndex, tokenLength);

            result.push_back(token);

            break;
        }

        size_t currSeparatorStartIndex = currIndex + match.position();
        size_t currSeparatorLength = match.length();

        std::wstring token;

        if (currSeparatorStartIndex == 0) {
            token = L"";
        } else {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = currSeparatorStartIndex - 1;
            size_t tokenLength = Indexes::Size(tokenStartIndex, tokenEndIndex);
            token = str.substr(tokenStartIndex, tokenLength);
        }

        result.push_back(token);

        if (currSeparatorStartIndex + currSeparatorLength - 1 == endIndex) {
            token = L"";
            result.push_back(token);
        }

        currIndex = currSeparatorStartIndex + currSeparatorLength;
    }
}

/**
 * Wraps a string with a character.
 */
std::wstring Strings::Wrap(const std::wstring& str, std::wstring::value_type start, std::wstring::value_type end)
{
    return start + str + end;
}

/**
 * Wraps a string with a string.
 */
std::wstring Strings::Wrap(const std::wstring& str, const std::wstring& start, const std::wstring& end)
{
    return start + str + end;
}

/**
 * Wraps a string with parentheses.
 */
std::wstring Strings::WrapWithParentheses(const std::wstring& str)
{
    return L'(' + str + L')';
}

/**
 * Wraps a string with curly brackets.
 */
std::wstring Strings::WrapWithCurlyBracket(const std::wstring& str)
{
    return L'{' + str + L'}';
}

/**
 * Wraps a string with square brackets.
 */
std::wstring Strings::WrapWithSquareBracket(const std::wstring& str)
{
    return L'[' + str + L']';
}

/**
 * Wraps a string with quotes.
 */
std::wstring Strings::WrapWithQuotes(const std::wstring& str)
{
    return L'"' + str + L'"';
}
