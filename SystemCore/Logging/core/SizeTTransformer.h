#ifndef SIZE_T_TRANSFORMER_H_7b513eb9_2c5a_4ade_99ff_e9d29f70bb7e
#define SIZE_T_TRANSFORMER_H_7b513eb9_2c5a_4ade_99ff_e9d29f70bb7e

#include "IValueTransformer.h"

namespace logging {

    /**
     * The SizeTTransformer class implements a value transformer to a size type.
     */
    class SizeTTransformer final : public tabular_data::IValueTransformer<size_t> {
    public:
        /**
         * Creates a Size Type Transformer.
         */
        static tabular_data::IValueTransformerSharedPtr<size_t> Make();

        /**
         * The SizeTTransformer constructor.
         */
        SizeTTransformer();

        /**
         * The SizeTTransformer destructor.
         */
        virtual ~SizeTTransformer();

        /**
         * Transforms a value to a size type.
         */
        virtual size_t Transform(const std::wstring& value) const override;
    };

}  // namespace logging

#endif // SIZE_T_TRANSFORMER_H_7b513eb9_2c5a_4ade_99ff_e9d29f70bb7e
