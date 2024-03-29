package cmakebuildsystem.core;

import base.core.*;
import base.interfaces.IBinaryComparator;
import cmakebuildsystem.interfaces.ICMakeListsManifest;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;

import java.util.ArrayList;
import java.util.List;

/**
 * The CMakeListsManifest class implements a manifest of a CMakeLists file.
 */
public final class CMakeListsManifest implements ICMakeListsManifest {
    private static final String PROPERTY_CMAKE_VERSION = "cmakeVersion";
    private static final String PROPERTY_PROJECT_VERSION = "projectVersion";
    private static final String PROPERTY_PRESET_PATHS = "presetPaths";
    private static final String PROPERTY_POSTSET_PATHS = "postsetPaths";
    private static final String PROPERTY_BUILD_PROPERTIES_PATH = "buildPropertiesPath";
    private static final String PROPERTY_INCLUDES_FILES_PROPERTY = "includesFilesProperty";
    private static final String PROPERTY_SOURCES_FILES_PROPERTY = "sourcesFilesProperty";
    private static final String PROPERTY_INCLUDES_PROPERTY = "includesProperty";
    private static final String PROPERTY_SOURCES_PROPERTY = "sourcesProperty";

    private static final String CMAKE_VERSION = "3.6";
    private static final String PROJECT_VERSION = "1.0";

    private static final String DEFAULT_PRESET_PATH = new ResourcePathBuilder()
        .addComponent(CMakeListsConstants.MANIFEST_DIRECTORY_NAME)
        .addComponent(CMakeListsConstants.DEFAULT_CMAKE_LISTS_PRESET_FILE_NAME)
        .build();

    private static final String DEFAULT_POSTSET_PATH = new ResourcePathBuilder()
        .addComponent(CMakeListsConstants.MANIFEST_DIRECTORY_NAME)
        .addComponent(CMakeListsConstants.DEFAULT_CMAKE_LISTS_POSTSET_FILE_NAME)
        .build();

    private static final List<String> DEFAULT_PRESET_PATHS = ArrayLists.make(DEFAULT_PRESET_PATH);

    private static final List<String> DEFAULT_POSTSET_PATHS = ArrayLists.make(DEFAULT_POSTSET_PATH);

    private static final String BUILD_PROPERTIES_PATH = new ResourcePathBuilder()
        .addComponent(CMakeListsConstants.MANIFEST_DIRECTORY_NAME)
        .addComponent(CMakeListsConstants.DEFAULT_CMAKE_LISTS_BUILD_PROPERTIES_FILE_NAME)
        .build();

    private static final String INCLUDES_FILES_PROPERTY = "INCLUDES_FILES";
    private static final String SOURCES_FILES_PROPERTY = "SOURCES_FILES";
    private static final String INCLUDES_PROPERTY = "INCLUDES";
    private static final String SOURCES_PROPERTY = "SOURCES";

    private final String cmakeVersion;
    private final String projectVersion;
    private final List<String> presetPaths;
    private final List<String> postsetPaths;
    private final String buildPropertiesPath;
    private final String includesFilesProperty;
    private final String sourcesFilesProperty;
    private final String includesProperty;
    private final String sourcesProperty;

    private final IBinaryComparator<ICMakeListsManifest> comparator = defaultComparator();
    private final int hashCode;

    /**
     * Creates the default manifest of a CMakeLists.
     */
    public static ICMakeListsManifest defaultManifest() {
        return new CMakeListsManifest(
            CMAKE_VERSION,
            PROJECT_VERSION,
            DEFAULT_PRESET_PATHS,
            DEFAULT_POSTSET_PATHS,
            BUILD_PROPERTIES_PATH,
            INCLUDES_FILES_PROPERTY,
            SOURCES_FILES_PROPERTY,
            INCLUDES_PROPERTY,
            SOURCES_PROPERTY);
    }

