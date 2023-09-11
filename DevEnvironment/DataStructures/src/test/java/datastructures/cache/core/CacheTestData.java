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
     * Gets the update data of least recently used cache.
     */
    @Override
    public List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> getLruUpdateData() {
        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data = new ArrayList<>();

        data.add(Triple.make("set", KeyValueNode.make(1, "a"), ArrayLists.make(KeyValueNode.make(1, "a"))));
        data.add(Triple.make("set", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"))));
        data.add(Triple.make("set", KeyValueNode.make(3, "c"), ArrayLists.make(KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"), KeyValueNode.make(3, "c"))));
        data.add(Triple.make("set", KeyValueNode.make(4, "d"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(3, "c"), KeyValueNode.make(4, "d"))));
        data.add(Triple.make("set", KeyValueNode.make(1, "a"), ArrayLists.make(KeyValueNode.make(3, "c"), KeyValueNode.make(4, "d"), KeyValueNode.make(1, "a"))));
        data.add(Triple.make("set", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(4, "d"), KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"))));
        data.add(Triple.make("set", KeyValueNode.make(5, "e"), ArrayLists.make(KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("set", KeyValueNode.make(1, "a"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"), KeyValueNode.make(1, "a"))));
        data.add(Triple.make("set", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(5, "e"), KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"))));
        data.add(Triple.make("set", KeyValueNode.make(5, "e"), ArrayLists.make(KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("set", KeyValueNode.make(4, "d"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"), KeyValueNode.make(4, "d"))));
        data.add(Triple.make("set", KeyValueNode.make(4, "d"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"), KeyValueNode.make(4, "d"))));
        data.add(Triple.make("get", KeyValueNode.make(5, "e"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(4, "d"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("get", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(4, "d"), KeyValueNode.make(5, "e"), KeyValueNode.make(2, "b"))));
        data.add(Triple.make("get", KeyValueNode.make(4, "d"), ArrayLists.make(KeyValueNode.make(5, "e"), KeyValueNode.make(2, "b"), KeyValueNode.make(4, "d"))));
        data.add(Triple.make("get", KeyValueNode.make(5, "e"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(4, "d"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("delete", KeyValueNode.make(4, "d"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("delete", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(5, "e"))));
        data.add(Triple.make("delete", KeyValueNode.make(5, "e"), new ArrayList<>()));

        return data;
    }

    /**
     * Gets the update data of a most recently used cache.
     */
    @Override
    public List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> getMruUpdateData()
    {
        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data = new ArrayList<>();

        data.add(Triple.make("set", KeyValueNode.make(1, "a"), ArrayLists.make(KeyValueNode.make(1, "a"))));
        data.add(Triple.make("set", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"))));
        data.add(Triple.make("set", KeyValueNode.make(3, "c"), ArrayLists.make(KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"), KeyValueNode.make(3, "c"))));
        data.add(Triple.make("set", KeyValueNode.make(4, "d"), ArrayLists.make(KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"), KeyValueNode.make(4, "d"))));
        data.add(Triple.make("set", KeyValueNode.make(1, "a"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(4, "d"), KeyValueNode.make(1, "a"))));
        data.add(Triple.make("set", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(4, "d"), KeyValueNode.make(1, "a"), KeyValueNode.make(2, "b"))));
        data.add(Triple.make("set", KeyValueNode.make(5, "e"), ArrayLists.make(KeyValueNode.make(4, "d"), KeyValueNode.make(1, "a"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("set", KeyValueNode.make(1, "a"), ArrayLists.make(KeyValueNode.make(4, "d"), KeyValueNode.make(5, "e"), KeyValueNode.make(1, "a"))));
        data.add(Triple.make("set", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(4, "d"), KeyValueNode.make(5, "e"), KeyValueNode.make(2, "b"))));
        data.add(Triple.make("set", KeyValueNode.make(5, "e"), ArrayLists.make(KeyValueNode.make(4, "d"), KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("set", KeyValueNode.make(4, "d"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"), KeyValueNode.make(4, "d"))));
        data.add(Triple.make("set", KeyValueNode.make(4, "d"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"), KeyValueNode.make(4, "d"))));
        data.add(Triple.make("get", KeyValueNode.make(5, "e"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(4, "d"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("get", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(4, "d"), KeyValueNode.make(5, "e"), KeyValueNode.make(2, "b"))));
        data.add(Triple.make("get", KeyValueNode.make(4, "c"), ArrayLists.make(KeyValueNode.make(5, "e"), KeyValueNode.make(2, "b"), KeyValueNode.make(4, "d"))));
        data.add(Triple.make("get", KeyValueNode.make(5, "e"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(4, "d"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("delete", KeyValueNode.make(4, "d"), ArrayLists.make(KeyValueNode.make(2, "b"), KeyValueNode.make(5, "e"))));
        data.add(Triple.make("delete", KeyValueNode.make(2, "b"), ArrayLists.make(KeyValueNode.make(5, "e"))));
        data.add(Triple.make("delete", KeyValueNode.make(5, "e"), ArrayLists.make()));

        return data;
    }
}
