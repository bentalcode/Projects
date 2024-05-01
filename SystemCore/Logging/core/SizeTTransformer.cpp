#include "SizeTTransformer.h"
#include "StringUtils.h"

using namespace logging;

/**
 * Creates a Size Type Transformer.
 */
tabular_data::IValueTransformerSharedPtr<size_t> SizeTTransformer::Make()
{
    return std::make_shared<SizeTTransformer>();
}

/**
 * The SizeTTransformer constructor.
 */
SizeTTransformer::SizeTTransformer() 
{
}

/**
 * The SizeTTransformer destructor.
 */
SizeTTransformer::~SizeTTransformer() 
{
}

/**
 * Transforms a value to a size type.
 */
size_t SizeTTransformer::Transform(const std::wstring& value) const
{
    std::wstring currValue = value;
    base::StringUtils::Trim(currValue);
    long long result = std::stoll(value);
    return result;
}
