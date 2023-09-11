package basicio.core;

import base.core.ResourceReader;
import basicio.interfaces.ILineReader;
import basicio.interfaces.ITestData;
import java.nio.file.Path;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The LineReaderTest class implements tests for reading lines.
 */
public final class LineReaderTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The LineReaderTest constructor.
     */
    public LineReaderTest() {
    }

    /**
     * Tests the logic for reading lines.
     */
    @Test
    public void readLinesTest() {
        for (Path path : this.testData.getFileFormatResourcePaths()) {
            String content = ResourceReader.loadString(path);
            this.testReadLines(content);
        }
    }

    /**
     * Tests the logic for reading lines.
     */
    private void testReadLines(String content) {
        ILineReader reader = LineReader.createStringLineReader(content);

        int numberOfLines = 0;

        while (reader.hasNext()) {
            String line = reader.next();
            ++numberOfLines;
        }
    }
}
