package graph;

import datastructures.DataStructureException;

/**
 * The GraphException class implements an exception for capturing errors in the graph module.
 */
public class GraphException extends DataStructureException {
    /**
     * The GraphException constructor.
     */
    public GraphException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The GraphException constructor.
     */
    public GraphException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
