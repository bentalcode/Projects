#include "StringUtils.h"
#include "ErrorCodes.h"
#include "Indexes.h"
#include <functional>
#include <algorithm>
#include <stack>
#include "NotImplementedException.h"
#include <assert.h>

#if WINDOWS
    #include <stringapiset.h>
#else
    #include <stdlib.h>
#endif

#include <vector>

using namespace base;

/**
 * Copies a null terminated string.
 */
void StringUtils::CopyString(
    const char* src, 
    size_t numOfCharactersToCopy, 
    char* dest, 
    size_t maxDestSize)
{
    CopyString<char>(
        src, 
        numOfCharactersToCopy, 
        dest, 
        maxDestSize);
}

/**
 * Copies a null terminated string.
 */
void StringUtils::CopyString(
    const wchar_t* src, 
    size_t numOfCharactersToCopy, 
    wchar_t* dest, size_t maxDestSize)
{
    CopyString<wchar_t>(
        src, 
        numOfCharactersToCopy, 
        dest, 
        maxDestSize);
}

/**
 * Gets a length a null terminated string.
 */
size_t StringUtils::GetStringLength(
    const char* str, 
    size_t maxLength)
{
    return GetStringLength<char>(
        str, 
        maxLength);
}

/**
 * Gets a length a null terminated string.
 */
size_t StringUtils::GetStringLength(
    const wchar_t* str, 
    size_t maxLength)
{
    return GetStringLength<wchar_t>(
        str, 
        maxLength);
}

/**
 * Converts a string to a wide string.
 */
