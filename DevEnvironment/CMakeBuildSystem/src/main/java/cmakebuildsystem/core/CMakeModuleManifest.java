package cmakebuildsystem.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import cmakebuildsystem.interfaces.CMakeModuleType;
import cmakebuildsystem.interfaces.ICMakeModuleManifest;
import cmakebuildsystem.interfaces.ICMakeListsManifest;
import cmakebuildsystem.interfaces.ICMakeModuleProperties;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.ArrayList;
import java.util.List;

/**
 * The CMakeModuleManifest class implements a CMake module.
 */
public final class CMakeModuleManifest implements ICMakeModuleManifest {
    private static final String PROPERTY_NAME = "name";
    private static final String PROPERTY_TYPE = "type";
    private static final String PROPERTY_PROPERTIES = "properties";
    private static final String PROPERTY_CMAKE_LISTS_MANIFEST = "cmakeListsManifest";
    private static final String PROPERTY_DEPENDENT_MODULES = "dependentModules";

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
     * Gets the properties of the module.
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
        writer.writeStringProperty(PROPERTY_NAME, this.name);
        writer.writeEnumProperty(PROPERTY_TYPE, this.type);
        writer.writeObjectProperty(PROPERTY_PROPERTIES, this.properties);
        writer.writeObjectProperty(PROPERTY_CMAKE_LISTS_MANIFEST, this.cmakeListsManifest);
        writer.writeCollectionProperty(PROPERTY_DEPENDENT_MODULES, this.dependentModules);
    }

    /**
     * Reads a json.
     */
    public static ICMakeModuleManifest readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(PROPERTY_NAME);

        CMakeModuleType type = reader.readEnumProperty(PROPERTY_TYPE, CMakeModuleType::parse);

        ICMakeModuleProperties properties = reader.hasProperty(PROPERTY_PROPERTIES) ?
            reader.readObjectProperty(PROPERTY_PROPERTIES, CMakeModuleProperties.class) :
            CMakeModuleProperties.defaultProperties();

        ICMakeListsManifest cmakeListsManifest = reader.hasProperty(PROPERTY_CMAKE_LISTS_MANIFEST) ?
            reader.readObjectProperty(PROPERTY_CMAKE_LISTS_MANIFEST, CMakeListsManifest.class) :
            CMakeListsManifest.defaultManifest();

        List<String> dependentModules = reader.hasProperty(PROPERTY_DEPENDENT_MODULES) ?
            reader.readStringListProperty(PROPERTY_DEPENDENT_MODULES) :
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
            return new HashCodeBuilder(113, 127)
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
