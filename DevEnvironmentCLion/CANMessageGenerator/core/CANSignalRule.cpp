#include "PreCompiled.h"
#include "CANSignalRule.h"
#include "CANMessageGeneratorException.h"
#include "Strings.h"

using namespace controllerareanetweok::messagegenerator;

const std::string CANSignalRule::messageSyntax = "SG_";
const std::string CANSignalRule::byteOrderBigEndianSyntax = "@0";
const std::string CANSignalRule::byteOrderLittleEndianSyntax = "@1";
const std::string CANSignalRule::valueTypeUnsignedSyntax = "+";
const std::string CANSignalRule::valueTypeSignedSyntax = "-";

/**
 * Creates a new rule.
 */
ICANSignalRulePtr CANSignalRule::make(
    const std::string& name,
    size_t bitStart,
    size_t bitLength,
    bool byteOrderBigEndian,
    bool valueTypeUnsigned,
    float scale,
    int offset,
    int minimum,
    int maximum,
    const std::string& unit,
    const std::string& transmittingNodeName)
{
    return std::make_shared<CANSignalRule>(
        name,
        bitStart,
        bitLength,
        byteOrderBigEndian,
        valueTypeUnsigned,
        scale,
        offset,
        minimum,
        maximum,
        unit,
        transmittingNodeName);
}

/**
 * The CANSignal constructor.
 */
CANSignalRule::CANSignalRule(
    const std::string& name,
    size_t bitStart,
    size_t bitLength,
    bool byteOrderBigEndian,
    bool valueTypeUnsigned,
    float scale,
    int offset,
    int minimum,
    int maximum,
    const std::string& unit,
    const std::string& transmittingNodeName) :
    m_name(name),
    m_bitStart(bitStart),
    m_bitLength(bitLength),
    m_byteOrderBigEndian(byteOrderBigEndian),
    m_valueTypeUnsigned(valueTypeUnsigned),
    m_scale(scale),
    m_offset(offset),
    m_minimum(minimum),
    m_maximum(maximum),
    m_unit(unit),
    m_transmittingNodeName(transmittingNodeName)
{
    if (minimum < maximum)
    {
        std::string errorMessage = "The maximum can not be less than the minimum.";
        throw CANMessageGeneratorException(errorMessage);
    }
}

/**
 * The CANSignalRule destructor.
 */
CANSignalRule::~CANSignalRule()
{
}

/**
 * Gets the name of the signal.
 */
const std::string& CANSignalRule::getName() const
{
    return m_name;
}

/**
 * Gets the bit start.
 * The bit start counts from 0 and marks the start of the signal in the data payload.
 */
size_t CANSignalRule::getBitStart() const
{
    return m_bitStart;
}

/**
 * Gets the bit length.
 * The bit length is the signal length.
 */
size_t CANSignalRule::getBitLength() const
{
    return m_bitLength;
}

/**
 * Returns true if the byte order is big endian.
 * Returns false of the byte order is little endian.
 */
bool CANSignalRule::byteOrderBigEndian() const
{
    return m_byteOrderBigEndian;
}

/**
 * Returns if the value type is unsigned.
 */
bool CANSignalRule::valueTypeUnsigned() const
{
    return m_valueTypeUnsigned;
}

/**
 * Gets the scale.
 * physical_value = offset + scale * raw_value_decimal
 */
float CANSignalRule::getScale() const
{
    return m_scale;
}

/**
 * Gets the offset.
 * physical_value = offset + scale * raw_value_decimal
 */
int CANSignalRule::getOffset() const
{
    return m_offset;
}

/**
 * Gets the minimum.
 */
int CANSignalRule::getMinimum() const
{
    return m_minimum;
}

/**
 * Gets the maximum.
 */
int CANSignalRule::getMaximum() const
{
    return m_maximum;
}

/**
 * Gets the unit.
 */
const std::string& CANSignalRule::getUnit() const
{
    return m_unit;
}

/**
 * Gets the transmitting node name.
 */
const std::string& CANSignalRule::getTransmittingNodeName() const
{
    return m_transmittingNodeName;
}

/**
 * Gets the string representation of this instance.
 */
std::string CANSignalRule::toString() const
{
    std::stringstream stream;

    stream << messageSyntax;
    stream << " ";
    stream << m_name;
    stream << " : ";
    stream << m_bitStart;
    stream << "|";
    stream << m_bitLength;
    stream << m_byteOrderBigEndian ? byteOrderBigEndianSyntax : byteOrderLittleEndianSyntax;
    stream << m_valueTypeUnsigned ? valueTypeUnsignedSyntax : valueTypeSignedSyntax;
    stream << " ";
    stream << "(";
    stream << m_scale;
    stream << ",";
    stream << m_offset;
    stream << ")";
    stream << " ";
    stream << "[";
    stream << m_minimum;
    stream << "|";
    stream << m_maximum;
    stream << "]";
    stream << " ";
    stream << base::Strings::wrapWithQuotes(m_unit);
    stream << " ";
    stream << m_transmittingNodeName;

    return stream.str();
}

/**
 * Writers the content of the rule.
 */
void CANSignalRule::writeRule(std::ostream& output) const
{
    std::string rule = toString();
    output << rule;
}
