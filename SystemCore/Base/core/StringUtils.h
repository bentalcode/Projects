#ifndef TO_STRING_H_6a667f1e_906d_45c3_a95c_825f14ccefe9
#define TO_STRING_H_6a667f1e_906d_45c3_a95c_825f14ccefe9

#include <limits>
#include <string>
#include <vector>
#include "BaseException.h"
#include <assert.h>

namespace base {

    /**
     * The StringUtils class implements generic string utilities.
     */
    class StringUtils final {
    public:
        StringUtils() = delete;
        ~StringUtils() = delete;

        /**
         * Copies a null terminated string.
         * Returns the number of characters written not including null terminated character.
         */
        static size_t CopyString(
            const char* src,
            size_t numOfCharactersToCopy,
            char* dest, size_t maxDestSize);

        /**
         * Copies a null terminated string.
         * Returns the number of characters written not including the null terminated character.
         */
        static size_t CopyString(
            const wchar_t* src,
            size_t numOfCharactersToCopy,
            wchar_t* dest, size_t maxDestSize);

        /**
         * Gets a length of a null terminated string.
         */
        static size_t GetStringLength(
            const char* str,
            size_t maxLength);

        /**
         * Gets a length of a null terminated string.
         */
        static size_t GetStringLength(
            const wchar_t* str,
            size_t maxLength);

        /**
         * Converts a string to a wide string.
         */
        static std::wstring StringToWideString(const std::string& str);

        /**
         * Converts a wide string to a string.
         */
        static std::string WideStringToString(const std::wstring& str);

        /**
         * Replaces all instances of a sub string in a string.
         */
        static void ReplaceAll(
            std::wstring& str,
            const std::wstring& from,
            const std::wstring& to);

        /**
         * Trims a string.
         */
        static void Trim(std::wstring& str);

        /**
         * Trims a string from left.
         */
        static void TrimFromLeft(std::wstring& str);

        /**
         * Trims a string from right.
         */
        static void TrimFromRight(std::wstring& str);

        /**
         * Lowercases the string.
         */
        static void ToLowercase(std::wstring& str);

        /**
         * Uppercases the string.
         */
        static void ToUppercase(std::wstring& str);

        /**
         * Checks whether a string starts with a given prefix.
         */
        static bool StartWith(
            const std::wstring& str,
            const std::wstring& prefix,
            size_t offset = 0);

        /**
         * Checks whether a string Has valid parantheses.
         */
        static bool HasValidParentheses(
            const std::wstring& str,
            std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>> parentheses = {
                {'(', ')'}, {'[', ']'}, {'{', '}'}});

        /**
         * Earses all occurrences of a character.
         * Returns true in case all occurrences have been removed.
         */
        static bool EraseAll(
            const std::wstring& str,
            std::wstring::value_type character,
            std::wstring& result);

        /**
         * Strips spaces between parantheses.
         */
        static bool StripSpacesBetweenParentheses(
            const std::wstring& str,
            std::wstring& result,
            std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>> parentheses = {
                {'(', ')'}, {'[', ']'}, {'{', '}'}});

        /**
         * Converts a vector to a string.
         */
        static std::wstring ToString(
            const std::vector<std::wstring>& tokens,
            const std::wstring& separator);

    private:
        /**
         * Checks whether a character is an open parenthesis.
         */
        static bool IsOpenParenthesis(
            std::wstring::value_type character,
            const std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>>& parentheses);

        /**
         * Checks whether a character is a close parenthesis.
         */
        static bool IsCloseParenthesis(
            std::wstring::value_type character,
            const std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>>& parentheses);

        /**
         * Checks whether parentheses are matching.
         */
        static bool AreMatchingParentheses(
            std::wstring::value_type openParenthesis,
            std::wstring::value_type closeParenthesis,
            const std::vector<std::pair<std::wstring::value_type, std::wstring::value_type>>& parentheses);

        /**
         * Copies a null terminated string.
         */
        template <typename CharType>
        static size_t CopyString(
            const CharType* src,
            size_t numOfCharactersToCopy,
            CharType* dest,
            size_t maxDestSize,
            CharType nullCharacter);

        /**
         * Gets a length a null terminated string.
         */
        template <typename CharType>
        static size_t GetStringLength(
            const CharType* str,
            size_t maxLength);
    };

    /**
     * Copies a null terminated string.
     */
    template <typename CharType>
    size_t StringUtils::CopyString(
        const CharType* src,
        size_t numOfCharactersToCopy,
        CharType* dest,
        size_t maxDestSize,
        CharType nullCharacter)
    {
        if (numOfCharactersToCopy >= std::numeric_limits<size_t>::max() - 1 ||
            numOfCharactersToCopy + 1 > maxDestSize) {

            long errorCode = ErrorCodes::NOT_ENOUGH_MEMORY;

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"StringUtils::CopyString() Has failed copying a string"
                << L" since the Size of the Destination buffer is not sufficient"
                << ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            throw BaseException(errorCode, errorMessage);
        }

        size_t counter = 0;

        size_t index = 0;
        while (index < numOfCharactersToCopy) {
            dest[index] = src[index];
            ++counter;

            ++index;
        }

        dest[index] = nullCharacter;

        assert(counter == numOfCharactersToCopy);

        if (counter !=  numOfCharactersToCopy) {
            long errorCode = ErrorCodes::FAIL;

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"StringUtils::CopyString() has failed copying string to destination buffer unexpectedly"
                << ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            throw BaseException(errorCode, errorMessage);
        }

        return counter;
    }

    /**
     * Gets a length a null terminated string.
     */
    template <typename CharType>
    size_t StringUtils::GetStringLength(
        const CharType* str,
        size_t maxLength)
    {
        size_t length = 0;
        size_t index = 0;

        while (str[index] != '\0') {
            ++length;

            if (length > maxLength) {
                long errorCode = ErrorCodes::INVALID_ARG;

                std::wstringstream errorMessageStream;
                errorMessageStream
                    << L"StringUtils::GetStringLength()  Has failed retrieving length of an input string"
                    << L" since it's Size is larger than maxLegnth"
                    << ErrorMessages::GetErrorCodeMessage(errorCode);

                std::wstring errorMessage = errorMessageStream.str();
                throw BaseException(errorCode, errorMessage);
            }
        }

        return length;
    }

    /**
     * Converts a vector to a string.
     */
    inline std::wstring StringUtils::ToString(
        const std::vector<std::wstring>& tokens,
        const std::wstring& separator)
    {
        std::wstringstream result;

        bool addSeparator = false;

        for (const std::wstring& token : tokens) {
            if (!addSeparator) {
                addSeparator = true;
            }
            else {
                result << separator;
            }

            result << token;
        }

        return result.str();
    }

} // namespace base

#endif // TO_STRING_H_6a667f1e_906d_45c3_a95c_825f14ccefe9