    /**
     * The CMakeListsManifest constructor.
     */
    public CMakeListsManifest(
        String cmakeVersion,
        String projectVersion,
        List<String> presetPaths,
        List<String> postsetPaths,
        String buildPropertiesPath,
        String includesFilesProperty,
        String sourcesFilesProperty,
        String includesProperty,
        String sourcesProperty) {

        Conditions.validateStringNotNullOrEmpty(
            cmakeVersion,
            "CMake Version");

        Conditions.validateStringNotNullOrEmpty(
            projectVersion,
            "Project Version");

        Conditions.validateNotNull(
            presetPaths,
            "Preset Paths");

        Conditions.validateNotNull(
            postsetPaths,
            "Postset Paths");

        this.cmakeVersion = cmakeVersion;
        this.projectVersion = projectVersion;
        this.presetPaths = presetPaths;
        this.postsetPaths = postsetPaths;
        this.buildPropertiesPath = buildPropertiesPath;
        this.includesFilesProperty = includesFilesProperty;
        this.sourcesFilesProperty = sourcesFilesProperty;
        this.includesProperty = includesProperty;
        this.sourcesProperty = sourcesProperty;

        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets the version of cmake.
     */
    @Override
    public String getCMakeVersion() {
        return this.cmakeVersion;
    }

    /**
     * Gets the version of project.
     */
    @Override
    public String getProjectVersion() {
        return this.projectVersion;
    }

    /**
     * Gets the paths of preset.
     */
    @Override
    public List<String> getPresetPaths() {
        return this.presetPaths;
    }

    /**
     * Gets the paths of postset.
     */
    @Override
    public List<String> getPostsetPaths() {
        return this.postsetPaths;
    }

    /**
     * Gets the path of build properties.
     */
    @Override
    public String getBuildPropertiesPath() {
        return this.buildPropertiesPath;
    }

    /**
     * Gets the includes files property.
     */
    @Override
    public String getIncludesFilesProperty() {
        return this.includesFilesProperty;
    }

    /**
     * Gets the sources files property.
     */
    @Override
    public String getSourcesFilesProperty() {
        return this.sourcesFilesProperty;
    }

    /**
     * Gets the includes property.
     */
    @Override
    public String getIncludesProperty() {
        return this.includesProperty;
    }

    /**
     * Gets the sources' property.
     */
    @Override
    public String getSourcesProperty() {
        return this.sourcesProperty;
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(PROPERTY_CMAKE_VERSION, this.cmakeVersion);
        writer.writeStringProperty(PROPERTY_PROJECT_VERSION, this.projectVersion);
        writer.writeCollectionProperty(PROPERTY_PRESET_PATHS, this.presetPaths);
        writer.writeCollectionProperty(PROPERTY_POSTSET_PATHS, this.postsetPaths);
        writer.writeStringProperty(PROPERTY_BUILD_PROPERTIES_PATH, this.buildPropertiesPath);
        writer.writeStringProperty(PROPERTY_INCLUDES_FILES_PROPERTY, this.includesFilesProperty);
        writer.writeStringProperty(PROPERTY_SOURCES_FILES_PROPERTY, this.sourcesFilesProperty);
        writer.writeStringProperty(PROPERTY_INCLUDES_PROPERTY, this.includesProperty);
        writer.writeStringProperty(PROPERTY_SOURCES_PROPERTY, this.sourcesProperty);
    }

    /**
     * Reads a json.
     */
    public static ICMakeListsManifest readJson(IJsonObjectReader reader) {
        String cmakeVersion = reader.hasProperty(PROPERTY_CMAKE_VERSION) ?
            reader.readStringProperty(PROPERTY_CMAKE_VERSION) :
            CMAKE_VERSION;

        String projectVersion = reader.hasProperty(PROPERTY_PROJECT_VERSION) ?
            reader.readStringProperty(PROPERTY_PROJECT_VERSION) :
            PROJECT_VERSION;

        List<String> presetPaths = reader.hasProperty(PROPERTY_PRESET_PATHS) ?
            reader.readStringListProperty(PROPERTY_PRESET_PATHS) :
            DEFAULT_PRESET_PATHS;

        List<String> postsetPaths = reader.hasProperty(PROPERTY_POSTSET_PATHS) ?
            reader.readStringListProperty(PROPERTY_POSTSET_PATHS) :
            DEFAULT_POSTSET_PATHS;

        String buildPropertiesPath = reader.hasProperty(PROPERTY_BUILD_PROPERTIES_PATH) ?
            reader.readStringProperty(PROPERTY_BUILD_PROPERTIES_PATH) :
            BUILD_PROPERTIES_PATH;

        String includesFilesProperty = reader.hasProperty(PROPERTY_INCLUDES_FILES_PROPERTY) ?
            reader.readStringProperty(PROPERTY_INCLUDES_FILES_PROPERTY) :
            INCLUDES_FILES_PROPERTY;

        String sourcesFilesProperty = reader.hasProperty(PROPERTY_SOURCES_FILES_PROPERTY) ?
            reader.readStringProperty(PROPERTY_SOURCES_FILES_PROPERTY) :
            SOURCES_FILES_PROPERTY;

        String includesProperty = reader.hasProperty(PROPERTY_INCLUDES_PROPERTY) ?
            reader.readStringProperty(PROPERTY_INCLUDES_PROPERTY) :
            INCLUDES_PROPERTY;

        String sourcesProperty = reader.hasProperty(PROPERTY_SOURCES_PROPERTY) ?
            reader.readStringProperty(PROPERTY_SOURCES_PROPERTY) :
            SOURCES_PROPERTY;

        return new CMakeListsManifest(
            cmakeVersion,
            projectVersion,
            presetPaths,
            postsetPaths,
            buildPropertiesPath,
            includesFilesProperty,
            sourcesFilesProperty,
            includesProperty,
            sourcesProperty);
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
    public boolean isEqual(ICMakeListsManifest other) {
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
    public int compareTo(ICMakeListsManifest other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICMakeListsManifest> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a cmake module manifest.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICMakeListsManifest> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICMakeListsManifest obj) {
            return new HashCodeBuilder(101, 103)
                .withString(obj.getCMakeVersion())
                .withString(obj.getProjectVersion())
                .withCollection(obj.getPresetPaths())
                .withCollection(obj.getPostsetPaths())
                .withString(obj.getBuildPropertiesPath())
                .withString(obj.getIncludesFilesProperty())
                .withString(obj.getSourcesFilesProperty())
                .withString(obj.getIncludesProperty())
                .withString(obj.getSourcesProperty())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICMakeListsManifest lhs, ICMakeListsManifest rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getCMakeVersion(), rhs.getCMakeVersion())
                .withString(lhs.getProjectVersion(), rhs.getProjectVersion())
                .withCollection(lhs.getPresetPaths(), rhs.getPresetPaths())
                .withCollection(lhs.getPostsetPaths(), rhs.getPostsetPaths())
                .withString(lhs.getBuildPropertiesPath(), rhs.getBuildPropertiesPath())
                .withString(lhs.getIncludesFilesProperty(), rhs.getIncludesFilesProperty())
                .withString(lhs.getSourcesFilesProperty(), rhs.getSourcesFilesProperty())
                .withString(lhs.getIncludesProperty(), rhs.getIncludesProperty())
                .withString(lhs.getSourcesProperty(), rhs.getSourcesProperty())
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
        public int compareTo(ICMakeListsManifest lhs, ICMakeListsManifest rhs) {
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
                .withString(lhs.getCMakeVersion(), rhs.getCMakeVersion())
                .withString(lhs.getProjectVersion(), rhs.getProjectVersion())
                .withCollection(lhs.getPresetPaths(), rhs.getPresetPaths())
                .withCollection(lhs.getPostsetPaths(), rhs.getPostsetPaths())
                .withString(lhs.getBuildPropertiesPath(), rhs.getBuildPropertiesPath())
                .withString(lhs.getIncludesFilesProperty(), rhs.getIncludesFilesProperty())
                .withString(lhs.getSourcesFilesProperty(), rhs.getSourcesFilesProperty())
                .withString(lhs.getIncludesProperty(), rhs.getIncludesProperty())
                .withString(lhs.getSourcesProperty(), rhs.getSourcesProperty())
                .build();
        }
    }
}
