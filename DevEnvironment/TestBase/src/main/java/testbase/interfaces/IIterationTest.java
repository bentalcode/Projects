package testbase.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IKeyIterable;
import base.interfaces.IKeyReverseIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IReverseIterator;
import base.interfaces.IValueIterable;
import base.interfaces.IValueReverseIterable;

/**
 * The IIterationTest interface defines a generic iteration test.
 */
public interface IIterationTest {
    /**
     * Tests the default iteration logic of a container.
     */
    <T extends Comparable<T>> void testIteration(
        IIterable<T> container,
        IIterator<T> expectedIterator,
        String containerName);

    /**
     * Tests the default iteration logic of a container.
     */
    <T extends Comparable<T>> void testIteration(
        IIterable<T> container,
        IIterator<T> expectedIterator,
        IBinaryComparator<T> comparator,
        String containerName);

    /**
     * Tests the forward iteration logic of a container.
     */
    <T extends Comparable<T>> void testForwardIteration(
        IIterable<T> container,
        IIterator<T> expectedIterator,
        String containerName);

    /**
     * Tests the forward iteration logic of a container.
     */
    <T extends Comparable<T>> void testForwardIteration(
        IIterable<T> container,
        IIterator<T> expectedIterator,
        IBinaryComparator<T> comparator,
        String containerName);

    /**
     * Tests the reverse iteration logic of a container.
     */
    <T extends Comparable<T>> void testReverseIteration(
        IReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        String containerName);

    /**
     * Tests the reverse iteration logic of a container.
     */
    <T extends Comparable<T>> void testReverseIteration(
        IReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        IBinaryComparator<T> comparator,
        String containerName);

    /**
     * Tests the key iteration logic of a container.
     */
    <T extends Comparable<T>> void testKeyIteration(
        IKeyIterable<T> container,
        IIterator<T> expectedIterator,
        String containerName);

    /**
     * Tests the key iteration logic of a container.
     */
    <T extends Comparable<T>> void testKeyIteration(
        IKeyIterable<T> container,
        IIterator<T> expectedIterator,
        IBinaryComparator<T> comparator,
        String containerName);

    /**
     * Tests the key reverse iteration logic of a container.
     */
    <T extends Comparable<T>> void testKeyReverseIteration(
        IKeyReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        String containerName);

    /**
     * Tests the key reverse iteration logic of a container.
     */
    <T extends Comparable<T>> void testKeyReverseIteration(
        IKeyReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        IBinaryComparator<T> comparator,
        String containerName);

    /**
     * Tests the value iteration logic of a container.
     */
    <T extends Comparable<T>> void testValueIteration(
        IValueIterable<T> container,
        IIterator<T> expectedIterator,
        String containerName);

    /**
     * Tests the value iteration logic of a container.
     */
    <T extends Comparable<T>> void testValueIteration(
        IValueIterable<T> container,
        IIterator<T> expectedIterator,
        IBinaryComparator<T> comparator,
        String containerName);

    /**
     * Tests the value reverse iteration logic of a container.
     */
    <T extends Comparable<T>> void testValueReverseIteration(
        IValueReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        String containerName);

    /**
     * Tests the value reverse iteration logic of a container.
     */
    <T extends Comparable<T>> void testValueReverseIteration(
        IValueReverseIterable<T> container,
        IReverseIterator<T> expectedReverseIterator,
        IBinaryComparator<T> comparator,
        String containerName);
}
