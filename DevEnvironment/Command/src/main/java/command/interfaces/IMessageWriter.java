package command.interfaces;

/**
 * The IMessageWriter interface defines a writer of messages.
 */
public interface IMessageWriter {
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
