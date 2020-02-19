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
    public <TValue extends Comparable<TValue>> void testIteration(
        IIterable<TValue> container,
        IIterator<TValue> containerIterator,
        String containerName) {

        this.testIteration(
            container,
            containerIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the default iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testIteration(
        IIterable<TValue> container,
        IIterator<TValue> containerIterator,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            containerIterator,
            "The iterator of the container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IIterator<TValue> expectedIterator = containerIterator;
        int index = 0;

        for (TValue element : container) {
            TValue expectedElement = expectedIterator.next();

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
    public <TValue extends Comparable<TValue>> void testForwardIteration(
        IIterable<TValue> container,
        IIterator<TValue> containerIterator,
        String containerName) {

        this.testForwardIteration(
            container,
            containerIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the forward iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testForwardIteration(
        IIterable<TValue> container,
        IIterator<TValue> containerIterator,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            containerIterator,
            "The iterator of the container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IIterator<TValue> iterator = container.getIterator();
        IIterator<TValue> expectedIterator = containerIterator;

        int index = 0;

        while (iterator.hasNext() && expectedIterator.hasNext()) {
            TValue element = iterator.next();
            TValue expectedElement = expectedIterator.next();

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
    public <TValue extends Comparable<TValue>> void testReverseIteration(
        IReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        String containerName) {

        this.testReverseIteration(
            container,
            containerReverseIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the reverse iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testReverseIteration(
        IReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            containerReverseIterator,
            "The reverse iterator of the container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IReverseIterator<TValue> reverseIterator = container.getReverseIterator();
        IReverseIterator<TValue> expectedReverseIterator = containerReverseIterator;

        int index = 0;

        while (reverseIterator.hasNext() && expectedReverseIterator.hasNext()) {
            TValue element = reverseIterator.next();
            TValue expectedElement = expectedReverseIterator.next();

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
    public <TValue extends Comparable<TValue>> void testKeyIteration(
        IKeyIterable<TValue> container,
        IIterator<TValue> containerIterator,
        String containerName) {

        this.testKeyIteration(
            container,
            containerIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the key iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testKeyIteration(
        IKeyIterable<TValue> container,
        IIterator<TValue> containerIterator,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            containerIterator,
            "The iterator of keys of the container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IIterator<TValue> iterator = container.getKeyIterator();
        IIterator<TValue> expectedIterator = containerIterator;

        int index = 0;

        while (iterator.hasNext() && expectedIterator.hasNext()) {
            TValue element = iterator.next();
            TValue expectedElement = expectedIterator.next();

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
    public <TValue extends Comparable<TValue>> void testKeyReverseIteration(
        IKeyReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        String containerName) {

        this.testKeyReverseIteration(
            container,
            containerReverseIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the key reverse iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testKeyReverseIteration(
        IKeyReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            containerReverseIterator,
            "The reverse iterator of keys of the container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IReverseIterator<TValue> reverseIterator = container.getKeyReverseIterator();
        IReverseIterator<TValue> expectedReverseIterator = containerReverseIterator;

        int index = 0;

        while (reverseIterator.hasNext() && expectedReverseIterator.hasNext()) {
            TValue element = reverseIterator.next();
            TValue expectedElement = expectedReverseIterator.next();

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
    public <TValue extends Comparable<TValue>> void testValueIteration(
        IValueIterable<TValue> container,
        IIterator<TValue> containerIterator,
        String containerName) {

        this.testValueIteration(
            container,
            containerIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the value iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testValueIteration(
        IValueIterable<TValue> container,
        IIterator<TValue> containerIterator,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            containerIterator,
            "The iterator of values of the container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IIterator<TValue> iterator = container.getValueIterator();
        IIterator<TValue> expectedIterator = containerIterator;

        int index = 0;

        while (iterator.hasNext() && expectedIterator.hasNext()) {
            TValue element = iterator.next();
            TValue expectedElement = expectedIterator.next();

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
    public <TValue extends Comparable<TValue>> void testValueReverseIteration(
        IValueReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        String containerName) {

        this.testValueReverseIteration(
            container,
            containerReverseIterator,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the value reverse iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testValueReverseIteration(
        IValueReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            containerReverseIterator,
            "The reverse iterator of values of the container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IReverseIterator<TValue> reverseIterator = container.getValueReverseIterator();
        IReverseIterator<TValue> expectedReverseIterator = containerReverseIterator;

        int index = 0;

        while (reverseIterator.hasNext() && expectedReverseIterator.hasNext()) {
            TValue element = reverseIterator.next();
            TValue expectedElement = expectedReverseIterator.next();

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
