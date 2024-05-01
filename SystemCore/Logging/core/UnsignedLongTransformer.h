#ifndef UNSIGNED_LONG_TRANSFORMER_H_5187bb1e_7f9f_4384_bd81_14677ea0d424
#define UNSIGNED_LONG_TRANSFORMER_H_5187bb1e_7f9f_4384_bd81_14677ea0d424

#include "ILogInformation.h"
#include "IValueTransformer.h"

namespace logging {

    /**
     * The UnsignedLongTransformer class implements a transformer to an unsigned long.
     */
    class UnsignedLongTransformer final : public tabular_data::IValueTransformer<unsigned long> {
    public:
        /**
         * Creates an Unsigned Long Transformer.
         */
        static tabular_data::IValueTransformerSharedPtr<unsigned long> Make();

        /**
         * The UnsignedLongTransformer constructor.
         */
        UnsignedLongTransformer();

        /**
         * The UnsignedLongTransformer destructor.
         */
        virtual ~UnsignedLongTransformer();

        /**
         * Transforms a value to an unsigned long.
         */
        virtual unsigned long Transform(const std::wstring& value) const override;
    };

}  // namespace logging

#endif // UNSIGNED_LONG_TRANSFORMER_H_5187bb1e_7f9f_4384_bd81_14677ea0d424

