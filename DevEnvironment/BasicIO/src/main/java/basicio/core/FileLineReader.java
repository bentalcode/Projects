package basicio.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.interfaces.ICloseable;
import base.interfaces.IDestructorHandler;
import basicio.interfaces.ILineReader;
import basicio.interfaces.LineSeparatorType;
import java.io.RandomAccessFile;
import java.nio.file.Path;

/**
 * The FileLineReader class implements a reader of lines of a file.
 */
public final class FileLineReader implements ILineReader, ICloseable {
    private final RandomAccessFile randomAccessFile;
    private final IDestructorHandler destructorHandler = new DestructorHandler();
    private long length;
    private long position;
    private long lineIndex;
    private long currLineStartPosition;
    private long currLineEndPosition;
    private LineSeparatorType currLineSeparator;

    /**
     * The FileLineReader constructor.
     */
    public FileLineReader(Path path) {
        RandomAccessFile randomAccessFile = RandomAccessFiles.create(path, "r");
        this.destructorHandler.register(randomAccessFile);
        this.randomAccessFile = randomAccessFile;

        this.reset();
    }

    /**
     * The FileLineReader constructor.
     */
    public FileLineReader(RandomAccessFile randomAccessFile) {
        Conditions.validateNotNull(
            randomAccessFile,
            "The random access file.");

        this.randomAccessFile = randomAccessFile;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.position < this.length;
    }

    /**
     * Gets the next element.
     */
    @Override
    public String next() {
        assert(this.hasNext());
        return this.nextLine();
    }

    /**
     * Gets the number of current line.
     */
    @Override
    public long currentLineNumber() {
        return this.lineIndex;
    }

    /**
     * Gets the start position of current line.
     */
    @Override
    public long currentLineStartPosition() {
        return this.currLineStartPosition;
    }

    /**
     * Gets the end position of current line.
     */
    @Override
    public long currentLineEndPosition() {
        return this.currLineEndPosition;
    }

    /**
     * Gets the separator of current line.
     */
    @Override
    public LineSeparatorType currentLineSeparator() {
        return this.currLineSeparator;
    }

    /**
     * Closes this resource gracefully.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }

    /**
     * Reads the next line.
     */
    private String nextLine() {
        StringBuilder lineBuilder = new StringBuilder();

        //
        // Iterate over each character until reaching end of current line or end of file...
        //
        while (this.position < this.length) {
            //
            // Read the current character...
            //
            char currCharacter = this.readCurrCharacter();

            //
            // In case of a \r or a \n read the next one for having at least two characters
            // for detecting a separator...
            //
            char prevCharacter = 0;
            if ((currCharacter == '\r' || currCharacter == '\n') && this.position < this.length - 1) {
                this.nextCharacter();

                prevCharacter = currCharacter;
                currCharacter = this.readCurrCharacter();
            }

            //
            // Detect whether encountering a line separator...
            //
            LineSeparatorType lineSeparator = findLineSeparator(
                prevCharacter,
                currCharacter);

            if (lineSeparator != null) {
                ++this.lineIndex;

                String separatorToken = lineSeparator.getToken();

                long lineStartPosition = (this.currLineEndPosition == -1) ? 0 : this.currLineEndPosition + 1;
                long lineEndPosition = this.position - 2 + separatorToken.length();

                if (separatorToken.length() == 1) {
                    this.previousCharacter();
                }

                //
                // Get the content of the current line...
                //
                String line = this.processResultantLine(
                    lineBuilder,
                    lineStartPosition,
                    lineEndPosition,
                    lineSeparator);

                //
                // Move to the next character.
                //
                this.nextCharacter();

                return line;
            }
            else {
                lineBuilder.append(currCharacter);

                this.nextCharacter();
            }
        }

        long lineStartPosition = this.currLineEndPosition + 1;
        long lineEndPosition = this.position - 1;

        return this.processResultantLine(
            lineBuilder,
            lineStartPosition,
            lineEndPosition,
            null);
    }

    /**
     * Processes the resultant line.
     */
    private String processResultantLine(
        StringBuilder lineBuilder,
        long lineStartPosition,
        long lineEndPosition,
        LineSeparatorType lineSeparator) {

        String line = lineBuilder.toString();

        this.currLineStartPosition = lineStartPosition;
        this.currLineEndPosition = lineEndPosition;
        this.currLineSeparator = lineSeparator;

        return line;
    }

    /**
     * Moves to the next character.
     */
    private void nextCharacter() {
        ++this.position;
    }

    /**
     * Moves to the previous character.
     */
    private void previousCharacter() {
        --this.position;
    }

    /**
     * Resets the reader.
     */
    private void reset() {
        this.length = RandomAccessFiles.length(this.randomAccessFile);
        this.position = 0;
        this.lineIndex = 0;
        this.currLineStartPosition = -1;
        this.currLineEndPosition = -1;
    }

    /**
     * Reads the current character.
     */
    private char readCurrCharacter() {
        RandomAccessFiles.seek(this.randomAccessFile, this.position);
        return (char)RandomAccessFiles.readByte(this.randomAccessFile);
    }

    /**
     * Finds the corresponding line separator.
     * Returns null of no line separator is matching.
     */
    public static LineSeparatorType findLineSeparator(char first, char second) {
        for (LineSeparatorType separatorType : LineSeparatorType.values()) {
            String token = separatorType.getToken();

            if (token.length() == 2 && token.charAt(0) == first && token.charAt(1) == second) {
                return separatorType;
            }
            else if (token.length() == 1) {
                if (token.charAt(0) == first) {
                    return separatorType;
                }
            }
        }

        return null;
    }
}
