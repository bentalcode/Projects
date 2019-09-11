package datastructures.hashmap;

import datastructures.DataStructureException;

/**
 * The HashMapException class implements an exception for capturing errors in the hash map module.
 */
public class HashMapException extends DataStructureException {
    /**
     * The HashMapException constructor.
     */
    public HashMapException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The HashMapException constructor.
     */
    public HashMapException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
