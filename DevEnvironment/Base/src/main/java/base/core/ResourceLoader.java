package base.core;

import base.interfaces.IResourceLoader;
import java.io.InputStream;
import java.util.Scanner;

/**
 * The ResourceLoader class implements complementary APIs for loading a resource.
 */
public final class ResourceLoader implements IResourceLoader {
    /**
     * The ResourceLoader constructor.
     */
    public ResourceLoader() {
    }

    /**
     * Loads a resource as a stream.
     */
    @Override
    public String load(String path) {
        String result;

        try (Scanner scanner = this.scan(path)) {
            scanner.useDelimiter("\\A");
            result = scanner.hasNext() ? scanner.next() : "";
        }

        return result;
    }

    /**
     * Scans a resource.
     */
    @Override
    public Scanner scan(String path) {
        Conditions.validateStringNotNullOrEmpty(
            path,
            "The path of a resource can not be null or empty.");

        InputStream stream = getClass()
            .getClassLoader()
            .getResourceAsStream(path);

        Scanner scanner = new Scanner(stream);

        return scanner;
    }
}
