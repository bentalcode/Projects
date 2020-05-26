package problems.interfaces;

import base.interfaces.ITriplet;
import java.util.List;

/**
 * The IMatchingTriplets interface defines a matching triplets problem.
 */
public interface IMatchingTriplets {
    /**
     * Finds the indexes of matching triplets.
     */
    List<ITriplet<Integer, Integer, Integer>> findMatchingTripletsIndexes(int[] values, int sum);

    /**
     * Finds the values of matching triplets.
     */
    List<ITriplet<Integer, Integer, Integer>> findMatchingTriplets(int[] values, int sum);

    /**
     * Finds the closest matching triplet.
     */
    ITriplet<Integer, Integer, Integer> findClosestMatchingTriplet(int[] values, int sum);

    /**
     * Finds triplets such that sum of two equals to third element.
     */
    List<ITriplet<Integer, Integer, Integer>> findTriplets(int[] values);
}
