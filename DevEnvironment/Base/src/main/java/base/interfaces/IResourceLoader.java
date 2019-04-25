package base.interfaces;

import java.util.Scanner;

/**
 * The IResourceLoader class defines a resource loader.
 */
public interface IResourceLoader {
    /**
     * Loads a resource as a stream.
     */
    String load(String path);

    /**
     * Scans a resource.
     */
    Scanner scan(String path);
}
