package canmessagegenerator.core;

import base.core.Conditions;
import canmessagegenerator.interfaces.ICANMessageRule;
import canmessagegenerator.interfaces.ICANMessageId;
import canmessagegenerator.interfaces.ICANMessageName;
import canmessagegenerator.interfaces.ICANSignalRule;
import java.io.PrintWriter;
import java.util.List;

/**
 * The CANMessage class implements a message of a controller area network.
 */
public final class CANMessageRule implements ICANMessageRule {
    private static final String messageSyntax = "BO_";
    private static final int minimumDataLength = 0;
    private static final int maximumDataLength = 1785;
    private static final String defaultTransmittingNodeName = "Vector__XXX";

    private final ICANMessageId id;
    private final ICANMessageName name;
    private final int length;
    private final String transmittingNodeName;
    private final List<ICANSignalRule> signalRules;

    /**
     * The CANMessage constructor.
     */
    public CANMessageRule(
        ICANMessageId id,
        ICANMessageName name,
        int length,
        String transmittingNodeName,
        List<ICANSignalRule> signalRules) {

        Conditions.validateNotNull(
            id,
            "The id of the message.");

        Conditions.validateNotNull(
            name,
            "The name of the message.");

        Conditions.validateNotNull(
            length >= minimumDataLength && length <=  maximumDataLength,
            "The length of the data.");

        Conditions.validate(
            signalRules.size() >= 1,
            "The signal rules.");

        this.id = id;
        this.name = name;
        this.length = length;
        this.transmittingNodeName = transmittingNodeName != null ? transmittingNodeName : defaultTransmittingNodeName;
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
    public int getLength() {
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

        String messageRule = toString();
        writer.println(messageRule);

        for (ICANSignalRule signalRule : this.signalRules) {
            writer.print("/t");
            signalRule.writeRule(writer);
        }
    }
}
