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
    private long lineStartPosition;
    private long lineEndPosition;
    private long currLineStartPosition;
    private long currLineEndPosition;
    private char followingCharacter;
    private StringBuilder lineBuilder;

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
        String line;

        //
        // Iterate over each character in the file in reverse order
        // until reaching end of previous line or start of file...
        //
        while (this.position >= 0) {
            //
            // Read the current character...
            //
            RandomAccessFiles.seek(this.randomAccessFile, this.position);
            char currCharacter = (char)RandomAccessFiles.readByte(this.randomAccessFile);

            //
            // In case of a \n read the next one for having at least two characters
            // for detecting a separator...
            //
            if (currCharacter == '\n' && this.position > 0) {
                this.nextCharacter();
                RandomAccessFiles.seek(this.randomAccessFile, this.position);

                this.followingCharacter = currCharacter;
                currCharacter = (char)RandomAccessFiles.readByte(this.randomAccessFile);
            }

            //
            // Detect whether encountering a line separator...
            //
            LineSeparatorType lineSeparatorType = LineSeparatorType.findLineSeparator(
                currCharacter,
                this.followingCharacter);

            if (lineSeparatorType != null) {
                ++this.lineIndex;

                this.lineStartPosition = this.position + 2;

                if (this.lineEndPosition == -1) {
                    this.lineEndPosition = (this.lineStartPosition > this.length - 1) ?
                        this.lineStartPosition :
                        this.length - 1;
                }

                String separatorToken = lineSeparatorType.getToken();

                //
                // Get the content of the current line...
                //
                line = this.processResultantLine(this.lineStartPosition, this.lineEndPosition);

                if (separatorToken.length() == 1) {
                    this.previousCharacter();
                    this.lineEndPosition = this.position;
                }
                else {
                    this.lineEndPosition = this.position - 1 + separatorToken.length();
                }

                //
                // Invalidate the second character of a line separator...
                //
                this.followingCharacter = 0;

                //
                // Move to the next character.
                //
                this.nextCharacter();

                return line;
            }
            else {
                this.lineBuilder.append(currCharacter);
                this.followingCharacter = currCharacter;

                this.nextCharacter();
            }
        }

        return this.processResultantLine(0, this.lineEndPosition);
    }

    /**
     * Processes the resultant line.
     */
    private String processResultantLine(long lineStartPosition, long lineEndPosition) {
        this.lineBuilder.reverse();
        String line = this.lineBuilder.toString();
        this.lineBuilder = new StringBuilder();

        this.currLineStartPosition = lineStartPosition;
        this.currLineEndPosition = lineEndPosition;

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
     * Reset the reader.
     */
    private void reset() {
        this.length = RandomAccessFiles.length(this.randomAccessFile);
        this.position = this.length - 1;
        this.lineIndex = 0;
        this.lineStartPosition = -1;
        this.lineEndPosition = -1;
        this.currLineStartPosition = -1;
        this.currLineEndPosition = -1;
        this.followingCharacter = 0;
        this.lineBuilder = new StringBuilder();
    }
}
