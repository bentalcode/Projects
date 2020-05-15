package clionbuild;

/**
 * The CLionBuildException class implements an exception for capturing errors in the CLionBuild module.
 */
public class CLionBuildException extends RuntimeException {
    /**
     * The CLionBuildException constructor.
     */
    public CLionBuildException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The CLionBuildException constructor.
     */
    public CLionBuildException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
