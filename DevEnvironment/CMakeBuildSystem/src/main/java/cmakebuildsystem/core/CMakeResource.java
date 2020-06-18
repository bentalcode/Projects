package cmakebuildsystem.core;

import base.core.Conditions;
import base.core.ResourceReader;
import cmakebuildsystem.interfaces.ICMakeBuildElement;
import cmakebuildsystem.interfaces.ICMakeWriter;

/**
 * The CMakeResource class implements a resource of a CMake.
 */
public final class CMakeResource implements ICMakeBuildElement {
    private final String path;

    /**
     * The CMakeResource constructor.
     */
    public CMakeResource(String path) {
        this.path = path;
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

        if (this.path == null) {
            return;
        }

        String content = ResourceReader.loadString(this.path);
        writer.write(content);
    }
}
