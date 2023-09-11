package cmakebuildsystem.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Streams;
import base.interfaces.IDestructorHandler;
import cmakebuildsystem.interfaces.ICMakeModule;
import java.io.ByteArrayOutputStream;
import java.io.OutputStream;

/**
 * The ModuleDeploymentSimulationLogic class implements a deployment-simulation logic of a module.
 */
public final class ModuleDeploymentSimulationLogic implements IModuleDeploymentLogic {
    private final ICMakeModule module;
    private final ByteArrayOutputStream outputStream;
    private final IDestructorHandler destructorHandler = new DestructorHandler();

    /**
     * The ModuleDeploymentSimulationLogic constructor.
     */
    public ModuleDeploymentSimulationLogic(ICMakeModule module) {
        Conditions.validateNotNull(
            module,
            "The module to deploy.");

        ByteArrayOutputStream outputStream = Streams.createByteArrayOutputStream();
        this.destructorHandler.register(outputStream);

        this.module = module;
        this.outputStream = outputStream;
    }

    /**
     * Gets the output stream.
     */
    @Override
    public OutputStream getOutputStream() {
        return this.outputStream;
    }

    /**
     * Sets the deployment data.
     */
    @Override
    public void setDeploymentData(ICMakeBuildContextData deploymentData) {
        Conditions.validateNotNull(
            deploymentData,
            "The deployment data.");

        String cmakeListsPath = this.module.getCMakeListsFilePath().toString();
        String cmakeListsData = this.outputStream.toString();

        deploymentData.setData(cmakeListsPath, cmakeListsData);
    }

    /**
     * Closes the allocated resources.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }
}
