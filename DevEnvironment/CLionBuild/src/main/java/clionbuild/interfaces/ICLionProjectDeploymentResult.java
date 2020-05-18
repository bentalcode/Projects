package clionbuild.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.util.Map;

/**
 * The ICLionProjectDeploymentResult interface defines a deployment result of a CLion project.
 */
public interface ICLionProjectDeploymentResult extends
    IUnaryComparator<ICLionProjectDeploymentResult>,
    IJsonSerialization {

    /**
     * Gets the project.
     */
    ICLionProject getProject();

    /**
     * Gets the data of the deployment.
     */
    Map<String, String> getDeploymentData();
}
