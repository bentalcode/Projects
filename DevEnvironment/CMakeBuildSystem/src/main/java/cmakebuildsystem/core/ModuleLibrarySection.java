package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.*;

import java.util.List;

/**
 * The ModuleLibrarySection class implements a section of a module library.
 */
public final class ModuleLibrarySection implements ICMakeBuildElement {
    private final ICMakeModule rootModule;
    private final ICMakeModule module;
    private final ICMakeModuleManifest moduleManifest;
    private final ICMakeListsManifest cmakeListsManifest;
    private final IIgnoreRules ignoreRules;

    /**
     * The ModuleLibrarySection constructor.
     */
    public ModuleLibrarySection(
        ICMakeModule rootModule,
        ICMakeModule module,
        ICMakeModuleManifest moduleManifest,
        ICMakeListsManifest cmakeListsManifest,
        IIgnoreRules ignoreRules) {

        Conditions.validateNotNull(
            module,
            "The CMake module.");

        Conditions.validateNotNull(
            module,
            "The CMake module manifest.");

        Conditions.validateNotNull(
            cmakeListsManifest,
            "The CMake Lists manifest.");

        Conditions.validateNotNull(
            ignoreRules,
            "The ignore rules.");

        this.rootModule = rootModule;
        this.module = module;
        this.moduleManifest = moduleManifest;
        this.cmakeListsManifest = cmakeListsManifest;
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
            this.cmakeListsManifest,
            this.ignoreRules);

        elements.add(module);

        //
        // Add section for module type command...
        //
        List<ICMakeBuildCommand> moduleTypeCommands =
            this.moduleManifest.getType().createModuleCommands(this.module.getName());

        for (ICMakeBuildCommand command : moduleTypeCommands) {
            elements.add(command);
        }

        elements.compile(writer, contextData);
    }
}
