package datastructures.collections.interfaces;

import base.interfaces.IPair;
import java.util.List;

/**
 * The ICollectionTestData interface defines the data of the tests of a collection.
 */
public interface ICollectionTestData {
    /**
     * Gets all sequence sub collections of a collection.
     */
    List<IPair<List<Character>, List<List<List<Character>>>>> getAllSequenceSubCollectionsOfCollection();
}
