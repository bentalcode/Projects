package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeVariable;
import cmakebuildsystem.interfaces.ICMakeWriter;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

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
    public void compile(
        ICMakeWriter writer,
        ICMakeBuildContextData contextData) {

        Conditions.validateNotNull(
            writer,
            "The CMake writer.");

        Conditions.validateNotNull(
            contextData,
            "The context data.");

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
        String prefixSection = formatVariableString(prefix);
        String nameSection = formatVariableString(name);

        if (prefixSection.isEmpty()) {
            return nameSection;
        }

        if (nameSection.isEmpty()) {
            return prefixSection;
        }

        String variableName = prefixSection + "_" + nameSection;
        return variableName;
    }

    /**
     * Gets variables as strings.
     */
    public static List<String> getVariablesAsStrings(List<ICMakeVariable> variables) {
        List<String> result = new ArrayList<>();

        for (ICMakeVariable variable : variables) {
            result.add(variable.getVariable());
        }

        Collections.sort(result);

        return result;
    }

    /**
     * Formats the variable string.
     */
    private static String formatVariableString(String str) {
        if (str.isEmpty()) {
            return str;
        }

        StringBuilder result = new StringBuilder();
        result.append(str.charAt(0));

        char prevCharacter = str.charAt(0);
        for (int i = 1; i < str.length(); ++i) {
            char currCharacter = str.charAt(i);

            if (Character.isLowerCase(prevCharacter) && Character.isUpperCase(currCharacter)) {
                result.append("_");
            }

            if (Character.isLowerCase(currCharacter)) {
                result.append(Character.toUpperCase(currCharacter));
            }
            else {
                result.append(currCharacter);
            }

            prevCharacter = currCharacter;
        }

        return result.toString();
    }
}
