package testbase;

import base.BaseException;

/**
 * The TestBaseException class implements an exception for capturing errors in the test base module.
 */
public class TestBaseException extends BaseException {
    /**
     * The BaseException constructor.
     */
    public TestBaseException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The BaseException constructor.
     */
    public TestBaseException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
