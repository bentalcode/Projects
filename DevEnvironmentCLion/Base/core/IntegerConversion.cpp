#include "PreCompiled.h"
#include "IntegerConversion.h"

using namespace base;

/**
 * The IntegerConversion constructor.
 */
IntegerConversion::IntegerConversion()
{
}

/**
 * The IntegerConversion constructor.
 */
IntegerConversion::~IntegerConversion()
{
}

/**
 * Converts an integer to a character.
 */
char IntegerConversion::toCharacter(int value) const
{
    if (value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min())
    {
        std::string errorMessage =
            "Failed to convert an integer: " + std::to_string(value) + " to a character." +
            "The input integer is out of range of a character.";

        throw BaseException(errorMessage);
    }

    return static_cast<char>(value);
}
