package cmakebuildsystem.interfaces;

import java.util.List;

/**
 * The ICMakeBuildCommand interface defines a command of a CMake build.
 */
public interface ICMakeBuildCommand extends ICMakeBuildElement {
    /**
     * Gets a name of a command.
     */
    String getName();

    /**
     * Gets a subject name of a command.
     */
    String getSubjectName();

    /**
     * Gets properties of a command.
     */
    List<String> getProperties();
}
