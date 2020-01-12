package clientserver.core;

import base.core.Casting;
import base.core.ResourceReader;
import base.interfaces.IPair;
import clientserver.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.interfaces.IJsonStreamingTest;
import java.nio.file.Path;

/**
 * The JsonStreamingTest class implements tests for json streaming.
 */
public final class JsonStreamingTest {
    private final ITestData testData = new TestData();

    /**
     * The JsonStreamingTest constructor.
     */
    public JsonStreamingTest() {
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
     * Tests the json streaming.
     */
    @Test
    public void testJsonStreaming() {
        IJsonStreamingTest test = new testbase.core.JsonStreamingTest();

        for (IPair<Path, Class<?>> resourceInformation : this.testData.getJsonResourcesInformation()) {
            String json = ResourceReader.loadString(resourceInformation.first());

            test.testStreaming(json, Casting.cast(resourceInformation.second()));
        }
    }
}
