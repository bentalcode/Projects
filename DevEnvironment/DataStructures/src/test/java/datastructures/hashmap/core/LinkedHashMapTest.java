package datastructures.hashmap.core;

import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.core.Lists;
import datastructures.core.TestData;
import datastructures.hashmap.interfaces.ILinkedHashMap;
import datastructures.hashmap.interfaces.ILinkedHashMapBuilder;
import datastructures.hashmap.interfaces.IMapData;
import datastructures.interfaces.ITestData;
import datastructures.node.interfaces.IKeyValueNode;
import testbase.core.Assertion;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import java.util.List;
import org.junit.Test;

/**
 * The LinkedHashMapTest class implements tests for a linked hash map.
 */
public final class LinkedHashMapTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The LinkedHashMapTest constructor.
     */
    public LinkedHashMapTest() {
    }

    /**
     * Tests the creation logic of a linked hash map.
     */
    @Test
    public void linkedHashMapCreationTest() {
        for (IMapData<Integer, String> data : this.testData.getHashMapData().getLinkedHashMapData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the creation with deletion logic of a linked hash map.
     */
    @Test
    public void linkedHashMapCreationWithDeletionTest() {
        for (IMapData<Integer, String> data : this.testData.getHashMapData().getLinkedHashMapData()) {
            this.testCreationWithDeletion(data);
        }
    }

    /**
     * Tests the iteration logic of a hash map.
     */
    @Test
    public void linkedHashMapIterationTest() {
        for (IMapData<Integer, String> data : this.testData.getHashMapData().getLinkedHashMapData()) {
            this.testIteration(data);
        }
    }

    /**
     * Tests the creation logic of a linked hash map.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testCreation(
        IMapData<TKey, TValue> data) {

        ILinkedHashMap<TKey, TValue> map = createLinkedHashMap(data);

        this.assertion.assertEqualsWithIterators(
            map.getIterator(),
            ListIterator.make(data.getData()),
            "Invalid creation logic of a linked hash map.");
    }

    /**
     * Tests the creation with deletion logic of a linked hash-map.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testCreationWithDeletion(
        IMapData<TKey, TValue> data) {

        ILinkedHashMap<TKey, TValue> map = createLinkedHashMap(data);

        this.assertion.assertEqualsWithIterators(
            map.getIterator(),
            ListIterator.make(data.getData()),
            "Invalid creation logic of a linked hash map.");

        List<IKeyValueNode<TKey, TValue>> keyValueNodes = Lists.fromIterator(map.getIterator());
        int currSize = map.size();

        for (IKeyValueNode<TKey, TValue> nodeToRemove : keyValueNodes) {
            IKeyValueNode<TKey, TValue> removedNode = map.remove(nodeToRemove.getKey());
            --currSize;

            this.assertion.assertTrue(
                !map.containsKey(nodeToRemove.getKey()),
                "Invalid remove logic of linked hash map: key was not removed.");

            this.assertion.assertEquals(
                removedNode,
                nodeToRemove,
                "Invalid remove logic of linked hash map: invalid removed key-value node.");

            this.assertion.assertTrue(
                map.size() == currSize,
                "Invalid remove logic of linked hash map: invalid size.");
        }
    }

    /**
     * Tests the iteration logic of a linked hash map.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testIteration(
        IMapData<TKey, TValue> data) {

        //
        // Create the container...
        //
        ILinkedHashMap<TKey, TValue> container = createLinkedHashMap(data);

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            ListIterator.make(data.getData()),
            "LinkedHashMap");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            ListIterator.make(data.getData()),
            "LinkedHashMap");

        //
        // Test the reverse iterator of the container...
        //
        iterationTest.testReverseIteration(
            container,
            ListReverseIterator.make(data.getData()),
            "LinkedHashMap");

        //
        // Test the key iterator of the container...
        //
        iterationTest.testKeyIteration(
            container,
            ListIterator.make(data.getKeys()),
            "LinkedHashMap");

        //
        // Test the key reverse iterator of the container...
        //
        iterationTest.testKeyReverseIteration(
            container,
            ListReverseIterator.make(data.getKeys()),
            "LinkedHashMap");

        //
        // Test the value iterator of the container...
        //
        iterationTest.testValueIteration(
            container,
            ListIterator.make(data.getValues()),
            "LinkedHashMap");

        //
        // Test the value reverse iterator of the container...
        //
        iterationTest.testValueReverseIteration(
            container,
            ListReverseIterator.make(data.getValues()),
            "LinkedHashMap");
    }

    /**
     * Creates a linked hash map.
     */
    private static <TKey extends Comparable<TKey>, TValue> ILinkedHashMap<TKey, TValue> createLinkedHashMap(
        IMapData<TKey, TValue> data) {

        ILinkedHashMapBuilder<TKey, TValue> mapBuilder = new LinkedHashMapBuilder<>();
        mapBuilder.set(ListIterator.make(data.getCreationData()));
        return mapBuilder.build();
    }
}
