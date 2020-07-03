package basicio.core;

import base.core.Files;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.core.ResourceReader;
import basicio.interfaces.ITestData;
import java.io.File;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The FileLineReaderTest class implements tests for reading lines from files.
 */
public final class FileLineReaderTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The FileLineReaderTest constructor.
     */
    public FileLineReaderTest() {
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
     * Tests the logic for reading lines from a file.
     */
    @Test
    public void readFileLinesTest() {
        for (Path path : this.testData.getFileFormatResourcePaths()) {
            String content = ResourceReader.loadString(path);
            File tempFile = Files.createTemporaryFile("testFile", ".txt", content);
            this.testReadFileLines(tempFile.toPath());
        }
    }

    /**
     * Tests the logic for reading lines from a file.
     */
    private void testReadFileLines(Path path) {
        List<String> lines = new ArrayList<>();

        try (FileLineReader reader = new FileLineReader(path)) {
            while (reader.hasNext()) {
                String line = reader.next();
                lines.add(line);
            }
        }

        List<String> linesInReverse = new ArrayList<>();

        try (FileLineReverseReader reader = new FileLineReverseReader(path)) {
            while (reader.hasNext()) {
                String line = reader.next();
                linesInReverse.add(line);
            }
        }

        this.assertion.assertEqualsWithIteratorAndReverseIterator(
            ListIterator.of(lines),
            ListReverseIterator.of(linesInReverse),
            "Incorrect logic for reading lines form a file.");
    }
}
