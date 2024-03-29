package datastructures.hashmap.core;

import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.core.Lists;
import datastructures.core.TestData;
import datastructures.hashmap.interfaces.IHashMap;
import datastructures.hashmap.interfaces.IHashMapBuilder;
import datastructures.hashmap.interfaces.IMapData;
import datastructures.interfaces.ITestData;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;
import testbase.core.Assertion;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import org.junit.Test;

/**
 * The HashMapTest class implements tests for a hash map.
 */
public final class HashMapTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The HashMapTest constructor.
     */
    public HashMapTest() {
    }

    /**
     * Tests the creation logic of a hash map.
     */
    @Test
    public void hashMapCreationTest() {
        for (IMapData<Integer, String> data : this.testData.getHashMapData().getHashMapData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the creation with deletion logic of a hash map.
     */
    @Test
    public void hashMapCreationWithDeletionTest() {
        for (IMapData<Integer, String> data : this.testData.getHashMapData().getHashMapData()) {
            this.testCreationWithDeletion(data);
        }
    }

    /**
     * Tests the iteration logic of a hash map.
     */
    @Test
    public void hashMapIterationTest() {
        for (IMapData<Integer, String> data : this.testData.getHashMapData().getHashMapData()) {
            this.testIteration(data);
        }
    }

    /**
     * Tests the creation logic of a hash-map.
     */
    private <TKey extends Comparable<TKey>, TValue> void testCreation(IMapData<TKey, TValue> data) {
        IHashMap<TKey, TValue> map = createHashMap(data);

        this.assertion.assertEqualsWithIterators(
            map.getIterator(),
            ListIterator.make(data.getData()),
            "Invalid creation logic of a hash map.");
    }

    /**
     * Tests the creation with deletion logic of a hash-map.
     */
    private <TKey extends Comparable<TKey>, TValue> void testCreationWithDeletion(IMapData<TKey, TValue> data) {
        IHashMap<TKey, TValue> map = createHashMap(data);

        this.assertion.assertEqualsWithIterators(
            map.getIterator(),
            ListIterator.make(data.getData()),
            "Invalid creation logic of a hash map.");

        List<IKeyValueNode<TKey, TValue>> keyValueNodes = Lists.fromIterator(map.getIterator());
        int currSize = map.size();

        for (IKeyValueNode<TKey, TValue> nodeToRemove : keyValueNodes) {
            IKeyValueNode<TKey, TValue> removedNode = map.remove(nodeToRemove.getKey());
            --currSize;

            this.assertion.assertTrue(
                !map.containsKey(nodeToRemove.getKey()),
                "Invalid remove logic of hash map: key has not been removed.");

            this.assertion.assertEquals(
                removedNode,
                nodeToRemove,
                "Invalid remove logic of hash map: invalid removed key-value node.");

            this.assertion.assertTrue(
                map.size() == currSize,
                "Invalid remove logic of hash map: invalid size.");
        }
    }

    /**
     * Tests the iteration logic of a hash map.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testIteration(
        IMapData<TKey, TValue> data) {

        //
        // Create the container...
        //
        IHashMap<TKey, TValue> container = createHashMap(data);

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            ListIterator.make(data.getData()),
            "HashMap");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            ListIterator.make(data.getData()),
            "HashMap");

        //
        // Test the reverse iterator of the container...
        //
        iterationTest.testReverseIteration(
            container,
            ListReverseIterator.make(data.getData()),
            "HashMap");

        //
        // Test the key iterator of the container...
        //
        iterationTest.testKeyIteration(
            container,
            ListIterator.make(data.getKeys()),
            "HashMap");

        //
        // Test the key reverse iterator of the container...
        //
        iterationTest.testKeyReverseIteration(
            container,
            ListReverseIterator.make(data.getKeys()),
            "HashMap");

        //
        // Test the value iterator of the container...
        //
        iterationTest.testValueIteration(
            container,
            ListIterator.make(data.getValues()),
            "HashMap");

        //
        // Test the value reverse iterator of the container...
        //
        iterationTest.testValueReverseIteration(
            container,
            ListReverseIterator.make(data.getValues()),
            "HashMap");
    }

    /**
     * Creates a hash map.
     */
    private static <TKey extends Comparable<TKey>, TValue> IHashMap<TKey, TValue> createHashMap(
        IMapData<TKey, TValue> data) {

        IHashMapBuilder<TKey, TValue> mapBuilder = new HashMapBuilder<>();
        mapBuilder.set(ListIterator.make(data.getCreationData()));
        return mapBuilder.build();
    }
}
