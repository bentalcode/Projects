package problems.interfaces;

/**
 * The IInterleavingStrings interface defines an interleaving strings problem.
 */
public interface IInterleavingStrings {
    /**
     * Checks whether the strings are interleaving with the following constraints:
     * Runtime: O(A+B)
     * Memory: O(A*B)
     * C is said to be interleaving A and B, if it contains all characters of A and B,
     * and order of all characters in individual strings is preserved.
     */
    boolean interleaving1(String left, String right, String interleaving);

    /**
     * Checks whether the strings are interleaving with the following constraints:
     * Runtime: O((A + B)^2)
     * Memory: O(1)
     * C is said to be interleaving A and B, if it contains all characters of A and B,
     * and order of all characters in individual strings is preserved.
     */
    boolean interleaving2(String left, String right, String interleaving);
}
