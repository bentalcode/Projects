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
 * Splits the string with a character separator.
 */
void Strings::splitString(
    const std::string& str,
    char separator,
    std::vector<std::string>& result)
{
    size_t startIndex = 0;
    size_t endIndex = str.size() - 1;
    splitString(str, startIndex, endIndex, separator, result);
}

/**
 * Splits the string with a character separator.
 */
void Strings::splitString(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    char separator,
    std::vector<std::string>& result)
{
    size_t currIndex = startIndex;
    while (currIndex <= endIndex)
    {
        size_t tokenStartIndex = 0;
        bool status = Strings::findTokenStartIndex(
            str,
            currIndex,
            endIndex,
            separator,
            tokenStartIndex);

        if (!status)
        {
            return;
        }

        size_t tokenEndIndex = 0;
        status = Strings::findTokenEndIndex(
            str,
            tokenStartIndex,
            endIndex,
            separator,
            tokenEndIndex);

        if (!status)
        {
            return;
        }

        assert(tokenEndIndex >= tokenStartIndex);
        size_t tokenLength = tokenEndIndex - tokenStartIndex + 1;
        std::string token = str.substr(tokenStartIndex, tokenLength);

        result.push_back(token);

        currIndex = tokenEndIndex + 2;
    }
}

/**
 * Splits a string with a regex separator.
 */
void Strings::splitString(
    const std::string& str,
    const std::string& separatorRegex,
    std::vector<std::string>& result)
{
    size_t startIndex = 0;
    size_t endIndex = str.size() - 1;

    splitString(
        str,
        startIndex,
        endIndex,
        separatorRegex,
        result);
}

/**
 * Splits a string with a regex separator.
 */
void Strings::splitString(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    const std::string& separatorRegex,
    std::vector<std::string>& result)
{
    std::regex regexExpression(separatorRegex);

    size_t currIndex = startIndex;

    while (currIndex <= endIndex)
    {
        std::smatch match;
        bool status = regex_search(
                str.begin() + currIndex,
                str.end(),
                match,
                regexExpression);

        if (!status)
        {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = endIndex;
            size_t tokenLength = Dimensions::length(tokenStartIndex, tokenEndIndex);

            std::string token = str.substr(tokenStartIndex, tokenLength);

            result.push_back(token);

            break;
        }

        size_t currSeparatorStartIndex = currIndex + match.position();
        size_t currSeparatorLength = match.length();

        std::string token;

        if (currSeparatorStartIndex == 0)
        {
            token = "";
        }
        else
        {
            size_t tokenStartIndex = currIndex;
            size_t tokenEndIndex = currSeparatorStartIndex - 1;
            size_t tokenLength = Dimensions::length(tokenStartIndex, tokenEndIndex);
            token = str.substr(tokenStartIndex, tokenLength);
        }

        result.push_back(token);

        if (currSeparatorStartIndex == endIndex)
        {
            token = "";
            result.push_back(token);
        }

        currIndex = currSeparatorStartIndex + currSeparatorLength;
    }
}

/**
 * Finds the start index of a token.
 */
bool Strings::findTokenStartIndex(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    char separator,
    size_t& result)
{
    size_t currIndex = startIndex;

    while (currIndex <= endIndex)
    {
        if (str[currIndex] != separator)
        {
            result = currIndex;
            return true;
        }

        ++currIndex;
    }

    return false;
}

/**
 * Finds the end index of a token.
 */
bool Strings::findTokenEndIndex(
    const std::string& str,
    size_t startIndex,
    size_t endIndex,
    char separator,
    size_t& result)
{
    if (str[startIndex] == separator)
    {
        return false;
    }

    size_t currIndex = startIndex + 1;

    while (currIndex <= endIndex)
    {
        if (str[currIndex] == separator)
        {
            result = currIndex - 1;
            return true;
        }

        ++currIndex;
    }

    result = endIndex;
    return true;
}
