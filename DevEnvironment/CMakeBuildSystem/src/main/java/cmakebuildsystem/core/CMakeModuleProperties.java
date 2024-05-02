package cmakebuildsystem.core;

import base.core.AbstractBinaryComparator;
import base.core.ArrayLists;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import cmakebuildsystem.interfaces.ICMakeModuleProperties;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.List;

/**
 * The CMakeModuleProperties class implements properties of a CMake module.
 */
public final class CMakeModuleProperties implements ICMakeModuleProperties {
    private static final String PROPERTY_PATH = "path";
    private static final String PROPERTY_DIRECTORY_NAME = "directoryName";
    private static final String PROPERTY_CMAKE_LISTS_TARGET_PATH = "cmakeListsTargetPath";
    private static final String PROPERTY_HEADER_FILE_EXTENSIONS = "headerFileExtensions";
    private static final String PROPERTY_SOURCE_FILE_EXTENSIONS = "sourceFileExtensions";
    private static final String PROPERTY_BUILD_FILE_EXTENSIONS = "buildFileExtensions";
    private static final String PROPERTY_CMAKE_LISTS_FILE_EXTENSIONS = "cmakeListsFileExtensions";

    private static final String DEFAULT_CMAKE_LISTS_TARGET_PATH = "CMakeLists.txt";
    private static final List<String> DEFAULT_HEADER_FILE_EXTENSIONS = ArrayLists.make("h");
    private static final List<String> DEFAULT_SOURCE_FILE_EXTENSIONS = ArrayLists.make("cpp");
    private static final List<String> DEFAULT_BUILD_FILE_EXTENSIONS = ArrayLists.make(".in");
    private static final List<String> DEFAULT_CMAKE_LISTS_FILE_EXTENSIONS = ArrayLists.make("CMakeLists.txt");

    private final String path;
    private final String directoryName;
    private final String cmakeListsTargetPath;
    private final List<String> headerFileExtensions;
    private final List<String> sourceFileExtensions;
    private final List<String> buildFileExtensions;
    private final List<String> cmakeListsFileExtensions;

    private final IBinaryComparator<ICMakeModuleProperties> comparator = defaultComparator();
    private final int hashCode;

    /**
     * Gets the default properties.
     */
    public static ICMakeModuleProperties defaultProperties() {
        return new CMakeModuleProperties(
            null,
            null,
            DEFAULT_CMAKE_LISTS_TARGET_PATH,
            DEFAULT_HEADER_FILE_EXTENSIONS,
            DEFAULT_SOURCE_FILE_EXTENSIONS,
            DEFAULT_BUILD_FILE_EXTENSIONS,
            DEFAULT_CMAKE_LISTS_FILE_EXTENSIONS);
    }

