package problems.core;

import base.core.Conditions;
import base.core.Doublet;
import base.interfaces.ICalculator;
import base.interfaces.IDoublet;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import problems.interfaces.ISparseSimilarityResult;

/**
 * The SparseSimilarity class implements a sparse similarity.
 */
public final class SparseSimilarity<T extends Comparable<T>> implements ICalculator<List<ISparseSimilarityResult>> {
    private final List<List<T>> collections;

    /**
     * The SparseSimilarity constructor.
     */
    public SparseSimilarity(List<List<T>> collections) {
        Conditions.validateNotNull(
            collections,
            "The collections of elements.");

        this.collections = collections;
    }

    /**
     * Given collections of elements, calculate the sparse of similarity of each pair of collections.
     * Sparse of Similarity = Size of intersection / Size of union
     */
    @Override
    public List<ISparseSimilarityResult> calculate() {
        List<ISparseSimilarityResult> result = new ArrayList<>();

        Map<IDoublet<Integer, Integer>, ISparseSimilarityResult> collectionResultMap = new HashMap<>();

        if (this.collections.isEmpty()) {
            return result;
        }

        List<List<T>> uniqueCollections = createUniqueCollections(this.collections);
        List<CollectionElement<T>> collectionsElements = createCollectionsElements(uniqueCollections);
        sort(collectionsElements);

        calculateCollectionsIntersections(
            collectionsElements,
            result,
            collectionResultMap);

        calculateSparseSimilarity(
            uniqueCollections,
            result);

        return result;
    }

    /**
     * Calculates the collections intersections.
     */
    private static <T extends Comparable<T>> void calculateCollectionsIntersections(
        List<CollectionElement<T>> collection,
        List<ISparseSimilarityResult> result,
        Map<IDoublet<Integer, Integer>, ISparseSimilarityResult> collectionResultMap) {

        int currIndex = 0;

        while (currIndex < collection.size()) {
            CollectionElement<T> currElement = collection.get(currIndex);
            T currValue = currElement.getValue();
            int currId = currElement.getCollectionId();

            int nextIndex = currIndex + 1;

            while (nextIndex < collection.size()) {
                CollectionElement<T> nextElement = collection.get(nextIndex);
                T nextValue = nextElement.getValue();
                int nextId = nextElement.getCollectionId();

                if (currValue != nextValue) {
                    break;
                }

                if (currId != nextId) {
                    addCollectionIntersection(
                        currId,
                        nextId,
                        result,
                        collectionResultMap);
                }

                ++nextIndex;
            }

            ++currIndex;
        }
    }

    /**
     * Calculates the collections sparse similarity.
     */
    private static <T extends Comparable<T>> void calculateSparseSimilarity(
        List<List<T>> collections,
        List<ISparseSimilarityResult> results) {

        for (ISparseSimilarityResult result : results) {
            int id1 = result.getCollectionId1();
            int id2 = result.getCollectionId2();

            List<T> collection1 = collections.get(id1);
            List<T> collection2 = collections.get(id2);

            int intersectionSize = result.getIntersectionSize();

            int unionSize = collection1.size() + collection2.size() - intersectionSize;
            result.setUnionSize(unionSize);

            double sparseSimilarity = (double)intersectionSize / (double)unionSize;
            result.setSparseSimilarity(sparseSimilarity);
        }
    }

    /**
     * Creates unique collections.
     */
    private static <T extends Comparable<T>> List<List<T>> createUniqueCollections(List<List<T>> collections) {
        List<List<T>> result = new ArrayList<>(collections.size());

        for (List<T> collection : collections) {
            List<T> uniqueCollection = createUniqueCollection(collection);
            result.add(uniqueCollection);
        }

        return result;
    }

    /**
     * Creates a unique collection.
     */
    private static <T extends Comparable<T>> List<T> createUniqueCollection(List<T> collection) {
        List<T> result = new ArrayList<>();

        if (collection.isEmpty()) {
            return result;
        }

        Collections.sort(collection);
        T currElement = collection.get(0);
        result.add(currElement);

        int prevIndex = 0;
        int currIndex = 1;

        while (currIndex < collection.size()) {
            T prevValue = collection.get(prevIndex);
            T currValue = collection.get(currIndex);

            if (!Objects.equals(currValue, prevValue)) {
                result.add(currValue);
            }

            prevIndex = currIndex;
            ++currIndex;
        }

        return result;
    }

    /**
     * Creates collections of elements.
     */
    private static <T extends Comparable<T>> List<CollectionElement<T>> createCollectionsElements(List<List<T>> collections) {
        List<CollectionElement<T>> result = new ArrayList<>();

        int collectionId = 0;
        for (List<T> collection : collections) {
            for (T value : collection) {
                CollectionElement<T> collectionElement = new CollectionElement<>(collectionId, value);
                result.add(collectionElement);
            }

            ++collectionId;
        }

        return result;
    }

    /**
     * Sorts the elements by value.
     */
    private static <T extends Comparable<T>> void sort(List<CollectionElement<T>> elements) {
        elements.sort((left, right) -> {
            if (left == null && right == null) {
                return 0;
            }

            if (left == null) {
                return -1;
            }

            if (right == null) {
                return 1;
            }

            return left.getValue().compareTo(right.getValue());
        });
    }

    /**
     * Adds a collection intersection.
     */
    private static void addCollectionIntersection(
        int id1,
        int id2,
        List<ISparseSimilarityResult> result,
        Map<IDoublet<Integer, Integer>, ISparseSimilarityResult> collectionResultMap) {

        IDoublet<Integer, Integer> collectionPairId = createCollectionPairId(id1, id2);

        ISparseSimilarityResult currResult;

        if (!collectionResultMap.containsKey(collectionPairId)) {
            currResult = new SparseSimilarityResult(
                collectionPairId.first(),
                collectionPairId.second());

            result.add(currResult);
            collectionResultMap.put(collectionPairId, currResult);
        }
        else {
            currResult = collectionResultMap.get(collectionPairId);
        }

        int newIntersectionSize = currResult.getIntersectionSize() + 1;
        currResult.setIntersectionSize(newIntersectionSize);
    }

    /**
     * Creates a collection pair id.
     */
    private static IDoublet<Integer, Integer> createCollectionPairId(int id1, int id2) {
        int firstId;
        int secondId;

        if (id1 <= id2) {
            firstId = id1;
            secondId = id2;
        }
        else {
            firstId = id2;
            secondId = id1;
        }

        return Doublet.make(firstId, secondId);
    }

    /**
     * The CollectionElement class implements an element of a collection.
     */
    private static final class CollectionElement<T extends Comparable<T>> {
        private final int collectionId;
        private final T value;

        /**
         * The CollectionElement constructor.
         */
        public CollectionElement(int collectionId, T value) {
            this.collectionId = collectionId;
            this.value = value;
        }

        /**
         * Gets an identifier of the collection.
         */
        public int getCollectionId() {
            return this.collectionId;
        }

        /**
         * Gets a value of the collection.
         */
        public T getValue() {
            return this.value;
        }
    }
}
