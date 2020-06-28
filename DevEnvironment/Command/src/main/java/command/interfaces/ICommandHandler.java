package command.interfaces;

/**
 * The ICommandHandler interface defines a command handler for running commands.
 */
public interface ICommandHandler {
    /**
     * Runs a command.
     *
     * Returns true if running the command successfully.
     * Returns false if failing to run the command.
     */
    boolean run(ICommand command, String[] arguments);
}
