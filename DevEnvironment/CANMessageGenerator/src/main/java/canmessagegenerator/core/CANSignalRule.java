package canmessagegenerator.core;

import base.core.Conditions;
import base.core.Strings;
import canmessagegenerator.interfaces.ICANSignalRule;
import java.io.PrintWriter;

/**
 * The CANSignalRule class implements a rule of signals of a controller area network messages.
 *
 * SG_ EngineSpeed : 24|16@1+ (0.125,0) [0|8031.875] "rpm" Vector_XXX
 *
 * Each message contains 1+ signals that start with SG_
 * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores
 * The bit start counts from 0 and marks the start of the signal in the data payload
 * The bit length is the signal length
 * The @1 specifies that the byte order is little-endian/Intel (vs @0 for big-endian/Motorola)
 * The + informs that the value type is unsigned (vs - for signed signals)
 * The (scale,offset) values are used in the physical value linear equation (more below)
 * The [min|max and unit are optional meta information (they can be set to [0|0| or "")
 * The receiver is the name of the receiving node (again, Vector__XXX is used as default)
 */
public final class CANSignalRule implements ICANSignalRule {
    private static final String messageSyntax = "SG_";
    private static final String byteOrderBigEndianSyntax = "@0";
    private static final String byteOrderLittleEndianSyntax = "@1";
    private static final String valueTypeUnsignedSyntax = "+";
    private static final String valueTypeSignedSyntax = "-";

    private final String name;
    private final int bitStart;
    private final int bitLength;
    private final boolean byteOrderBigEndian;
    private final boolean valueTypeUnsigned;
    private final double scale;
    private final int offset;
    private final int minimum;
    private final int maximum;
    private final String unit;
    private final String transmittingNodeName;

    /**
     * Creates a new rule.
     */
    public static ICANSignalRule make(
        String name,
        int bitStart,
        int bitLength,
        boolean byteOrderBigEndian,
        boolean valueTypeUnsigned,
        double scale,
        int offset,
        int minimum,
        int maximum,
        String unit,
        String transmittingNodeName) {

        return new CANSignalRule(
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
    private CANSignalRule(
        String name,
        int bitStart,
        int bitLength,
        boolean byteOrderBigEndian,
        boolean valueTypeUnsigned,
        double scale,
        int offset,
        int minimum,
        int maximum,
        String unit,
        String transmittingNodeName) {

        Conditions.validate(
            bitStart >= 0,
            "The bit start can not be a negative number.");

        Conditions.validate(
            bitLength >= 0,
            "The bit length can not be a negative number.");

        Conditions.validate(
            maximum >= minimum,
            "The maximum can not be less than the minimum.");

        this.name = name;
        this.bitStart = bitStart;
        this.bitLength = bitLength;
        this.byteOrderBigEndian = byteOrderBigEndian;
        this.valueTypeUnsigned = valueTypeUnsigned;
        this.scale = scale;
        this.offset = offset;
        this.minimum = minimum;
        this.maximum = maximum;
        this.unit = unit;
        this.transmittingNodeName = transmittingNodeName;
    }

    /**
     * Gets the name of the signal.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets the bit start.
     * The bit start counts from 0 and marks the start of the signal in the data payload.
     */
    @Override
    public int getBitStart() {
        return this.bitStart;
    }

    /**
     * Gets the bit length.
     * The bit length is the signal length.
     */
    @Override
    public int getBitLength() {
        return this.bitLength;
    }

    /**
     * Returns true if the byte order is big endian.
     * Returns false of the byte order is little endian.
     */
    @Override
    public boolean byteOrderBigEndian() {
        return this.byteOrderBigEndian;
    }

    /**
     * Returns if the value type is unsigned.
     */
    @Override
    public boolean valueTypeUnsigned() {
        return this.valueTypeUnsigned;
    }

    /**
     * Gets the scale.
     * physical_value = offset + scale * raw_value_decimal
     */
    @Override
    public double getScale() {
        return this.scale;
    }

    /**
     * Gets the offset.
     * physical_value = offset + scale * raw_value_decimal
     */
    @Override
    public int getOffset() {
        return this.offset;
    }

    /**
     * Gets the minimum.
     */
    @Override
    public int getMinimum() {
        return this.minimum;
    }

    /**
     * Gets the maximum.
     */
    @Override
    public int getMaximum() {
        return this.maximum;
    }

    /**
     * Gets the unit.
     */
    @Override
    public String getUnit() {
        return this.unit;
    }

    /**
     * Gets the transmitting node name.
     */
    @Override
    public String getTransmittingNodeName() {
        return this.transmittingNodeName;
    }

    /**
     * Gets the string representation of the rule.
     */
    @Override
    public String toString() {
        StringBuilder messageBuilder = new StringBuilder();

        messageBuilder.append(messageSyntax);
        messageBuilder.append(" ");
        messageBuilder.append(this.name);
        messageBuilder.append(" : ");
        messageBuilder.append(this.bitStart);
        messageBuilder.append("|");
        messageBuilder.append(this.bitLength);
        messageBuilder.append(this.byteOrderBigEndian ? byteOrderBigEndianSyntax : byteOrderLittleEndianSyntax);
        messageBuilder.append(this.valueTypeUnsigned ? valueTypeUnsignedSyntax : valueTypeSignedSyntax);
        messageBuilder.append(" ");
        messageBuilder.append("(");
        messageBuilder.append(this.scale);
        messageBuilder.append(",");
        messageBuilder.append(this.offset);
        messageBuilder.append(")");
        messageBuilder.append(" ");
        messageBuilder.append("[");
        messageBuilder.append(this.minimum);
        messageBuilder.append("|");
        messageBuilder.append(this.maximum);
        messageBuilder.append("]");
        messageBuilder.append(" ");
        messageBuilder.append(Strings.wrapWithQuotes(this.unit));
        messageBuilder.append(" ");
        messageBuilder.append(this.transmittingNodeName);

        return messageBuilder.toString();
    }

    /**
     * Writers the content of the rule.
     */
    @Override
    public void writeRule(PrintWriter writer) {
        Conditions.validateNotNull(
            writer,
            "The writer for writing the rule.");

        String rule = toString();
        writer.println(rule);
    }
}
