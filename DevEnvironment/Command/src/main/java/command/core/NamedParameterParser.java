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
                    arg, CommandConstants.shortNamedParameterPrefix.length(), arg.length() - 1,
                    CommandConstants.helpShortName, 0, CommandConstants.helpShortName.length() - 1)) {

                IPair<String, String> nameAndValue = Pair.make(
                    CommandConstants.helpShortName,
                    CommandConstants.trueValue);

                return ParsingResult.successfulResult(nameAndValue);
            }
            else {
                return this.parseNamedParameter(arg, CommandConstants.shortNamedParameterPrefix);
            }
        }
        else if (isLongNamedParameter(arg)) {
            if (StringEquality.equalsIgnoreCase(
                    arg, CommandConstants.longNamedParameterPrefix.length(), arg.length() - 1,
                    CommandConstants.helpLongName, 0, CommandConstants.helpLongName.length() - 1)) {

                IPair<String, String> nameAndValue = Pair.make(
                    CommandConstants.helpLongName,
                    CommandConstants.trueValue);

                return ParsingResult.successfulResult(nameAndValue);
            }
            else {
                return this.parseNamedParameter(arg, CommandConstants.longNamedParameterPrefix);
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
        int separatorIndex = arg.indexOf(CommandConstants.namedParameterSeparator);

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

            int valueStartIndex = separatorIndex + CommandConstants.namedParameterSeparator.length();
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
            arg.startsWith(CommandConstants.shortNamedParameterPrefix) &&
            !arg.startsWith(CommandConstants.longNamedParameterPrefix);
    }

    /**
     * Checks if a parameter is long named parameter.
     */
    public static boolean isLongNamedParameter(String arg) {
        return arg != null && arg.startsWith(CommandConstants.longNamedParameterPrefix);
    }
}
