package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeBuildInstruction;
import cmakebuild.interfaces.ICMakeVariable;
import cmakebuild.interfaces.ICMakeWriter;
import java.util.List;

/**
 * The SetInstruction class implements a set instruction of a CMake build.
 */
public final class SetInstruction implements ICMakeBuildInstruction {
    private final ICMakeVariable variable;
    private final List<String> items;

    /**
     * The SetInstruction constructor.
     */
    public SetInstruction(ICMakeVariable variable, List<String> items) {
        Conditions.validateNotNull(
            variable,
            "The variable of a set instruction.");

        Conditions.validateNotNull(
            items,
            "The items of a set instruction.");

        this.variable = variable;
        this.items = items;
    }

    /**
     * Compiles a CMake build instruction.
     */
    @Override
    public void compile(ICMakeWriter writer) {
        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        String instruction = ICMakeListsConstants.setInstruction + "(" + this.variable.getName();
        writer.write(instruction);

        writer.rightIndent();

        for (String item : items) {
            writer.write(item);
        }

        writer.leftIndent();

        writer.write(")");
    }
}
