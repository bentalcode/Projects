package testbase.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import datastructures.collections.interfaces.IKeyIterable;
import datastructures.collections.interfaces.IKeyReverseIterable;
import datastructures.collections.interfaces.IValueIterable;
import datastructures.collections.interfaces.IValueReverseIterable;

/**
 * The IIterationTest interface defines a generic iteration test.
 */
public interface IIterationTest {
    /**
     * Tests the default iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testIteration(
        IIterable<TValue> container,
        IIterable<TValue> expectedContainer,
        String containerName);

    /**
     * Tests the default iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testIteration(
        IIterable<TValue> container,
        IIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the forward iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testForwardIteration(
        IIterable<TValue> container,
        IIterable<TValue> expectedContainer,
        String containerName);

    /**
     * Tests the forward iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testForwardIteration(
        IIterable<TValue> container,
        IIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testReverseIteration(
        IReverseIterable<TValue> container,
        IReverseIterable<TValue> expectedContainer,
        String containerName);

    /**
     * Tests the reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testReverseIteration(
        IReverseIterable<TValue> container,
        IReverseIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the key iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testKeyIteration(
        IKeyIterable<TValue> container,
        IKeyIterable<TValue> expectedContainer,
        String containerName);

    /**
     * Tests the key iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testKeyIteration(
        IKeyIterable<TValue> container,
        IKeyIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the key reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testKeyReverseIteration(
        IKeyReverseIterable<TValue> container,
        IKeyReverseIterable<TValue> expectedContainer,
        String containerName);

    /**
     * Tests the key reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testKeyReverseIteration(
        IKeyReverseIterable<TValue> container,
        IKeyReverseIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the value iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testValueIteration(
        IValueIterable<TValue> container,
        IValueIterable<TValue> expectedContainer,
        String containerName);

    /**
     * Tests the value iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testValueIteration(
        IValueIterable<TValue> container,
        IValueIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the value reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testValueReverseIteration(
        IValueReverseIterable<TValue> container,
        IValueReverseIterable<TValue> expectedContainer,
        String containerName);

    /**
     * Tests the value reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testValueReverseIteration(
        IValueReverseIterable<TValue> container,
        IValueReverseIterable<TValue> expectedContainer,
        IBinaryComparator<TValue> comparator,
        String containerName);
}
