#include "StringConversion.h"
#include "StringEquality.h"
#include "NotImplementedException.h"

using namespace base;

const std::wstring StringConversion::BOOLEAN_TRUE_VALUE = L"true";
const std::wstring StringConversion::BOOLEAN_FALSE_VALUE = L"false";

/**
 * The StringConversion constructor.
 */
StringConversion::StringConversion()
{
}

/**
 * The StringConversion constructor.
 */
StringConversion::~StringConversion()
{
}

/**
 * Converts a string to a boolean.
 */
bool StringConversion::ToBoolean(const std::wstring& value) const
{
    if (StringEquality::AreEqualIgnoreCase(value, BOOLEAN_TRUE_VALUE))
    {
        return true;
    }
    else if (StringEquality::AreEqualIgnoreCase(value, BOOLEAN_FALSE_VALUE))
    {
        return false;
    }
    else
    {
        long errorCode = ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"Failed to convert a string: " << value << L" to a boolean. "
            << L"The string is not true or false."
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }
}

/**
 * Converts a string to a short.
 */
short StringConversion::ToShort(const std::wstring& value) const
{
    int result = std::stoi(value);

    if (result < std::numeric_limits<short>::min() || result > std::numeric_limits<short>::max())
    {
        long errorCode = ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"Failed to convert a string: " << value << L" to a short. "
            << L"The string is not in the required range for a short."
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    return static_cast<short>(result);
}

/**
 * Converts a string to an integer.
 */
int StringConversion::ToInteger(const std::wstring& value) const
{
    return std::stoi(value);
}

/**
 * Converts a string to a long.
 */
long StringConversion::ToLong(const std::wstring& value) const
{
    return std::stol(value);
}

/**
 * Converts a string to a size_t.
 */
size_t StringConversion::ToSizeT(const std::wstring& value) const
{
    long result = std::stol(value);

    if (result < 0 || result > std::numeric_limits<size_t>::max())
    {
        long errorCode = ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"Failed to convert a string: " << value << L" to a size_t. "
            << L"The string is not in the required range for a size_t."
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    return static_cast<size_t>(result);
}

/**
 * Converts a string to a float.
 */
float StringConversion::ToFloat(const std::wstring& value) const
{
    return std::stof(value);
}

/**
 * Converts a string to a double.
 */
double StringConversion::ToDouble(const std::wstring& value) const
{
    return std::stod(value);
}

/**
 * Converts a string to a character.
 */
char StringConversion::ToCharacter(const std::wstring& value) const
{
    if (value.size() != 1)
    {
        long errorCode = ErrorCodes::INVALID_ARG;

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"Failed to convert a string: " << value << L" to a character. "
            << L"The input string is not a single character long."
            << ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();
        throw BaseException(errorCode, errorMessage);
    }

    return value[0];
}

/**
 * Converts a string to a duration.
 */
DurationSharedPtr StringConversion::ToDuration(const std::wstring& value) const
{
    return Duration::Parse(value);
}
