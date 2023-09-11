package problems.interfaces;

import base.interfaces.IPair;

/**
 * The IEvenlyDistribution interface defines an evenly distribution of integers.
 */
public interface IEvenlyDistribution {
    /**
     * Distributes the numbers evenly.
     */
    IPair<int[], int[]> evenlyDistribute(int[] values);

    /**
     * Distributes the numbers evenly by using a Heuristic algorithm.
     */
    IPair<int[], int[]> evenlyDistributeHeuristic(int[] values);
}
