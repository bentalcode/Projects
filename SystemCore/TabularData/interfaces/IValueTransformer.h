#ifndef I_VALUE_TRANSFORMER_H_027165e3_6fdc_49a3_ac75_82531e0d0e35
#define I_VALUE_TRANSFORMER_H_027165e3_6fdc_49a3_ac75_82531e0d0e35

#include <string>
#include <memory>

namespace tabular_data {

/**
 * The IValueTransformer interface defines a Value Transformer.
 */
template <typename T>
class IValueTransformer {
public:
    IValueTransformer() = default;
    virtual ~IValueTransformer() = default;

    /**
     * Transforms a value.
     */
    virtual T Transform(const std::wstring& value) const = 0;
};

/**
 * Defines the Shared Ptr of Value Transformer.
 */
template <typename T>
using IValueTransformerSharedPtr = std::shared_ptr<IValueTransformer<T>>;

} // namespace tabular_data

#endif // I_VALUE_TRANSFORMER_H_027165e3_6fdc_49a3_ac75_82531e0d0e35
