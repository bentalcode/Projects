package alphabeticalordercommand.core;

import alphabeticalordercommand.interfaces.IAlphabeticalOrderResults;
import alphabeticalordercommand.interfaces.ITestData;
import base.core.ListIterator;
import base.interfaces.ICalculator;
import base.interfaces.IPair;
import java.util.List;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The AlphabeticalOrderTest class implements tests for an alphabetical order.
 */
public final class AlphabeticalOrderTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The AlphabeticalOrderTest constructor.
     */
    public AlphabeticalOrderTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the logic of an alphabetical order.
     */
    @Test
    public void AlphabeticalOrderTest() {
        List<IPair<List<String>, List<Character>>> data = this.testData.getAlphabeticalOrderData();

        for (IPair<List<String>, List<Character>> dataEntry : data) {
            this.testAlphabeticalOrder(dataEntry.first(), dataEntry.second());
        }
    }

    /**
     * Tests the logic of an alphabetical order.
     */
    private void testAlphabeticalOrder(
        List<String> data,
        List<Character> characters) {

        ICalculator<IAlphabeticalOrderResults> calculator = new AlphabeticalOrderCalculator(data);
        IAlphabeticalOrderResults results = calculator.calculate();

        this.assertion.assertEqualsWithIterators(
            ListIterator.make(characters),
            results.getIterator(),
            "Invalid alphabetical order");
    }
}
