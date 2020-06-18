package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeVariable;
import cmakebuildsystem.interfaces.ICMakeWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * The AddBinaryCommand class implements an add-binary command of a CMake build.
 */
abstract class AddBinaryCommand extends CMakeBuildCommand {
    /**
     * The AddBinaryCommand constructor.
     */
    protected AddBinaryCommand(
        String name,
        String moduleName,
        List<String> properties) {

        super(
            name,
            moduleName,
            properties);
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

        List<ICMakeVariable> sourcesVariables = this.getSourcesVariables(contextData);
        List<String> sourcesVariablesStrings = CMakeVariable.getVariablesAsStrings(sourcesVariables);

        this.begin(writer);
        this.addParameters(writer, sourcesVariablesStrings);
        this.end(writer);
    }

    /**
     * Gets the sources variables.
     */
    private List<ICMakeVariable> getSourcesVariables(ICMakeBuildContextData contextData) {
        List<ICMakeVariable> variables = new ArrayList<>();

        ICMakeModuleContextData moduleContextData = contextData.getModuleContextData(this.getSubjectName());

        String sourcesVariableName = CMakeModule.createSourcesVariableName(moduleContextData);
        ICMakeVariable sourcesVariable = moduleContextData.getVariable(sourcesVariableName);

        variables.add(sourcesVariable);

        for (ICMakeModule dependentModules : moduleContextData.getDependencies()) {
            ICMakeModuleContextData dependentModuleContextData = contextData.getModuleContextData(dependentModules.getName());

            String dependentSourcesVariableName = CMakeModule.createSourcesVariableName(dependentModuleContextData);
            ICMakeVariable dependentSourcesVariable = dependentModuleContextData.getVariable(dependentSourcesVariableName);

            variables.add(dependentSourcesVariable);
        }

        return variables;
    }
}
