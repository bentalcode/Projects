package canmessagegenerator;

import base.BaseException;

/**
 * The CANMessageGeneratorException class implements an exception for capturing errors
 * in the CAN Message Generator module.
 */
public final class CANMessageGeneratorException extends BaseException {
    /**
     * The CANMessageGeneratorException constructor.
     */
    public CANMessageGeneratorException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The CANMessageGeneratorException constructor.
     */
    public CANMessageGeneratorException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
