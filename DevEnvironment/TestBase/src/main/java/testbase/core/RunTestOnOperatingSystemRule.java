package testbase.core;

import base.core.ArrayLists;
import base.core.Collections;
import base.core.Conditions;
import base.core.Environment;
import base.interfaces.OperatingSystemType;
import java.util.List;
import org.junit.AssumptionViolatedException;
import org.junit.rules.TestRule;
import org.junit.runner.Description;
import org.junit.runners.model.Statement;

/**
 * The RunTestOnOperatingSystemRule class implements a rule for running tests on the supported operating systems.
 */
public final class RunTestOnOperatingSystemRule implements TestRule {
    private final List<OperatingSystemType> operatingSystemTypes;

    /**
     * Creates a rule for running tests on unix.
     */
    public static TestRule runOnUnix() {
        return new RunTestOnOperatingSystemRule(
            ArrayLists.make(
                OperatingSystemType.Unix,
                OperatingSystemType.PosixUnix));
    }

    /**
     * Creates a rule for running tests on Windows.
     */
    public static TestRule runOnWindowsRule() {
        return new RunTestOnOperatingSystemRule(ArrayLists.make(OperatingSystemType.Windows));
    }

    /**
     * Creates a rule for running tests on Mac.
     */
    public static TestRule runOnMacRule() {
        return new RunTestOnOperatingSystemRule(ArrayLists.make(OperatingSystemType.Mac));
    }

    /**
     * The RunTestOnOperatingSystemRule constructor.
     */
    private RunTestOnOperatingSystemRule(List<OperatingSystemType> operatingSystemTypes) {
        Conditions.validateNotNull(
            operatingSystemTypes,
            "The supported operating systems.");

        this.operatingSystemTypes = operatingSystemTypes;
    }

    /**
     * Applies the rule statement.
     */
    @Override
    public Statement apply(Statement base, Description description) {
        return new OperatingSystemRule(base, this.operatingSystemTypes);
    }

    /**
     * The OperatingSystemRule class implements an operating system rule.
     */
    private static final class OperatingSystemRule extends Statement {
        private final Statement base;
        private final List<OperatingSystemType> operatingSystemTypes;

        /**
         * The OperatingSystemRule constructor.
         */
        private OperatingSystemRule(
            Statement base,
            List<OperatingSystemType> operatingSystemTypes) {

            this.base = base;
            this.operatingSystemTypes = operatingSystemTypes;
        }

        /**
         * Evaluates the rule.
         */
        @Override
        public void evaluate() throws Throwable {
            OperatingSystemType operatingSystemType = Environment.getOperatingSystem();

            if (!this.isOperatingSystemSupported(operatingSystemType)) {
                String errorMessage =
                    "This test can run only on operating systems: " + Collections.toString(this.operatingSystemTypes) +
                    "; Ignoring this test on: " + operatingSystemType + ".";

                throw new AssumptionViolatedException(errorMessage);
            }
            else {
                this.base.evaluate();
            }
        }

        /**
         * Determines whether the operating system is supported.
         */
        private boolean isOperatingSystemSupported(OperatingSystemType operatingSystemType) {
            for (OperatingSystemType supportedOperatingSystemType : this.operatingSystemTypes) {
                if (operatingSystemType == supportedOperatingSystemType) {
                    return true;
                }
            }

            return false;
        }
    }
}
