package command.interfaces;

import base.interfaces.IMessageWriter;

/**
 * The ICommand interface defines a command.
 */
public interface ICommand {
    /**
     * Sets process information of a command.
     */
    void setProcessInformation(IProcessInformation processInformation);

    /**
     * Gets process information of a command.
     */
    IProcessInformation getProcessInformation();

    /**
     * Sets parameters of a command.
     */
    void setParameters(ICommandParameters parameters);

    /**
     * Gets parameters of a command.
     */
    ICommandParameters getParameters();

    /**
     * Sets a message writer of a command.
     */
    void setMessageWriter(IMessageWriter messageWriter);

    /**
     * Gets a message writer of a command.
     */
    IMessageWriter getMessageWriter();

    /**
     * Runs the logic of a command.
     */
    void run();
}
