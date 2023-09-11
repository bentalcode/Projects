package command.core;

import base.core.Pair;
import base.core.ParsingResult;
import base.core.StringEquality;
import base.interfaces.IPair;
import base.interfaces.IParser;
import base.interfaces.IParsingResult;

/**
 * The NamedParameterParser class implements a parser of a named parameter.
 */
public final class NamedParameterParser implements IParser<String, IPair<String, String>> {
    /**
     * The NamedParameterParser constructor.
     */
    public NamedParameterParser() {
    }

    /**
     * Parses a named parameter.
     */
    @Override
    public IParsingResult<IPair<String, String>> parse(String arg) {
        if (isShortNamedParameter(arg)) {
            if (StringEquality.equalsIgnoreCase(
                    arg, CommandConstants.SHORT_NAMED_PARAMETER_PREFIX.length(), arg.length() - 1,
                    CommandConstants.HELP_SHORT_NAME, 0, CommandConstants.HELP_SHORT_NAME.length() - 1)) {

                IPair<String, String> nameAndValue = Pair.make(
                    CommandConstants.HELP_SHORT_NAME,
                    CommandConstants.TRUE_VALUE);

                return ParsingResult.successfulResult(nameAndValue);
            }
            else {
                return this.parseNamedParameter(arg, CommandConstants.SHORT_NAMED_PARAMETER_PREFIX);
            }
        }
        else if (isLongNamedParameter(arg)) {
            if (StringEquality.equalsIgnoreCase(
                    arg, CommandConstants.LONG_NAMED_PARAMETER_PREFIX.length(), arg.length() - 1,
                    CommandConstants.HELP_LONG_NAME, 0, CommandConstants.HELP_LONG_NAME.length() - 1)) {

                IPair<String, String> nameAndValue = Pair.make(
                    CommandConstants.HELP_LONG_NAME,
                    CommandConstants.TRUE_VALUE);

                return ParsingResult.successfulResult(nameAndValue);
            }
            else {
                return this.parseNamedParameter(arg, CommandConstants.LONG_NAMED_PARAMETER_PREFIX);
            }
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
        int separatorIndex = arg.indexOf(CommandConstants.NAMED_PARAMETER_SEPARATOR);

        String name;
        String value;

        if (separatorIndex == -1) {
            //
            // This is a flag parameter...
            //
            int nameStartIndex = prefix.length();
            int nameEndIndex = arg.length() - 1;

            name = arg.substring(nameStartIndex, nameEndIndex + 1);
            value = null;
        }
        else {
            //
            // This is a named parameter...
            //
            int nameStartIndex = prefix.length();
            int nameEndIndex = separatorIndex - 1;

            int valueStartIndex = separatorIndex + CommandConstants.NAMED_PARAMETER_SEPARATOR.length();
            int valueEndIndex = arg.length() - 1;

            name = arg.substring(nameStartIndex, nameEndIndex + 1);
            value = arg.substring(valueStartIndex, valueEndIndex + 1);
        }

        IPair<String, String> namedParameter = Pair.make(name, value);
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
        return
            arg != null &&
            arg.startsWith(CommandConstants.SHORT_NAMED_PARAMETER_PREFIX) &&
            !arg.startsWith(CommandConstants.LONG_NAMED_PARAMETER_PREFIX);
    }

    /**
     * Checks if a parameter is long named parameter.
     */
    public static boolean isLongNamedParameter(String arg) {
        return arg != null && arg.startsWith(CommandConstants.LONG_NAMED_PARAMETER_PREFIX);
    }
}
