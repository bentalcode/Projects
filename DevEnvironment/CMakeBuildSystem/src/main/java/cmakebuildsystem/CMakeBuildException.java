package cmakebuildsystem;

import base.BaseException;

/**
 * The CMakeBuildException class implements an exception for capturing errors in the CMakeBuild module.
 */
public class CMakeBuildException extends BaseException {
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
