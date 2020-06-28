package command.interfaces;

/**
 * The ICommand interface defines a command.
 */
public interface ICommand {
    /**
     * Sets information of a command.
     */
    void setInformation(ICommandInformation commandInformation);

    /**
     * Gets information of a command.
     */
    ICommandInformation getInformation();

    /**
     * Sets a message writer of a command.
     */
    void setMessageWriter(ICommandMessageWriter messageWriter);

    /**
     * Gets a message writer of a command.
     */
    ICommandMessageWriter getMessageWriter();

    /**
     * Runs the logic of a command.
     */
    void run();
}
