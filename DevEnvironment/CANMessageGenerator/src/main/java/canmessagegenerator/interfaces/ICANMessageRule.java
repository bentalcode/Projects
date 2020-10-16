package canmessagegenerator.interfaces;

import java.util.List;

/**
 * The ICANMessageRule interface defines a rule of a controller area network messages.
 *
 * BO_ 2364540158 EEC1: 8 Vector_XXX
 *
 * A message starts with BO_ and the ID must be unique and in decimal (not hexadecimal)
 * The DBC ID adds adds 3 extra bits for 29 bit CAN IDs to serve as an ‘extended ID’ flag
 * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores
 * The length (DLC) must be an integer between 0 and 1785
 * The sender is the name of the transmitting node, or Vector__XXX if no name is available
 */
public interface ICANMessageRule extends ICANRule {
    /**
     * Gets the identifier of the message.
     */
    ICANMessageId getId();

    /**
     * Gets the name of the message.
     */
    ICANMessageName getName();

    /**
     * The length (DLC) must be an integer between 0 and 1785.
     */
    int getLength();

    /**
     * Gets the name of the transmitting node.
     */
    String getTransmittingNodeName();

    /**
     * Gets the signal rules.
     */
    List<ICANSignalRule> getSignalRules();
}
