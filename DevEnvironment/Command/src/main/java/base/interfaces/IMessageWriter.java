package base.interfaces;

import java.io.PrintWriter;

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

    /**
     * Gets an error writer.
     */
    PrintWriter getErrorWriter();

    /**
     * Gets a warning writer.
     */
    PrintWriter getWarningWriter();

    /**
     * Gets an informational writer.
     */
    PrintWriter getInformationalWriter();
}
