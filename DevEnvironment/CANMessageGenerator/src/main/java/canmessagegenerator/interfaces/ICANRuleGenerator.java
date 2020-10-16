package canmessagegenerator.interfaces;

/**
 * The ICANRuleGenerator interface defines a generator of a CAN rule.
 */
public interface ICANRuleGenerator<T> {
    /**
     * Generates a new rule.
     */
    T generate(String name);
}
