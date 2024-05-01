#ifndef STRING_TRANSFORMER_H_dfa21af2_cf49_4ed4_aef3_1c23e0d5dc27
#define STRING_TRANSFORMER_H_dfa21af2_cf49_4ed4_aef3_1c23e0d5dc27

#include "IValueTransformer.h"

namespace logging {

    /**
     * The StringTransformer class implements a value transformer to a string.
     */
    class StringTransformer final : public tabular_data::IValueTransformer<std::wstring> {
    public:
        /**
         * Creates a String Transformer.
         */
        static tabular_data::IValueTransformerSharedPtr<std::wstring> Make();

        /**
         * The StringTransformer constructor.
         */
        StringTransformer();

        /**
         * The StringTransformer destructor.
         */
        virtual ~StringTransformer();

        /**
         * Transforms a value to a string.
         */
        virtual std::wstring Transform(const std::wstring& value) const override;
    };

}  // namespace logging

#endif // STRING_TRANSFORMER_H_dfa21af2_cf49_4ed4_aef3_1c23e0d5dc27

