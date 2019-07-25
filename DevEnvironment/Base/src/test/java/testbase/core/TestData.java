package testbase.core;

import base.core.Pair;
import base.core.Paths;
import base.core.ResourcePathBuilder;
import base.interfaces.IPair;
import base.interfaces.ITestData;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DataDirectoryName = "data";
    private static final String PrimesDirectoryName = "primes";
    private static final String PrimesFileName = "primes.txt";

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets path of a primes resource.
     */
    @Override
    public Path getPrimesResourcePath() {
        Path path = this.createResourcePath(
            TestData.DataDirectoryName,
            TestData.PrimesDirectoryName,
            TestData.PrimesFileName);

        return path;
    }

    /**
     * Gets values of integer-string.
     */
    @Override
    public List<IPair<Integer, String>> getIntegerStrings() {
        List<IPair<Integer, String>> values = new ArrayList<>();

        values.add(Pair.of(0, "0"));
        values.add(Pair.of(101, "101"));
        values.add(Pair.of(-2222, "-2222"));
        values.add(Pair.of(2222, "2222"));
        values.add(Pair.of(22222222, "22222222"));

        return values;
    }

    /**
     * Creates a path of a resource.
     */
    private Path createResourcePath(
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
}
