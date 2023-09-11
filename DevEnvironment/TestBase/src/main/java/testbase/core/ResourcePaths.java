package testbase.core;

import base.core.Paths;
import base.core.ResourcePathBuilder;
import java.nio.file.Path;

/**
 * The ResourcePaths class implements complementary APIs for resource paths.
 */
public final class ResourcePaths {
    /**
     * Creates a path of a resource.
     */
    public static Path create(
        String rootDirectory,
        String subDirectory) {

        String path = new ResourcePathBuilder()
            .addComponent(rootDirectory)
            .addComponent(subDirectory)
            .build();

        return Paths.create(path);
    }

    /**
     * Creates a path of a resource.
     */
    public static Path create(
        String rootDirectory,
        String subDirectory,
        String resourceName) {

        String path = new ResourcePathBuilder()
            .addComponent(rootDirectory)
            .addComponent(subDirectory)
            .addComponent(resourceName)
            .build();

        return Paths.create(path);
    }

    /**
     * Creates a path of a resource.
     */
    public static Path create(
        String rootDirectory,
        String subDirectory1,
        String subDirectory2,
        String resourceName) {

        String path = new ResourcePathBuilder()
            .addComponent(rootDirectory)
            .addComponent(subDirectory1)
            .addComponent(subDirectory2)
            .addComponent(resourceName)
            .build();

        return Paths.create(path);
    }

    /**
     * The ResourcePaths constructor - Disables the default constructor.
     */
    private ResourcePaths() {
    }
}
