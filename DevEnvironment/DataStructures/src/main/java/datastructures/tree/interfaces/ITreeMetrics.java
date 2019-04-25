package datastructures.tree.interfaces;

/**
 * The ITreeMetrics interface defines metrics of a tree.
 */
public interface ITreeMetrics {
    /**
     * Gets the height of a tree.
     */
    int getHeight();

    /**
     * Gets the number of nodes of a tree.
     */
    int getNumberOfNodes();

    /**
     * Gets the number of inner nodes of a tree.
     */
    int getNumberOfInnerNodes();

    /**
     * Gets the number of leaf nodes of a tree.
     */
    int getNumberOfLeafNodes();

    /**
     * Gets the size in bytes of a tree.
     */
    long getSizeInBytes();
}
