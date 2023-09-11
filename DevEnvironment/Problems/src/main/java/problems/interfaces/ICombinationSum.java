package problems.interfaces;

import java.util.List;
import java.util.Set;

/**
 * The ICombinationSum interface defines a combination sum problem.
 */
public interface ICombinationSum {
    /**
     * Gets the combination sum.
     * All numbers will be positive integers.
     * The result set must not contain duplicate combinations.
     */
    Set<List<Integer>> combinationSum(int[] values, int sum);

    /**
     * Gets the combination sum.
     * Each value should be used once.
     * The result set must not contain duplicate combinations.
     */
    Set<List<Integer>> singleCombinationSum(int[] values, int sum);
}
