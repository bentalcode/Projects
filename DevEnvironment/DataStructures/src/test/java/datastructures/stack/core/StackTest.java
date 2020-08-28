package datastructures.stack.core;

import base.core.ListIterator;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.stack.interfaces.IStack;
import datastructures.stack.interfaces.IStackData;
import java.util.List;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The StackTest class implements tests for a stack.
 */
public final class StackTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The StackTest constructor.
     */
    public StackTest() {
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
     * Tests the creation logic of a stack.
     */
    @Test
    public void stackCreationTest() {
        for (IStackData<Integer> data : this.testData.getStackData().getData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the creation and removal logic of a stack.
     */
    @Test
    public void listCreationAndRemovalTest() {
        for (IStackData<Integer> data : this.testData.getStackData().getData()) {
            this.testCreationWithRemoval(data);
        }
    }

    /**
     * Tests the creation logic of a stack.
     */
    private <T extends Comparable<T>> void testCreation(IStackData<T> data) {
        IStack<T> stack = this.createStack(data);

        this.assertion.assertEqualsWithIterators(
            stack.getIterator(),
            ListIterator.make(data.getData()),
            "Invalid creation logic of a stack.");
    }

    /**
     * Tests the creation and removal logic of a stack.
     */
    private <T extends Comparable<T>> void testCreationWithRemoval(IStackData<T> data) {
        IStack<T> stack = this.createStack(data);

        this.assertion.assertEqualsWithIterators(
            stack.getIterator(),
            ListIterator.make(data.getData()),
            "Invalid creation logic of a stack.");

        List<T> expectedData = data.getData();
        int currSize = expectedData.size();
        int currIndex = 0;

        while (!stack.empty()) {
            T currItem = stack.peek();
            T currExpectedItem = expectedData.get(currIndex);

            this.assertion.assertEquals(
                currItem,
                currExpectedItem,
                "Invalid remove logic of stack: invalid peek value.");

            this.assertion.assertTrue(
                stack.size() == currSize,
                "Invalid remove logic of stack: invalid size.");

            stack.pop();
            ++currIndex;
            --currSize;
        }
    }

    /**
     * Creates a stack.
     */
    private <T extends Comparable<T>> IStack<T> createStack(IStackData<T> data) {
        IStack<T> stack = new Stack<>(data.getClassType());

        for (T item : data.getCreationData()) {
            stack.push(item);
        }

        return stack;
    }
}
