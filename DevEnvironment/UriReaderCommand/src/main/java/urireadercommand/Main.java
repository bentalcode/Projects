package urireadercommand;

import command.core.CommandHandler;
import command.interfaces.ICommand;
import urireadercommand.core.UriReaderCommand;

/**
 * The main entry of the command.
 */
public final class Main {
    /**
     * The main entry.
     */
    public static void main(String[] args) {
        int exitStatus;

        ICommand command = new UriReaderCommand();

        try (CommandHandler commandHandler = new CommandHandler()) {
            exitStatus = commandHandler.run(command, args);
        }

        System.exit(exitStatus);
    }
}
