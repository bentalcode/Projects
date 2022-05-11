package problems.core;

import org.junit.Test;

import java.util.Comparator;
import java.util.PriorityQueue;

public final class TestingTest {
    /**
     * The TestingTest constructor.
     */
    public TestingTest() {
    }

    /**
     * Tests the logic.
     */
    @Test
    public void test() {
        ListNode[] lists = {};
        new Solution().mergeKLists(lists);
    }
}

class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }

  class Pair<T1, T2> {
    private final T1 first;
    private final T2 second;

    public Pair(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }

    public T1 first() {
        return this.first;
    }

    public T2 second() {
        return this.second;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        PriorityQueue<Pair<ListNode, Integer>> priorityQueue = new PriorityQueue<>(new Comparator<Pair<ListNode, Integer>>() {
            @Override
            public int compare(Pair<ListNode, Integer> left, Pair<ListNode, Integer> right) {
                if (left == null && right == null) {
                    return 0;
                }

                if (left == null) {
                    return -1;
                }

                if (right == null) {
                    return 1;
                }

                ListNode leftHead = left.first();
                ListNode rightHead = right.first();
                assert(leftHead != null);
                assert(rightHead != null);

                int leftValue = leftHead.val;
                int rightValue = rightHead.val;

                return Integer.compare(leftValue, rightValue);
            }
        });

        for (int index = 0; index < lists.length; ++index) {
            ListNode currHead = lists[index];
            priorityQueue.offer(new Pair<>(currHead, index));
        }

        ListNode head = null;
        ListNode tail = null;

        while (!priorityQueue.isEmpty()) {
            Pair<ListNode, Integer> currRecord = priorityQueue.poll();

            ListNode currHead = currRecord.first();
            int currIndex = currRecord.second();
            ListNode nextHead = currHead.next;

            if (head == null) {
                head = currHead;
                tail = currHead;
            }
            else {
                connect(tail, currHead);
                tail = currHead;
            }

            if (nextHead != null) {
                priorityQueue.offer(new Pair<>(nextHead, currIndex));
            }

            connect(tail, null);
        }

        return head;
    }

    private static void connect(ListNode prevNode, ListNode nextNode) {
        if (prevNode != null) {
            prevNode.next = nextNode;
        }
    }
}


