package canmessagegeneratorcommand;

import base.BaseException;
import canmessagegeneratorcommand.core.CANMessageGeneratorCommand;
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
        ICommand command = new CANMessageGeneratorCommand();

        try (CommandHandler commandHandler = new CommandHandler()) {
            commandHandler.run(command, args);
        }
        catch (BaseException e) {
            String errorMessage =
                "The CANMessageGenerator has failed to run due to runtime error: " + e.getMessage() +
                ", Exit Status: 0";

            command.getMessageWriter().writeErrorMessage(errorMessage);
            System.exit(0);
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