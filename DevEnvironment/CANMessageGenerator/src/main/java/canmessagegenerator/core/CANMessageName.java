package canmessagegenerator.core;

import canmessagegenerator.CANMessageGeneratorException;
import canmessagegenerator.interfaces.ICANMessageName;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CANMessageName class implements an name of a controller area network message.
 */
public final class CANMessageName implements ICANMessageName {
    private static final int minNameLength = 1;
    private static final int maxNameLength = 32;

    private final char[] name;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * Creates a new message name.
     */
    public static ICANMessageName make(char[] name) {
        return new CANMessageName(name);
    }

    /**
     * The CANMessageName Constructor.
     */
    private CANMessageName(char[] name) {
        validateName(name);

        this.name = name;
    }

    /**
     * Gets the name of a CAN message.
     * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores.
     */
    @Override
    public char[] getName() {
        return this.name;
    }

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return new String(this.name);
    }

    /**
     * Validates the name of the message.
     */
    private void validateName(char[] name) {
        if (name.length < minNameLength || name.length > maxNameLength) {
            String errorMessage = "The length of the message is invalid.";

            this.log.error(errorMessage);
            throw new CANMessageGeneratorException(errorMessage);
        }

        for (char character : name) {
            if (!validNameCharacter(character)) {
                String errorMessage =
                    "The following character: " + character + " is invalid." +
                    "; A character can be between 'a' to 'Z', or a digit, or an underscore.";

                this.log.error(errorMessage);
                throw new CANMessageGeneratorException(errorMessage);
            }
        }
    }

    /**
     * Validates that the name of the character is valid.
     */
    private static boolean validNameCharacter(char character) {
        return
            Character.isDigit(character) ||
            (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') ||
            character == '_';
    }
}
