package cmakebuild.interfaces;

import java.util.List;

/**
 * The ICMakeBuildElementList interface defines a list of elements of a CMake build.
 */
public interface ICMakeBuildElementList extends ICMakeBuildElement {
    /**
     * Adds a new element.
     */
    void add(ICMakeBuildElement element);

    /**
     * Adds a new list of elements.
     */
    void add(List<ICMakeBuildElement> elements);
}
