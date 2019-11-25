package problems.interfaces;

import java.util.List;

/**
 * The ICombinationSum interface defines a combination sum.
 */
public interface ICombinationSum {
    /**
     * Gets the combination sum.
     * All numbers will be positive integers.
     * The result set must not contain duplicate combinations.
     */
    List<List<Integer>> combinationSum(int[] values, int sum);

    /**
     * Gets the combination sum.
     * Each value should be used once.
     * All numbers will be positive integers.
     * The result set must not contain duplicate combinations.
     */
    List<List<Integer>> singleCombinationSum(int[] values, int sum);
}
