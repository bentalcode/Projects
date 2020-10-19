#include "PreCompiled.h"
#include "CANMessageName.h"
#include "CANMessageGeneratorException.h"

using namespace controllerareanetwork::messagegenerator;

const size_t CANMessageName::minNameLength = 1;
const size_t CANMessageName::maxNameLength = 32;

/**
 * Creates a new message name.
 */
ICANMessageNamePtr CANMessageName::make(const std::vector<std::string::value_type>& name)
{
    return std::make_shared<CANMessageName>(name);
}

/**
 * The CANMessageName Constructor.
 */
CANMessageName::CANMessageName(const std::vector<std::string::value_type>& name) :
    m_name(name)
{
}

/**
 * The CANMessageName destructor.
 */
CANMessageName::~CANMessageName()
{
}

/**
 * Gets the name of a CAN message.
 * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores.
 */
std::vector<std::string::value_type> CANMessageName::getName() const
{
    return m_name;
}

/**
 * Gets the string representation of this instance.
 */
std::string CANMessageName::toString() const
{
    return std::string(&m_name[0], m_name.size());
}

/**
 * Validates the name of the message.
 */
void CANMessageName::validateName(const std::vector<std::string::value_type>& name)
{
    if (name.size() < minNameLength || name.size() > maxNameLength)
    {
        std::string errorMessage = "The length of the message is invalid.";
        throw CANMessageGeneratorException(errorMessage);
    }

    for (char character : name)
    {
        if (!validNameCharacter(character))
        {
            std::string errorMessage =
               "The following character: " + std::to_string(character) + " is invalid." +
               "; A character can be between 'a' to 'Z', or a digit, or an underscore.";

            throw new CANMessageGeneratorException(errorMessage);
        }
    }
}

/**
 * Validates that the name of the character is valid.
 */
bool CANMessageName::validNameCharacter(std::string::value_type character)
{
    return
        std::isdigit(character) ||
        (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') ||
        character == '_';
}
