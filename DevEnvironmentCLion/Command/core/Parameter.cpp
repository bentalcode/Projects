#include "PreCompiled.h"
#include "Parameter.h"
#include "CommandConstants.h"
#include "Conversion.h"
#include "Strings.h"

using namespace command;

/**
 * Creates a new parameter.
 */
IParameterSharedPtr Parameter::make(
    const std::string& name,
    const std::string& value,
    bool defined)
{
    return std::make_shared<Parameter>(name, value, defined);
}

/**
 * The Parameter constructor.
 */
Parameter::Parameter(
    const std::string& name,
    const std::string& value,
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
const std::string& Parameter::getName() const
{
    return m_name;
}

/**
 * Checks whether the value of the parameter is defined.
 */
bool Parameter::isDefined() const
{
    return m_defined;
}

/**
 * Gets a boolean value of a parameter.
 */
bool Parameter::getBooleanValue() const
{
    return base::Conversion::stringConversion().toBoolean(m_value);
}

/**
 * Gets a short value of a parameter.
 */
short Parameter::getShortValue() const
{
    return base::Conversion::stringConversion().toShort(m_value);
}

/**
 * Gets an integer value of a parameter.
 */
int Parameter::getIntegerValue() const
{
    return base::Conversion::stringConversion().toInteger(m_value);
}

/**
 * Gets a long value of a parameter.
 */
long Parameter::getLongValue() const
{
    return base::Conversion::stringConversion().toLong(m_value);
}

/**
 * Gets a size_t value of a parameter.
 */
size_t Parameter::getSizeTValue() const
{
    return base::Conversion::stringConversion().toSizeT(m_value);
}

/**
 * Gets a float value of a parameter.
 */
float Parameter::getFloatValue() const
{
    return base::Conversion::stringConversion().toFloat(m_value);
}

/**
 * Gets a double value of a parameter.
 */
double Parameter::getDoubleValue() const
{
    return base::Conversion::stringConversion().toDouble(m_value);
}

/**
 * Gets a character value of a parameter.
 */
char Parameter::getCharacterValue() const
{
    return base::Conversion::stringConversion().toCharacter(m_value);
}

/**
 * Gets a string value of a parameter.
 */
const std::string& Parameter::getStringValue() const
{
    return m_value;
}

/**
 * Gets a duration value of a parameter.
 */
base::DurationSharedPtr Parameter::getDurationValue() const
{
    return base::Conversion::stringConversion().toDuration(m_value);
}

/**
 * Gets a string array value of a parameter.
 */
void Parameter::getStringArrayValue(std::vector<std::string>& result) const
{
    base::Strings::splitString(m_value, ",", result);
}
