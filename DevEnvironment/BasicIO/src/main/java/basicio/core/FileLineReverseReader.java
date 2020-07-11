package basicio.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.interfaces.ICloseable;
import base.interfaces.IDestructorHandler;
import basicio.interfaces.ILineReverseReader;
import basicio.interfaces.LineSeparatorType;
import java.io.RandomAccessFile;
import java.nio.file.Path;

/**
 * The FileLineReverseReader class implements a reader of lines of a file in reverse.
 */
public final class FileLineReverseReader implements ILineReverseReader, ICloseable {
    private final RandomAccessFile randomAccessFile;
    private final IDestructorHandler destructorHandler = new DestructorHandler();
    private long length;
    private long position;
    private long lineIndex;
    private Character followingCharacter;
    private LineSeparatorType prevLineSeparator;
    private long currLineStartPosition;
    private long currLineEndPosition;
    private LineSeparatorType currLineSeparator;

    /**
     * The FileLineReverseReader constructor.
     */
    public FileLineReverseReader(Path path) {
        RandomAccessFile randomAccessFile = RandomAccessFiles.create(path, "r");
        this.destructorHandler.register(randomAccessFile);
        this.randomAccessFile = randomAccessFile;

        this.reset();
    }

    /**
     * The FileLineReverseReader constructor.
     */
    public FileLineReverseReader(RandomAccessFile randomAccessFile) {
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
        return this.position >= 0;
    }

    /**
     * Gets the next element.
     */
    @Override
    public String next() {
        assert(this.hasNext());

        String currLine = this.nextLine();

        return currLine;
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
     * Gets the separator current line.
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
        // Iterate over each character in reverse order until
        // reaching end of previous line or start of file...
        //
        while (this.position >= 0) {
            //
            // Read the current character...
            //
            char currCharacter;

            if (this.followingCharacter == null) {
                currCharacter = this.readCurrCharacter();
            }
            else {
                currCharacter = this.followingCharacter;
            }

            //
            // In case of a \n read the next one for having at least two characters
            // for detecting a separator...
            //
            char prevCharacter = 0;

            if (currCharacter == '\n' && this.position > 0) {
                this.nextCharacter();

                prevCharacter = currCharacter;
                currCharacter = this.readCurrCharacter();
            }

            //
            // Detect whether encountering a line separator...
            //
            LineSeparatorType lineSeparator = findLineSeparator(
                currCharacter,
                prevCharacter);

            if (lineSeparator != null) {
                ++this.lineIndex;

                long lineStartPosition = this.position + 2;
                long lineEndPosition;

                if (this.currLineStartPosition == -1) {
                    lineEndPosition = (lineStartPosition > this.length - 1) ?
                        lineStartPosition :
                        this.length - 1;
                }
                else {
                    lineEndPosition = this.currLineStartPosition - 1;
                }

                //
                // Get the content of the current line...
                //
                String line = this.processResultantLine(
                    lineBuilder,
                    lineStartPosition,
                    lineEndPosition,
                    this.prevLineSeparator);

                this.prevLineSeparator = lineSeparator;

                String separatorToken = lineSeparator.getToken();

                if (separatorToken.length() == 1) {
                    this.previousCharacter();
                    this.followingCharacter = currCharacter;
                }
                else {
                    this.followingCharacter = null;
                }

                //
                // Move to the next character.
                //
                this.nextCharacter();

                return line;
            }
            else {
                lineBuilder.append(currCharacter);
                this.followingCharacter = null;

                this.nextCharacter();
            }
        }

        long lineStartPosition = 0;
        long lineEndPosition = this.currLineStartPosition - 1;
        LineSeparatorType lineSeparator = this.prevLineSeparator;

        return this.processResultantLine(
            lineBuilder,
            lineStartPosition,
            lineEndPosition,
            lineSeparator);
    }

    /**
     * Processes the resultant line.
     */
    private String processResultantLine(
        StringBuilder lineBuilder,
        long lineStartPosition,
        long lineEndPosition,
        LineSeparatorType lineSeparator) {

        lineBuilder.reverse();
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
        --this.position;
    }

    /**
     * Moves to the previous character.
     */
    private void previousCharacter() {
        ++this.position;
    }

    /**
     * Resets the reader.
     */
    private void reset() {
        this.length = RandomAccessFiles.length(this.randomAccessFile);
        this.position = this.length - 1;
        this.lineIndex = 0;
        this.currLineStartPosition = -1;
        this.currLineEndPosition = -1;
        this.followingCharacter = null;
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
                if (token.charAt(0) == second) {
                    return separatorType;
                }
            }
        }

        return null;
    }
}
