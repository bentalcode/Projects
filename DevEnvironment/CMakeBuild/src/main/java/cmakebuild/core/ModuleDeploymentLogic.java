package cmakebuild.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Streams;
import base.interfaces.IDestructorHandler;
import cmakebuild.interfaces.ICMakeModule;
import java.io.OutputStream;

/**
 * The ModuleDeploymentLogic class implements a deployment logic of a module.
 */
public final class ModuleDeploymentLogic implements IModuleDeploymentLogic {
    private final ICMakeModule module;
    private final OutputStream outputStream;
    private final IDestructorHandler destructorHandler = new DestructorHandler();

    /**
     * The ModuleDeploymentLogic constructor.
     */
    public ModuleDeploymentLogic(ICMakeModule module) {
        Conditions.validateNotNull(
            module,
            "The module to deploy.");

        OutputStream outputStream = Streams.createOutputStream(module.getCMakeListsFilePath());
        this.destructorHandler.register(outputStream);

        this.module = module;
        this.outputStream = outputStream;
    }

    /**
     * Gets the output stream.
     */
    public OutputStream getOutputStream() {
        return this.outputStream;
    }

    /**
     * Sets the deployment data.
     */
    public void setDeploymentData(ICMakeBuildContextData deploymentData) {
        Conditions.validateNotNull(
            deploymentData,
            "The deployment data.");

        deploymentData.setData(this.module.getCMakeListsFilePath().toString(), null);
    }

    /**
     * Closes the allocated resources.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }
}
