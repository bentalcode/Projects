package clionbuild.core;

import base.core.Conditions;
import base.core.Writers;
import base.interfaces.IWriter;
import clionbuild.interfaces.ICLionModule;
import clionbuild.interfaces.ICMakeListsManifest;
import java.io.Writer;

/**
 * The CMakeListsWriter class implements a writer of a CLionLists file.
 */
public final class CMakeListsWriter implements IWriter {
    private final ICMakeListsManifest manifest;
    private final ICLionModule module;

    /**
     * The CMakeListsWriter constructor.
     */
    public CMakeListsWriter(
        ICMakeListsManifest manifest,
        ICLionModule module) {

        Conditions.validateNotNull(
            manifest,
            "The manifest of a CMakeLists file.");

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
        this.writeCMakeVersion(writer);
        this.writeProjectVersion(writer);
    }

    /**
     * Writes a CMake version.
     */
    private void writeCMakeVersion(Writer writer) {
        String line =
            ICMakeListsConstants.cmakeMinimumRequired +
            "(" + ICMakeListsConstants.version + " " + this.manifest.getCMakeVersion() + ")";

        Writers.write(writer, line);
        Writers.write(writer, "\n");
    }

    /**
     * Writes a project version.
     */
    private void writeProjectVersion(Writer writer) {
        String line =
            ICMakeListsConstants.project +
            "(" + this.getModuleName() + " " + ICMakeListsConstants.version + " " + this.manifest.getProjectVersion() + ")";

        Writers.write(writer, line);
        Writers.write(writer, "\n");
    }

    /**
     * Gets the name of a module.
     */
    private String getModuleName() {
        String name = this.manifest.getName();
        return name;
    }
}
