package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeBuildElement;
import cmakebuild.interfaces.ICMakeBuildElementList;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeWriter;
import cmakebuild.interfaces.IIgnoreRules;

/**
 * The ModuleLibrarySection class implements a section of a module library.
 */
public final class ModuleLibrarySection implements ICMakeBuildElement {
    private final ICMakeModule rootModule;
    private final ICMakeModule module;
    private final IIgnoreRules ignoreRules;

    /**
     * The ModuleLibrarySection constructor.
     */
    public ModuleLibrarySection(
        ICMakeModule rootModule,
        ICMakeModule module,
        IIgnoreRules ignoreRules) {

        Conditions.validateNotNull(
            module,
            "The CMake module.");

        Conditions.validateNotNull(
            ignoreRules,
            "The ignore rules.");

        this.rootModule = rootModule;
        this.module = module;
        this.ignoreRules = ignoreRules;
    }

    /**
     * Compiles a CMake build.
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

        ICMakeBuildElementList elements = new CMakeBuildElementList();

        //
        // Add the module section...
        //
        ICMakeBuildElement module = new ModuleSection(
            this.rootModule,
            this.module,
            this.ignoreRules);

        elements.add(module);

        //
        // Add the add library command...
        //
        ICMakeBuildElement addLibraryCommand = new AddLibraryCommand(this.module.getName());
        elements.add(addLibraryCommand);

        elements.compile(writer, contextData);
    }
}
