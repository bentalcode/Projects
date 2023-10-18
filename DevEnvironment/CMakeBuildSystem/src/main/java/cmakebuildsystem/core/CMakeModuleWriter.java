package cmakebuildsystem.core;

import base.core.Conditions;
import base.interfaces.IWriter;
import cmakebuildsystem.interfaces.ICMakeListsManifest;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeModuleManifest;
import cmakebuildsystem.interfaces.ICMakeProjectManifest;
import java.io.Writer;

/**
 * The CMakeModuleWriter class implements a writer of a CMake module.
 */
public final class CMakeModuleWriter implements IWriter {
    private final ICMakeProjectManifest projectManifest;
    private final ICMakeModuleManifest moduleManifest;
    private final ICMakeModule module;
    private final ICMakeBuildContextData contextData;

    /**
     * The CMakeModuleWriter constructor.
     */
    public CMakeModuleWriter(
        ICMakeProjectManifest projectManifest,
        ICMakeModuleManifest moduleManifest,
        ICMakeModule module,
        ICMakeBuildContextData contextData) {

        Conditions.validateNotNull(
            projectManifest,
            "The manifest of a project.");

        Conditions.validateNotNull(
            moduleManifest,
            "The manifest of a module.");

        Conditions.validateNotNull(
            module,
            "The CMake module.");

        Conditions.validateNotNull(
            contextData,
            "The context data.");

        this.projectManifest = projectManifest;
        this.moduleManifest = moduleManifest;
        this.module = module;
        this.contextData = contextData;
    }

    /**
     * Writes a CMake module.
     */
    @Override
    public void write(Writer writer) {
        IWriter cmakeListsWriter = new CMakeListsWriter(
            this.projectManifest.getEditorSettings(),
            this.projectManifest.getIgnoreRules(),
            this.moduleManifest,
            this.module,
            this.contextData);

        cmakeListsWriter.write(writer);
    }
}
