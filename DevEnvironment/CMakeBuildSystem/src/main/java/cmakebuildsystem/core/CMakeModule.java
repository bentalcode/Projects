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
    private static final String propertyName = "name";
    private static final String propertyRootPath = "rootPath";
    private static final String propertyHeaderFilesPaths = "headerFilesPaths";
    private static final String propertySourceFilesPaths = "sourceFilesPaths";
    private static final String propertyCmakeListsFilePath = "cmakeListsFilePath";
    private static final String propertyDependentModules = "dependentModules";

    private final String name;
    private final Path rootPath;
    private final List<Path> headerFilesPaths;
    private final List<Path> sourceFilesPaths;
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
            cmakeListsFilePath,
            "The paths of cmakelists file.");

        Conditions.validateNotNull(
            dependentModules,
            "The dependent modules.");

        this.name = name;
        this.rootPath = rootPath;
        this.headerFilesPaths = headerFilesPaths;
        this.sourceFilesPaths = sourceFilesPaths;
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
        writer.writeStringProperty(propertyName, this.name);
        writer.writeStringProperty(propertyRootPath, this.rootPath.toString());
        writer.writeCollectionProperty(propertyHeaderFilesPaths, this.headerFilesPaths, Path::toString);
        writer.writeCollectionProperty(propertySourceFilesPaths, this.sourceFilesPaths, Path::toString);
        writer.writeStringProperty(propertyCmakeListsFilePath, this.cmakeListsFilePath.toString());
        writer.writeStringCollectionProperty(propertyDependentModules, this.dependentModules);
    }

    /**
     * Reads a json.
     */
    public static ICMakeModule readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(propertyName);
        Path rootPath = reader.readProperty(propertyRootPath, value -> { return Paths.create(value); });
        List<Path> headerFilesPaths = reader.readListProperty(propertyHeaderFilesPaths, value -> { return Paths.create(value); });
        List<Path> sourceFilesPaths = reader.readListProperty(propertySourceFilesPaths, value -> { return Paths.create(value); });
        Path cmakeListsFilePath = reader.readProperty(propertyCmakeListsFilePath, value -> { return Paths.create(value); });
        List<String> dependentModules = reader.hasProperty(propertyDependentModules) ?
            reader.readStringListProperty(propertyDependentModules) :
            new ArrayList<>();

        return new CMakeModule(
            name,
            rootPath,
            headerFilesPaths,
            sourceFilesPaths,
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
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withString(obj.getRootPath().toString())
                .withCollection(obj.getHeaderFilesPaths())
                .withCollection(obj.getSourceFilesPaths())
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
                .withCollection(lhs.getHeaderFilesPaths(), rhs.getHeaderFilesPaths(), (lhsPath, rhsPath) -> lhsPath.equals(rhsPath))
                .withCollection(lhs.getSourceFilesPaths(), rhs.getSourceFilesPaths(), (lhsPath, rhsPath) -> lhsPath.equals(rhsPath))
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
                .withCollection(lhs.getHeaderFilesPaths(), rhs.getHeaderFilesPaths(), (lhsPath, rhsPath) -> lhsPath.compareTo(rhsPath))
                .withCollection(lhs.getSourceFilesPaths(), rhs.getSourceFilesPaths(), (lhsPath, rhsPath) -> lhsPath.compareTo(rhsPath))
                .withObject(lhs.getCMakeListsFilePath(), rhs.getCMakeListsFilePath())
                .withCollection(lhs.getDependentModules(), rhs.getDependentModules())
                .build();
        }
    }

    /**
     * Creates an includes variable of a module.
     */
    public static ICMakeVariable createIncludesVariable(ICMakeModuleContextData contextData) {
        ICMakeVariable variable = CMakeVariable.createVariable(
            contextData.getModule().getName(),
            contextData.getManifest().getCMakeListsManifest().getIncludesProperty());

        return variable;
    }

    /**
     * Creates an includes variable name of a module.
     */
    public static String createIncludesVariableName(ICMakeModuleContextData contextData) {
        String variableName = CMakeVariable.createVariableName(
            contextData.getModule().getName(),
            contextData.getManifest().getCMakeListsManifest().getIncludesProperty());

        return variableName;
    }

    /**
     * Creates a sources variable of a module.
     */
    public static ICMakeVariable createSourcesVariable(ICMakeModuleContextData contextData) {
        ICMakeVariable variable = CMakeVariable.createVariable(
            contextData.getModule().getName(),
            contextData.getManifest().getCMakeListsManifest().getSourcesProperty());

        return variable;
    }

    /**
     * Creates a sources variable name of a module.
     */
    public static String createSourcesVariableName(ICMakeModuleContextData contextData) {
        String variableName = CMakeVariable.createVariableName(
            contextData.getModule().getName(),
            contextData.getManifest().getCMakeListsManifest().getSourcesProperty());

        return variableName;
    }
}
