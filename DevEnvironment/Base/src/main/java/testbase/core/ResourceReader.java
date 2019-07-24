package testbase.core;

import base.interfaces.ICloseable;
import base.interfaces.IResourceReader;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.InputStream;
import java.nio.file.Path;

/**
 * The ResourceReader implements a resource reader.
 */
public final class ResourceReader implements IResourceReader, ICloseable {
    private final Path path;
    private final InputStream stream;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The ResourceReader constructor.
     */
    public ResourceReader(Path path) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a resource.");

        this.path = path;
        this.stream = this.open();
    }

    /**
     * Gets a stream of a resource.
     * Use this API when reading binary streams.
     */
    public InputStream getStream() {
        return this.stream;
    }

    /**
     * Reads a string.
     * The stream will reach the end after this method is invoked.
     */
    public String readString() {
        String result = Scanners.scanStream(this.stream);
        return result;
    }

    /**
     * Closes streams.
     */
    public void close() {
        Streams.closeQuietly(this.stream);
    }

    /**
     * Loads a string.
     */
    public static String loadString(Path path) {
        String result;

        try (ResourceReader reader = new ResourceReader(path)) {
            result = reader.readString();
        }

        return result;
    }

    /**
     * Opens a stream.
     */
    private InputStream open() {
        ClassLoader classLoader = getClass().getClassLoader();

        InputStream stream = classLoader.getResourceAsStream(this.path.toString());

        if (stream == null) {
            String errorMessage = "The resource: " + this.path + " failed to get opened as a stream.";

            this.log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return stream;
    }
}
