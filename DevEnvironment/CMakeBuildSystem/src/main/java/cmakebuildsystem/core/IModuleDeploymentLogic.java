package cmakebuildsystem.core;

import base.interfaces.ICloseable;
import java.io.OutputStream;

/**
 * The IModuleDeploymentLogic interface defines a deployment logic of a module.
 */
public interface IModuleDeploymentLogic extends ICloseable {
    /**
     * Gets the output stream.
     */
    OutputStream getOutputStream();

    /**
     * Sets the deployment data.
     */
    void setDeploymentData(ICMakeBuildContextData deploymentData);
}
