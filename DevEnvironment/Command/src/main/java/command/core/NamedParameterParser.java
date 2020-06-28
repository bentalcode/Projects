package command.core;

import base.core.Pair;
import base.interfaces.IPair;
import command.interfaces.IParsingResult;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The NamedParameterParser class implements a named parameter parser.
 */
public final class NamedParameterParser {
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The NamedParameterParser constructor.
     */
    public NamedParameterParser() {
    }

    /**
     * Parses a named parameter.
     */
    public IParsingResult<IPair<String, String>> parse(String arg) {
        if (isShortNamedParameter(arg)) {
            return this.parseNamedParameter(arg, ICommandConstants.shortNamedParameterPrefix);
        }
        else if (isLongNamedParameter(arg)) {
            return this.parseNamedParameter(arg, ICommandConstants.longNamedParameterPrefix);
        }
        else {
            String errorMessage = "The argument: " + arg + " is not a named parameter.";
            return ParsingResult.failureResult(errorMessage);
        }
    }

    /**
     * Parses a named parameter.
     */
    private IParsingResult<IPair<String, String>> parseNamedParameter(String arg, String prefix) {
        int separatorIndex = arg.indexOf(ICommandConstants.namedParameterSeparator);

        String name;
        String value;

        if (separatorIndex == -1) {
            name = arg;
            value = ICommandConstants.trueValue;
        }
        else {
            int nameStartIndex = prefix.length();
            int nameEndIndex = separatorIndex - 1;

            int valueStartIndex = separatorIndex + ICommandConstants.namedParameterSeparator.length();
            int valueEndIndex = arg.length() - 1;

            name = arg.substring(nameStartIndex, nameEndIndex + 1);
            value = arg.substring(valueStartIndex, valueEndIndex + 1);
        }

        IPair<String, String> namedParameter = Pair.of(name, value);
        return ParsingResult.successfulResult(namedParameter);
    }

    /**
     * Checks if a parameter is named parameter.
     */
    public static boolean isNamedParameter(String arg) {
        return isShortNamedParameter(arg) || isLongNamedParameter(arg);
    }

    /**
     * Checks if a parameter is short named parameter.
     */
    public static boolean isShortNamedParameter(String arg) {
        return arg != null && arg.startsWith(ICommandConstants.shortNamedParameterPrefix);
    }

    /**
     * Checks if a parameter is long named parameter.
     */
    public static boolean isLongNamedParameter(String arg) {
        return arg != null && arg.startsWith(ICommandConstants.longNamedParameterPrefix);
    }
}
