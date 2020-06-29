package command.core;

import java.nio.file.Path;
import java.nio.file.Paths;

/**
 * The ICommandConstants interface defines constants of a command.
 */
public interface ICommandConstants {
    String manifestResourceName = "manifest.json";
    Path defaultManifestPath = Paths.get(manifestResourceName);

    String shortNamedParameterPrefix = "-";
    String longNamedParameterPrefix = "--";
    String namedParameterSeparator = ":=";

    String trueValue = "true";

    String helpShortName = "h";
    String helpLongName = "help";
}
