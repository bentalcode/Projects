#include "ToString.h"

using namespace base;

/**
 * Creates an instance of a ToString interface.
 */
IToStringSharedPtr<std::wstring> DefaultToString::Make()
{
    return std::make_shared<DefaultToString>();
}

/**
 * The DefaultToString constructor.
 */
DefaultToString::DefaultToString() 
{
}

/**
 * The DefaultToString destructor.
 */
DefaultToString::~DefaultToString() 
{
}

/**
 * Gets a string translation of an object.
 */
std::wstring DefaultToString::ToString(const std::wstring& str) const
{
    return str;
}

/**
 * Creates an instance of a ToString interface.
 */
IToStringSharedPtr<long> HResultToString::Make()
{
    return std::make_shared<HResultToString>();
}

/**
 * The HResultToString constructor.
 */
HResultToString::HResultToString() 
{
}

/**
 * The HResultToString destructor.
 */
HResultToString::~HResultToString() 
{
}

/**
 * Gets a string translation of an object.
 */
std::wstring HResultToString::ToString(const long& hr) const
{
    std::wstringstream stream;
    stream << std::hex << hr;
    return stream.str();
}
