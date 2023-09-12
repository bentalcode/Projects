package cmakebuildsystem.core;

import base.core.Conditions;
import base.core.ResourceReader;
import cmakebuildsystem.interfaces.ICMakeBuildElement;
import cmakebuildsystem.interfaces.ICMakeWriter;
import java.nio.file.Path;
import java.util.List;

/**
 * The CMakeResource class implements a resource of a CMake.
 */
public final class CMakeResource implements ICMakeBuildElement {
    private final List<Path> paths;

    /**
     * The CMakeResource constructor.
     */
    public CMakeResource(List<Path> paths) {
        Conditions.validateNotNull(
            paths,
            "The paths of a cmake resource.");

        this.paths = paths;
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

        for (Path path : this.paths) {
            String content = ResourceReader.loadString(path);
            writer.write(content);
        }
    }
}
