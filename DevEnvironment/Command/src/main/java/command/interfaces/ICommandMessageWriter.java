package command.interfaces;

import base.interfaces.IMessageWriter;

/**
 * The ICommandMessageWriter interface defines a writer of a command messages.
 */
public interface ICommandMessageWriter {
    /**
     * Writes a usage message.
     */
    void writeUsageMessage();

    /**
     * Writes a usage message.
     */
    void writeUsageMessage(boolean status);

    /**
     * Gets the message writer.
     */
    IMessageWriter getMessageWriter();

}
