package testbase.core;

import base.core.TwoDimensionalList;
import base.core.TwoDimensionalListIterator;
import base.interfaces.ITestData;
import base.interfaces.ITwoDimensionalList;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import java.util.List;

/**
 * The TwoDimensionalListTest class implements tests for a two dimensional list.
 */
public final class TwoDimensionalListTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The TwoDimensionalListTest constructor.
     */
    public TwoDimensionalListTest() {
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
     * Tests the creation logic of a two dimensional list.
     */
    @Test
    public void twoDimensionalListCreationTest() {

        for (List<List<Integer>> data : this.testData.getTwoDimensionalListsData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the iteration logic of a two dimensional list.
     */
    @Test
    public void twoDimensionalListIterationTest() {
        for (List<List<Integer>> data : this.testData.getTwoDimensionalListsData()) {
            this.testIteration(data);
        }
    }

    /**
     * Tests the creation logic of a two dimensional list.
     */
    private <T extends Comparable<T>> void testCreation(List<List<T>> data) {
        //
        // Create the container...
        //
        ITwoDimensionalList<T> container = this.createTwoDimensionalList(data);

        //
        // Test the data of the container...
        //
        this.assertion.assertEqualsWithIterators(
            container.getIterator(),
            TwoDimensionalListIterator.of(data),
            "Invalid creation logic of a two dimensional list.");
    }

    /**
     * Tests the iteration logic of a two dimensional list.
     */
    private <T extends Comparable<T>> void testIteration(List<List<T>> data) {
        //
        // Create the container...
        //
        ITwoDimensionalList<T> container = this.createTwoDimensionalList(data);

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            TwoDimensionalListIterator.of(data),
            "TwoDimensionalList");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            TwoDimensionalListIterator.of(data),
            "TwoDimensionalList");
    }

    /**
     * Creates a two dimensional list.
     */
    private <T extends Comparable<T>> ITwoDimensionalList<T> createTwoDimensionalList(List<List<T>> data) {
        ITwoDimensionalList<T> result = new TwoDimensionalList<>(data);
        return result;
    }
}
