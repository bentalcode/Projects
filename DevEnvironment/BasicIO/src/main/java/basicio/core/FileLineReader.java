package basicio.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.interfaces.ICloseable;
import base.interfaces.IDestructorHandler;
import basicio.interfaces.ILineReverseReader;
import java.io.RandomAccessFile;
import java.nio.file.Path;

/**
 * The FileLineReader class implements a reader of lines of a file.
 */
public final class FileLineReader implements ILineReverseReader, ICloseable {
    private final RandomAccessFile randomAccessFile;
    private final IDestructorHandler destructorHandler = new DestructorHandler();
    private long position;
    private long length;
    private long lineIndex;
    private long currLineStartPosition;
    private long currLineEndPosition;

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
     * Gets the next line.
     */
    private String nextLine() {
        this.currLineStartPosition = RandomAccessFiles.getFilePointer(this.randomAccessFile);
        String line = RandomAccessFiles.readLine(this.randomAccessFile);
        this.currLineEndPosition = RandomAccessFiles.getFilePointer(this.randomAccessFile);

        this.position = this.currLineEndPosition;

        if (line != null) {
            ++this.lineIndex;
        }
        else {
            this.position = this.length;
            this.currLineStartPosition = -1;
            this.currLineEndPosition = -1;
        }

        return line;
    }

    /**
     * Resets the reader.
     */
    void reset() {
        this.position = 0;
        this.length = RandomAccessFiles.length(this.randomAccessFile);
        this.lineIndex = 0;
        this.currLineStartPosition = -1;
        this.currLineEndPosition = -1;
    }
}
