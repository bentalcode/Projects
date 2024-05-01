#include "UnsignedLongTransformer.h"
#include "StringUtils.h"

using namespace logging;

/**
 * Creates an Unsigned Long Transformer.
 */
tabular_data::IValueTransformerSharedPtr<unsigned long> UnsignedLongTransformer::Make()
{
    return std::make_shared<UnsignedLongTransformer>();
}

/**
 * The UnsignedLongTransformer constructor.
 */
UnsignedLongTransformer::UnsignedLongTransformer() 
{
}

/**
 * The UnsignedLongTransformer destructor.
 */
UnsignedLongTransformer::~UnsignedLongTransformer() 
{
}

/**
 * Transforms a value to an unsigned long.
 */
unsigned long UnsignedLongTransformer::Transform(const std::wstring& value) const
{
    std::wstring currValue = value;
    base::StringUtils::Trim(currValue);
    unsigned long result = std::stol(value);
    return result;
}
