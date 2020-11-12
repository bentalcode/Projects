package datastructures.graph.interfaces;

import java.util.List;

/**
 * The IPathFinder interface defines a path finder.
 */
public interface IPathFinder<TKey extends Comparable<TKey>, TValue> {
    /**
     * Finds paths.
     */
    List<IWalk<TKey, TValue>> findPaths(IRoute<TKey, TValue> route);
}
