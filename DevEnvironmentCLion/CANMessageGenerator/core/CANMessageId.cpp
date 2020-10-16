#include "PreCompiled.h"
#include "CANMessageId.h"

using namespace controllerareanetweok::messagegenerator;

/**
 * Creates a new messages id.
 */
ICANMessageIdPtr CANMessageId::make(unsigned int mainId, unsigned int extendedId)
{
    return std::make_shared<CANMessageId>(mainId, extendedId);
}

/**
 * The CANMessageId Constructor.
 */
CANMessageId::CANMessageId(unsigned int mainId, unsigned int extendedId) :
    m_mainId(mainId),
    m_extendedId(extendedId)
{
}

/**
 * The CANMessageId destructor.
 */
CANMessageId::~CANMessageId()
{
}

/**
 * Gets the main id. Bits: {28, 27, 26, ... 0}.
 */
unsigned int CANMessageId::getMainId() const
{
    return m_mainId;
}

/**
 * Gets the extended id. Bits: {31, 30, 29}.
 */
unsigned int CANMessageId::getExtendedId() const
{
    return m_extendedId;
}

/**
 * Gets the id.
 */
unsigned int CANMessageId::getId() const
{
    return m_mainId | m_extendedId;
}

/**
 * Gets the string representation of this instance.
 */
std::string CANMessageId::toString() const
{
    unsigned int id = getId();
    return std::to_string(id);
}
