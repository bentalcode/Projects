package datastructures.collections.core;

import base.core.Conditions;
import base.core.Pair;
import base.interfaces.IBinaryComparator;
import base.interfaces.IComparableComparator;
import base.interfaces.IIterator;
import base.interfaces.IPair;
import base.interfaces.IRange;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * The Collections class implements complementary APIs for collections.
 */
public final class Collections {
    private static final String DefaultPrefix = "{";
    private static final String DefaultPostfix = "}";
    private static final String DefaultDelimiter = ", ";

    /**
     * Converts a collection of values into a string.
     */
    public static <T> String toString(IIterator<T> iterator) {
        String prefix = Collections.DefaultPrefix;
        String postfix = Collections.DefaultPostfix;
        String delimiter = Collections.DefaultDelimiter;

        return Collections.toString(
            prefix,
            postfix,
            iterator,
            delimiter);
    }

    /**
     * Converts a collection of values into a string.
     */
    public static <T> String toString(
        String prefix,
        String postfix,
        IIterator<T> iterator,
        String delimiter) {

        Conditions.validateNotNull(
            iterator,
            "The iterator of values.");

        StringBuilder result = new StringBuilder();

        if (prefix != null) {
            result.append(prefix);
        }

        int index = 0;
        while (iterator.hasNext()) {

            if (delimiter != null && index > 0) {
                result.append(delimiter);
            }

            T value = iterator.next();

            result.append(value);

            ++index;
        }

        if (postfix != null) {
            result.append(postfix);
        }

        return result.toString();
    }

    /**
     * Calculates all possible sequences of sub collections of a collection.
     */
    public static <T> List<List<List<T>>> calculateSequenceSubCollectionsOfCollection(List<T> collection) {
        Conditions.validateNotNull(
            collection,
            "The input collection.");

        List<List<List<T>>> result = new ArrayList<>();

        if (collection.isEmpty()) {
            return result;
        }

        List<IPair<List<List<T>>, Integer>> sequences = new ArrayList<>();
        Collections.calculateSequenceSubCollectionsOfCollection(
            collection,
            sequences);

        for (IPair<List<List<T>>, Integer> sequence : sequences) {
            List<List<T>> currSequenceResult = sequence.first();
            int currSequenceSize = sequence.second();

            if (currSequenceSize == collection.size()) {
                result.add(currSequenceResult);
            }
        }

        return result;
    }

    /**
     * Calculates all possible sequences of sub collections of a collection.
     */
    private static <T> void calculateSequenceSubCollectionsOfCollection(
        List<T> collection,
        List<IPair<List<List<T>>, Integer>> result) {

        for (int startIndex = 0; startIndex < collection.size(); ++startIndex) {
            for (int endIndex = startIndex; endIndex < collection.size(); ++endIndex) {

                int collectionSize = endIndex - startIndex + 1;
                List<T> currSubCollection = collection.subList(startIndex, startIndex + collectionSize);
                assert(currSubCollection.size() == collectionSize);

                if (startIndex == 0) {
                    List<List<T>> newSequenceResult = new ArrayList<>();
                    newSequenceResult.add(currSubCollection);
                    int newSequenceSize = currSubCollection.size();

                    result.add(Pair.of(newSequenceResult, newSequenceSize));
                }
                else {
                    int currNumberOfResults = result.size();

                    for (int i = 0; i < currNumberOfResults; ++i) {
                        IPair<List<List<T>>, Integer> currResult = result.get(i);

                        List<List<T>> currSequenceResult = currResult.first();
                        int currSequenceSize = currResult.second();

                        if (startIndex == currSequenceSize) {
                            List<List<T>> newSequenceResult = new ArrayList<>(currSequenceResult);
                            newSequenceResult.add(currSubCollection);
                            int newSequenceSize = currSequenceSize + currSubCollection.size();

                            result.add(Pair.of(newSequenceResult, newSequenceSize));
                        }
                    }
                }
            }
        }
    }

    /**
     * Validate index of a range.
     */
    public static void validateIndex(int index, IRange<Integer> range, String collectionName) {
        Conditions.validateNotNull(
            range,
            "The range.");

        Conditions.validate(
            range.inRange(index),
            "The index of collection: " + collectionName + " is out of range." +
            " Index = " + index + ", Range = " + range);
    }

    /**
     * Validate index of a range.
     */
    public static void validateIndex(int index, int startIndex, int endIndex, String collectionName) {
        Conditions.validateNotNull(
            startIndex <= endIndex,
            "Invalid range of collection: " + collectionName);

        Conditions.validateNotNull(
            index >= startIndex && index <= endIndex,
            "The index of collection: " + collectionName + " is out of range." +
            " Index = " + index + ", Range = [" + startIndex + "-" + endIndex + "]");
    }

    /**
     * The Collections constructor - Disables the default constructor.
     */
    private Collections() {
    }
}
