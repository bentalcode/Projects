package problems.core;

import base.interfaces.ICalculator;
import java.util.ArrayList;
import java.util.List;

/**
 * The Combination class implements a combination problem.
 */
public final class Combination implements ICalculator<List<List<Integer>>> {
    private final int n;
    private final int k;

    /**
     * The Combination constructor.
     */
    public Combination(int n, int k) {
        this.n = n;
        this.k = k;
    }

    /**
     * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
     */
    @Override
    public List<List<Integer>> calculate() {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> currValues = new ArrayList<>(this.k);

        this.findCombinations(
            1,
            this.n,
            0,
            k,
            currValues,
            result);

        return result;
    }

    /**
     * Finds all the combinations.
     */
    private void findCombinations(
        int startValue,
        int endValue,
        int numberOfSelectedValues,
        int k,
        List<Integer> currValues,
        List<List<Integer>> result) {

        assert(startValue <= endValue + 1);

        if (numberOfSelectedValues == k) {
            List<Integer> newResult = new ArrayList<>(currValues);
            result.add(newResult);
            return;
        }

        if (startValue > endValue) {
            return;
        }

        int numberOfAvailableValues = endValue - startValue + 1;
        int reminderValuesToSelect = k - numberOfSelectedValues;

        if (reminderValuesToSelect > numberOfAvailableValues) {
            return;
        }

        for (int currValue = startValue; currValue <= endValue; ++currValue) {
            currValues.add(currValue);

            this.findCombinations(
                currValue + 1,
                endValue,
                numberOfSelectedValues + 1,
                k,
                currValues,
                result);

            currValues.remove(currValues.size() - 1);
        }
    }
}
