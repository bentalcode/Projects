package base.core;

/**
 * The DestructorException class implements an exception for capturing errors during a destruction of objects.
 */
public class DestructorException extends BaseException {
    /**
     * The DestructorException constructor.
     */
    public DestructorException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The DestructorException constructor.
     */
    public DestructorException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
