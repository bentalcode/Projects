package command.interfaces;

/**
 * The ICommandParser interface defines a command parser.
 */
public interface ICommandParser {
    /**
     * Parses parameters of a command.
     */
    IParsingResult<ICommandParameters> parse(String[] arguments);
}
