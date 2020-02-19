package base.core;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * The Stacks class implements complementary APIs for stacks.
 */
public final class Stacks {
    /**
     * Converts a stacks to an array.
     */
    public static <T> List<T> toArray(Stack<T> stack) {
        Conditions.validateNotNull(
            stack,
            "The stack.");

        List<T> result = new ArrayList<>();

        while (!stack.empty()) {
            result.add(stack.pop());
        }

        return result;
    }

    /**
     * Converts a stacks to an array in reverse order.
     */
    public static <T> List<T> toArrayInReverseOrder(Stack<T> stack) {
        Conditions.validateNotNull(
            stack,
            "The stack.");

        int size = stack.size();
        List<T> result = new ArrayList<>(size);

        for (int i = 0; i < size; ++i) {
            result.add(null);
        }

        int insertIndex = size - 1;
        while (!stack.empty() && insertIndex >= 0) {
            result.set(insertIndex, stack.peek());

            stack.pop();
            --insertIndex;
        }

        return result;
    }

    /**
     * The Stacks constructor - Disables the default constructor.
     */
    private Stacks() {
    }
}
