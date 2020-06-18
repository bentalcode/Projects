package cmakebuildsystem.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import cmakebuildsystem.interfaces.ICMakeProject;
import cmakebuildsystem.interfaces.ICMakeProjectDeploymentResult;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.Map;

/**
 * The CMakeProjectDeploymentResult class implements a deployment result of a CMake project.
 */
public final class CMakeProjectDeploymentResult implements ICMakeProjectDeploymentResult {
    private static final String propertyProject = "propertyProject";
    private static final String propertyDeploymentData = "deploymentData";

    private final ICMakeProject project;
    private final Map<String, String> deploymentData;

    private final IBinaryComparator<ICMakeProjectDeploymentResult> comparator = defaultComparator();
    private final int hashCode;

    /**
     * Gets the project.
     */
    public CMakeProjectDeploymentResult(
        ICMakeProject project,
        Map<String, String> deploymentData) {

        Conditions.validateNotNull(
            project,
            "The project of a CMake build.");

        Conditions.validateNotNull(
            deploymentData,
            "The data of deployment.");

        this.project = project;
        this.deploymentData = deploymentData;

        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets the project.
     */
    @Override
    public ICMakeProject getProject() {
        return this.project;
    }

    /**
     * Gets the data of the deployment.
     */
    @Override
    public Map<String, String> getDeploymentData() {
        return this.deploymentData;
    }

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return JsonObjectStream.serialize(this);
    }

    /**
     * Serializes an object from a json.
     */
    public static ICMakeProjectDeploymentResult fromJson(String json) {
        return JsonObjectStream.deserialize(json, CMakeProjectDeploymentResult.class);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeObjectProperty(propertyProject, this.project);
        writer.writeMapProperty(propertyDeploymentData, this.deploymentData);
    }

    /**
     * Reads a json.
     */
    public static ICMakeProjectDeploymentResult readJson(IJsonObjectReader reader) {
        ICMakeProject project = reader.readObjectProperty(propertyProject, CMakeProject.class);
        Map<String, String> deploymentData = reader.readStringMapProperty(propertyDeploymentData);

        return new CMakeProjectDeploymentResult(
            project,
            deploymentData);
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(ICMakeProjectDeploymentResult other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(ICMakeProjectDeploymentResult other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICMakeProjectDeploymentResult> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a deployment result.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICMakeProjectDeploymentResult> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICMakeProjectDeploymentResult obj) {
            return new HashCodeBuilder(3, 5)
                .withObject(obj.getProject())
                .withMap(obj.getDeploymentData())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICMakeProjectDeploymentResult lhs, ICMakeProjectDeploymentResult rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.getProject(), rhs.getProject())
                .withMap(lhs.getDeploymentData(), rhs.getDeploymentData())
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(ICMakeProjectDeploymentResult lhs, ICMakeProjectDeploymentResult rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withObject(lhs.getProject(), rhs.getProject())
                .withMap(lhs.getDeploymentData(), rhs.getDeploymentData())
                .build();
        }
    }
}
