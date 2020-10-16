package canmessagegenerator.interfaces;

/**
 * The ICANMessageName interface defines a name of a message of a controller area network.
 */
public interface ICANMessageName {
    /**
     * Gets the name of a CAN message.
     * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores.
     */
    char[] getName();
}
