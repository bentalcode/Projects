package clionbuild.core;

import base.core.Conditions;
import base.interfaces.IWriter;
import clionbuild.interfaces.ICLionModule;
import clionbuild.interfaces.ICLionModuleManifest;
import clionbuild.interfaces.IEditorSettings;
import clionbuild.interfaces.IIgnoreRules;
import java.io.Writer;

/**
 * The CLionModuleWriter class implements a writer of a CLion module.
 */
public final class CLionModuleWriter implements IWriter {
    private final ICLionModuleManifest manifest;
    private final IEditorSettings editorSettings;
    private final IIgnoreRules ignoreRules;
    private final ICLionModule module;

    /**
     * The CLionModuleWriter constructor.
     */
    public CLionModuleWriter(
        ICLionModuleManifest manifest,
        IEditorSettings editorSettings,
        IIgnoreRules ignoreRules,
        ICLionModule module) {

        Conditions.validateNotNull(
            manifest,
            "The manifest of a CLion module.");

        Conditions.validateNotNull(
            editorSettings,
            "The settings of an editor.");

        Conditions.validateNotNull(
            module,
            "The CLion module.");

        Conditions.validateNotNull(
            ignoreRules,
            "The ignore rules.");

        this.manifest = manifest;
        this.editorSettings = editorSettings;
        this.module = module;
        this.ignoreRules = ignoreRules;
    }

    /**
     * Writes a the CLion module.
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
