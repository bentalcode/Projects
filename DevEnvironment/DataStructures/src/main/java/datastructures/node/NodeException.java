package datastructures.node;

import datastructures.DataStructureException;

/**
 * The NodeException class implements an exception for capturing errors in the node module.
 */
public class NodeException extends DataStructureException {
    /**
     * The NodeException constructor.
     */
    public NodeException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The NodeException constructor.
     */
    public NodeException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
