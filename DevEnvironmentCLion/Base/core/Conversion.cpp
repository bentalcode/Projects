#include "PreCompiled.h"
#include "Conversion.h"

using namespace base;

/**
 * Gets the string conversion.
 */
const IStringConversion& Conversion::stringConversion()
{
    static StringConversion stringConversion;
    return stringConversion;
}
