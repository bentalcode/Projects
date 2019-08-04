package datastructures.graph.interfaces;

/**
 * The IGraphLogic interface defines detection logic of a graph.
 */
public interface IGraphLogic<TKey extends Comparable<TKey>, TValue> {
    /**
     * Detects whether a graph contains a loop.
     */
    boolean detectLoop();
}
