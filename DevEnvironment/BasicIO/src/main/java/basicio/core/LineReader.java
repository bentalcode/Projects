package basicio.core;

import base.core.DestructorHandler;
import base.core.Scanners;
import base.interfaces.ICloseable;
import base.interfaces.IDestructorHandler;
import basicio.interfaces.ILineReader;
import basicio.interfaces.LineSeparatorType;
import java.nio.file.Path;
import java.util.Scanner;

/**
 * The LineReader class implements a reader of lines.
 */
public final class LineReader implements ILineReader, ICloseable {
    private final Scanner scanner;
    private final IDestructorHandler destructorHandler = new DestructorHandler();
    private long lineNumber;
    private long currLineStartPosition = -1;
    private long currLineEndPosition = -1;

    /**
     * Creates a file line reader.
     */
    public static LineReader createFileLineReader(Path path) {
        return new LineReader(path);
    }

    /**
     * Creates a string line reader.
     */
    public static LineReader createStringLineReader(String str) {
        return new LineReader(str);
    }

    /**
     * The LineReader constructor from a file path.
     */
    private LineReader(Path path) {
        Scanner scanner = Scanners.createFileScanner(path);
        this.destructorHandler.register(scanner);
        this.scanner = scanner;
    }

    /**
     * The LineReader constructor from a string.
     */
    private LineReader(String str) {
        Scanner scanner = Scanners.createStringScanner(str);
        this.destructorHandler.register(scanner);
        this.scanner = scanner;
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.scanner.hasNextLine();
    }

    /**
     * Gets the next element.
     */
    @Override
    public String next() {
        assert(this.hasNext());

        if (this.currLineStartPosition == -1) {
            this.currLineStartPosition = 0;
        }

        String currLine = this.scanner.nextLine();
        ++this.lineNumber;

        this.currLineEndPosition = this.currLineStartPosition + currLine.length();

        return currLine;
    }

    /**
     * Gets the number of current line.
     */
    @Override
    public long currentLineNumber() {
        return this.lineNumber;
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
     * Gets the line separator of current line.
     */
    @Override
    public LineSeparatorType currentLineSeparator() {
        throw new UnsupportedOperationException();
    }

    /**
     * Closes this resource gracefully.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }
}
