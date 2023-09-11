package datastructures.cache.interfaces;

import base.interfaces.ITriple;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The ICacheTestData interface defines the data of the tests of a cache.
 */
public interface ICacheTestData {
    /**
     * Gets the update data of the least recently used cache.
     */
    List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> getLruUpdateData();

    /**
     * Gets the update data of a most recently used cache.
     */
    List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> getMruUpdateData();
}
