#include "PreCompiled.h"
#include "Parameter.h"
#include "CommandConstants.h"

using namespace command;

/**
 * Creates a help parameter.
 */
IParameterPtr Parameter::createHelpParameter()
{
    return std::make_shared<Parameter>(CommandConstants::helpShortName, "", false);
}

/**
 * Creates a new parameter.
 */
IParameterPtr Parameter::make(
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
    return true;
}

/**
 * Gets a short value of a parameter.
 */
short Parameter::getShortValue() const
{
    return 0;
}

/**
 * Gets an integer value of a parameter.
 */
int Parameter::getIntegerValue() const
{
    return 0;
}

/**
 * Gets a long value of a parameter.
 */
long Parameter::getLongValue() const
{
    return 0;
}

/**
 * Gets a float value of a parameter.
 */
float Parameter::getFloatValue() const
{
    return 0.0;
}

/**
 * Gets a double value of a parameter.
 */
double Parameter::getDoubleValue() const
{
    return 0.0;
}

/**
 * Gets a character value of a parameter.
 */
char Parameter::getCharacterValue() const
{
    return 0;
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
base::DurationPtr Parameter::getDurationValue() const
{
    return nullptr;
}

/**
 * Gets a string array value of a parameter.
 */
void Parameter::getStringArrayValue(std::vector<std::string>& result) const
{

}
