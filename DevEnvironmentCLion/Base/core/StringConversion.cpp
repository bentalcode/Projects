#include "PreCompiled.h"
#include "StringConversion.h"
#include "StringEquality.h"
#include "NotImplementedException.h"

using namespace base;

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
bool StringConversion::toBoolean(const std::string& value) const
{
    if (StringEquality::equalsIgnoreCase(value, "true"))
    {
        return true;
    }
    else if (StringEquality::equalsIgnoreCase(value, "false"))
    {
        return false;
    }
    else
    {
        std::string errorMessage =
            "Failed to convert a string: " + value + " to a boolean. "
            "The string is not true or false.";

        throw BaseException(errorMessage);
    }
}

/**
 * Converts a string to a short.
 */
short StringConversion::toShort(const std::string& value) const
{
    int result = std::stoi(value);

    if (result < std::numeric_limits<short>::min() || result > std::numeric_limits<short>::max())
    {
        std::string errorMessage =
            "Failed to convert a string: " + value + " to a short." +
            "The string is not in the required range for a short.";
    }

    return static_cast<short>(result);
}

/**
 * Converts a string to an integer.
 */
int StringConversion::toInteger(const std::string& value) const
{
    return std::stoi(value);
}

/**
 * Converts a string to a long.
 */
long StringConversion::toLong(const std::string& value) const
{
    return std::stol(value);
}

/**
 * Converts a string to a size_t.
 */
size_t StringConversion::toSizeT(const std::string& value) const
{
    long result = std::stol(value);

    if (result < 0 || result > std::numeric_limits<size_t>::max())
    {
        std::string errorMessage =
            "Failed to convert a string: " + value + " to a size_t." +
            "The string is not in the required range for a size_t.";
    }

    return static_cast<size_t>(result);
}

/**
 * Converts a string to a float.
 */
float StringConversion::toFloat(const std::string& value) const
{
    return std::stof(value);
}

/**
 * Converts a string to a double.
 */
double StringConversion::toDouble(const std::string& value) const
{
    return std::stod(value);
}

/**
 * Converts a string to a character.
 */
char StringConversion::toCharacter(const std::string& value) const
{
    if (value.size() != 1)
    {
        std::string errorMessage =
            "Failed to convert a string: " + value + " to a character." +
            "The input string is not a single character long.";

        throw BaseException(errorMessage);
    }

    return value[0];
}

/**
 * Converts a string to a duration.
 */
DurationPtr StringConversion::toDuration(const std::string& value) const
{
    throw NotImplementedException("StringConversion::toDuration");
}
