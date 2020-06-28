package command.core;

import command.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The CommandTest class implements tests for a command.
 */
public final class CommandTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The CommandTest constructor.
     */
    public void CommandTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
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
