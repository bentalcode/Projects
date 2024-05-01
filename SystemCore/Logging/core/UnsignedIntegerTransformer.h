#ifndef UNSIGNED_INTERGER_TRANSFORMER_H_dc61dfd9_18ff_4bd7_a8eb_16175137e174
#define UNSIGNED_INTERGER_TRANSFORMER_H_dc61dfd9_18ff_4bd7_a8eb_16175137e174

#include "IValueTransformer.h"

namespace logging {

    /**
     * The UnsignedIntegerTransformer class implements a transformer to an unsigned integer.
     */
    class UnsignedIntegerTransformer final : public tabular_data::IValueTransformer<unsigned int> {
    public:
        /**
         * Creates an Unsigned Integer Transformer.
         */
        static tabular_data::IValueTransformerSharedPtr<unsigned int> Make();

        /**
         * The UnsignedIntegerTransformer constructor.
         */
        UnsignedIntegerTransformer();

        /**
         * The UnsignedIntegerTransformer destructor.
         */
        virtual ~UnsignedIntegerTransformer();

        /**
         * Transforms a value to an unsigned integer.
         */
        virtual unsigned int Transform(const std::wstring& value) const override;
    };

}  // namespace logging

#endif // UNSIGNED_INTERGER_TRANSFORMER_H_dc61dfd9_18ff_4bd7_a8eb_16175137e174

