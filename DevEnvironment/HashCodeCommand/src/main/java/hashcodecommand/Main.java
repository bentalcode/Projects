package hashcodecommand;

import hashcodecommand.core.HashCodeCommand;
import command.core.CommandHandler;
import command.interfaces.ICommand;

/**
 * The main entry of the command.
 */
public final class Main {
    /**
     * The main entry.
     */
    public static void main(String[] args) {
        int exitStatus;

        ICommand command = new HashCodeCommand();

        try (CommandHandler commandHandler = new CommandHandler()) {
            exitStatus = commandHandler.run(command, args);
        }

        System.exit(exitStatus);
    }
}
