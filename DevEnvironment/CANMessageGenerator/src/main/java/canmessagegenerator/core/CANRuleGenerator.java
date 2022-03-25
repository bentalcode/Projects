package canmessagegenerator.core;

import base.core.RandomGenerator;
import base.interfaces.IRandomGenerator;
import java.util.ArrayList;
import java.util.List;

/**
 * The CANSignalRuleGenerator class implements a generator of CAN signal rules.
 */
public abstract class CANRuleGenerator {
    private static final String DEFAULT_NODE_NAME = "Vector__XXX";
    private static final String NODE_NAME_PREFIX = "Node";
    private static final int NUMBER_OF_NODES = 100;
    private static final List<String> transmittingNodeNames = createTransmittingNodeNames();

    private final IRandomGenerator randomGenerator = new RandomGenerator();

    /**
     * The CANRuleGenerator constructor.
     */
    protected CANRuleGenerator() {
    }

    /**
     * Generates a random generator.
     */
    protected IRandomGenerator randomGenerator() {
        return this.randomGenerator;
    }

    /**
     * Generates a new transmitting node name.
     */
    protected String generateTransmittingNodeName() {
        return this.generateTransmittingNodeName(transmittingNodeNames);
    }

    /**
     * Generates a new transmitting node name.
     */
    private String generateTransmittingNodeName(List<String> transmittingNodeNames) {
        int numberOfNames = transmittingNodeNames.size();
        int nameIndex = this.randomGenerator.nextInteger(0, numberOfNames - 1);

        String name = transmittingNodeNames.get(nameIndex);

        return name;
    }

    /**
     * Creates the transmitting node names.
     */
    private static List<String> createTransmittingNodeNames() {
        List<String> result = new ArrayList<>();
        result.add(DEFAULT_NODE_NAME);

        for (int i = 0; i < NUMBER_OF_NODES; ++i) {
            String nodeName = NODE_NAME_PREFIX + i;
            result.add(nodeName);
        }

        return result;
    }
}
