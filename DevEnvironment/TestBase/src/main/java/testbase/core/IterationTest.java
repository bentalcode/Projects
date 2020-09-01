package testbase.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IKeyIterable;
import base.interfaces.IKeyReverseIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IReverseIterator;
import base.interfaces.IValueIterable;
import base.interfaces.IValueReverseIterable;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;

/**
 * The IterationTest class implements a generic iteration test.
 */
public final class IterationTest implements IIterationTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The IterationTest constructor.
     */
    public IterationTest() {
    }

    /**
     * Tests the default iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testIteration(
        IIterable<T> container,
        IIterator<T> expectedIterator,
        String containerName) {

        this.testIteration(
            container,
            expectedIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the default iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testIteration(
        IIterable<T> container,
        IIterator<T> expectedIterator,
        IBinaryComparator<T> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedIterator,
            "The iterator of the container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        int index = 0;

        for (T element : container) {
            T expectedElement = expectedIterator.next();

            String errorMessage =
                "The default iteration logic of " + containerName + " is invalid." +
                " Invalid element found in index: " + index +
                ", Expected: " + expectedElement + ", Found: " + element;

            this.assertion.assertEquals(
                element,
                expectedElement,
                errorMessage);

            ++index;
        }
    }

    /**
     * Tests the forward iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testForwardIteration(
        IIterable<T> container,
        IIterator<T> expectedIterator,
        String containerName) {

        this.testForwardIteration(
            container,
            expectedIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the forward iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testForwardIteration(
        IIterable<T> container,
        IIterator<T> expectedIterator,
        IBinaryComparator<T> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedIterator,
            "The expected iterator.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IIterator<T> iterator = container.getIterator();

        int index = 0;

        while (iterator.hasNext() && expectedIterator.hasNext()) {
            T element = iterator.next();
            T expectedElement = expectedIterator.next();

            String errorMessage =
                "The forward iteration logic of " + containerName + " is invalid." +
                " Invalid element found in index: " + index +
                ", Expected: " + expectedElement + ", Found: " + element;

            this.assertion.assertEquals(
                element,
                expectedElement,
                errorMessage);

            ++index;
        }
    }

    /**
     * Tests the reverse iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testReverseIteration(
        IReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        String containerName) {

        this.testReverseIteration(
            container,
            expectedReverseIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the reverse iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testReverseIteration(
        IReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        IBinaryComparator<T> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedReverseIterator,
            "The expected reverse iterator.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IReverseIterator<T> reverseIterator = container.getReverseIterator();

        int index = 0;

        while (reverseIterator.hasNext() && expectedReverseIterator.hasNext()) {
            T element = reverseIterator.next();
            T expectedElement = expectedReverseIterator.next();

            String errorMessage =
                "The reverse iteration logic of " + containerName + " is invalid." +
                " Invalid element found in reverse index: " + index +
                ", Expected: " + expectedElement + ", Found: " + element;

            this.assertion.assertEquals(
                element,
                expectedElement,
                errorMessage);

            ++index;
        }
    }

    /**
     * Tests the key iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testKeyIteration(
        IKeyIterable<T> container,
        IIterator<T> expectedIterator,
        String containerName) {

        this.testKeyIteration(
            container,
            expectedIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the key iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testKeyIteration(
        IKeyIterable<T> container,
        IIterator<T> expectedIterator,
        IBinaryComparator<T> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedIterator,
            "The expected iterator of keys.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IIterator<T> iterator = container.getKeyIterator();

        int index = 0;

        while (iterator.hasNext() && expectedIterator.hasNext()) {
            T element = iterator.next();
            T expectedElement = expectedIterator.next();

            String errorMessage =
                "The key iteration logic of " + containerName + " is invalid." +
                " Invalid element found in index: " + index +
                ", Expected: " + expectedElement + ", Found: " + element;

            this.assertion.assertEquals(
                element,
                expectedElement,
                errorMessage);

            ++index;
        }
    }

    /**
     * Tests the key reverse iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testKeyReverseIteration(
        IKeyReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        String containerName) {

        this.testKeyReverseIteration(
            container,
            expectedReverseIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the key reverse iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testKeyReverseIteration(
        IKeyReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        IBinaryComparator<T> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedReverseIterator,
            "The expected reverse iterator of keys.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IReverseIterator<T> reverseIterator = container.getKeyReverseIterator();

        int index = 0;

        while (reverseIterator.hasNext() && expectedReverseIterator.hasNext()) {
            T element = reverseIterator.next();
            T expectedElement = expectedReverseIterator.next();

            String errorMessage =
                "The key reverse iteration logic of " + containerName + " is invalid." +
                " Invalid element found in reverse index: " + index +
                ", Expected: " + expectedElement + ", Found: " + element;

            this.assertion.assertEquals(
                element,
                expectedElement,
                errorMessage);

            ++index;
        }
    }

    /**
     * Tests the value iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testValueIteration(
        IValueIterable<T> container,
        IIterator<T> expectedIterator,
        String containerName) {

        this.testValueIteration(
            container,
            expectedIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the value iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testValueIteration(
        IValueIterable<T> container,
        IIterator<T> expectedIterator,
        IBinaryComparator<T> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedIterator,
            "The expected iterator of values.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IIterator<T> iterator = container.getValueIterator();

        int index = 0;

        while (iterator.hasNext() && expectedIterator.hasNext()) {
            T element = iterator.next();
            T expectedElement = expectedIterator.next();

            String errorMessage =
                "The value iteration logic of " + containerName + " is invalid." +
                " Invalid element found in index: " + index +
                ", Expected: " + expectedElement + ", Found: " + element;

            this.assertion.assertEquals(
                element,
                expectedElement,
                errorMessage);

            ++index;
        }
    }

    /**
     * Tests the value reverse iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testValueReverseIteration(
        IValueReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        String containerName) {

        this.testValueReverseIteration(
            container,
            expectedReverseIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the value reverse iteration logic of a container.
     */
    @Override
    public <T extends Comparable<T>> void testValueReverseIteration(
        IValueReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        IBinaryComparator<T> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedReverseIterator,
            "The expected reverse iterator of values.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IReverseIterator<T> reverseIterator = container.getValueReverseIterator();

        int index = 0;

        while (reverseIterator.hasNext() && expectedReverseIterator.hasNext()) {
            T element = reverseIterator.next();
            T expectedElement = expectedReverseIterator.next();

            String errorMessage =
                "The value reverse iteration logic of " + containerName + " is invalid." +
                " Invalid element found in reverse index: " + index +
                ", Expected: " + expectedElement + ", Found: " + element;

            this.assertion.assertEquals(
                element,
                expectedElement,
                errorMessage);

            ++index;
        }
    }
}
