package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeVariable;
import cmakebuild.interfaces.ICMakeWriter;

/**
 * The CMakeVariable class implements a variable of a CMake build.
 */
public final class CMakeVariable implements ICMakeVariable {
    private final String name;

    /**
     * The CMakeVariable constructor.
     */
    public CMakeVariable(String name) {
        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of a variable");

        this.name = name;
    }

    /**
     * Gets the name of a variable.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets the variable.
     */
    @Override
    public String getVariable() {
        String variable = "${" + this.name + "}";
        return variable;
    }

    /**
     * Compiles a CMake build.
     */
    @Override
    public void compile(ICMakeWriter writer) {
        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        String variable = this.getVariable();
        writer.write(variable);
    }

    /**
     * Creates a variable.
     */
    public static ICMakeVariable createVariable(String prefix, String name) {
        String variableName = createVariableName(prefix, name);
        return new CMakeVariable(variableName);
    }

    /**
     * Creates a variable name.
     */
    public static String createVariableName(String prefix, String name) {
        String variableName = prefix + "_" + name;
        variableName = variableName.toUpperCase();
        return variableName;
    }
}
