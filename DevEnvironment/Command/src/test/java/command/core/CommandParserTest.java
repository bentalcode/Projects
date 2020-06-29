package command.core;

import base.interfaces.IParser;
import command.interfaces.ICommandData;
import command.interfaces.ICommandManifest;
import command.interfaces.ICommandParameters;
import base.interfaces.IParsingResult;
import command.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The CommandParserTest class implements tests for a command parser.
 */
public final class CommandParserTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The CommandParserTest constructor.
     */
    public void CommandParserTest() {
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
        for (ICommandData data : this.testData.getCommandsData()) {
            ICommandManifest manifest = CommandManifest.load(data.getManifestResourcePath());

            for (String commandLine : data.getCommandlineStrings()) {
                this.testCommandParser(manifest, commandLine);
            }
        }
    }

    /**
     * Tests the logic for parsing parameters of a command.
     */
    private void testCommandParser(ICommandManifest manifest, String commandline) {
        String[] arguments = commandline.split(" ");

        IParser<String[], ICommandParameters> commandParser = new CommandParser(manifest);
        IParsingResult<ICommandParameters> result = commandParser.parse(arguments);

        this.assertion.assertTrue(
            result.succeeded(),
            "Incorrect logic of parsing a command.");
    }
}
