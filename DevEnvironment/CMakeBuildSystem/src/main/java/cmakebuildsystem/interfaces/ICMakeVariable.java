package cmakebuildsystem.interfaces;

/**
 * The ICMakeVariable interface defines a variable of a CMake build.
 */
public interface ICMakeVariable extends ICMakeBuildElement {
    /**
     * Gets the name of a variable.
     */
    String getName();

    /**
     * Gets the variable.
     */
    String getVariable();
}
