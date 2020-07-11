package cheadercommand;

import cheadercommand.core.CHeaderCommand;
import command.core.CommandHandler;
import command.interfaces.ICommand;
import command.interfaces.ICommandHandler;

/**
 * The main entry of the command.
 */
public final class Main {
    /**
     * The main entry.
     */
    public static void main(String[] args) {
        ICommand command = new CHeaderCommand();

        try {
            ICommandHandler commandHandler = new CommandHandler();
            commandHandler.run(command, args);
        }
        catch(Exception e) {
            String errorMessage =
                "The CHeaderCommand has failed to run due to an unexpected error: " + e.getMessage() +
                ", Exit Status: -1";

            command.getMessageWriter().writeErrorMessage(errorMessage);

            System.exit(-1);
        }

        System.exit(0);
    }
}
