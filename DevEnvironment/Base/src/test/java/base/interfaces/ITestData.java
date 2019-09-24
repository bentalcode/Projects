package base.interfaces;

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
    List<IPair<Integer, String>> getIntegerStrings();

    /**
     * Gets all sequence sub strings of a string.
     */
    List<IPair<String, List<List<String>>>> getAllSequenceSubStringsOfString();
}
