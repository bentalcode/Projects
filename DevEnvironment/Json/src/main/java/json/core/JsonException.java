package json.core;

import base.BaseException;

/**
 * The JsonException class implements an exception for capturing errors in the json module.
 */
public class JsonException extends BaseException {
    /**
     * The JsonException constructor.
     */
    public JsonException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The JsonException constructor.
     */
    public JsonException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
