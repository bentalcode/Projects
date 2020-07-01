package basicio.core;

import base.core.DestructorHandler;
import base.core.Scanners;
import base.interfaces.ICloseable;
import base.interfaces.IDestructorHandler;
import basicio.interfaces.ILineReader;
import java.nio.file.Path;
import java.util.Scanner;

/**
 * The FileLineReader class implements a reader of lines of a file.
 */
public final class FileLineReader implements ILineReader, ICloseable {
    private final Scanner scanner;
    private long lineNumber;
    private final IDestructorHandler destructorHandler = new DestructorHandler();

    /**
     * The FileLineReader constructor.
     */
    public FileLineReader(Path path) {
        Scanner scanner = Scanners.createFileScanner(path);
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

        String currLine = this.scanner.nextLine();
        ++this.lineNumber;

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
     * Closes this resource gracefully.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }
}
