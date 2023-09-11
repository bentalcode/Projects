package command.interfaces;

/**
 * The ICommandHandler interface defines a command handler for running commands.
 */
public interface ICommandHandler {
    /**
     * Runs a command and returns the exit status.
     */
    int run(ICommand command, String[] arguments);
}
