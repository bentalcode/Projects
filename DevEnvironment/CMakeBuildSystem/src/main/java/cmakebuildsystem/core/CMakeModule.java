package cmakebuildsystem.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.Paths;
import base.interfaces.IBinaryComparator;
import cmakebuildsystem.interfaces.ICMakeModule;
import cmakebuildsystem.interfaces.ICMakeVariable;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The CMakeModule class implements a CMake module.
 */
public final class CMakeModule implements ICMakeModule {
    private static final String PROPERTY_NAME = "name";
    private static final String PROPERTY_ROOT_PATH = "rootPath";
    private static final String PROPERTY_HEADER_FILES_PATHS = "headerFilesPaths";
    private static final String PROPERTY_SOURCE_FILES_PATHS = "sourceFilesPaths";
    private static final String PROPERTY_BUILD_FILES_PATHS = "buildFilesPaths";
    private static final String PROPERTY_CMAKE_LISTS_FILE_PATH = "cmakeListsFilePath";
    private static final String PROPERTY_DEPENDENT_MODULES = "dependentModules";

    private final String name;
    private final Path rootPath;
    private final List<Path> headerFilesPaths;
    private final List<Path> sourceFilesPaths;
    private final List<Path> buildFilesPaths;
    private final Path cmakeListsFilePath;
    private final List<String> dependentModules;

    private final IBinaryComparator<ICMakeModule> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CMakeModule constructor.
     */
    public CMakeModule(
        String name,
        Path rootPath,
        List<Path> headerFilesPaths,
        List<Path> sourceFilesPaths,
        List<Path> buildFilesPaths,
        Path cmakeListsFilePath,
        List<String> dependentModules) {

        Conditions.validateStringNotNullOrEmpty(
            name,
            "The name of a module.");

        Conditions.validatePathNotNullOrEmpty(
            rootPath,
            "The root path of a module.");

        Conditions.validateNotNull(
            headerFilesPaths,
            "The paths of header files.");

        Conditions.validateNotNull(
            sourceFilesPaths,
            "The paths of source files.");

        Conditions.validateNotNull(
            buildFilesPaths,
            "The paths of build files.");

        Conditions.validateNotNull(
            cmakeListsFilePath,
            "The paths of cmakelists file.");

        Conditions.validateNotNull(
            dependentModules,
            "The dependent modules.");

        this.name = name;
        this.rootPath = rootPath;
        this.headerFilesPaths = headerFilesPaths;
        this.sourceFilesPaths = sourceFilesPaths;
        this.buildFilesPaths = buildFilesPaths;
        this.cmakeListsFilePath = cmakeListsFilePath;
        this.dependentModules = dependentModules;

        this.hashCode = comparator.hashCode();
    }

    /**
     * Gets the name of the module.
     */
    @Override
    public String getName() {
        return this.name;
    }

    /**
     * Gets the root path of the module.
     */
    @Override
    public Path getRootPath() {
        return this.rootPath;
    }

    /**
     * Gets the paths of the header files.
     */
    @Override
    public List<Path> getHeaderFilesPaths() {
        return this.headerFilesPaths;
    }

    /**
     * Gets the paths of the source files.
     */
    @Override
    public List<Path> getSourceFilesPaths() {
        return this.sourceFilesPaths;
    }

    /**
     * Gets the paths of the build files.
     */
    @Override
    public List<Path> getBuildFilesPaths() {
        return this.buildFilesPaths;
    }

    /**
     * Gets the path of the CMakeLists file.
     */
    @Override
    public Path getCMakeListsFilePath() {
        return this.cmakeListsFilePath;
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
        writer.writeStringProperty(PROPERTY_ROOT_PATH, this.rootPath.toString());
        writer.writeCollectionProperty(PROPERTY_HEADER_FILES_PATHS, this.headerFilesPaths, Path::toString);
        writer.writeCollectionProperty(PROPERTY_SOURCE_FILES_PATHS, this.sourceFilesPaths, Path::toString);
        writer.writeCollectionProperty(PROPERTY_BUILD_FILES_PATHS, this.buildFilesPaths, Path::toString);
        writer.writeStringProperty(PROPERTY_CMAKE_LISTS_FILE_PATH, this.cmakeListsFilePath.toString());
        writer.writeCollectionProperty(PROPERTY_DEPENDENT_MODULES, this.dependentModules);
    }

