package canmessagegenerator.interfaces;

import java.io.PrintWriter;

/**
 * The ICANRule interface defines a rule of a controller area network.
 */
public interface ICANRule {
    /**
     * Writers the content of the rule.
     */
    void writeRule(PrintWriter writer);
}
