#include "PreCompiled.h"
#include "Conversion.h"

using namespace base;

/**
 * Gets an integer conversion.
 */
const IIntegerConversion& Conversion::integerConversion()
{
    static IntegerConversion conversion;
    return conversion;
}

/**
 * Gets a string conversion.
 */
const IStringConversion& Conversion::stringConversion()
{
    static StringConversion conversion;
    return conversion;
}
