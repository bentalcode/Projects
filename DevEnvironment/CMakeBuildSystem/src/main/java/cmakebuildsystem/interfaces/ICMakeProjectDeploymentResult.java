package cmakebuildsystem.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.util.Map;

/**
 * The ICMakeProjectDeploymentResult interface defines a deployment result of a CMake project.
 */
public interface ICMakeProjectDeploymentResult extends
    IUnaryComparator<ICMakeProjectDeploymentResult>,
    IJsonSerialization {

    /**
     * Gets the project.
     */
    ICMakeProject getProject();

    /**
     * Gets the data of the deployment.
     */
    Map<String, String> getDeploymentData();
}
