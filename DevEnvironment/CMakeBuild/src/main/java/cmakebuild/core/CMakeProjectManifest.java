package cmakebuild.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import cmakebuild.interfaces.ICMakeModuleManifest;
import cmakebuild.interfaces.ICMakeProjectManifest;
import cmakebuild.interfaces.IEditorSettings;
import cmakebuild.interfaces.IIgnoreRules;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.util.List;

/**
 * The CMakeProjectManifest class implements a manifest of a CMake project.
 */
public final class CMakeProjectManifest implements ICMakeProjectManifest {
    private static final String propertyName = "name";
    private static final String propertyRootPath = "rootPath";
    private static final String propertyModules = "modules";
    private static final String propertyEditorSettings = "editorSettings";
    private static final String propertyIgnoreRules = "ignoreRules";

    private final String name;
    private final String rootPath;
    private final List<ICMakeModuleManifest> modules;
    private final IEditorSettings editorSettings;
    private final IIgnoreRules ignoreRules;

    private final IBinaryComparator<ICMakeProjectManifest> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CMakeProjectManifest constructor.
     */
    CMakeProjectManifest(
        String name,
        String rootPath,
        List<ICMakeModuleManifest> modules,
        IEditorSettings editorSettings,
        IIgnoreRules ignoreRules) {

        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of a project.");

        Conditions.validateStringNotNullOrEmpty(
            rootPath,
            "The path of the root of a project.");

        Conditions.validateNotNull(
            modules,
            "The modules of a project.");

        Conditions.validateNotNull(
            editorSettings,
            "The settings of an editor.");

        Conditions.validateNotNull(
            ignoreRules,
            "The ignore rules.");

        this.name = name;
        this.rootPath = rootPath;
        this.modules = modules;
        this.editorSettings = editorSettings;
        this.ignoreRules = ignoreRules;

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
    public List<ICMakeModuleManifest> getModulesManifests() {
        return this.modules;
    }

    /**
     * Gets settings of an editor.
     */
    @Override
    public IEditorSettings getEditorSettings() {
        return this.editorSettings;
    }

    /**
     * Gets the ignore rules.
     */
    @Override
    public IIgnoreRules getIgnoreRules() {
        return this.ignoreRules;
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
    public static ICMakeProjectManifest fromJson(String json) {
        return JsonObjectStream.deserialize(json, CMakeProjectManifest.class);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeStringProperty(propertyName, this.name);
        writer.writeStringProperty(propertyRootPath, this.rootPath);
        writer.writeCollectionProperty(propertyModules, this.modules);
        writer.writeObjectProperty(propertyEditorSettings, this.editorSettings);
        writer.writeObjectProperty(propertyIgnoreRules, this.ignoreRules);
    }

    /**
     * Reads a json.
     */
    public static ICMakeProjectManifest readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(propertyName);
        String rootPath = reader.readStringProperty(propertyRootPath);
        List<ICMakeModuleManifest> modules = reader.readListProperty(propertyModules, CMakeModuleManifest.class);

        IEditorSettings editorSettings = reader.hasProperty(propertyEditorSettings) ?
            reader.readObjectProperty(propertyEditorSettings, EditorSettings.class) :
            EditorSettings.defaultEditorSettings();

        IIgnoreRules ignoreRules = reader.hasProperty(propertyIgnoreRules) ?
            reader.readObjectProperty(propertyIgnoreRules, IgnoreRules.class) :
            IgnoreRules.defaultIgnoreRules();

        return new CMakeProjectManifest(
            name,
            rootPath,
            modules,
            editorSettings,
            ignoreRules);
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
    public boolean isEqual(ICMakeProjectManifest other) {
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
    public int compareTo(ICMakeProjectManifest other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICMakeProjectManifest> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a project manifest.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICMakeProjectManifest> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICMakeProjectManifest obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withString(obj.getRootPath())
                .withCollection(obj.getModulesManifests())
                .withObject(obj.getEditorSettings())
                .withObject(obj.getIgnoreRules())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICMakeProjectManifest lhs, ICMakeProjectManifest rhs) {
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
                .withObject(lhs.getEditorSettings(), rhs.getEditorSettings())
                .withObject(lhs.getIgnoreRules(), rhs.getIgnoreRules())
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
        public int compareTo(ICMakeProjectManifest lhs, ICMakeProjectManifest rhs) {
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
                .withObject(lhs.getEditorSettings(), rhs.getEditorSettings())
                .withObject(lhs.getIgnoreRules(), rhs.getIgnoreRules())
                .build();
        }
    }
}
