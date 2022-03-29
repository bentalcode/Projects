package algorithms.interfaces;

/**
 * The ICollectionMajority interface defines a collection majority logic.
 */
public interface ICollectionMajority {
    /**
     * Gets a majority of value in an array with O(N) and O(1) memory.
     */
    Integer getMajorityValue(int[] values);

    /**
     * Gets a majority of value in a generic array with O(N) and O(1) memory.
     */
    <T> T getMajority(T[] values);
}
