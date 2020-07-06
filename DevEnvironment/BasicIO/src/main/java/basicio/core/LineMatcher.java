package basicio.core;

import base.core.DestructorHandler;
import base.interfaces.IDestructorHandler;
import java.io.Closeable;
import java.nio.file.Path;

/**
 * The LineMatcher class implements a line matcher.
 */
public final class LineMatcher extends AbstractLineMatcher implements Closeable {
    private final IDestructorHandler destructorHandler = new DestructorHandler();

    /**
     * Creates a line matcher of a file.
     */
    public static LineMatcher createFileLineMatcher(Path path) {
        return new LineMatcher(LineReader.createFileLineReader(path));
    }

    /**
     * Creates a line matcher of a string.
     */
    public static LineMatcher createStringLineMatcher(String str) {
        return new LineMatcher(LineReader.createStringLineReader(str));
    }

    /**
     * The LineMatcher constructor.
     */
    private LineMatcher(LineReader reader) {
        super(reader);
        this.destructorHandler.register(reader);
    }

    /**
     * Closes this resource gracefully.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }
}
