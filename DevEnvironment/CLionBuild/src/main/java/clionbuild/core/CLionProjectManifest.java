package clionbuild.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import clionbuild.interfaces.ICLionModuleManifest;
import clionbuild.interfaces.ICLionProjectManifest;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.List;

/**
 * The CLionProjectManifest class implements a manifest of a CLion project.
 */
public final class CLionProjectManifest implements ICLionProjectManifest {
    private static final String PropertyName = "name";
    private static final String PropertyRootPath = "rootPath";
    private static final String PropertyModules = "modules";

    private final String name;
    private final String rootPath;
    private final List<ICLionModuleManifest> modules;
    private final IBinaryComparator<ICLionProjectManifest> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CLionProjectManifest constructor.
     */
    CLionProjectManifest(
        String name,
        String rootPath,
        List<ICLionModuleManifest> modules) {

        this.name = name;
        this.rootPath = rootPath;
        this.modules = modules;
        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets the name of the project.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets the path of the root of the project.
     */
    @Override
    public String getRootPath() {
        return this.rootPath;
    }

    /**
     * Gets the list of the modules manifests.
     */
    @Override
    public List<ICLionModuleManifest> getModulesManifests() {
        return this.modules;
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
    public static ICLionProjectManifest fromJson(String json) {
        return JsonObjectStream.deserialize(json, CLionProjectManifest.class);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(PropertyName, this.name);
        writer.writeStringProperty(PropertyRootPath, this.rootPath);
        writer.writeCollectionProperty(PropertyModules, this.modules);
    }

    /**
     * Reads a json.
     */
    public static ICLionProjectManifest readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(PropertyName);
        String rootPath = reader.readStringProperty(PropertyRootPath);
        List<ICLionModuleManifest> modules = reader.readListProperty(PropertyModules, CLionModuleManifest.class);

        return new CLionProjectManifest(
            name,
            rootPath,
            modules);
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
    public boolean isEqual(ICLionProjectManifest other) {
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
    public int compareTo(ICLionProjectManifest other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICLionProjectManifest> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a fruit.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICLionProjectManifest> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICLionProjectManifest obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withString(obj.getRootPath())
                .withCollection(obj.getModulesManifests())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICLionProjectManifest lhs, ICLionProjectManifest rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getName(), rhs.getName())
                .withString(lhs.getRootPath(), rhs.getRootPath())
                .withCollection(lhs.getModulesManifests(), rhs.getModulesManifests())
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
        public int compareTo(ICLionProjectManifest lhs, ICLionProjectManifest rhs) {
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
                .withString(lhs.getName(), rhs.getName())
                .withString(lhs.getRootPath(), rhs.getRootPath())
                .withCollection(lhs.getModulesManifests(), rhs.getModulesManifests())
                .build();
        }
    }
}
