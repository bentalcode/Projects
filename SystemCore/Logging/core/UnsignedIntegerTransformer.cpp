#include "UnsignedIntegerTransformer.h"
#include "StringUtils.h"

using namespace logging;

/**
 * Creates an Unsigned Integer Transformer.
 */
tabular_data::IValueTransformerSharedPtr<unsigned int> UnsignedIntegerTransformer::Make()
{
    return std::make_shared<UnsignedIntegerTransformer>();
}

/**
 * The UnsignedIntegerTransformer constructor.
 */
UnsignedIntegerTransformer::UnsignedIntegerTransformer() 
{
}

/**
 * The UnsignedIntegerTransformer destructor.
 */
UnsignedIntegerTransformer::~UnsignedIntegerTransformer() 
{
}

/**
 * Transforms a value to an unsigned integer.
 */
unsigned int UnsignedIntegerTransformer::Transform(const std::wstring& value) const
{
    std::wstring currValue = value;
    base::StringUtils::Trim(currValue);
    unsigned int result = std::stoi(value);
    return result;
}
