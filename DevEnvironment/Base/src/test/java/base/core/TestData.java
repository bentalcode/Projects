package base.core;

import base.interfaces.IPair;
import base.interfaces.ITestData;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DATA_DIRECTORY_NAME = "data";
    private static final String PRIMES_DIRECTORY_NAME = "primes";
    private static final String IS_PRIME_FILE_NAME = "isPrime.txt";
    private static final String PRIMES_FILE_NAME = "primes.txt";

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets path of is-primes resource.
     */
    @Override
    public Path getIsPrimeResourcePath() {
        return this.createResourcePath(
            TestData.DATA_DIRECTORY_NAME,
            TestData.PRIMES_DIRECTORY_NAME,
            TestData.IS_PRIME_FILE_NAME);
    }

    /**
     * Gets path of primes resource.
     */
    @Override
    public Path getPrimesResourcePath() {
        return this.createResourcePath(
            TestData.DATA_DIRECTORY_NAME,
            TestData.PRIMES_DIRECTORY_NAME,
            TestData.PRIMES_FILE_NAME);
    }

    /**
     * Gets values of integer-string.
     */
    @Override
    public List<IPair<Integer, String>> getIntegerStrings() {
        List<IPair<Integer, String>> values = new ArrayList<>();

        values.add(Pair.make(0, "0"));
        values.add(Pair.make(101, "101"));
        values.add(Pair.make(-2222, "-2222"));
        values.add(Pair.make(2222, "2222"));
        values.add(Pair.make(22222222, "22222222"));

        return values;
    }

    /**
     * Gets data of two-dimensional lists.
     */
    @Override
    public List<List<List<Integer>>> getTwoDimensionalListsData() {
        List<List<List<Integer>>> data = new ArrayList<>();

        int numberOfRows = 10;
        int numberOfColumns = 20;

        for (int row = 0; row < numberOfRows; ++row) {
            for (int column = 0; column < numberOfColumns; ++column) {
                List<List<Integer>> listData = this.createTwoDimensionalListData(row, column);
                data.add(listData);
            }
        }

        return data;
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

    /**
     * Creates data of a two-dimensional list.
     */
    private List<List<Integer>> createTwoDimensionalListData(int rows, int columns)
    {
        List<List<Integer>> data = new ArrayList<>();

        int value = 0;
        for (int row = 0; row < rows; ++row) {
            List<Integer> rowData = new ArrayList<>();

            for (int column = 0; column < columns; ++column) {
                ++value;

                rowData.add(value);
            }

            data.add(rowData);
        }

        return data;
    }
}
