package canmessagegenerator.core;

import base.core.Conditions;
import canmessagegenerator.interfaces.ICANMessageRule;
import canmessagegenerator.interfaces.ICANMessageId;
import canmessagegenerator.interfaces.ICANMessageName;
import canmessagegenerator.interfaces.ICANSignalRule;
import java.io.PrintWriter;
import java.util.List;

/**
 * The CANMessageRule class implements a rule of a controller area network messages.
 *
 * BO_ 2364540158 EEC1: 8 Vector_XXX
 *
 * A message starts with BO_ and the ID must be unique and in decimal (not hexadecimal)
 * The DBC ID adds adds 3 extra bits for 29 bit CAN IDs to serve as an ‘extended ID’ flag
 * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores
 * The length (DLC) must be an integer between 0 and 1785
 * The sender is the name of the transmitting node, or Vector__XXX if no name is available
 */
public final class CANMessageRule implements ICANMessageRule {
    private static final String messageSyntax = "BO_";
    private static final int minimumDataLength = 0;
    private static final int maximumDataLength = 1785;

    private final ICANMessageId id;
    private final ICANMessageName name;
    private final short length;
    private final String transmittingNodeName;
    private final List<ICANSignalRule> signalRules;

    /**
     * Creates a new rule.
     */
    public static ICANMessageRule make(
        ICANMessageId id,
        ICANMessageName name,
        short length,
        String transmittingNodeName,
        List<ICANSignalRule> signalRules) {

        return new CANMessageRule(
            id,
            name,
            length,
            transmittingNodeName,
            signalRules);
    }

    /**
     * The CANMessage constructor.
     */
    private CANMessageRule(
        ICANMessageId id,
        ICANMessageName name,
        short length,
        String transmittingNodeName,
        List<ICANSignalRule> signalRules) {

        Conditions.validateNotNull(
            id,
            "The id of the message is not defined.");

        Conditions.validateNotNull(
            name,
            "The name of the message is not defined.");

        Conditions.validateNotNull(
            length >= minimumDataLength && length <=  maximumDataLength,
            "The length of the data is out of range.");

        Conditions.validate(
            !signalRules.isEmpty(),
            "The signal rules are not defined.");

        this.id = id;
        this.name = name;
        this.length = length;
        this.transmittingNodeName = transmittingNodeName;
        this.signalRules = signalRules;
    }

    /**
     * Gets the identifier of the message.
     */
    @Override
    public ICANMessageId getId() {
        return this.id;
    }

    /**
     * Gets the name of the message.
     */
    @Override
    public ICANMessageName getName() {
        return this.name;
    }

    /**
     * The length (DLC) must be an integer between 0 and 1785.
     */
    @Override
    public short getLength() {
        return this.length;
    }

    /**
     * Gets the name of the transmitting node.
     */
    @Override
    public String getTransmittingNodeName() {
        return this.transmittingNodeName;
    }

    /**
     * Gets the signal rules.
     */
    @Override
    public List<ICANSignalRule> getSignalRules() {
        return this.signalRules;
    }

    @Override
    public String toString() {
        StringBuilder messageBuilder = new StringBuilder();
        messageBuilder.append(messageSyntax);
        messageBuilder.append(" ");
        messageBuilder.append(this.id);
        messageBuilder.append(" ");
        messageBuilder.append(this.name);
        messageBuilder.append(": ");
        messageBuilder.append(this.length);
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

        String ruleString = toString();
        writer.println(ruleString);

        for (ICANSignalRule signalRule : this.signalRules) {
            writer.print("/t");
            signalRule.writeRule(writer);
        }
    }
}
