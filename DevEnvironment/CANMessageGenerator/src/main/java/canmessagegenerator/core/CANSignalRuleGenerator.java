package canmessagegenerator.core;

import base.core.ArrayLists;
import base.core.CaseInsensitiveStringComparator;
import base.core.Pair;
import base.interfaces.IPair;
import base.interfaces.IPrimitiveSize;
import canmessagegenerator.CANMessageGeneratorException;
import canmessagegenerator.interfaces.ICANMessageName;
import canmessagegenerator.interfaces.ICANRuleGenerator;
import canmessagegenerator.interfaces.ICANSignalRule;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

/**
 * The CANSignalRuleGenerator class implements a generator of CAN signal rules.
 */
public final class CANSignalRuleGenerator extends CANRuleGenerator implements ICANRuleGenerator<ICANSignalRule> {
    private static final int dataMinSizeInBits = 1;
    private static final int dataMaxSizeInBits = 1024;

    private static final double minPhysicalValue = 0.0;
    private static final double maxPhysicalValue = 1000000.0;

    private static final int maxRawValueSizeInBits = 32;

    private static final int minValue = 0;
    private static final int maxValue = 10;

    private static final Map<String, List<String>> nameUnitsMap = createNameUnitsMap();

    /**
     * The CANSignalRuleGenerator constructor.
     */
    public CANSignalRuleGenerator() {
    }

