#include "Parameter.h"
#include "CommandConstants.h"
#include "Strings.h"
#include "StringConversion.h"

using namespace command;

/**
 * Creates a new parameter.
 */
IParameterSharedPtr Parameter::Make(
    const std::wstring& name,
    const std::wstring& value,
    bool defined)
{
    return std::make_shared<Parameter>(name, value, defined);
}

/**
 * The Parameter constructor.
 */
Parameter::Parameter(
    const std::wstring& name,
    const std::wstring& value,
    bool defined) :
    m_name(name),
    m_value(value),
    m_defined(defined)
{
}

/**
 * The Parameter destructor.
 */
Parameter::~Parameter()
{
}

/**
 * Gets the name of the parameter.
 */
const std::wstring& Parameter::GetName() const
{
    return m_name;
}

/**
 * Checks whether the value of the parameter is defined.
 */
bool Parameter::IsDefined() const
{
    return m_defined;
}

/**
 * Gets a boolean value of a parameter.
 */
bool Parameter::GetBooleanValue() const
{
    base::StringConversion stringConversion;
    return stringConversion.ToBoolean(m_value);
}

/**
 * Gets a short value of a parameter.
 */
short Parameter::GetShortValue() const
{
    base::StringConversion stringConversion;
    return stringConversion.ToShort(m_value);
}

/**
 * Gets an integer value of a parameter.
 */
int Parameter::GetIntegerValue() const
{
    base::StringConversion stringConversion;
    return stringConversion.ToInteger(m_value);
}

/**
 * Gets a long value of a parameter.
 */
long Parameter::GetLongValue() const
{
    base::StringConversion stringConversion;
    return stringConversion.ToLong(m_value);
}

/**
 * Gets a size_t value of a parameter.
 */
size_t Parameter::GetSizeTValue() const
{
    base::StringConversion stringConversion;
    return stringConversion.ToSizeT(m_value);
}

/**
 * Gets a float value of a parameter.
 */
float Parameter::GetFloatValue() const
{
    base::StringConversion stringConversion;
    return stringConversion.ToFloat(m_value);
}

/**
 * Gets a double value of a parameter.
 */
double Parameter::GetDoubleValue() const
{
    base::StringConversion stringConversion;
    return stringConversion.ToDouble(m_value);
}

/**
 * Gets a character value of a parameter.
 */
wchar_t Parameter::GetCharacterValue() const
{
    base::StringConversion stringConversion;
    return stringConversion.ToCharacter(m_value);
}

/**
 * Gets a string value of a parameter.
 */
const std::wstring& Parameter::GetStringValue() const
{
    return m_value;
}

/**
 * Gets a duration value of a parameter.
 */
base::DurationSharedPtr Parameter::GetDurationValue() const
{
    base::StringConversion stringConversion;
    return stringConversion.ToDuration(m_value);
}

/**
 * Gets a string array value of a parameter.
 */
void Parameter::GetStringArrayValue(std::vector<std::wstring>& result) const
{
    base::Strings::SplitString(m_value, L",", result);
}
