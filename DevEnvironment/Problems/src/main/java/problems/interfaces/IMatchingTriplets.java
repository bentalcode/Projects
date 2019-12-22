package problems.interfaces;

import base.interfaces.ITriplet;
import java.util.List;
import java.util.Set;

/**
 * The IMatchingTriplets interface defines a matching triplets problem.
 */
public interface IMatchingTriplets {
    /**
     * Gets the matching triplets indexes.
     */
    List<ITriplet<Integer, Integer, Integer>> getMatchingTripletsIndexes(int[] values, int sum);

    /**
     * Gets the matching triplets values.
     */
    Set<ITriplet<Integer, Integer, Integer>> getMatchingTriplets(int[] values, int sum);

    /**
     * Gets the closest matching triplet.
     */
    ITriplet<Integer, Integer, Integer> getClosestMatchingTriplet(int[] values, int sum);
}
