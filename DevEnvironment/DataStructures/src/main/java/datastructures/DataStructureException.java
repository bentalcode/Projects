package datastructures;

/**
 * The DataStructureException class implements an exception for capturing errors in the data-structure module.
 */
public class DataStructureException extends RuntimeException {
    /**
     * The DataStructureException constructor.
     */
    public DataStructureException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The DataStructureException constructor.
     */
    public DataStructureException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
