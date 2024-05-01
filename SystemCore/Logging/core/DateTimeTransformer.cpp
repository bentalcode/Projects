#include "DateTimeTransformer.h"
#include "StringUtils.h"
#include <algorithm>

using namespace logging;

/**
 * Creates a Date Time Transformer.
 */
tabular_data::IValueTransformerSharedPtr<base::DateTimeSharedPtr> DateTimeTransformer::Make(const std::wstring& format)
{
    return std::make_shared<DateTimeTransformer>(format);
}

/**
 * The DateTimeTransformer constructor.
 */
DateTimeTransformer::DateTimeTransformer(const std::wstring& format) : 
    m_format(format) 
{
}

/**
 * The DateTimeTransformer destructor.
 */
DateTimeTransformer::~DateTimeTransformer() 
{
}

/**
 * Transforms a value to a date time.
 */
base::DateTimeSharedPtr DateTimeTransformer::Transform(const std::wstring& value) const
{
    //
    // Trim the input string...
    //
    std::wstring currValue = value;
    base::StringUtils::Trim(currValue);

    //
    // Parse date time with out the milliseconds section since it is not supported in the parse API...
    //
    std::wstring::reverse_iterator millisecondsSeparatorIterator = std::find_if(
        currValue.rbegin(), 
        currValue.rend(),
        [](std::wstring::value_type character) { return character == '.'; });

    unsigned int milliseconds = 0;

    if (millisecondsSeparatorIterator != currValue.rend()) {
        std::wstring::iterator millisecondsStartIterator = millisecondsSeparatorIterator.base();

        std::wstring millisecondsSection(millisecondsStartIterator, currValue.end());
        currValue.erase(millisecondsStartIterator - 1, currValue.end());

        milliseconds = std::stoi(millisecondsSection);
    }
    
    base::DateTimeSharedPtr result = base::DateTime::Parse(currValue, m_format);
    
    //
    // Add the milliseconds section back to the parsed time...
    //
    if (milliseconds > 0) {
        base::DurationSharedPtr duration = base::Duration::FromMilliseconds(milliseconds);
        result->Add(*duration);
    }

    return result;
}
