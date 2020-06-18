package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeWriter;
import java.util.List;

/**
 * The SetCommand class implements a set command of a CMake build.
 */
public final class SetCommand extends CMakeBuildCommand {
    private final List<String> items;

    /**
     * The SetCommand constructor.
     */
    public SetCommand(String subjectName, List<String> items) {
        super(
            ICMakeListsConstants.setCommand,
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
