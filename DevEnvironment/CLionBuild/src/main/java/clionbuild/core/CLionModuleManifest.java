package clionbuild.core;

import base.core.AbstractBinaryComparator;
import base.core.ArrayLists;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import clionbuild.interfaces.ICLionModuleManifest;
import clionbuild.interfaces.ICMakeListsManifest;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.List;

/**
 * The CLionModuleManifest class implements a CLion module.
 */
public final class CLionModuleManifest implements ICLionModuleManifest {
    private static final String propertyName = "name";
    private static final String propertyPath = "path";
    private static final String propertyCMakeListsTargetPath = "cmakeListsTargetPath";
    private static final String propertyHeaderFileExtensions = "headerFileExtensions";
    private static final String propertySourceFileExtensions = "sourceFileExtensions";
    private static final String propertyCMakeListsFileExtensions = "cmakeListsFileExtensions";
    private static final String propertyCMakeListsManifest = "cmakeListsManifest";

    private static final String defaultCmakeListsTargetPath = "CMakeLists.txt";
    private static final List<String> defaultHeaderFileExtensions = ArrayLists.of("h");
    private static final List<String> defaultSourceFileExtensions = ArrayLists.of("cpp");
    private static final List<String> defaultCMakeListsFileExtensions = ArrayLists.of("CMakeLists.txt");

    private final String name;
    private final String path;
    private final String cmakeListsTargetPath;
    private final List<String> headerFileExtensions;
    private final List<String> sourceFileExtensions;
    private final List<String> cmakeListsFileExtensions;
    private final ICMakeListsManifest cmakeListsManifest;
    private final IBinaryComparator<ICLionModuleManifest> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CLionModuleManifest constructor.
     */
    CLionModuleManifest(
        String name,
        String path,
        String cmakeListsTargetPath,
        List<String> headerFileExtensions,
        List<String> sourceFileExtensions,
        List<String> cmakeListsFileExtensions,
        ICMakeListsManifest cmakeListsManifest) {

        this.name = name;
        this.path = path;
        this.cmakeListsTargetPath = cmakeListsTargetPath;
        this.headerFileExtensions = headerFileExtensions;
        this.sourceFileExtensions = sourceFileExtensions;
        this.cmakeListsFileExtensions = cmakeListsFileExtensions;
        this.cmakeListsManifest = cmakeListsManifest;

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
     * Gets the path of the module.
     */
    @Override
    public String getPath() {
        return this.path;
    }

    /**
     * Gets the target path of the CMakeLists file.
     */
    @Override
    public String getCMakeListsTargetPath() {
        return this.cmakeListsTargetPath;
    }

    /**
     * Gets the extensions of a header file.
     */
    @Override
    public List<String> getHeaderFileExtensions() {
        return this.headerFileExtensions;
    }

    /**
     * Gets the extensions of a source file.
     */
    @Override
    public List<String> getSourceFileExtensions() {
        return this.sourceFileExtensions;
    }

    /**
     * Gets the extensions of a CMakeLists file.
     */
    @Override
    public List<String> getCMakeListsFileExtensions() {
        return this.cmakeListsFileExtensions;
    }

    /**
     * Gets the manifest of a CMakeLists file.
     */
    @Override
    public ICMakeListsManifest getCMakeListsManifest() {
        return this.cmakeListsManifest;
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
        writer.writeStringProperty(propertyPath, this.path);
        writer.writeStringProperty(propertyCMakeListsTargetPath, this.cmakeListsTargetPath);
        writer.writeStringCollectionProperty(propertyHeaderFileExtensions, this.headerFileExtensions);
        writer.writeStringCollectionProperty(propertySourceFileExtensions, this.sourceFileExtensions);
        writer.writeStringCollectionProperty(propertyCMakeListsFileExtensions, this.cmakeListsFileExtensions);
        writer.writeObjectProperty(propertyCMakeListsManifest, this.cmakeListsManifest);
    }

    /**
     * Reads a json.
     */
    public static ICLionModuleManifest readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(propertyName);

        String path = null;

        if (reader.hasProperty(propertyPath)) {
            path = reader.readStringProperty(propertyPath);
        }

        String cmakeListsTargetPath = reader.hasProperty(propertyCMakeListsTargetPath) ?
            reader.readStringProperty(propertyCMakeListsTargetPath) :
            defaultCmakeListsTargetPath;

        List<String> headerFileExtensions = reader.hasProperty(propertyHeaderFileExtensions) ?
            reader.readStringListProperty(propertyHeaderFileExtensions) :
            defaultHeaderFileExtensions;

        List<String> sourceFileExtensions = reader.hasProperty(propertySourceFileExtensions) ?
            reader.readStringListProperty(propertySourceFileExtensions) :
            defaultSourceFileExtensions;

        List<String> cmakeListsFileExtensions = reader.hasProperty(propertyCMakeListsFileExtensions) ?
            reader.readStringListProperty(propertyCMakeListsFileExtensions) :
            defaultCMakeListsFileExtensions;

        ICMakeListsManifest cmakeListsManifest = reader.readObjectProperty(
            propertyCMakeListsManifest,
            CMakeListsManifest.class);

        return new CLionModuleManifest(
            name,
            path,
            cmakeListsTargetPath,
            headerFileExtensions,
            sourceFileExtensions,
            cmakeListsFileExtensions,
            cmakeListsManifest);
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
    public boolean isEqual(ICLionModuleManifest other) {
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
    public int compareTo(ICLionModuleManifest other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICLionModuleManifest> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a clion module manifest.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICLionModuleManifest> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICLionModuleManifest obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withString(obj.getPath())
                .withString(obj.getCMakeListsTargetPath())
                .withCollection(obj.getHeaderFileExtensions())
                .withCollection(obj.getSourceFileExtensions())
                .withCollection(obj.getCMakeListsFileExtensions())
                .withObject(obj.getCMakeListsManifest())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICLionModuleManifest lhs, ICLionModuleManifest rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getName(), rhs.getName())
                .withString(lhs.getPath(), rhs.getPath())
                .withString(lhs.getCMakeListsTargetPath(), rhs.getCMakeListsTargetPath())
                .withCollection(lhs.getHeaderFileExtensions(), rhs.getHeaderFileExtensions())
                .withCollection(lhs.getSourceFileExtensions(), rhs.getSourceFileExtensions())
                .withCollection(lhs.getCMakeListsFileExtensions(), rhs.getCMakeListsFileExtensions())
                .withObject(lhs.getCMakeListsManifest(), rhs.getCMakeListsManifest())
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
        public int compareTo(ICLionModuleManifest lhs, ICLionModuleManifest rhs) {
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
                .withString(lhs.getPath(), rhs.getPath())
                .withString(lhs.getCMakeListsTargetPath(), rhs.getCMakeListsTargetPath())
                .withCollection(lhs.getHeaderFileExtensions(), rhs.getHeaderFileExtensions())
                .withCollection(lhs.getSourceFileExtensions(), rhs.getSourceFileExtensions())
                .withCollection(lhs.getCMakeListsFileExtensions(), rhs.getCMakeListsFileExtensions())
                .withObject(lhs.getCMakeListsManifest(), rhs.getCMakeListsManifest())
                .build();
        }
    }
}
