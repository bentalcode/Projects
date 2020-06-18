package cmakebuild.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import cmakebuild.interfaces.CMakeModuleType;
import cmakebuild.interfaces.ICMakeModuleManifest;
import cmakebuild.interfaces.ICMakeListsManifest;
import cmakebuild.interfaces.ICMakeModuleProperties;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * The CMakeModuleManifest class implements a CMake module.
 */
public final class CMakeModuleManifest implements ICMakeModuleManifest {
    private static final String propertyName = "name";
    private static final String propertyType = "type";
    private static final String propertyProperties = "properties";
    private static final String propertyCMakeListsManifest = "cmakeListsManifest";
    private static final String propertyDependentModules = "dependentModules";

    private final String name;
    private final CMakeModuleType type;
    private final ICMakeModuleProperties properties;
    private final ICMakeListsManifest cmakeListsManifest;
    private final List<String> dependentModules;

    private final IBinaryComparator<ICMakeModuleManifest> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CMakeModuleManifest constructor.
     */
    public CMakeModuleManifest(
        String name,
        CMakeModuleType type,
        ICMakeModuleProperties properties,
        ICMakeListsManifest cmakeListsManifest,
        List<String> dependentModules) {

        this.name = name;
        this.type = type;
        this.properties = properties;
        this.cmakeListsManifest = cmakeListsManifest;
        this.dependentModules = dependentModules;

        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets the name of the module.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets the type of the module.
     */
    @Override
    public CMakeModuleType getType() {
        return this.type;
    }

    /**
     * Gets the propertis of the module.
     */
    @Override
    public ICMakeModuleProperties getProperties() {
        return this.properties;
    }

    /**
     * Gets the manifest of a CMakeLists file.
     */
    @Override
    public ICMakeListsManifest getCMakeListsManifest() {
        return this.cmakeListsManifest;
    }

    /**
     * Gets the dependent modules.
     */
    @Override
    public List<String> getDependentModules() {
        return this.dependentModules;
    }

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return JsonObjectStream.serialize(this);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(propertyName, this.name);
        writer.writeEnumProperty(propertyType, this.type);
        writer.writeObjectProperty(propertyProperties, this.properties);
        writer.writeObjectProperty(propertyCMakeListsManifest, this.cmakeListsManifest);
        writer.writeStringCollectionProperty(propertyDependentModules, this.dependentModules);
    }

    /**
     * Reads a json.
     */
    public static ICMakeModuleManifest readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(propertyName);

        CMakeModuleType type = reader.readEnumProperty(propertyType, value -> { return CMakeModuleType.parse(value); });

        ICMakeModuleProperties properties = reader.hasProperty(propertyProperties) ?
            reader.readObjectProperty(
                propertyProperties,
                CMakeModuleProperties.class) :
            CMakeModuleProperties.defaultProperties();

        ICMakeListsManifest cmakeListsManifest = reader.readObjectProperty(
            propertyCMakeListsManifest,
            CMakeListsManifest.class);

        List<String> dependentModules = reader.hasProperty(propertyDependentModules) ?
            reader.readStringListProperty(propertyDependentModules) :
            new ArrayList<>();

        return new CMakeModuleManifest(
            name,
            type,
            properties,
            cmakeListsManifest,
            dependentModules);
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
    public boolean isEqual(ICMakeModuleManifest other) {
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
    public int compareTo(ICMakeModuleManifest other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICMakeModuleManifest> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a cmake module manifest.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICMakeModuleManifest> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICMakeModuleManifest obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withEnum(obj.getType())
                .withObject(obj.getProperties())
                .withObject(obj.getCMakeListsManifest())
                .withCollection(obj.getDependentModules())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICMakeModuleManifest lhs, ICMakeModuleManifest rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getName(), rhs.getName())
                .withEnum(lhs.getType(), rhs.getType())
                .withObject(lhs.getProperties(), rhs.getProperties())
                .withObject(lhs.getCMakeListsManifest(), rhs.getCMakeListsManifest())
                .withCollection(lhs.getDependentModules(), rhs.getDependentModules())
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
        public int compareTo(ICMakeModuleManifest lhs, ICMakeModuleManifest rhs) {
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
                .withEnum(lhs.getType(), rhs.getType())
                .withObject(lhs.getProperties(), rhs.getProperties())
                .withObject(lhs.getCMakeListsManifest(), rhs.getCMakeListsManifest())
                .withCollection(lhs.getDependentModules(), rhs.getDependentModules())
                .build();
        }
    }
}
