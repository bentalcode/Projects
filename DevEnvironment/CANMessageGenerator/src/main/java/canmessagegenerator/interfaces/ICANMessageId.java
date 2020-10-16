package canmessagegenerator.interfaces;

/**
 * The ICANMessageId interface defines an id of a controller area network message.
 */
public interface ICANMessageId {
    /**
     * Gets the main id. Bits: {28, 27, 26, ... 0}.
     */
    int getMainId();

    /**
     * Gets the extended id. Bits: {31, 30, 29}.
     */
    int getExtendedId();

    /**
     * Gets the id.
     */
    int getId();
}
