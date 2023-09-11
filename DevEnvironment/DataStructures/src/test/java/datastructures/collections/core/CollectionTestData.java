package datastructures.collections.core;

import base.core.ArrayLists;
import base.core.Pair;
import base.core.Strings;
import base.interfaces.IPair;
import datastructures.collections.interfaces.ICollectionTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The CollectionTestData class implements data of tests of a collection.
 */
public final class CollectionTestData implements ICollectionTestData {
    /**
     * The CollectionTestData constructor.
     */
    public CollectionTestData() {
    }

    /**
     * Gets all sequence sub collections of a collection.
     */
    @Override
    public List<IPair<List<Character>, List<List<List<Character>>>>> getAllSequenceSubCollectionsOfCollection() {
        List<IPair<List<Character>, List<List<List<Character>>>>> result = new ArrayList<>();

        result.add(this.getAllSequenceSubCollectionsOfCollection1());
        result.add(this.getAllSequenceSubCollectionsOfCollection2());
        result.add(this.getAllSequenceSubCollectionsOfCollection3());

        return result;
    }

    /**
     * Gets all sequence sub collections of a string1.
     */
    private IPair<List<Character>, List<List<List<Character>>>> getAllSequenceSubCollectionsOfCollection1() {
        List<Character> collection = Strings.toList("");
        List<List<List<Character>>> collectionOfSubCollections = new ArrayList<>();

        return Pair.make(collection, collectionOfSubCollections);
    }

    /**
     * Gets all sequence sub collections of a collection2.
     */
    private IPair<List<Character>, List<List<List<Character>>>> getAllSequenceSubCollectionsOfCollection2() {
        List<Character> collection = Strings.toList("abc");

        List<List<List<Character>>> collectionOfSubCollections = new ArrayList<>();

        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("abc")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("a"), Strings.toList("bc")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("ab"), Strings.toList("c")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("a"), Strings.toList("b"), Strings.toList("c")));

        return Pair.make(collection, collectionOfSubCollections);
    }

    /**
     * Gets all sequence sub collections of a collection3.
     */
    private IPair<List<Character>, List<List<List<Character>>>> getAllSequenceSubCollectionsOfCollection3() {
        List<Character> collection = Strings.toList("abcd");

        List<List<List<Character>>> collectionOfSubCollections = new ArrayList<>();

        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("abcd")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("a"), Strings.toList("bcd")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("ab"), Strings.toList("cd")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("a"), Strings.toList("b"), Strings.toList("cd")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("abc"), Strings.toList("d")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("a"), Strings.toList("bc"), Strings.toList("d")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("ab"), Strings.toList("c"), Strings.toList("d")));
        collectionOfSubCollections.add(ArrayLists.make(Strings.toList("a"), Strings.toList("b"), Strings.toList("c"), Strings.toList("d")));

        return Pair.make(collection, collectionOfSubCollections);
    }
}
