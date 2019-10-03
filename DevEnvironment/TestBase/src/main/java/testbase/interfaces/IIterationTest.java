package testbase.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterable;
import base.interfaces.IReverseIterator;
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
        IIterator<TValue> containerIterator,
        String containerName);

    /**
     * Tests the default iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testIteration(
        IIterable<TValue> container,
        IIterator<TValue> containerIterator,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the forward iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testForwardIteration(
        IIterable<TValue> container,
        IIterator<TValue> containerIterator,
        String containerName);

    /**
     * Tests the forward iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testForwardIteration(
        IIterable<TValue> container,
        IIterator<TValue> containerIterator,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testReverseIteration(
        IReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        String containerName);

    /**
     * Tests the reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testReverseIteration(
        IReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the key iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testKeyIteration(
        IKeyIterable<TValue> container,
        IIterator<TValue> containerIterator,
        String containerName);

    /**
     * Tests the key iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testKeyIteration(
        IKeyIterable<TValue> container,
        IIterator<TValue> containerIterator,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the key reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testKeyReverseIteration(
        IKeyReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        String containerName);

    /**
     * Tests the key reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testKeyReverseIteration(
        IKeyReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the value iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testValueIteration(
        IValueIterable<TValue> container,
        IIterator<TValue> containerIterator,
        String containerName);

    /**
     * Tests the value iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testValueIteration(
        IValueIterable<TValue> container,
        IIterator<TValue> containerIterator,
        IBinaryComparator<TValue> comparator,
        String containerName);

    /**
     * Tests the value reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testValueReverseIteration(
        IValueReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        String containerName);

    /**
     * Tests the value reverse iteration logic of a container.
     */
    <TValue extends Comparable<TValue>> void testValueReverseIteration(
        IValueReverseIterable<TValue> container,
        IReverseIterator<TValue> containerReverseIterator,
        IBinaryComparator<TValue> comparator,
        String containerName);
}
