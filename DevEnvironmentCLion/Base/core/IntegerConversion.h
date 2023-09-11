#ifndef INTEGER_CONVERSION_H_61360d73_3fae_4460_b523_55efa1aba008
#define INTEGER_CONVERSION_H_61360d73_3fae_4460_b523_55efa1aba008

#include "IIntegerConversion.h"

namespace base {

    /**
     * The IntegerConversion class implements conversions for an integer.
     */
    class IntegerConversion final : public IIntegerConversion
    {
    public:
        /**
         * The IntegerConversion constructor.
         */
        IntegerConversion();

        /**
         * The IntegerConversion destructor.
         */
        virtual ~IntegerConversion();

        /**
         * The copy/move constructors.
         */
        IntegerConversion(const IntegerConversion&) = delete;
        IntegerConversion(IntegerConversion&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IntegerConversion& operator=(const IntegerConversion&) = delete;
        IntegerConversion& operator=(IntegerConversion&&) = delete;

        /**
         * Converts an integer to a character.
         */
        virtual char toCharacter(int value) const override;
    };
}

#endif // INTEGER_CONVERSION_H_61360d73_3fae_4460_b523_55efa1aba008
