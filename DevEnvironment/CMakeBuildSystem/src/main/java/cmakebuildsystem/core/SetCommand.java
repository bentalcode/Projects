package cmakebuildsystem.core;

import base.core.ArrayLists;
import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeBuildCommand;
import cmakebuildsystem.interfaces.ICMakeWriter;
import java.util.List;

/**
 * The SetCommand class implements a set command of a CMake build.
 */
public final class SetCommand extends CMakeBuildCommand {
    private final List<String> items;

    /**
     * Creates a new set command.
     */
    public static ICMakeBuildCommand make(String subjectName, String value) {
        return new SetCommand(subjectName, ArrayLists.make(value));
    }

    /**
     * Creates a new set command.
     */
    public static ICMakeBuildCommand make(String subjectName, List<String> items) {
        return new SetCommand(subjectName, items);
    }

    /**
     * The SetCommand constructor.
     */
    private SetCommand(String subjectName, List<String> items) {
        super(
            CMakeListsConstants.SET_COMMAND,
            subjectName);

        Conditions.validateNotNull(
            items,
            "The items of a set command.");

        this.items = items;
    }

    /**
     * Compiles a CMake build element.
     */
    @Override
    public void compile(
        ICMakeWriter writer,
        ICMakeBuildContextData contextData) {

        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        Conditions.validateNotNull(
            contextData,
            "The context data.");

        this.begin(writer);
        this.addParameters(writer, this.items);
        this.end(writer);
    }
}
