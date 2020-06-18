package cmakebuild.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import cmakebuild.interfaces.ICMakeListsManifest;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;

/**
 * The CMakeListsManifest class implements a manifest of a CMakeLists file.
 */
public final class CMakeListsManifest implements ICMakeListsManifest {
    private static final String PropertyCMakeVersion = "cmakeVersion";
    private static final String PropertyProjectVersion = "projectVersion";
    private static final String PropertyPresetPath = "presetPath";
    private static final String PropertyPostsetPath = "postsetPath";
    private static final String PropertyIncludesFilesProperty = "includesFilesProperty";
    private static final String PropertySourcesFilesProperty = "sourcesFilesProperty";
    private static final String PropertyIncludesProperty = "includesProperty";
    private static final String PropertySourcesProperty = "sourcesProperty";

    private static final String defaultIncludesFilesProperty = "INCLUDES_FILES";
    private static final String defaultSourcesFilesProperty = "SOURCES_FILES";
    private static final String defaultIncludesProperty = "INCLUDES";
    private static final String defaultSourcesProperty = "SOURCES";

    private final String cmakeVersion;
    private final String projectVersion;
    private final String presetPath;
    private final String postsetPath;
    private final String includesFilesProperty;
    private final String sourcesFilesProperty;
    private final String includesProperty;
    private final String sourcesProperty;

    private final IBinaryComparator<ICMakeListsManifest> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CMakeListsManifest constructor.
     */
    CMakeListsManifest(
        String cmakeVersion,
        String projectVersion,
        String presetPath,
        String postsetPath,
        String includesFilesProperty,
        String sourcesFilesProperty,
        String includesProperty,
        String sourcesProperty) {

        this.cmakeVersion = cmakeVersion;
        this.projectVersion = projectVersion;
        this.presetPath = presetPath;
        this.postsetPath = postsetPath;
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
     * Gets the path of preset.
     */
    @Override
    public String getPresetPath() {
        return this.presetPath;
    }

    /**
     * Gets the path of postset.
     */
    @Override
    public String getPostsetPath() {
        return this.postsetPath;
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
     * Gets the sources property.
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
        writer.writeStringProperty(PropertyCMakeVersion, this.cmakeVersion);
        writer.writeStringProperty(PropertyProjectVersion, this.projectVersion);
        writer.writeStringProperty(PropertyPresetPath, this.presetPath);
        writer.writeStringProperty(PropertyPostsetPath, this.postsetPath);
        writer.writeStringProperty(PropertyIncludesFilesProperty, this.includesFilesProperty);
        writer.writeStringProperty(PropertySourcesFilesProperty, this.sourcesFilesProperty);
        writer.writeStringProperty(PropertyIncludesProperty, this.includesProperty);
        writer.writeStringProperty(PropertySourcesProperty, this.sourcesProperty);
    }

    /**
     * Reads a json.
     */
    public static ICMakeListsManifest readJson(IJsonObjectReader reader) {
        String cmakeVersion = reader.readStringProperty(PropertyCMakeVersion);
        String projectVersion = reader.readStringProperty(PropertyProjectVersion);
        String presetPath = null;

        if (reader.hasProperty(PropertyPresetPath)) {
            presetPath = reader.readStringProperty(PropertyPresetPath);
        }

        String postsetPath = null;

        if (reader.hasProperty(PropertyPostsetPath)) {
            postsetPath = reader.readStringProperty(PropertyPostsetPath);
        }

        String includesFilesProperty = reader.hasProperty(PropertyIncludesFilesProperty) ?
            reader.readStringProperty(PropertyIncludesFilesProperty) :
            defaultIncludesFilesProperty;

        String sourcesFilesProperty = reader.hasProperty(PropertySourcesFilesProperty) ?
            reader.readStringProperty(PropertySourcesFilesProperty) :
            defaultSourcesFilesProperty;

        String includesProperty = reader.hasProperty(PropertyIncludesProperty) ?
            reader.readStringProperty(PropertyIncludesProperty) :
            defaultIncludesProperty;

        String sourcesProperty = reader.hasProperty(PropertySourcesProperty) ?
            reader.readStringProperty(PropertySourcesProperty) :
            defaultSourcesProperty;

        return new CMakeListsManifest(
            cmakeVersion,
            projectVersion,
            presetPath,
            postsetPath,
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
            return new HashCodeBuilder(3, 5)
                .withString(obj.getCMakeVersion())
                .withString(obj.getProjectVersion())
                .withString(obj.getPresetPath())
                .withString(obj.getPostsetPath())
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
                .withString(lhs.getPresetPath(), rhs.getPresetPath())
                .withString(lhs.getPostsetPath(), rhs.getPostsetPath())
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
                .withString(lhs.getPresetPath(), rhs.getPresetPath())
                .withString(lhs.getPostsetPath(), rhs.getPostsetPath())
                .withString(lhs.getIncludesFilesProperty(), rhs.getIncludesFilesProperty())
                .withString(lhs.getSourcesFilesProperty(), rhs.getSourcesFilesProperty())
                .withString(lhs.getIncludesProperty(), rhs.getIncludesProperty())
                .withString(lhs.getSourcesProperty(), rhs.getSourcesProperty())
                .build();
        }
    }
}
