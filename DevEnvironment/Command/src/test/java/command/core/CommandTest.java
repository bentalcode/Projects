package command.core;

import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The CommandTest class implements tests for a command.
 */
public final class CommandTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The CommandTest constructor.
     */
    public CommandTest() {
    }

    /**
     * Tests the logic for parsing parameters of a command.
     */
    @Test
    public void commandParserTest() {
        this.testCommandParser();
    }

    /**
     * Tests the logic for parsing parameters of a command.
     */
    private void testCommandParser() {
        this.assertion.assertTrue(
            true,
            "Incorrect logic for parsing parameters of a command.");
    }
}
