package testbase.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterable;
import base.interfaces.IReverseIterator;
import datastructures.collections.interfaces.IKeyIterable;
import datastructures.collections.interfaces.IKeyIterator;
import datastructures.collections.interfaces.IKeyReverseIterable;
import datastructures.collections.interfaces.IKeyReverseIterator;
import datastructures.collections.interfaces.IValueIterable;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.collections.interfaces.IValueReverseIterable;
import datastructures.collections.interfaces.IValueReverseIterator;
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
        IIterable<TValue> expectedContainer,
        String containerName) {

        this.testIteration(
            container,
            expectedContainer,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the default iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testIteration(
        IIterable<TValue> container,
        IIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedContainer,
            "The expected container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IIterator<TValue> dataIterator = expectedContainer.getIterator();
        int index = 0;

        for (TValue element : container) {
            TValue expectedElement = dataIterator.next();

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
        IIterable<TValue> dataContainer,
        String containerName) {

        this.testForwardIteration(
            container,
            dataContainer,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the forward iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testForwardIteration(
        IIterable<TValue> container,
        IIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedContainer,
            "The expected container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IIterator<TValue> iterator = container.getIterator();
        IIterator<TValue> expectedIterator = expectedContainer.getIterator();

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
        IReverseIterable<TValue> dataContainer,
        String containerName) {

        this.testReverseIteration(
            container,
            dataContainer,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the reverse iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testReverseIteration(
        IReverseIterable<TValue> container,
        IReverseIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedContainer,
            "The expected container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IReverseIterator<TValue> iterator = container.getReverseIterator();
        IReverseIterator<TValue> expectedIterator = expectedContainer.getReverseIterator();

        int index = 0;

        while (iterator.hasNext() && expectedIterator.hasNext()) {
            TValue element = iterator.next();
            TValue expectedElement = expectedIterator.next();

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
        IKeyIterable<TValue> expectedContainer,
        String containerName) {

        this.testKeyIteration(
            container,
            expectedContainer,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the key iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testKeyIteration(
        IKeyIterable<TValue> container,
        IKeyIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedContainer,
            "The expected container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IKeyIterator<TValue> iterator = container.getKeyIterator();
        IKeyIterator<TValue> expectedIterator = expectedContainer.getKeyIterator();

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
        IKeyReverseIterable<TValue> expectedContainer,
        String containerName) {

        this.testKeyReverseIteration(
            container,
            expectedContainer,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the key reverse iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testKeyReverseIteration(
        IKeyReverseIterable<TValue> container,
        IKeyReverseIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedContainer,
            "The expected container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IKeyReverseIterator<TValue> iterator = container.getKeyReverseIterator();
        IKeyReverseIterator<TValue> expectedIterator = expectedContainer.getKeyReverseIterator();

        int index = 0;

        while (iterator.hasNext() && expectedIterator.hasNext()) {
            TValue element = iterator.next();
            TValue expectedElement = expectedIterator.next();

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
        IValueIterable<TValue> expectedContainer,
        String containerName) {

        this.testValueIteration(
            container,
            expectedContainer,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the value iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testValueIteration(
        IValueIterable<TValue> container,
        IValueIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedContainer,
            "The expected container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IValueIterator<TValue> iterator = container.getValueIterator();
        IValueIterator<TValue> expectedIterator = expectedContainer.getValueIterator();

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
        IValueReverseIterable<TValue> expectedContainer,
        String containerName) {

        this.testValueReverseIteration(
            container,
            expectedContainer,
            base.core.Comparator.defaultComparator(),
            containerName);
    }

    /**
     * Tests the value reverse iteration logic of a container.
     */
    @Override
    public <TValue extends Comparable<TValue>> void testValueReverseIteration(
        IValueReverseIterable<TValue> container,
        IValueReverseIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName) {

        Conditions.validateNotNull(
            container,
            "The container.");

        Conditions.validateNotNull(
            expectedContainer,
            "The expected container.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an element.");

        IValueReverseIterator<TValue> iterator = container.getValueReverseIterator();
        IValueReverseIterator<TValue> expectedIterator = expectedContainer.getValueReverseIterator();

        int index = 0;

        while (iterator.hasNext() && expectedIterator.hasNext()) {
            TValue element = iterator.next();
            TValue expectedElement = expectedIterator.next();

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
