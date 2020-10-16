package canmessagegenerator.core;

import base.core.Bits;
import canmessagegenerator.interfaces.ICANMessageId;
import canmessagegenerator.interfaces.ICANMessageName;
import canmessagegenerator.interfaces.ICANMessageRule;
import canmessagegenerator.interfaces.ICANRuleGenerator;
import canmessagegenerator.interfaces.ICANSignalRule;
import java.util.ArrayList;
import java.util.List;

/**
 * The ICANMessageRuleGenerator interface defines a generator of CAN message rules.
 */
public final class CANMessageRuleGenerator extends CANRuleGenerator implements ICANRuleGenerator<ICANMessageRule> {
    private static final int minLength = 0;
    private static final int maxLength = 1785;

    private static final int minNumberOfSignalRules = 1;
    private static final int maxNumberOfSignalRules = 10;

    private final ICANRuleGenerator<ICANSignalRule> signalRules = new CANSignalRuleGenerator();

    /**
     * The CANMessageRuleGenerator constructor.
     */
    public CANMessageRuleGenerator() {
    }

    /**
     * Generates a new CAN message rule.
     */
    @Override
    public ICANMessageRule generate(String name) {
        ICANMessageId messageId = this.generateMessageId();
        ICANMessageName messageName = CANMessageName.make(name.toCharArray());
        short length = this.generateLength();
        String transmittingNodeName = this.generateTransmittingNodeName();
        List<ICANSignalRule> signalRules = this.generateSignalRules(name);

        return CANMessageRule.make(
            messageId,
            messageName,
            length,
            transmittingNodeName,
            signalRules);
    }

    /**
     * Generates a message id.
     */
    private ICANMessageId generateMessageId() {
        int mainId = this.generateId(0, 28);
        int extendedId = this.generateId(29, 30);

        return CANMessageId.make(mainId, extendedId);
    }

    /**
     * Generates a length.
     */
    private short generateLength() {
        short length = (short)this.randomGenerator().nextInteger(minLength, maxLength);
        return length;
    }

    /**
     * Generates signal rules.
     */
    private List<ICANSignalRule> generateSignalRules(String name) {
        int numberOfRules = this.randomGenerator().nextInteger(
            minNumberOfSignalRules,
            maxNumberOfSignalRules);

        List<ICANSignalRule> rules = new ArrayList<>(numberOfRules);

        for (int i = 0; i < numberOfRules; ++i) {
            ICANSignalRule rule = this.signalRules.generate(name);
            rules.add(rule);
        }

        return rules;
    }

    /**
     * Generates an id.
     */
    private int generateId(int startBitIndex, int endBitEndIndex) {
        assert(startBitIndex <= endBitEndIndex);

        int id = 0;

        for (int bitIndex = startBitIndex; bitIndex <= endBitEndIndex; ++bitIndex) {
            int bitValue = this.randomGenerator().nextBoolean() ? 1 : 0;
            id = Bits.set(id, bitIndex, bitValue);
        }

        return id;
    }
}
