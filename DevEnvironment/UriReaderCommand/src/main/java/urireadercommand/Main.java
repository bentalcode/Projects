package urireadercommand;

import base.BaseException;
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
        ICommand command = new UriReaderCommand();

        try (CommandHandler commandHandler = new CommandHandler()) {
            commandHandler.run(command, args);
        }
        catch (BaseException e) {
            String errorMessage =
                "The UriReaderCommand has failed to run due to runtime error: " + e.getMessage() +
                ", Exit Status: 0";

            command.getMessageWriter().writeErrorMessage(errorMessage);
            System.exit(0);
        }
        catch(Exception e) {
            String errorMessage =
                "The UriReaderCommand has failed to run due to an unexpected error: " + e.getMessage() +
                ", Exit Status: -1";

            command.getMessageWriter().writeErrorMessage(errorMessage);

            System.exit(-1);
        }

        System.exit(0);
    }
}