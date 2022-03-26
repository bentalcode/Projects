package basicio.core;

import base.core.Doublet;
import base.core.Files;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.core.ResourceReader;
import base.interfaces.IDoublet;
import basicio.interfaces.ITestData;
import basicio.interfaces.LineSeparatorType;
import java.io.File;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
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
        List<IDoublet<Long, Long>> linesPositions = new ArrayList<>();
        List<LineSeparatorType> linesSeparators = new ArrayList<>();

        try (FileLineReader reader = new FileLineReader(path)) {
            while (reader.hasNext()) {
                String line = reader.next();
                long lineStartIndex = reader.currentLineStartPosition();
                long lineEndIndex = reader.currentLineEndPosition();
                LineSeparatorType lineSeparator = reader.currentLineSeparator();

                lines.add(line);
                linesPositions.add(Doublet.make(lineStartIndex, lineEndIndex));
                linesSeparators.add(lineSeparator);
            }
        }

        List<String> reverseLines = new ArrayList<>();
        List<IDoublet<Long, Long>> reverseLinesPositions = new ArrayList<>();
        List<LineSeparatorType> reverseLinesSeparators = new ArrayList<>();

        try (FileLineReverseReader reader = new FileLineReverseReader(path)) {
            while (reader.hasNext()) {
                String line = reader.next();
                long lineStartIndex = reader.currentLineStartPosition();
                long lineEndIndex = reader.currentLineEndPosition();
                LineSeparatorType lineSeparator = reader.currentLineSeparator();

                reverseLines.add(line);
                reverseLinesPositions.add(Doublet.make(lineStartIndex, lineEndIndex));
                reverseLinesSeparators.add(lineSeparator);
            }
        }

        this.assertion.assertEqualsWithIteratorAndReverseIterator(
            ListIterator.make(lines),
            ListReverseIterator.make(reverseLines),
            "Incorrect logic for reading lines from a file.");

        this.assertion.assertEqualsWithIteratorAndReverseIterator(
            ListIterator.make(linesPositions),
            ListReverseIterator.make(reverseLinesPositions),
            "Incorrect logic for reading lines positions from a file.");

        this.assertion.assertEqualsWithIteratorAndReverseIterator(
            ListIterator.make(linesSeparators),
            ListReverseIterator.make(reverseLinesSeparators),
            "Incorrect logic for reading lines separators from a file.");
    }
}
