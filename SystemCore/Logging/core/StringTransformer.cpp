#include "StringTransformer.h"
#include "StringUtils.h"

using namespace logging;

/**
 * Creates a String Transformer.
 */
tabular_data::IValueTransformerSharedPtr<std::wstring> StringTransformer::Make()
{
    return std::make_shared<StringTransformer>();
}

/**
 * The StringTransformer constructor.
 */
StringTransformer::StringTransformer() 
{
}

/**
 * The StringTransformer destructor.
 */
StringTransformer::~StringTransformer() 
{
}

/**
 * Transforms a value to a string.
 */
std::wstring StringTransformer::Transform(const std::wstring& value) const
{
    std::wstring result = value;
    base::StringUtils::Trim(result);
    return result;
}
