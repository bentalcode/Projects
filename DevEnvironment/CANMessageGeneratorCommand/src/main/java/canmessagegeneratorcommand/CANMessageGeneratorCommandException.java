package canmessagegeneratorcommand;

import base.BaseException;

/**
 * The CANMessageGeneratorCommandException class implements an exception
 * for capturing errors in the CAN Message Generator Command module.
 */
public class CANMessageGeneratorCommandException extends BaseException {
    /**
     * The CANMessageGeneratorCommandException constructor.
     */
    public CANMessageGeneratorCommandException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The CANMessageGeneratorCommandException constructor.
     */
    public CANMessageGeneratorCommandException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
