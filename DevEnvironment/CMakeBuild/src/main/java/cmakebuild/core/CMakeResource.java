package cmakebuild.core;

import base.core.Conditions;
import base.core.ResourceReader;
import cmakebuild.interfaces.ICMakeBuildElement;
import cmakebuild.interfaces.ICMakeWriter;

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
    public void compile(ICMakeWriter writer) {
        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        if (this.path == null) {
            return;
        }

        String content = ResourceReader.loadString(this.path);
        writer.write(content);
    }
}
