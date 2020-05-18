package clionbuild.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.Paths;
import base.interfaces.IBinaryComparator;
import clionbuild.interfaces.ICLionModule;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.nio.file.Path;
import java.util.List;

/**
 * The CLionModule class implements a CLion module.
 */
public final class CLionModule implements ICLionModule {
    private static final String propertyName = "name";
    private static final String propertyRootPath = "rootPath";
    private static final String propertyHeaderFilesPaths = "headerFilesPaths";
    private static final String propertySourceFilesPaths = "sourceFilesPaths";
    private static final String propertyCmakeListsFilePath = "cmakeListsFilePath";

    private final String name;
    private final Path rootPath;
    private final List<Path> headerFilesPaths;
    private final List<Path> sourceFilesPaths;
    private final Path cmakeListsFilePath;

    private final IBinaryComparator<ICLionModule> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CLionModule constructor.
     */
    public CLionModule(
        String name,
        Path rootPath,
        List<Path> headerFilesPaths,
        List<Path> sourceFilesPaths,
        Path cmakeListsFilePath) {

        this.name = name;
        this.rootPath = rootPath;
        this.headerFilesPaths = headerFilesPaths;
        this.sourceFilesPaths = sourceFilesPaths;
        this.cmakeListsFilePath = cmakeListsFilePath;

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
    }

    /**
     * Reads a json.
     */
    public static ICLionModule readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(propertyName);
        Path rootPath = reader.readProperty(propertyRootPath, value -> { return Paths.create(value); });
        List<Path> headerFilesPaths = reader.readListProperty(propertyHeaderFilesPaths, value -> { return Paths.create(value); });
        List<Path> sourceFilesPaths = reader.readListProperty(propertySourceFilesPaths, value -> { return Paths.create(value); });
        Path cmakeListsFilePath = reader.readProperty(propertyCmakeListsFilePath, value -> { return Paths.create(value); });

        return new CLionModule(
            name,
            rootPath,
            headerFilesPaths,
            sourceFilesPaths,
            cmakeListsFilePath);
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
    public boolean isEqual(ICLionModule other) {
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
    public int compareTo(ICLionModule other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICLionModule> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a clion module manifest.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICLionModule> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICLionModule obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withString(obj.getRootPath().toString())
                .withCollection(obj.getHeaderFilesPaths())
                .withCollection(obj.getSourceFilesPaths())
                .withObject(obj.getCMakeListsFilePath())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICLionModule lhs, ICLionModule rhs) {
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
        public int compareTo(ICLionModule lhs, ICLionModule rhs) {
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
                .build();
        }
    }
}
