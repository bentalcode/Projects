package base.interfaces;

import java.io.InputStream;

/**
 * The IResourceReader interface defines a resource reader.
 */
public interface IResourceReader {
    /**
     * Gets a stream of a resource.
     * Use this API when reading binary streams.
     */
    InputStream getStream();

    /**
     * Reads a string.
     * The stream will reach the end after this method is invoked.
     */
    String readString();
}
