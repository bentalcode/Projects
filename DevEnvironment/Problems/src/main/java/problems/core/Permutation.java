package problems.core;

import base.core.ArrayLists;
import base.core.Arrays;
import base.core.EqualBuilder;
import problems.interfaces.IPermutation;
import java.util.ArrayList;
import java.util.List;

/**
 * The Permutation class implements a permutation.
 */
public final class Permutation implements IPermutation {
    /**
     * Calculates permutations.
     */
    @Override
    public <T extends Comparable<T>> List<List<T>> permute(T[] values) {
        List<List<T>> results = new ArrayList<>();
        this.permute(values, 0 , results);
        return results;
    }

    /**
     * Calculates unique permutations.
     */
    @Override
    public <T extends Comparable<T>> List<List<T>> permuteUnique(T[] values) {
        List<List<T>> results = new ArrayList<>();
        this.permuteUnique(values, 0 , results);
        return results;
    }

    /**
     * Calculates permutations.
     */
    private <T extends Comparable<T>> void permute(T[] values, int index, List<List<T>> results) {
        assert(index >= 0 && index <= values.length);

        if (index == values.length) {
            List<T> newResult = ArrayLists.make(values);
            results.add(newResult);
            return;
        }

        for (int i = index; i < values.length; ++i) {
            Arrays.swap(values, i, index);
            this.permute(values, index + 1, results);
            Arrays.swap(values, i, index);
        }
    }

    /**
     * Calculates unique permutations.
     */
    private <T extends Comparable<T>> void permuteUnique(T[] values, int index, List<List<T>> results) {
        assert(index >= 0 && index <= values.length);

        if (index == values.length) {
            List<T> newResult = ArrayLists.make(values);
            this.addUniqueResult(newResult, results);
            return;
        }

        for (int i = index; i < values.length; ++i) {
            Arrays.swap(values, i, index);
            this.permuteUnique(values, index + 1, results);
            Arrays.swap(values, i, index);
        }
    }

    /**
     * Adds a unique result.
     */
    private <T extends Comparable<T>> void addUniqueResult(List<T> newResult, List<List<T>> results) {
        for (List<T> currResult : results) {

            boolean equals = new EqualBuilder().withCollection(
                currResult,
                newResult).build();

            if (equals) {
                return;
            }
        }

        results.add(newResult);
    }
}
