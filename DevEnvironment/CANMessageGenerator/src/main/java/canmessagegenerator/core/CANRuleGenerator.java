package canmessagegenerator.core;

import base.core.RandomGenerator;
import base.interfaces.IRandomGenerator;
import java.util.ArrayList;
import java.util.List;

/**
 * The CANSignalRuleGenerator class implements a generator of CAN signal rules.
 */
public abstract class CANRuleGenerator {
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
     * Generates a transmitting node name.
     */
    protected String generateTransmittingNodeName() {
        return this.generateTransmittingNodeName(transmittingNodeNames);
    }

    /**
     * Generates a transmitting node name.
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
        result.add("Vector__XXX");

        for (int i = 0; i < 100; ++i) {
            String nodeName = "Node" + i;
            result.add(nodeName);
        }

        return result;
    }
}
