#include "PreCompiled.h"
#include "CANSignalRuleGenerator.h"
#include "CANSignalRule.h"
#include "CANMessageGeneratorException.h"
#include <cmath>

using namespace controllerareanetwork::messagegenerator;

const short CANSignalRuleGenerator::dataMinSizeInBits = 1;
const short CANSignalRuleGenerator::dataMaxSizeInBits = 1024;

const float CANSignalRuleGenerator::minPhysicalValue = 0.0;
const float CANSignalRuleGenerator::maxPhysicalValue = 1000000.0;

const size_t CANSignalRuleGenerator::maxRawValueSizeInBits = 32;

const int CANSignalRuleGenerator::minValue = 0;
const int CANSignalRuleGenerator::maxValue = 10;

/**
 * The CANSignalRuleGenerator constructor.
 */
CANSignalRuleGenerator::CANSignalRuleGenerator()
{
}

/**
 * The CANSignalRuleGenerator destructor.
 */
CANSignalRuleGenerator::~CANSignalRuleGenerator()
{
}

/**
 * Generates a new CAN signal rule.
 */
ICANSignalRulePtr CANSignalRuleGenerator::generate(const std::string& name)
{
    //
    // Generate a random data size...
    //
    size_t dataSizeInBits = generateDataSize(dataMinSizeInBits, dataMaxSizeInBits);

    //
    // Generate a random bit start and bit length...
    //
    std::pair<size_t, size_t> bitStartAndBitLength = generateBitStartAndBitLength(
        dataSizeInBits,
        maxRawValueSizeInBits);

    size_t bitStart = bitStartAndBitLength.first;
    size_t bitLength = bitStartAndBitLength.second;

    //
    // Generate whether the value type is unsigned...
    //
    bool valueTypeUnsigned = generateValueTypeUnsigned();

    //
    // Generate whether the byte order is big endian...
    //
    bool byteOrderBigEndian = generateByteOrderBigEndian();

    //
    // Generate a random physical value in the specified range...
    //
    float physicalValue = randomGenerator().nextFloat(minPhysicalValue, maxPhysicalValue);

    //
    // Generate a random scale and offset...
    //
    std::pair<float, size_t> scaleAndOffset = generateScaleAndOffset(
        physicalValue,
        valueTypeUnsigned,
        bitLength);

    float scale = scaleAndOffset.first;
    size_t offset = scaleAndOffset.second;

    //
    // Generate minimum and maximum values...
    //
    std::pair<int, int> minimumMaximumValues = generateMinimumMaximumValues(minValue, maxValue);

    int minimumValue = minimumMaximumValues.first;
    int maximumValue = minimumMaximumValues.second;

    std::string unit = generateUnit(name);
    std::string transmittingNodeName = generateTransmittingNodeName();

    return CANSignalRule::make(
        name,
        bitStart,
        bitLength,
        byteOrderBigEndian,
        valueTypeUnsigned,
        scale,
        offset,
        minimumValue,
        maximumValue,
        unit,
        transmittingNodeName);
}

/**
 * Generates the size of the data in bits.
 */
size_t CANSignalRuleGenerator::generateDataSize(
    size_t dataMinSizeInBits,
    size_t dataMaxSizeInBits)
{
    assert(dataMaxSizeInBits >= dataMinSizeInBits);

    size_t dataSize = randomGenerator().nextSizeT(dataMinSizeInBits, dataMaxSizeInBits);
    return dataSize;
}

/**
 * Generates a bit start and bit length for the relevant data.
 */
std::pair<size_t, size_t> CANSignalRuleGenerator::generateBitStartAndBitLength(
    size_t dataSizeInBits,
    size_t maxRawValueBitLength)
{
    size_t maxBitLength = std::min(dataSizeInBits, maxRawValueBitLength);

    size_t bitLength = randomGenerator().nextSizeT(1, maxBitLength);
    size_t remainderSize = dataSizeInBits - bitLength;

    size_t bitStart = 0;

    if (remainderSize > 0)
    {
        bitStart = randomGenerator().nextSizeT(0, remainderSize - 1);
    }

    return std::make_pair(bitStart, bitLength);
}

/**
 * Generates whether the byte order is big endian.
 */
bool CANSignalRuleGenerator::generateByteOrderBigEndian()
{
    bool byteOrderBigEndian = randomGenerator().nextBoolean();
    return byteOrderBigEndian;
}

/**
 * Generates whether the value type is unsigned.
 */
