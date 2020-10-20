#include "PreCompiled.h"
#include "Strings.h"
#include "Dimensions.h"
#include <regex>

using namespace base;

/**
 * Trims from start (in place).
 */
void Strings::leftTrim(std::string& str)
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
 * Trims from end (in place).
 */
void Strings::rightTrim(std::string& str)
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
void Strings::trim(std::string& str)
{
    leftTrim(str);
    rightTrim(str);
}

/**
 * Trims from start (copying).
 */
std::string Strings::leftTrimCopy(const std::string& str)
{
    std::string copiedStr(str);
    leftTrim(copiedStr);
    return copiedStr;
}

/**
 * Trims from end (copying).
 */
std::string Strings::rightTrimCopy(const std::string& str)
{
    std::string copiedStr(str);
    rightTrim(copiedStr);
    return copiedStr;
}

/**
 * Trims from both ends (copying).
 */
std::string Strings::trimCopy(const std::string& str)
{
    std::string copiedStr(str);
    trim(copiedStr);
    return copiedStr;
}

/**
 * Splits the string with a separator.
 */
void Strings::splitString(
    const std::string& str,
    const std::string& separator,
    std::vector<std::string>& result)
{
    size_t startIndex = 0;
    size_t endIndex = str.size() - 1;
    splitString(str, startIndex, endIndex, separator, result);
}

/**
 * Splits the string with a separator.
 */
void Strings::splitString(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    const std::string& separator,
    std::vector<std::string>& result)
{
    size_t currIndex = startIndex;
    while (currIndex <= endIndex)
    {
        size_t currSeparatorStartIndex = str.find(separator, currIndex);

        if (currSeparatorStartIndex == std::string::npos)
        {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = endIndex;
            size_t tokenLength = Dimensions::indexes(tokenStartIndex, tokenEndIndex);

            std::string token = str.substr(tokenStartIndex, tokenLength);

            result.push_back(token);

            break;
        }

        std::string token;

        if (currSeparatorStartIndex == 0)
        {
            token = "";
        }
        else
        {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = currSeparatorStartIndex - 1;
            size_t tokenLength = Dimensions::indexes(tokenStartIndex, tokenEndIndex);
            token = str.substr(tokenStartIndex, tokenLength);
        }

        result.push_back(token);

        if (currSeparatorStartIndex + separator.size() - 1 == endIndex)
        {
            token = "";
            result.push_back(token);
        }

        currIndex = currSeparatorStartIndex + separator.size();
    }
}

/**
 * Splits a string with a regex separator.
 */
void Strings::splitStringWithRegex(
    const std::string& str,
    const std::string& separatorRegex,
    std::vector<std::string>& result)
{
    size_t startIndex = 0;
    size_t endIndex = str.size() - 1;

    splitStringWithRegex(
        str,
        startIndex,
        endIndex,
        separatorRegex,
        result);
}

/**
 * Splits a string with a regex separator.
 */
void Strings::splitStringWithRegex(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    const std::string& separatorRegex,
    std::vector<std::string>& result) {
    std::regex regexExpression(separatorRegex);

    size_t currIndex = startIndex;

    while (currIndex <= endIndex) {
        std::smatch match;
        bool status = regex_search(
                str.begin() + currIndex,
                str.end(),
                match,
                regexExpression);

        if (!status) {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = endIndex;
            size_t tokenLength = Dimensions::indexes(tokenStartIndex, tokenEndIndex);

            std::string token = str.substr(tokenStartIndex, tokenLength);

            result.push_back(token);

            break;
        }

        size_t currSeparatorStartIndex = currIndex + match.position();
        size_t currSeparatorLength = match.length();

        std::string token;

        if (currSeparatorStartIndex == 0) {
            token = "";
        } else {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = currSeparatorStartIndex - 1;
            size_t tokenLength = Dimensions::indexes(tokenStartIndex, tokenEndIndex);
            token = str.substr(tokenStartIndex, tokenLength);
        }

        result.push_back(token);

        if (currSeparatorStartIndex + currSeparatorLength - 1 == endIndex) {
            token = "";
            result.push_back(token);
        }

        currIndex = currSeparatorStartIndex + currSeparatorLength;
    }
}

/**
 * Wraps a string with a character.
 */
std::string Strings::wrap(const std::string& str, std::string::value_type start, std::string::value_type end)
{
    return start + str + end;
}

/**
 * Wraps a string with a string.
 */
std::string Strings::wrap(const std::string& str, const std::string& start, const std::string& end)
{
    return start + str + end;
}

/**
 * Wraps a string with parentheses.
 */
std::string Strings::wrapWithParentheses(const std::string& str)
{
    return '(' + str + ')';
}

/**
 * Wraps a string with curly brackets.
 */
std::string Strings::wrapWithCurlyBracket(const std::string& str)
{
    return '{' + str + '}';
}

/**
 * Wraps a string with square brackets.
 */
std::string Strings::wrapWithSquareBracket(const std::string& str)
{
    return '[' + str + ']';
}

/**
 * Wraps a string with quotes.
 */
std::string Strings::wrapWithQuotes(const std::string& str)
{
    return '"' + str + '"';
}
