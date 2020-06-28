package command.interfaces;

/**
 * The ICommandMessageWriter interface defines a writer of a command message.
 */
public interface ICommandMessageWriter {
    /**
     * Writes a usage message.
     */
    void writeUsageMessage();

    /**
     * Writes an informational message.
     */
    void writeInformationalMessage(String message);

    /**
     * Writes a warning message.
     */
    void writeWarningMessage(String message);

    /**
     * Writes an error message.
     */
    void writeErrorMessage(String message);
}
