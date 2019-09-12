package datastructures.hashmap.interfaces;

import java.util.List;

/**
 * The IHashMapTestData interface defines the data of the tests of a hash map.
 */
public interface IHashMapTestData {
    /**
     * Gets the data of hash maps.
     */
    List<IMapData<Integer, String>> getData();
}
