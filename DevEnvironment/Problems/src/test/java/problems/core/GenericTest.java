package problems.core;

import java.util.*;

import base.core.Pair;
import datastructures.expressiontree.interfaces.IExpressionTree;
import org.junit.Test;

public final class GenericTest {
    /**
     * The GenericTest constructor.
     */
    public GenericTest() {
    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    /**
     * Tests the logic of the generic test.
     */
    @Test
    public void test() {
        int results = new Solution().numTrees(3);
    }

    class Solution {
        public int numTrees(int n) {
            if (n < 0) {
                throw new IllegalArgumentException("The input N has to be equal or greater than zero.");
            }

            if (n <= 1) {
                return 1;
            }

            int startIndex = 1;
            int endIndex = n;

            Map<Integer, Integer> cache = new HashMap<>();
            //cache.put(1, 1);

            return numOfTrees(startIndex, endIndex, cache);
        }

        private int numOfTrees(
                int startIndex,
                int endIndex,
                Map<Integer, Integer> cache) {

            int length = indexesSize(startIndex, endIndex);

            if (cache.containsKey(length)) {
                return cache.get(length);
            }

            int counter = calculateNumOfTrees(startIndex, endIndex, cache);

            cache.put(length, counter);

            return length;
        }

        private int calculateNumOfTrees(
                int startIndex,
                int endIndex,
                Map<Integer, Integer> cache) {

            if (startIndex >= endIndex) {
                return 1;
            }

            int counter = 0;

            for (int index = startIndex; index <= endIndex; ++index) {
                int leftCounter = numOfTrees(startIndex, index - 1, cache);
                int rightCounter = numOfTrees(index + 1, endIndex, cache);

                counter += (leftCounter * rightCounter);
            }

            return counter;
        }

        private int indexesSize(int startIndex, int endIndex) {
            return startIndex <= endIndex ? endIndex - startIndex + 1 : 0;
        }
    }
}
