package base.interfaces;

import base.core.Pair;
import java.nio.file.Path;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets path of a primes resource.
     */
    Path getPrimesResourcePath();

    /**
     * Gets values of integer-string.
     */
    List<Pair<Integer, String>> getIntegerStrings();
}