    /**
     * The CMakeModuleProperties constructor.
     */
    public CMakeModuleProperties(
        String path,
        String directoryName,
        String cmakeListsTargetPath,
        List<String> headerFileExtensions,
        List<String> sourceFileExtensions,
        List<String> buildFileExtensions,
        List<String> cmakeListsFileExtensions) {

        this.path = path;
        this.directoryName = directoryName;
        this.cmakeListsTargetPath = cmakeListsTargetPath;
        this.headerFileExtensions = headerFileExtensions;
        this.sourceFileExtensions = sourceFileExtensions;
        this.buildFileExtensions = buildFileExtensions;
        this.cmakeListsFileExtensions = cmakeListsFileExtensions;

        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets the path of the module.
     */
    @Override
    public String getPath() {
        return this.path;
    }

    /**
     * Gets the name of the directory.
     */
    @Override
    public String getDirectoryName() {
        return this.directoryName;
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
     * Gets the extensions of a build file.
     */
    @Override
    public List<String> getBuildFileExtensions() {
        return this.buildFileExtensions;
    }

    /**
     * Gets the extensions of a CMakeLists file.
     */
    @Override
    public List<String> getCMakeListsFileExtensions() {
        return this.cmakeListsFileExtensions;
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
        if (this.path != null) {
            writer.writeStringProperty(PROPERTY_PATH, this.path);
        }

        if (this.directoryName != null) {
            writer.writeStringProperty(PROPERTY_DIRECTORY_NAME, this.directoryName);
        }

        writer.writeStringProperty(PROPERTY_CMAKE_LISTS_TARGET_PATH, this.cmakeListsTargetPath);
        writer.writeCollectionProperty(PROPERTY_HEADER_FILE_EXTENSIONS, this.headerFileExtensions);
        writer.writeCollectionProperty(PROPERTY_SOURCE_FILE_EXTENSIONS, this.sourceFileExtensions);
        writer.writeCollectionProperty(PROPERTY_BUILD_FILE_EXTENSIONS, this.buildFileExtensions);
        writer.writeCollectionProperty(PROPERTY_CMAKE_LISTS_FILE_EXTENSIONS, this.cmakeListsFileExtensions);
    }

    /**
     * Reads a json.
     */
    public static ICMakeModuleProperties readJson(IJsonObjectReader reader) {
        String path = null;

        if (reader.hasProperty(PROPERTY_PATH)) {
            path = reader.readStringProperty(PROPERTY_PATH);
        }

        String directoryName = null;

        if (reader.hasProperty(PROPERTY_DIRECTORY_NAME)) {
            directoryName = reader.readStringProperty(PROPERTY_DIRECTORY_NAME);
        }

        String cmakeListsTargetPath = reader.hasProperty(PROPERTY_CMAKE_LISTS_TARGET_PATH) ?
            reader.readStringProperty(PROPERTY_CMAKE_LISTS_TARGET_PATH) :
                DEFAULT_CMAKE_LISTS_TARGET_PATH;

        List<String> headerFileExtensions = reader.hasProperty(PROPERTY_HEADER_FILE_EXTENSIONS) ?
            reader.readStringListProperty(PROPERTY_HEADER_FILE_EXTENSIONS) :
                DEFAULT_HEADER_FILE_EXTENSIONS;

        List<String> sourceFileExtensions = reader.hasProperty(PROPERTY_SOURCE_FILE_EXTENSIONS) ?
            reader.readStringListProperty(PROPERTY_SOURCE_FILE_EXTENSIONS) :
                DEFAULT_SOURCE_FILE_EXTENSIONS;

        List<String> buildFileExtensions = reader.hasProperty(PROPERTY_BUILD_FILE_EXTENSIONS) ?
            reader.readStringListProperty(PROPERTY_BUILD_FILE_EXTENSIONS) :
                DEFAULT_BUILD_FILE_EXTENSIONS;

        List<String> cmakeListsFileExtensions = reader.hasProperty(PROPERTY_CMAKE_LISTS_FILE_EXTENSIONS) ?
            reader.readStringListProperty(PROPERTY_CMAKE_LISTS_FILE_EXTENSIONS) :
                DEFAULT_CMAKE_LISTS_FILE_EXTENSIONS;

        return new CMakeModuleProperties(
            path,
            directoryName,
            cmakeListsTargetPath,
            headerFileExtensions,
            sourceFileExtensions,
            buildFileExtensions,
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
    public boolean isEqual(ICMakeModuleProperties other) {
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
    public int compareTo(ICMakeModuleProperties other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICMakeModuleProperties> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a cmake module manifest.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICMakeModuleProperties> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICMakeModuleProperties obj) {
            return new HashCodeBuilder(131, 137)
                .withString(obj.getPath())
                .withString(obj.getDirectoryName())
                .withString(obj.getCMakeListsTargetPath())
                .withCollection(obj.getHeaderFileExtensions())
                .withCollection(obj.getSourceFileExtensions())
                .withCollection(obj.getBuildFileExtensions())
                .withCollection(obj.getCMakeListsFileExtensions())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICMakeModuleProperties lhs, ICMakeModuleProperties rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getPath(), rhs.getPath())
                .withString(lhs.getDirectoryName(), rhs.getDirectoryName())
                .withString(lhs.getCMakeListsTargetPath(), rhs.getCMakeListsTargetPath())
                .withCollection(lhs.getHeaderFileExtensions(), rhs.getHeaderFileExtensions())
                .withCollection(lhs.getSourceFileExtensions(), rhs.getSourceFileExtensions())
                .withCollection(lhs.getBuildFileExtensions(), rhs.getBuildFileExtensions())
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
        public int compareTo(ICMakeModuleProperties lhs, ICMakeModuleProperties rhs) {
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
                .withString(lhs.getPath(), rhs.getPath())
                .withString(lhs.getDirectoryName(), rhs.getDirectoryName())
                .withString(lhs.getCMakeListsTargetPath(), rhs.getCMakeListsTargetPath())
                .withCollection(lhs.getHeaderFileExtensions(), rhs.getHeaderFileExtensions())
                .withCollection(lhs.getSourceFileExtensions(), rhs.getSourceFileExtensions())
                .withCollection(lhs.getBuildFileExtensions(), rhs.getBuildFileExtensions())
                .withCollection(lhs.getCMakeListsFileExtensions(), rhs.getCMakeListsFileExtensions())
                .build();
        }
    }
}
