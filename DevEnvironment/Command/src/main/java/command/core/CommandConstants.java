package command.core;

import java.nio.file.Path;
import java.nio.file.Paths;

/**
 * The CommandConstants class implements defines constants of a command.
 */
public final class CommandConstants {
    public static final String MANIFEST_RESOURCE_NAME = "manifest.json";
    public static final Path DEFAULT_MANIFEST_PATH = Paths.get(MANIFEST_RESOURCE_NAME);

    public static final String SHORT_NAMED_PARAMETER_PREFIX = "-";
    public static final String LONG_NAMED_PARAMETER_PREFIX = "--";
    public static final String NAMED_PARAMETER_SEPARATOR = ":=";

    public static final String TRUE_VALUE = "true";

    public static final String HELP_SHORT_NAME = "h";
    public static final String HELP_LONG_NAME = "help";

    /**
     * Disables the default constructor - This is a static class.
     */
    private CommandConstants() {
    }
}
