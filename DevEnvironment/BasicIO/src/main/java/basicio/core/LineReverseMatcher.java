package basicio.core;

import base.core.DestructorHandler;
import base.interfaces.IDestructorHandler;
import java.io.Closeable;
import java.nio.file.Path;

/**
 * The LineReverseMatcher class implements a line reverse matcher.
 */
public final class LineReverseMatcher extends AbstractLineMatcher implements Closeable {
    private final IDestructorHandler destructorHandler = new DestructorHandler();

    /**
     * Creates a line reverse matcher of a file.
     */
    public static LineReverseMatcher createFileLineReverseMatcher(Path path) {
        return new LineReverseMatcher(new FileLineReverseReader(path));
    }

    /**
     * The LineReverseMatcher constructor.
     */
    private LineReverseMatcher(FileLineReverseReader reader) {
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
