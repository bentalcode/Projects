package cmakebuild.core;

import base.core.Conditions;
import base.interfaces.IWriter;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeModuleManifest;
import cmakebuild.interfaces.IEditorSettings;
import cmakebuild.interfaces.IIgnoreRules;
import java.io.Writer;

/**
 * The CMakeModuleWriter class implements a writer of a CMake module.
 */
public final class CMakeModuleWriter implements IWriter {
    private final ICMakeModuleManifest manifest;
    private final IEditorSettings editorSettings;
    private final IIgnoreRules ignoreRules;
    private final ICMakeModule module;

    /**
     * The CMakeModuleWriter constructor.
     */
    public CMakeModuleWriter(
        ICMakeModuleManifest manifest,
        IEditorSettings editorSettings,
        IIgnoreRules ignoreRules,
        ICMakeModule module) {

        Conditions.validateNotNull(
            manifest,
            "The manifest of a CMake module.");

        Conditions.validateNotNull(
            editorSettings,
            "The settings of an editor.");

        Conditions.validateNotNull(
            module,
            "The CMake module.");

        Conditions.validateNotNull(
            ignoreRules,
            "The ignore rules.");

        this.manifest = manifest;
        this.editorSettings = editorSettings;
        this.module = module;
        this.ignoreRules = ignoreRules;
    }

    /**
     * Writes a the CMake module.
     */
    @Override
    public void write(Writer writer) {
        IWriter cmakeListsWriter = new CMakeListsWriter(
            this.manifest.getCMakeListsManifest(),
            this.module,
            this.editorSettings,
            this.ignoreRules);

        cmakeListsWriter.write(writer);
    }
}
