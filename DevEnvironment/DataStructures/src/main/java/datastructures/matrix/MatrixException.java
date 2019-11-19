package datastructures.matrix;

/**
 * The MatrixException class implements an exception for capturing errors in the matrix module.
 */
public class MatrixException extends RuntimeException {
    /**
     * The MatrixException constructor.
     */
    public MatrixException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The MatrixException constructor.
     */
    public MatrixException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
