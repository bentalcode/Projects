package clionbuild.core;

import base.core.Conditions;
import base.interfaces.IWriter;
import clionbuild.interfaces.ICLionModule;
import clionbuild.interfaces.ICLionModuleManifest;
import java.io.Writer;

/**
 * The CLionModuleWriter class implements a writer of a CLion module.
 */
public final class CLionModuleWriter implements IWriter {
    private final ICLionModuleManifest manifest;
    private final ICLionModule module;

    /**
     * The CLionModuleWriter constructor.
     */
    public CLionModuleWriter(
        ICLionModuleManifest manifest,
        ICLionModule module) {

        Conditions.validateNotNull(
            manifest,
            "The manifest of a CLion module.");

        Conditions.validateNotNull(
            module,
            "The CLion module.");

        this.manifest = manifest;
        this.module = module;
    }

    /**
     * Writes a the CLion module.
     */
    @Override
    public void write(Writer writer) {
        IWriter cmakeListsWriter = new CMakeListsWriter(
            this.manifest.getCMakeListsManifest(),
            this.module);

        cmakeListsWriter.write(writer);
    }
}
