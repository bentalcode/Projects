package datastructures.hashmap.core;

import base.core.ListIterator;
import base.core.Lists;
import base.interfaces.IIterator;
import datastructures.core.TestData;
import datastructures.hashmap.interfaces.IHashMap;
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
    private final IAssertion assertion = new Assertion();

    /**
     * The BinaryTreeTest constructor.
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
        for (IMapData<Integer, String> mapData : this.testData.getHashMapData().getData()) {
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
        for (IMapData<Integer, String> mapData : this.testData.getHashMapData().getData()) {
            this.testCreation(
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

        IIterator<IKeyValueNode<TKey, TValue>> creationDataIterator = ListIterator.of(data);

        IHashMap<TKey, TValue> map = new HashMapBuilder<TKey, TValue>()
            .set(creationDataIterator)
            .build();

        IIterator<IKeyValueNode<TKey, TValue>> dataIterator = ListIterator.of(data);

        this.assertion.assertEquals(
            map.getIterator(),
            dataIterator,
            "Invalid creation logic of a hash map.");
    }

    /**
     * Tests the creation with deletion logic of a hash-map.
     */
    private <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> void testCreationWithDeletion(
        List<IKeyValueNode<TKey, TValue>> creationData,
        List<IKeyValueNode<TKey, TValue>> data) {

        IIterator<IKeyValueNode<TKey, TValue>> creationDataIterator = ListIterator.of(data);

        IHashMap<TKey, TValue> map = new HashMapBuilder<TKey, TValue>()
            .set(creationDataIterator)
            .build();

        IIterator<IKeyValueNode<TKey, TValue>> dataIterator = ListIterator.of(data);

        this.assertion.assertEquals(
            map.getIterator(),
            dataIterator,
            "Invalid creation logic of a hash map.");

        List<IKeyValueNode<TKey, TValue>> keyValueNodes = Lists.fromIterator(map.getIterator());
        int currSize = map.size();

        for (IKeyValueNode<TKey, TValue> keyValueNode : keyValueNodes) {
            TValue removedValue = map.remove(keyValueNode.getKey());
            --currSize;

            this.assertion.assertTrue(
                !map.containsKey(keyValueNode.getKey()),
                "Invalid remove logic: key was not removed.");

            this.assertion.assertEquals(
                removedValue,
                keyValueNode.getValue(),
                "Invalid remove logic: invalid removed value.");

            this.assertion.assertTrue(
                currSize == map.size(),
                "Invalid remove logic: invalid size.");
        }
    }
}
