#ifndef CONVERSION_H_b3ae1e83_7982_4c4a_8061_3bd109d16646
#define CONVERSION_H_b3ae1e83_7982_4c4a_8061_3bd109d16646

#include "IntegerConversion.h"
#include "StringConversion.h"

namespace base
{
    /**
     * The Conversion class implements complementary APIs for conversions.
     */
    class Conversion final
    {
    public:
        /**
         * Gets an integer conversion.
         */
        static const IIntegerConversion& integerConversion();

        /**
         * Gets a string conversion.
         */
        static const IStringConversion& stringConversion();

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Conversion() = delete;
        ~Conversion() = delete;
    };
}

#endif // CONVERSION_H_b3ae1e83_7982_4c4a_8061_3bd109d16646
