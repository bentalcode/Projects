package problems.interfaces;

import base.interfaces.IPair;

/**
 * The IEventlyDistribution interface defines an interface of an evently distribution of integers.
 */
public interface IEventlyDistribution {
    /**
     * Distributes the numbers evenly.
     */
    IPair<int[], int[]> evenlyDistribute(int[] values);

    /**
     * Distributes the numbers evenly by using a Heuristic algorithm.
     */
    IPair<int[], int[]> evenlyDistributeHeuristic(int[] values);
}
