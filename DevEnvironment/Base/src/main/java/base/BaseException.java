package base;

/**
 * The BaseException class implements an exception for capturing errors in the base module.
 */
public class BaseException extends RuntimeException {
    /**
     * The BaseException constructor.
     */
    public BaseException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The BaseException constructor.
     */
    public BaseException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
