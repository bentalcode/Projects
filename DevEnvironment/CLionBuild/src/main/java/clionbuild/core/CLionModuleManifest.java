package clionbuild.core;

import base.core.AbstractBinaryComparator;
import base.core.ArrayLists;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import clionbuild.interfaces.ICLionModuleManifest;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.List;

/**
 * The CLionModuleManifest class implements a CLion module.
 */
public final class CLionModuleManifest implements ICLionModuleManifest {
    private static final String PropertyName = "name";
    private static final String PropertyRootPath = "rootPath";
    private static final String PropertyCmakeListsFilePath = "cmakeListsFilePath";
    private static final String PropertyHeaderFileExtensions = "headerFileExtensions";
    private static final String PropertySourceFileExtensions = "sourceFileExtensions";
    private static final String PropertyCMakeListsFileExtensions = "cmakeListsFileExtensions";

    private static final String defaultCmakeListsFilePath = "CMakeLists.txt";
    private static final List<String> defaultHeaderFileExtensions = ArrayLists.of("h");
    private static final List<String> defaultSourceFileExtensions = ArrayLists.of("cpp");
    private static final List<String> defaultCMakeListsFileExtensions = ArrayLists.of("CMakeLists.txt");

    private final String name;
    private final String rootPath;
    private final String cmakeListsFilePath;
    private final List<String> headerFileExtensions;
    private final List<String> sourceFileExtensions;
    private final List<String> cmakeListsFileExtensions;
    private final IBinaryComparator<ICLionModuleManifest> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CLionModuleManifest constructor.
     */
    CLionModuleManifest(
        String name,
        String rootPath,
        String cmakeListsFilePath,
        List<String> headerFileExtensions,
        List<String> sourceFileExtensions,
        List<String> cmakeListsFileExtensions) {

        this.name = name;
        this.rootPath = rootPath;
        this.cmakeListsFilePath = cmakeListsFilePath;
        this.headerFileExtensions = headerFileExtensions;
        this.sourceFileExtensions = sourceFileExtensions;
        this.cmakeListsFileExtensions = cmakeListsFileExtensions;

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
     * Gets the path of the root of the module.
     */
    @Override
    public String getRootPath() {
        return this.rootPath;
    }

    /**
     * Gets the path of the CMakeLists file.
     */
    @Override
    public String getCMakeListsFilePath() {
        return this.cmakeListsFilePath;
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
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(PropertyName, this.name);
        writer.writeStringProperty(PropertyRootPath, this.rootPath);
        writer.writeStringProperty(PropertyCmakeListsFilePath, this.cmakeListsFilePath);
        writer.writeStringCollectionProperty(PropertyHeaderFileExtensions, this.headerFileExtensions);
        writer.writeStringCollectionProperty(PropertySourceFileExtensions, this.sourceFileExtensions);
        writer.writeStringCollectionProperty(PropertyCMakeListsFileExtensions, this.cmakeListsFileExtensions);
    }

    /**
     * Reads a json.
     */
    public static ICLionModuleManifest readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(PropertyName);

        String rootPath = null;

        if (reader.hasProperty(PropertyRootPath)) {
            rootPath = reader.readStringProperty(PropertyRootPath);
        }

        String cmakeListsFilePath = reader.hasProperty(PropertyCmakeListsFilePath) ?
            reader.readStringProperty(PropertyCmakeListsFilePath) :
            defaultCmakeListsFilePath;

        List<String> headerFileExtensions = reader.hasProperty(PropertyHeaderFileExtensions) ?
            reader.readStringListProperty(PropertyHeaderFileExtensions) :
            defaultHeaderFileExtensions;

        List<String> sourceFileExtensions = reader.hasProperty(PropertySourceFileExtensions) ?
            reader.readStringListProperty(PropertySourceFileExtensions) :
            defaultSourceFileExtensions;

        List<String> cmakeListsFileExtensions = reader.hasProperty(PropertyCMakeListsFileExtensions) ?
            reader.readStringListProperty(PropertyCMakeListsFileExtensions) :
            defaultCMakeListsFileExtensions;

        return new CLionModuleManifest(
            name,
            rootPath,
            cmakeListsFilePath,
            headerFileExtensions,
            sourceFileExtensions,
            cmakeListsFileExtensions);
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
                .withString(obj.getRootPath())
                .withString(obj.getCMakeListsFilePath())
                .withCollection(obj.getHeaderFileExtensions())
                .withCollection(obj.getSourceFileExtensions())
                .withCollection(obj.getCMakeListsFileExtensions())
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
                .withString(lhs.getRootPath(), rhs.getRootPath())
                .withString(lhs.getCMakeListsFilePath(), rhs.getCMakeListsFilePath())
                .withCollection(lhs.getHeaderFileExtensions(), rhs.getHeaderFileExtensions())
                .withCollection(lhs.getSourceFileExtensions(), rhs.getSourceFileExtensions())
                .withCollection(lhs.getCMakeListsFileExtensions(), rhs.getCMakeListsFileExtensions())
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
                .withString(lhs.getRootPath(), rhs.getRootPath())
                .withString(lhs.getCMakeListsFilePath(), rhs.getCMakeListsFilePath())
                .withCollection(lhs.getHeaderFileExtensions(), rhs.getHeaderFileExtensions())
                .withCollection(lhs.getSourceFileExtensions(), rhs.getSourceFileExtensions())
                .withCollection(lhs.getCMakeListsFileExtensions(), rhs.getCMakeListsFileExtensions())
                .build();
        }
    }
}
