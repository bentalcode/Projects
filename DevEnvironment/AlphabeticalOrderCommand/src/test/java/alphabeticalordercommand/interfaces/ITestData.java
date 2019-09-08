package alphabeticalordercommand.interfaces;

import base.interfaces.IPair;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets the data of an alphabetical order.
     */
    List<IPair<List<String>, List<Character>>> getAlphabeticalOrderData();
}