bool CANSignalRuleGenerator::generateValueTypeUnsigned()
{
    bool valueTypeUnsigned = randomGenerator().nextBoolean();
    return valueTypeUnsigned;
}

/**
 * Generates an offset and a scale for calculating the physical data.
 * physical_value = offset + scale * raw_value_decimal.
 */
std::pair<float, int> CANSignalRuleGenerator::generateScaleAndOffset(
    float physicalValue,
    bool valueTypeUnsigned,
    size_t bitLength)
{
    assert(bitLength <= sizeof(int) * 8);

    size_t valueBitLength = bitLength;

    //
    // Calculate the max raw value...
    //
    if (!valueTypeUnsigned && valueBitLength > 0) {
        --valueBitLength;
    }

    int minRawValue = 0;
    int maxRawValue = std::pow(2, valueBitLength);

    //
    // Generate a random raw value in the specified range...
    //
    int rawValue = randomGenerator().nextInteger(minRawValue, maxRawValue);

    //
    // Assume that the range of the offset is bounds by the integer section of the physical value...
    //
    int offsetMinValue = 0;
    int offsetMaxValue = static_cast<int>(physicalValue);

    //
    // Generate a random offset in the specified range...
    //
    int offset = randomGenerator().nextInteger(offsetMinValue, offsetMaxValue);

    //
    // Calculate the value of the scale since all the parameters in the linear equation are set:
    // physical_value = offset + scale * raw_value_decimal
    //
    float scale = (physicalValue - (float)offset) / (float)rawValue;

    return std::make_pair(scale, offset);
}

/**
 * Generates minimum maximum values.
 */
std::pair<int, int> CANSignalRuleGenerator::generateMinimumMaximumValues(int from, int to)
{
    int maximumValue = randomGenerator().nextInteger(from, to);
    int minimumValue = randomGenerator().nextInteger(from, maximumValue);

    return std::make_pair(minimumValue, maximumValue);
}

/**
 * Generates a unit.
 */
std::string CANSignalRuleGenerator::generateUnit(const std::string& name)
{
    static std::unique_ptr<NameUnitMap> nameUnitMap(createNameUnitsMap());
    return generateUnit(name, *nameUnitMap);
}

/**
 * Generates a unit.
 */
std::string CANSignalRuleGenerator::generateUnit(
    const std::string& name,
    const NameUnitMap& nameToUnitsMap)
{
    NameUnitMap::const_iterator nameUnitsIterator = nameToUnitsMap.find(name);

    if (nameUnitsIterator == nameToUnitsMap.end()) {
        std::string errorMessage = "The rule: " + name + " is not supported.";
        throw CANMessageGeneratorException(errorMessage);
    }

    const std::vector<std::string>& units = nameUnitsIterator->second;
    size_t numberOfUnits = units.size();
    size_t unitIndex = randomGenerator().nextSizeT(0, numberOfUnits - 1);
    const std::string& unit = units.at(unitIndex);

    return unit;
}

/**
 * Creates a name-units map.
 */
CANSignalRuleGenerator::NameUnitMap* CANSignalRuleGenerator::createNameUnitsMap()
{
    std::unique_ptr<NameUnitMap> result = std::make_unique<NameUnitMap>();

    result->insert(std::make_pair<std::string, std::vector<std::string>>("BRAKE_MODULE", {"XXX"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("BRAKE_PEDAL_PRESSED", {"NEO"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("ENGINE_COOLANT", {"C"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("ENGINE_COOLANT_TEMPERATURE", {"C", "F"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("ENGINE_SPEED", {"rpm"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("FL_WHEEL_SPEED", {"milliarcsecond", "milliarcminute"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("FR_WHEEL_SPEED", {"km/h"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("GPS_LATITUDE", {"milliarcsecond, milliarcminute"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("GAS_REGEN_CMD", {"NEO"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("HV_BATTERY_CURRENT", {"hvBatteryCurrent"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("HV_BATTERY_VOLTAGE", {"V"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("LATERAL_ACCELERATION", {"m/s2"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("ROLLING_COUNTER", {"NEO"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("GPS_LONGITUDE", {"NEO"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("STEERING_SPEED", {"degree/s"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("STEERING_WHEEL_ANGLE", {"deg"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("STEERING_WHEEL_RATE", {"deg/s"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("WHEEL_BASED_VEHICLE_SPEED", {"km/h", "m/h"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("WHEEL_SPEEDS", {"kph"}));
    result->insert(std::make_pair<std::string, std::vector<std::string>>("YAW_RATE", {"grad/s"}));

    return result.release();
}
