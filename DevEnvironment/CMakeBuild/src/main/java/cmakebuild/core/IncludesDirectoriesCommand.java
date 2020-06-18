package cmakebuild.core;

import base.core.Conditions;
import cmakebuild.interfaces.ICMakeModule;
import cmakebuild.interfaces.ICMakeVariable;
import cmakebuild.interfaces.ICMakeWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * The IncludesDirectoriesCommand class implements an include directories command of a CMake build.
 */
public final class IncludesDirectoriesCommand extends CMakeBuildCommand {
    /**
     * The IncludesDirectoriesCommand constructor.
     */
    public IncludesDirectoriesCommand(String moduleName) {
        super(
            ICMakeListsConstants.includeDirectoriesCommand,
            moduleName);
    }

    /**
     * Compiles a CMake build element.
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

        List<ICMakeVariable> variables = this.getIncludeDirectoriesVariables(contextData);
        List<String> variablesStrings = CMakeVariable.getVariablesAsStrings(variables);

        this.begin(writer);
        this.addParameters(writer, variablesStrings);
        this.end(writer);
    }

    /**
     * Gets the include directories variables.
     */
    private List<ICMakeVariable> getIncludeDirectoriesVariables(ICMakeBuildContextData contextData) {
        List<ICMakeVariable> variables = new ArrayList<>();

        ICMakeModuleContextData moduleContextData = contextData.getModuleContextData(this.getSubjectName());

        String moduleVariableName = CMakeModule.createIncludesVariableName(moduleContextData);
        ICMakeVariable moduleVariable = moduleContextData.getVariable(moduleVariableName);

        variables.add(moduleVariable);

        for (ICMakeModule dependentModule : moduleContextData.getDependencies()) {
            ICMakeModuleContextData dependentModuleContextData = contextData.getModuleContextData(dependentModule.getName());

            String dependentModuleVariableName = CMakeModule.createIncludesVariableName(dependentModuleContextData);
            ICMakeVariable dependentModuleVariable = dependentModuleContextData.getVariable(dependentModuleVariableName);

            variables.add(dependentModuleVariable);
        }

        return variables;
    }
}
