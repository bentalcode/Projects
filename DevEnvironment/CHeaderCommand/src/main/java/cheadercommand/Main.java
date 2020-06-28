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
        ICommand cheaderCommand = new CHeaderCommand();

        try {
            ICommandHandler commandHandler = new CommandHandler();
            commandHandler.run(cheaderCommand, args);
        }
        catch(Exception e) {
            String errorMessage =
                "The CHeaderCommand has failed to run due to an unexpected error: " + e.getMessage() +
                ", Exit Status: -1";

            cheaderCommand.getMessageWriter().writeErrorMessage(errorMessage);

            System.exit(-1);
        }

        System.exit(0);
    }
}