    /**
     * Generates a new CAN signal rule.
     */
    @Override
    public ICANSignalRule generate(String name) {
        //
        // Generate a message name...
        //
        ICANMessageName messageName = CANMessageName.make(name.toCharArray());

        //
        // Generate a random data size...
        //
        int dataSizeInBits = this.generateDataSize(dataMinSizeInBits, dataMaxSizeInBits);

        //
        // Generate a random bit start and bit length...
        //
        IPair<Integer, Integer> bitStartAndBitLength = this.generateBitStartAndBitLength(
            dataSizeInBits,
            maxRawValueSizeInBits);

        int bitStart = bitStartAndBitLength.first();
        int bitLength = bitStartAndBitLength.second();

        //
        // Generate whether the value type is unsigned...
        //
        boolean valueTypeUnsigned = this.generateValueTypeUnsigned();

        //
        // Generate whether the byte order is big endian...
        //
        boolean byteOrderBigEndian = this.generateByteOrderBigEndian();

        //
        // Generate a random physical value in the specified range...
        //
        double physicalValue = this.randomGenerator().nextDouble(minPhysicalValue, maxPhysicalValue);

        //
        // Generate a random scale and offset...
        //
        IPair<Double, Integer> scaleAndOffset = this.generateScaleAndOffset(
            physicalValue,
            valueTypeUnsigned,
            bitLength);

        double scale = scaleAndOffset.first();
        int offset = scaleAndOffset.second();

        //
        // Generate minimum and maximum values...
        //
        IPair<Integer, Integer> minimumMaximumValues = this.generateMinimumMaximumValues(minValue, maxValue);

        int minimumValue = minimumMaximumValues.first();
        int maximumValue = minimumMaximumValues.second();

        String unit = this.generateUnit(name, nameUnitsMap);
        String transmittingNodeName = this.generateTransmittingNodeName();

        return CANSignalRule.make(
            messageName,
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
     * Generates the size of the data.
     */
    private int generateDataSize(
        int dataMinSizeInBits,
        int dataMaxSizeInBits) {

        assert(dataMinSizeInBits >= 0);
        assert(dataMaxSizeInBits >= dataMinSizeInBits);

        return this.randomGenerator().nextInteger(dataMinSizeInBits, dataMaxSizeInBits);
    }

    /**
     * Generates a bit start and bit length for the relevant data.
     */
    private IPair<Integer, Integer> generateBitStartAndBitLength(
        int dataSizeInBits,
        int maxRawValueSizeInBits) {

        int maxBitLength = Math.min(dataSizeInBits, maxRawValueSizeInBits);

        int bitLength = this.randomGenerator().nextInteger(1, maxBitLength);
        int remainderSize = dataSizeInBits - bitLength;

        int bitStart = 0;

        if (remainderSize > 0) {
            bitStart = this.randomGenerator().nextInteger(0, remainderSize - 1);
        }

        return Pair.make(bitStart, bitLength);
    }

    /**
     * Generates whether the byte order is big endian.
     */
    private boolean generateByteOrderBigEndian() {
        return this.randomGenerator().nextBoolean();
    }

    /**
     * Generates whether the value type is unsigned.
     */
    private boolean generateValueTypeUnsigned() {
        return this.randomGenerator().nextBoolean();
    }

    /**
     * Generates an offset and a scale for calculating the physical data.
     * physical_value = offset + scale * raw_value_decimal.
     */
    private IPair<Double, Integer> generateScaleAndOffset(
        double physicalValue,
        boolean valueTypeUnsigned,
        int bitLength) {

        assert(bitLength <= IPrimitiveSize.InBits.IntegerSize);

        int valueBitLength = bitLength;

        //
        // Calculate the max raw value...
        //
        if (!valueTypeUnsigned && valueBitLength > 0) {
            --valueBitLength;
        }

        int minRawValue = 0;
        int maxRawValue = (valueBitLength >= 32) ? Integer.MAX_VALUE : (1 << valueBitLength) - 1;

        //
        // Generate a random raw value in the specified range...
        //
        int rawValue = this.randomGenerator().nextInteger(minRawValue, maxRawValue);

        //
        // Assume that the range of the offset is bounds by the integer section of the physical value...
        //
        int offsetMinValue = 0;
        int offsetMaxValue = (int)physicalValue;

        //
        // Generate a random offset in the specified range...
        //
        int offset = this.randomGenerator().nextInteger(offsetMinValue, offsetMaxValue);

        //
        // Calculate the value of the scale since all the parameters in the linear equation are set:
        // physical_value = offset + scale * raw_value_decimal
        //
        double scale = (physicalValue - (double)offset) / (double)rawValue;

        return Pair.make(scale, offset);
    }

    /**
     * Generates minimum maximum values.
     */
    private IPair<Integer, Integer> generateMinimumMaximumValues(int from, int to) {
        int maximumValue = this.randomGenerator().nextInteger(from, to);
        int minimumValue = this.randomGenerator().nextInteger(from, maximumValue);

        return Pair.make(minimumValue, maximumValue);
    }

    /**
     * Generates a unit.
     */
    private String generateUnit(
        String name,
        Map<String, List<String>> nameToUnitsMap) {

        if (!nameToUnitsMap.containsKey(name)) {
            String errorMessage = "The rule: " + name + " is not supported.";
            throw new CANMessageGeneratorException(errorMessage);
        }

        List<String> units = nameToUnitsMap.get(name);
        int numberOfUnits = units.size();
        int unitIndex = this.randomGenerator().nextInteger(0, numberOfUnits - 1);
        return units.get(unitIndex);
    }

    /**
     * Creates a name-units map.
     */
    private static Map<String, List<String>> createNameUnitsMap() {
        Map<String, List<String>> result = new TreeMap<>(new CaseInsensitiveStringComparator());

        result.put("BRAKE_MODULE", ArrayLists.make("XXX"));
        result.put("BRAKE_PEDAL_PRESSED", ArrayLists.make("NEO"));
        result.put("ENGINE_COOLANT", ArrayLists.make("C"));
        result.put("ENGINE_COOLANT_TEMPERATURE", ArrayLists.make("C", "F"));
        result.put("ENGINE_SPEED", ArrayLists.make("rpm"));
        result.put("FL_WHEEL_SPEED", ArrayLists.make("milliarcsecond", "milliarcminute"));
        result.put("FR_WHEEL_SPEED", ArrayLists.make("km/h"));
        result.put("GPS_LATITUDE", ArrayLists.make("milliarcsecond, milliarcminute"));
        result.put("GAS_REGEN_CMD", ArrayLists.make("NEO"));
        result.put("HV_BATTERY_CURRENT", ArrayLists.make("hvBatteryCurrent"));
        result.put("HV_BATTERY_VOLTAGE", ArrayLists.make("V"));
        result.put("LATERAL_ACCELERATION", ArrayLists.make("m/s2"));
        result.put("ROLLING_COUNTER", ArrayLists.make("NEO"));
        result.put("GPS_LONGITUDE", ArrayLists.make("NEO"));
        result.put("STEERING_SPEED", ArrayLists.make("degree/s"));
        result.put("STEERING_WHEEL_ANGLE", ArrayLists.make("deg"));
        result.put("STEERING_WHEEL_RATE", ArrayLists.make("deg/s"));
        result.put("WHEEL_BASED_VEHICLE_SPEED", ArrayLists.make("km/h", "m/h"));
        result.put("WHEEL_SPEEDS", ArrayLists.make("kph"));
        result.put("YAW_RATE", ArrayLists.make("grad/s"));

        return result;
    }
}
