package cmakebuild;

/**
 * The CMakeBuildException class implements an exception for capturing errors in the CMakeBuild module.
 */
public class CMakeBuildException extends RuntimeException {
    /**
     * The CMakeBuildException constructor.
     */
    public CMakeBuildException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The CMakeBuildException constructor.
     */
    public CMakeBuildException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
