package cmakebuildsystem.core;

import base.core.Conditions;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeWriter;

/**
 * The TargetLinkLibrariesCommand class implements a target-link-libraries command of a CMake build.
 */
public final class TargetLinkLibrariesCommand extends CMakeBuildCommand {
    /**
     * The TargetLinkLibrariesCommand constructor.
     */
    public TargetLinkLibrariesCommand(String moduleName) {
        super(
            CMakeListsConstants.TARGET_LINK_LIBRARIES_COMMAND,
            moduleName);
    }

    /**
     * Compiles a CMake build command.
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

        String moduleName = this.getSubjectName();
        ICMakeModuleContextData moduleContextData = contextData.getModuleContextData(moduleName);

        this.begin(writer);

        String parameter =
            CMakeListsConstants.PRIVATE_LINK_LIBRARY + " " +
            getDependentModulesString(moduleContextData);

        this.addParameter(writer, parameter);

        this.end(writer);
    }

    /**
     * Gets a dependent modules string.
     */
    private static String getDependentModulesString(ICMakeModuleContextData moduleContextData) {
        StringBuilder result = new StringBuilder();

        for (ICMakeModule dependentModule : moduleContextData.getDependencies()) {
            if (result.length() > 0) {
                result.append(" ");
            }

            result.append(dependentModule.getName());
        }

        return result.toString();
    }
}
