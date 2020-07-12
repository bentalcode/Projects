package algorithms;

import base.BaseException;

/**
 * The AlgorithmsException class implements an exception for capturing errors in the algorithms module.
 */
public class AlgorithmsException extends BaseException {
    /**
     * The AlgorithmsException constructor.
     */
    public AlgorithmsException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The AlgorithmsException constructor.
     */
    public AlgorithmsException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
