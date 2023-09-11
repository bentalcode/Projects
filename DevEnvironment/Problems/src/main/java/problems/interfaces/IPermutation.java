package problems.interfaces;

import java.util.List;

/**
 * The IPermutation interface defines a permutation problem.
 */
public interface IPermutation {
    /**
     * Calculates permutations.
     */
    <T extends Comparable<T>> List<List<T>> permute(T[] values);

    /**
     * Calculates unique permutations.
     */
    <T extends Comparable<T>> List<List<T>> permuteUnique(T[] values);
}
