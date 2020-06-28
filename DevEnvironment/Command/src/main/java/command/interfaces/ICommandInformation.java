package command.interfaces;

/**
 * The ICommandInformation interface defines information of a command.
 */
public interface ICommandInformation {
    /**
     * Gets the process information.
     */
    IProcessInformation getProcessInformation();

    /**
     * Gets the parameters of the command.
     */
    ICommandParameters getParameters();
}
