package cmakebuild.core;

import base.core.Conditions;
import base.interfaces.IPair;
import cmakebuild.interfaces.ICMakeBuildInstruction;
import cmakebuild.interfaces.ICMakeVariable;
import cmakebuild.interfaces.ICMakeWriter;
import java.util.List;

/**
 * The AddLibraryInstruction class implements an add library instruction of a CMake build.
 */
public final class AddLibraryInstruction implements ICMakeBuildInstruction {
    private final List<IPair<String, ICMakeVariable>> modules;

    /**
     * The AddLibraryInstruction constructor.
     */
    public AddLibraryInstruction(List<IPair<String, ICMakeVariable>> modules) {
        Conditions.validateNotNull(
            modules,
            "The modules of an library instruction.");

        this.modules = modules;
    }

    /**
     * Compiles a CMake build instruction.
     */
    @Override
    public void compile(ICMakeWriter writer) {
        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        String instruction = ICMakeListsConstants.addLibraryInstruction + "(";
        writer.write(instruction);

        writer.rightIndent();

        for (IPair<String, ICMakeVariable> module : this.modules) {
            String moduleName = module.first();
            String moduleSources = module.second().getVariable();

            String moduleEntry = moduleName + " " + moduleSources;

            writer.write(moduleEntry);
        }

        writer.leftIndent();

        writer.write(")");
    }
}
