package problems.core;


import problems.interfaces.IKPermutation;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The KPermutationTest class implements tests for a k permutation problem.
 */
public final class KPermutationTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The KPermutationTest constructor.
     */
    public KPermutationTest() {
    }

    /**
     * Tests the logic of k permutation.
     */
    @Test
    public void kPermutationTest() {
        int[][] permutations1 = {
            {1}
        };

        int[][] permutations2 = {
            {1, 2},
            {2, 1}
        };

        int[][] permutations3 = {
            {1, 2, 3},
            {1, 3, 2},
            {2, 1, 3},
            {2, 3, 1},
            {3, 1, 2},
            {3, 2, 1}
        };

        int[][] permutations4 = {
            {1, 2, 3, 4},
            {1, 2, 4, 3},
            {1, 3, 2, 4},
            {1, 3, 4, 2},
            {1, 4, 2, 3},
            {1, 4, 3, 2},

            {2, 1, 3, 4},
            {2, 1, 4, 3},
            {2, 3, 1, 4},
            {2, 3, 4, 1},
            {2, 4, 1, 3},
            {2, 4, 3, 1},

            {3, 1, 2, 4},
            {3, 1, 4, 2},
            {3, 2, 1, 4},
            {3, 2, 4, 1},
            {3, 4, 1, 2},
            {3, 4, 2, 1},

            {4, 1, 2, 3},
            {4, 1, 3, 2},
            {4, 2, 1, 3},
            {4, 2, 3, 1},
            {4, 3, 1, 2},
            {4, 3, 2, 1},
        };

        int[][][] permutationSets = {
            permutations1,
            permutations2,
            permutations3,
            permutations4
        };

        int size = 0;
        for (int[][] permutationSet : permutationSets) {
            ++size;

            int k = 0;
            for (int[] permutation : permutationSet) {
                ++k;
                this.testKPermutation(size, k, permutation);
            }
        }
    }

    /**
     * Tests the logic of k permutation.
     */
    private void testKPermutation(int size, int k, int[] expectedResult) {
        IKPermutation kPermutation = new KPermutation();
        int[] result = kPermutation.kPermutation(size, k);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of calculating the k permutation.");
    }
}
