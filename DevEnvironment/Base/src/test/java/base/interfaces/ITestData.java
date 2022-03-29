package base.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets path of an is-prime resource.
     */
    Path getIsPrimeResourcePath();

    /**
     * Gets path of a primes' resource.
     */
    Path getPrimesResourcePath();

    /**
     * Gets values of integer-string.
     */
    List<IPair<Integer, String>> getIntegerStrings();

    /**
     * Gets data of two-dimensional lists.
     */
    List<List<List<Integer>>> getTwoDimensionalListsData();
}
