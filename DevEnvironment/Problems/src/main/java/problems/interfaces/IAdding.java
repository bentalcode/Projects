package problems.interfaces;

/**
 * The IAdding interface defines an adding problem.
 */
public interface IAdding {
    /**
     * Adding numbers with a specified base.
     */
    int[] add(int[] left, int[] right, int base);

    /**
     * Adding string numbers with a specified base.
     */
    String addStringNumbers(String left, String right, int base);
}
