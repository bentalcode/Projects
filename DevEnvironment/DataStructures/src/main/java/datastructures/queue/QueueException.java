package datastructures.queue;

import datastructures.DataStructureException;

/**
 * The QueueException class implements an exception for capturing errors in the queue module.
 */
public class QueueException extends DataStructureException {
    /**
     * The QueueException constructor.
     */
    public QueueException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The QueueException constructor.
     */
    public QueueException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
