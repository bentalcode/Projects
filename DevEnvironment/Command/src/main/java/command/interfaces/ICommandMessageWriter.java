package command.interfaces;

/**
 * The ICommandMessageWriter interface defines a writer of a command message.
 */
public interface ICommandMessageWriter extends IMessageWriter {
    /**
     * Writes a usage message.
     */
    void writeUsageMessage();
}
