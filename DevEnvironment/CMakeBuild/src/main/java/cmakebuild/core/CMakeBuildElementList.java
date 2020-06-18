package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeBuildElement;
import cmakebuild.interfaces.ICMakeBuildElementList;
import cmakebuild.interfaces.ICMakeWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * The CMakeBuildElementList class implements a list elements of a CMake build.
 */
public final class CMakeBuildElementList implements ICMakeBuildElementList {
    private final List<ICMakeBuildElement> elements = new ArrayList<>();

    /**
     * The CMakeBuildElementList constructor.
     */
    public CMakeBuildElementList() {
    }

    /**
     * Adds a new element.
     */
    public void add(ICMakeBuildElement element) {
        Conditions.validateNotNull(
            element,
            "The element of a cmake build.");

        this.elements.add(element);
    }

    /**
     * Adds a new list of elements.
     */
    @Override
    public void add(List<ICMakeBuildElement> elements) {
        Conditions.validateNotNull(
            elements,
            "The elements of a cmake build.");

        this.elements.addAll(elements);
    }

    /**
     * Compiles a CMake build.
     */
    @Override
    public void compile(
        ICMakeWriter writer,
        ICMakeBuildContextData contextData) {

        for (int i = 0; i < this.elements.size(); ++i) {
            if (i > 0) {
                writer.newLine();
            }

            ICMakeBuildElement element = this.elements.get(i);
            element.compile(writer, contextData);
        }
    }
}
