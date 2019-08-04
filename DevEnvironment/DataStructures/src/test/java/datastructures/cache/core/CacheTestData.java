package datastructures.cache.core;

import base.core.ArrayLists;
import base.core.Triple;
import base.interfaces.ITriple;
import datastructures.cache.interfaces.ICacheTestData;
import datastructures.node.core.KeyValueNode;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.ArrayList;
import java.util.List;

/**
 * The CacheTestData class implements the data of the tests of a cache.
 */
public final class CacheTestData implements ICacheTestData {
    /**
     * The CacheTestData constructor.
     */
    public CacheTestData() {
    }

    /**
     * Gets the least recently used data.
     */
    @Override
    public List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> getLRUData() {
        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data = new ArrayList<>();

        data.add(Triple.of("set", KeyValueNode.of(1, "a"), ArrayLists.of(KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(2, "b"), ArrayLists.of(KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(3, "c"), KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(4, "d"), ArrayLists.of(KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"), KeyValueNode.of(2, "b"))));
        data.add(Triple.of("set", KeyValueNode.of(1, "a"), ArrayLists.of(KeyValueNode.of(1, "a"), KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"))));
        data.add(Triple.of("set", KeyValueNode.of(2, "b"), ArrayLists.of(KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"), KeyValueNode.of(4, "d"))));
        data.add(Triple.of("set", KeyValueNode.of(5, "e"), ArrayLists.of(KeyValueNode.of(5, "e"), KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(1, "a"), ArrayLists.of(KeyValueNode.of(1, "a"), KeyValueNode.of(5, "e"), KeyValueNode.of(2, "b"))));
        data.add(Triple.of("set", KeyValueNode.of(2, "b"), ArrayLists.of(KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"), KeyValueNode.of(5, "e"))));
        data.add(Triple.of("set", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(3, "c"), KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(4, "d"), ArrayLists.of(KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"), KeyValueNode.of(2, "b"))));
        data.add(Triple.of("set", KeyValueNode.of(5, "e"), ArrayLists.of(KeyValueNode.of(5, "e"), KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"))));
        data.add(Triple.of("get", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(3, "c"), KeyValueNode.of(5, "e"), KeyValueNode.of(4, "d"))));
        data.add(Triple.of("get", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(3, "c"), KeyValueNode.of(5, "e"), KeyValueNode.of(4, "d"))));
        data.add(Triple.of("get", KeyValueNode.of(4, "d"), ArrayLists.of(KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"), KeyValueNode.of(5, "e"))));
        data.add(Triple.of("get", KeyValueNode.of(5, "e"), ArrayLists.of(KeyValueNode.of(5, "e"), KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"))));
        data.add(Triple.of("delete", KeyValueNode.of(4, "d"), ArrayLists.of(KeyValueNode.of(5, "e"), KeyValueNode.of(3, "c"))));
        data.add(Triple.of("delete", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(5, "e"))));
        data.add(Triple.of("delete", KeyValueNode.of(5, "e"), new ArrayList<>()));

        return data;
    }
}
