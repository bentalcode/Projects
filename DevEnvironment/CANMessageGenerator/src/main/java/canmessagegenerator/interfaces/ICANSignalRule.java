package canmessagegenerator.interfaces;

/**
 * The ICANSignalRule interface defines a rule of signals of a controller area network messages.
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
public interface ICANSignalRule extends ICANRule {
    /**
     * Gets the name of the signal.
     */
    String getName();

    /**
     * Gets the bit start.
     * The bit start counts from 0 and marks the start of the signal in the data payload.
     */
    int getBitStart();

    /**
     * Gets the bit length.
     * The bit length is the signal length.
     */
    int getBitLength();

    /**
     * Returns true if the byte order is big endian.
     * Returns false of the byte order is little endian.
     */
    boolean byteOrderBigEndian();

    /**
     * Returns if the value type is unsigned.
     */
    boolean valueTypeUnsigned();

    /**
     * Gets the scale.
     * physical_value = offset + scale * raw_value_decimal
     */
    double getScale();

    /**
     * Gets the offset.
     * physical_value = offset + scale * raw_value_decimal
     */
    int getOffset();

    /**
     * Gets the minimum.
     */
    int getMinimum();

    /**
     * Gets the maximum.
     */
    int getMaximum();

    /**
     * Gets the unit.
     */
    String getUnit();

    /**
     * Gets the transmitting node name.
     */
    String getTransmittingNodeName();
}
