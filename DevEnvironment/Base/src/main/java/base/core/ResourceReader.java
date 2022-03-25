package base.core;

import base.BaseException;
import base.interfaces.ICloseable;
import base.interfaces.IResourceReader;
import java.io.InputStream;
import java.nio.file.Path;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The ResourceReader implements a resource reader.
 */
public final class ResourceReader implements IResourceReader, ICloseable {
    private final Path path;
    private final InputStream stream;

    private static final Logger LOG = LoggerFactory.getLogger(ResourceReader.class);

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
        return Scanners.scanStream(this.stream);
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
    public static String loadString(String path) {
        return ResourceReader.loadString(Paths.create(path));
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
        return open(this.path);
    }

    /**
     * Opens a stream.
     */
    public static InputStream open(Path path) {
        ClassLoader classLoader = ResourceReader.class.getClassLoader();

        InputStream stream = classLoader.getResourceAsStream(path.toString());

        if (stream == null) {
            String errorMessage = "The resource: " + path + " failed to get opened as a stream.";

            LOG.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return stream;
    }
}
