package datastructures.list.core;

import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.list.interfaces.ITwoDimensionalList;
import datastructures.list.interfaces.ITwoDimensionalListData;
import testbase.core.Assertion;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import java.util.List;
import org.junit.Test;

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
     * Tests the creation logic of a two dimensional list.
     */
    @Test
    public void twoDimensionalListCreationTest() {
        List<ITwoDimensionalListData<Integer>> data = this.testData.getTwoDimensionalListData().getData();

        for (ITwoDimensionalListData<Integer> listData : data) {
            this.testCreation(listData);
        }
    }

    /**
     * Tests the iteration logic of a two dimensional list.
     */
    @Test
    public void twoDimensionalListIterationTest() {
        List<ITwoDimensionalListData<Integer>> data = this.testData.getTwoDimensionalListData().getData();

        for (ITwoDimensionalListData<Integer> listData : data) {
            this.testIteration(listData);
        }
    }

    /**
     * Tests the creation logic of a two dimensional list.
     */
    private <T extends Comparable<T>> void testCreation(ITwoDimensionalListData<T> data) {
        //
        // Create the container...
        //
        ITwoDimensionalList<T> container = createTwoDimensionalList(data);

        //
        // Test the data of the container...
        //
        this.assertion.assertEqualsWithIterators(
            container.getIterator(),
            TwoDimensionalListIterator.make(data.getCreationData()),
            "Invalid creation logic of a two dimensional list.");
    }

    /**
     * Tests the iteration logic of a two dimensional list.
     */
    private <T extends Comparable<T>> void testIteration(ITwoDimensionalListData<T> data) {
        //
        // Create the container...
        //
        ITwoDimensionalList<T> container = createTwoDimensionalList(data);

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            TwoDimensionalListIterator.make(data.getCreationData()),
            "TwoDimensionalList");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            TwoDimensionalListIterator.make(data.getCreationData()),
            "TwoDimensionalList");
    }

    /**
     * Creates a two dimensional list.
     */
    private static <T extends Comparable<T>> ITwoDimensionalList<T> createTwoDimensionalList(ITwoDimensionalListData<T> data) {
        ITwoDimensionalList<T> result = new TwoDimensionalList<>(data.getCreationData());
        return result;
    }
}
