package datastructures.hashmap.core;

import base.core.ListIterator;
import base.core.Lists;
import datastructures.collections.core.CollectionEquatableComparator;
import datastructures.collections.interfaces.ICollectionEquatableComparator;
import datastructures.core.TestData;
import datastructures.hashmap.interfaces.IHashMap;
import datastructures.hashmap.interfaces.IHashMapBuilder;
import datastructures.hashmap.interfaces.IMapData;
import datastructures.interfaces.ITestData;
import datastructures.node.interfaces.IKeyValueNode;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import java.util.List;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The HashMapTest class implements tests for a hash map.
 */
public final class HashMapTest {
    private final ITestData testData = new TestData();
    private final ICollectionEquatableComparator comparator = new CollectionEquatableComparator();
    private final IAssertion assertion = new Assertion();

    /**
     * The HashMapTest constructor.
     */
    public HashMapTest() {
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
     * Tests the creation logic of a hash map.
     */
    @Test
    public void HashMapCreationTest() {
        for (IMapData<Integer, String> mapData : this.testData.getHashMapData().getHashMapData()) {
            this.testCreation(
                mapData.getCreationData(),
                mapData.getData());
        }
    }

    /**
     * Tests the creation logic of a hash map.
     */
    @Test
    public void HashMapCreationWithDeletionTest() {
        for (IMapData<Integer, String> mapData : this.testData.getHashMapData().getHashMapData()) {
            this.testCreationWithDeletion(
                mapData.getCreationData(),
                mapData.getData());
        }
    }

    /**
     * Tests the creation logic of a hash-map.
     */
    private <TKey extends Comparable<TKey>, TValue> void testCreation(
        List<IKeyValueNode<TKey, TValue>> creationData,
        List<IKeyValueNode<TKey, TValue>> data) {

        IHashMapBuilder<TKey, TValue> mapBuilder = new HashMapBuilder<>();
        mapBuilder.set(ListIterator.of(creationData));
        IHashMap<TKey, TValue> map = mapBuilder.build();

        this.assertion.assertTrue(
            this.comparator.isEqual(map, data),
            "Invalid creation logic of a hash map.");
    }

    /**
     * Tests the creation with deletion logic of a hash-map.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testCreationWithDeletion(
        List<IKeyValueNode<TKey, TValue>> creationData,
        List<IKeyValueNode<TKey, TValue>> data) {

        IHashMapBuilder<TKey, TValue> mapBuilder = new HashMapBuilder<>();
        mapBuilder.set(ListIterator.of(creationData));
        IHashMap<TKey, TValue> map = mapBuilder.build();

        this.assertion.assertTrue(
            this.comparator.isEqual(map, data),
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
}
