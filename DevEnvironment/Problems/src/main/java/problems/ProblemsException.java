package problems;

/**
 * The ProblemsExceptions class implements an exception for capturing errors in the problems module.
 */
public class ProblemsException extends RuntimeException {
    /**
     * The ProblemsException constructor.
     */
    public ProblemsException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The ProblemsException constructor.
     */
    public ProblemsException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
