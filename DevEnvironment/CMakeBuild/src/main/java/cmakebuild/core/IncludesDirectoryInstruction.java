package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeBuildInstruction;
import cmakebuild.interfaces.ICMakeVariable;
import cmakebuild.interfaces.ICMakeWriter;
import java.util.List;

/**
 * The IncludesDirecotoryInstruction class implements an include directory instruction of a CMake build.
 */
public final class IncludesDirectoryInstruction implements ICMakeBuildInstruction {
    private final List<ICMakeVariable> variables;

    /**
     * The SetInstruction constructor.
     */
    public IncludesDirectoryInstruction(List<ICMakeVariable> variables) {
        Conditions.validateNotNull(
            variables,
            "The variables of an includes directory instruction.");

        this.variables = variables;
    }

    /**
     * Compiles a CMake build instruction.
     */
    @Override
    public void compile(ICMakeWriter writer) {
        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        String instruction = ICMakeListsConstants.includeDirectoriesInstruction + "(" ;
        writer.write(instruction);

        writer.rightIndent();

        for (ICMakeVariable variable : this.variables) {
            writer.write(variable.getVariable());
        }

        writer.leftIndent();

        writer.write(")");
    }
}