    /**
     * Reads a json.
     */
    public static ICMakeModule readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(PROPERTY_NAME);
        Path rootPath = reader.readProperty(PROPERTY_ROOT_PATH, Paths::create);
        List<Path> headerFilesPaths = reader.readListProperty(PROPERTY_HEADER_FILES_PATHS, Paths::create);
        List<Path> sourceFilesPaths = reader.readListProperty(PROPERTY_SOURCE_FILES_PATHS, Paths::create);
        List<Path> buildFilesPaths = reader.hasProperty(PROPERTY_BUILD_FILES_PATHS) ?
            reader.readListProperty(PROPERTY_BUILD_FILES_PATHS, Paths::create) :
            new ArrayList<>();

        Path cmakeListsFilePath = reader.readProperty(PROPERTY_CMAKE_LISTS_FILE_PATH, Paths::create);

        List<String> dependentModules = reader.hasProperty(PROPERTY_DEPENDENT_MODULES) ?
            reader.readStringListProperty(PROPERTY_DEPENDENT_MODULES) :
            new ArrayList<>();

        return new CMakeModule(
            name,
            rootPath,
            headerFilesPaths,
            sourceFilesPaths,
            buildFilesPaths,
            cmakeListsFilePath,
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
    public boolean isEqual(ICMakeModule other) {
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
    public int compareTo(ICMakeModule other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICMakeModule> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a cmake module manifest.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICMakeModule> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICMakeModule obj) {
            return new HashCodeBuilder(107, 109)
                .withString(obj.getName())
                .withString(obj.getRootPath().toString())
                .withCollection(obj.getHeaderFilesPaths())
                .withCollection(obj.getSourceFilesPaths())
                .withCollection(obj.getBuildFilesPaths())
                .withObject(obj.getCMakeListsFilePath())
                .withCollection(obj.getDependentModules())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICMakeModule lhs, ICMakeModule rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getName(), rhs.getName())
                .withObject(lhs.getRootPath(), rhs.getRootPath())
                .withCollection(lhs.getHeaderFilesPaths(), rhs.getHeaderFilesPaths(), Path::equals)
                .withCollection(lhs.getSourceFilesPaths(), rhs.getSourceFilesPaths(), Path::equals)
                .withCollection(lhs.getBuildFilesPaths(), rhs.getBuildFilesPaths(), Path::equals)
                .withObject(lhs.getCMakeListsFilePath(), rhs.getCMakeListsFilePath())
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
        public int compareTo(ICMakeModule lhs, ICMakeModule rhs) {
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
                .withObject(lhs.getRootPath(), rhs.getRootPath())
                .withCollection(lhs.getHeaderFilesPaths(), rhs.getHeaderFilesPaths(), Path::compareTo)
                .withCollection(lhs.getSourceFilesPaths(), rhs.getSourceFilesPaths(), Path::compareTo)
                .withCollection(lhs.getBuildFilesPaths(), rhs.getBuildFilesPaths(), Path::compareTo)
                .withObject(lhs.getCMakeListsFilePath(), rhs.getCMakeListsFilePath())
                .withCollection(lhs.getDependentModules(), rhs.getDependentModules())
                .build();
        }
    }

    /**
     * Creates an includes variable of a module.
     */
    public static ICMakeVariable createIncludesVariable(ICMakeModuleContextData contextData) {
        return CMakeVariable.createVariable(
            contextData.getModule().getName(),
            contextData.getCMakeListsManifest().getIncludesProperty());
    }

    /**
     * Creates an includes variable name of a module.
     */
    public static String createIncludesVariableName(ICMakeModuleContextData contextData) {
        return CMakeVariable.createVariableName(
            contextData.getModule().getName(),
            contextData.getCMakeListsManifest().getIncludesProperty());
    }

    /**
     * Creates a sources variable of a module.
     */
    public static ICMakeVariable createSourcesVariable(ICMakeModuleContextData contextData) {
        return CMakeVariable.createVariable(
            contextData.getModule().getName(),
            contextData.getCMakeListsManifest().getSourcesProperty());
    }

    /**
     * Creates a sources variable name of a module.
     */
    public static String createSourcesVariableName(ICMakeModuleContextData contextData) {
        return CMakeVariable.createVariableName(
            contextData.getModule().getName(),
            contextData.getCMakeListsManifest().getSourcesProperty());
    }
}
