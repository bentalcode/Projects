package command.core;

import java.nio.file.Path;
import java.nio.file.Paths;

/**
 * The CommandConstants class implements defines constants of a command.
 */
public final class CommandConstants {
    public static final String manifestResourceName = "manifest.json";
    public static final Path defaultManifestPath = Paths.get(manifestResourceName);

    public static final String shortNamedParameterPrefix = "-";
    public static final String longNamedParameterPrefix = "--";
    public static final String namedParameterSeparator = ":=";

    public static final String trueValue = "true";

    public static final String helpShortName = "h";
    public static final String helpLongName = "help";

    /**
     * Disables the default constructor - This is a static class.
     */
    private CommandConstants() {
    }
}
