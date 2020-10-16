package canmessagegeneratorcommand;

import command.CommandException;

/**
 * The CANMessageGeneratorCommand class captures errors in the CAN Message Generator Command module.
 */
public class CANMessageGeneratorCommandException extends CommandException {
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