std::wstring StringUtils::StringToWideString(const std::string& str)
{
    if (str.empty()) {
        return L"";
    }

#if WINDOWS
    std::vector<std::wstring::value_type> buffer(str.size());

    UINT CodePage = CP_ACP;
    DWORD flags = 0;
    int strLengthInBytes = static_cast<int>(str.size() * sizeof(std::string::value_type));
    int bufferLengthInCharacters = static_cast<int>(buffer.size() * sizeof(std::wstring::value_type));

    int numberOfCharactersWritten = MultiByteToWideChar(
        CodePage, 
        flags, 
        str.c_str(), 
        strLengthInBytes, 
        &buffer[0], 
        bufferLengthInCharacters);

    if (numberOfCharactersWritten <= 0) {
        long errorCode = ErrorCodes::GetLastErrorCode();

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The StringUtils has failed converting a string to a wide string" 
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    buffer.resize(numberOfCharactersWritten);

    return std::wstring(buffer.begin(), buffer.end());

#elif LINUX

    std::vector<std::wstring::value_type> buffer(str.size());
    size_t bufferLength = buffer.size();

    size_t numberOfCharactersWritten = mbstowcs(
        &buffer[0], 
        str.c_str(), 
        bufferLength);

    if (numberOfCharactersWritten == 0) {
        long errorCode = ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The StringUtils has failed converting a string to a wide string" 
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw utilities_exception(errorCode, errorMessage);
    }

    buffer.resize(numberOfCharactersWritten);

    return std::wstring(buffer.begin(), buffer.end());
#else
    throw NotImplementedException(L"StringUtils::StringToWideString()");
#endif
}

/**
 * Converts a wide string to a string.
 */
std::string StringUtils::WideStringToString(const std::wstring& str)
{
    if (str.empty()) {
        return "";
    }

#if WINDOWS
    std::vector<std::string::value_type> buffer(str.size());

    UINT CodePage = CP_ACP;
    DWORD flags = 0;
    int strLengthInCharacters = static_cast<int>(str.size());
    int bufferLengthInBytes = static_cast<int>(buffer.size() * sizeof(std::string::value_type));
    LPCCH defaultCharacter = nullptr;
    LPBOOL usedDefaultChar = nullptr;

    int numberOfBytesWritten = WideCharToMultiByte(
        CodePage, 
        flags, 
        str.c_str(), 
        strLengthInCharacters, 
        &buffer[0],
        bufferLengthInBytes, 
        defaultCharacter, 
        usedDefaultChar);

    if (numberOfBytesWritten <= 0) {
        long errorCode = ErrorCodes::GetLastErrorCode();

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The StringUtils has failed converting a wide string to a string" 
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    size_t numberOfCharactersWritten = numberOfBytesWritten / sizeof(std::string::value_type);
    buffer.resize(numberOfCharactersWritten);

    return std::string(buffer.begin(), buffer.end());

#elif LINUX

    std::vector<std::string::value_type> buffer(str.size());
    size_t bufferLengthInBytes = buffer.size() * sizeof(std::string::value_type);

    size_t numberOfBytesWritten = wcstombs(
        &buffer[0], 
        str.c_str(), 
        bufferLengthInBytes);

    if (numberOfBytesWritten == 0) {
        long errorCode = ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The StringUtils has failed converting a wide string to a string" 
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw utilities_exception(errorCode, errorMessage);
    }

    size_t numberOfCharactersWritten = numberOfBytesWritten / sizeof(std::string::value_type);
    buffer.resize(numberOfCharactersWritten);

    return std::string(buffer.begin(), buffer.end());
#else
    throw NotImplementedException(L"StringUtils::WideStringToString()");
#endif
}

/**
 * Replaces all instances of a sub string in a string.
 */
void StringUtils::ReplaceAll(std::wstring& str, const std::wstring& from, const std::wstring& to)
{
    if (from.empty() || str.size() < from.size()) {
        return;
    }

    size_t startPosition = 0;

    while (true) {
        startPosition = str.find(from, startPosition);

        if (startPosition == std::string::npos) {
            break;
        }

        str.replace(startPosition, from.length(), to);
        startPosition += to.length();
    }
}

/**
 * Trims a string.
 */
void StringUtils::Trim(std::wstring& str)
{
    TrimFromLeft(str);
    TrimFromRight(str);
}

/**
 * Trims a string from left.
 */
void StringUtils::TrimFromLeft(std::wstring& str)
{
    std::wstring::iterator startCharacterIterator = std::find_if(
        str.begin(), 
        str.end(), 
        [](std::wstring::value_type character) { return std::isspace(character) == 0; });

    str.erase(str.begin(), startCharacterIterator);
}

/**
 * Trims a string from right.
 */
void StringUtils::TrimFromRight(std::wstring& str)
{
    std::wstring::reverse_iterator endCharacterIterator = std::find_if(
        str.rbegin(), 
        str.rend(), 
        [](std::wstring::value_type character) { return std::isspace(character) == 0; });

    str.erase(endCharacterIterator.base(), str.end());
}

/**
 * Lowercases the string.
 */
void StringUtils::ToLowercase(std::wstring& str) 
{
    std::transform(
        str.begin(), 
        str.end(), 
        str.begin(),
        [](std::wstring::value_type character) { return std::tolower(character); });
}

/**
 * Uppercases the string.
 */
void StringUtils::ToUppercase(std::wstring& str) 
{
    std::transform(
        str.begin(), 
        str.end(), 
        str.begin(),
        [](std::wstring::value_type character) { return std::toupper(character); });
}

/**
 * Checks whether a string starts with a given prefix.
 */
bool StringUtils::StartWith(
    const std::wstring& str, 
    const std::wstring& prefix,
    size_t offset) {

    size_t strLength = str.size();

    if (offset >= strLength) {
        return false;
    }

    size_t prefixLength = prefix.size();

    if (prefixLength > strLength - offset) {
        return false;
    } 

    size_t leftIndex = offset;
    size_t rightIndex = 0;

    while (leftIndex < strLength && rightIndex < prefixLength) {
        std::wstring::value_type leftCharacter = str.at(leftIndex);
        std::wstring::value_type rightCharacter = prefix.at(rightIndex);

        if (leftCharacter != rightCharacter) {
            break;    
        }

        ++leftIndex;
        ++rightIndex;
    }

    return leftIndex == offset + prefixLength && rightIndex == prefixLength;
}

/**
 * Checks whether a string has valid parantheses.
 */
bool StringUtils::HasValidParentheses(
    const std::wstring& str,
    std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>> parentheses)
{
    if (str.size() <= 1) {
        return true;
    }

    std::stack<std::wstring::value_type> stack;

    for (std::wstring::value_type character : str) {
        if (IsOpenParenthesis(character, parentheses)) {
            stack.push(character);
        } 
        else if (IsCloseParenthesis(character, parentheses)) {
            if (stack.empty()) {
                return false;
            }
            
            std::wstring::value_type openParenthesis = stack.top();

            if (!AreMatchingParentheses(
                    openParenthesis, 
                    character, 
                    parentheses)) {
                
                return false;
            }

            stack.pop();
        }
    }

    return stack.empty();
}

/**
 * Erases all occurrences of a character.
 * Returns true in case all occurrences have been removed.
 */
bool StringUtils::EraseAll(
    const std::wstring& str, 
    std::wstring::value_type character,
    std::wstring& result)
{
    bool status = false;

    assert(result.empty());
    
    std::vector<std::wstring::value_type> buffer;
    buffer.reserve(str.size());

    for (const std::wstring::value_type& currCharacter : str) {
        if (currCharacter != character) {
            buffer.push_back(currCharacter);
        } 
        else {
            status = true;
        }
    }

    result.assign(buffer.begin(), buffer.end());
    return true;
}

/**
 * Strips spaces between parantheses.
 */
bool StringUtils::StripSpacesBetweenParentheses(
    const std::wstring& str, 
    std::wstring& result,
    std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>> parentheses)
{
    assert(result.empty());
    result = L"";

    size_t length = str.length();

    if (length <= 1) {
        result = str;
        return true;
    }

    //
    // Find the indexes of parentheses in input string...
    //
    std::vector<std::pair<size_t, size_t>> parenthesesIndexes;
    std::stack<std::pair<std::wstring::value_type, size_t>> parenthesesStack;

    for (size_t index = 0; index < length; ++index) {
        std::wstring::value_type character = str.at(index);

        if (IsOpenParenthesis(character, parentheses)) {
            parenthesesStack.push(std::make_pair(character, index));
        } 
        else if (IsCloseParenthesis(character, parentheses)) {
            if (parenthesesStack.empty()) {
                return false;
            }

            const std::pair<std::wstring::value_type, size_t>& openParenthesisData = parenthesesStack.top();
            std::wstring::value_type openParenthesis = openParenthesisData.first;

            if (!AreMatchingParentheses(
                    openParenthesis, 
                    character, 
                    parentheses)) {

                return false;
            }

            size_t openParenthesisIndex = openParenthesisData.second;
            parenthesesIndexes.push_back(std::make_pair(openParenthesisIndex, index));

            parenthesesStack.pop();
        }
    }

    if (!parenthesesStack.empty()) {
        return false;
    }

    std::vector<std::wstring::value_type> buffer;
    buffer.reserve(length);

    for (size_t index = 0; index < length; ++index) {
        std::wstring::value_type character = str.at(index);

        if (character != ' ') {
            buffer.push_back(character);
        } 
        else {
            bool skipCharacter = false;

            for (const std::pair<size_t, size_t>& currParenthesesIndexes : parenthesesIndexes) {
                if (index > currParenthesesIndexes.first && index < currParenthesesIndexes.second) {
                    skipCharacter = true;
                    break;
                }
            }

            if (!skipCharacter) {
                buffer.push_back(character);
            }
        }
    }

    result.append(buffer.begin(), buffer.end());

    return true;
}

/**
 * Checks whether a character is an open parenthesis.
 */
bool StringUtils::IsOpenParenthesis(
    std::wstring::value_type character,
    const std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>>& parentheses)
{
    for (std::pair<std::wstring::value_type, std::wstring::value_type> parenthesesPair : parentheses) {
        std::wstring::value_type openParenthesis = parenthesesPair.first;

        if (character == openParenthesis) {
            return true;
        }
    }

    return false;
}

/**
 * Checks whether a character is a close parenthesis.
 */
bool StringUtils::IsCloseParenthesis(
    std::wstring::value_type character,
    const std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>>& parentheses)
{
    for (std::pair<std::wstring::value_type, std::wstring::value_type> parenthesesPair : parentheses) {
        std::wstring::value_type closeParenthesis = parenthesesPair.second;

        if (character == closeParenthesis) {
            return true;
        }
    }

    return false;
}

/**
 * Checks whether parentheses are matching.
 */
bool StringUtils::AreMatchingParentheses(
    std::wstring::value_type openParenthesis, 
    std::wstring::value_type closeParenthesis,
    const std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>>& parentheses)
{
    for (const std::pair<std::wstring::value_type, std::wstring::value_type>& parenthesesPair : parentheses) {
        std::wstring::value_type currOpenParenthesis = parenthesesPair.first;
        std::wstring::value_type currCloseParenthesis = parenthesesPair.second;

        if (openParenthesis == currOpenParenthesis && closeParenthesis == currCloseParenthesis) {
            return true;
        }
    }

    return false;
}
