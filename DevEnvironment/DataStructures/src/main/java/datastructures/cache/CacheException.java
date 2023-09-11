package datastructures.cache;

import datastructures.DataStructureException;

/**
 * The CacheException class implements an exception for capturing errors in the cache module.
 */
public class CacheException extends DataStructureException {
    /**
     * The CacheException constructor.
     */
    public CacheException(String errorMessage) {
        super(errorMessage);
    }
}
