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
 * The ICANMessageRuleGenerator class implements a generator of CAN message rules.
 */
public final class CANMessageRuleGenerator extends CANRuleGenerator implements ICANRuleGenerator<ICANMessageRule> {
    private static final short MIN_LENGTH = 0;
    private static final short MAX_LENGTH = 1785;
    private static final int MIN_NUMBER_OF_SIGNAL_RULES = 1;
    private static final int MAX_NUMBER_OF_SIGNAL_RULES = 10;

    private final ICANRuleGenerator<ICANSignalRule> signalRuleGenerator = new CANSignalRuleGenerator();

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
        //
        // Generate a random message id...
        //
        ICANMessageId messageId = this.generateMessageId();

        //
        // Generate a message name...
        //
        ICANMessageName messageName = CANMessageName.make(name.toCharArray());

        //
        // Generate a random length...
        //
        short length = this.generateLength();

        //
        // Generate a random transmitting node...
        //
        String transmittingNodeName = this.generateTransmittingNodeName();

        //
        // Generate random signal rules...
        //
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
     * Generates a new length.
     */
    private short generateLength() {
        return (short)this.randomGenerator().nextInteger(MIN_LENGTH, MAX_LENGTH);
    }

    /**
     * Generates new signal rules.
     */
    private List<ICANSignalRule> generateSignalRules(String name) {
        int numberOfRules = this.randomGenerator().nextInteger(
                MIN_NUMBER_OF_SIGNAL_RULES,
                MAX_NUMBER_OF_SIGNAL_RULES);

        List<ICANSignalRule> rules = new ArrayList<>(numberOfRules);

        for (int i = 0; i < numberOfRules; ++i) {
            ICANSignalRule rule = this.signalRuleGenerator.generate(name);
            rules.add(rule);
        }

        return rules;
    }

    /**
     * Generates a new id.
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
