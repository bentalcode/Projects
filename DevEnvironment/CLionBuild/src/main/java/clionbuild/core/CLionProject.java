package clionbuild.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.Paths;
import base.interfaces.IBinaryComparator;
import clionbuild.interfaces.ICLionModule;
import clionbuild.interfaces.ICLionProject;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;
import java.nio.file.Path;
import java.util.List;

/**
 * The CLionProject implements a CLion project.
 */
public final class CLionProject implements ICLionProject {
    private static final String propertyName = "name";
    private static final String propertyRootPath = "rootPath";
    private static final String propertyModules = "modules";

    private final String name;
    private final Path rootPath;
    private final List<ICLionModule> modules;

    private final IBinaryComparator<ICLionProject> comparator = defaultComparator();
    private final int hashCode;

    /**
     * The CLionProject constructor.
     */
    public CLionProject(
        String name,
        Path rootPath,
        List<ICLionModule> modules) {

        this.name = name;
        this.rootPath = rootPath;
        this.modules = modules;

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
    public Path getRootPath() {
        return this.rootPath;
    }

    /**
     * Gets the list of the modules.
     */
    @Override
    public List<ICLionModule> getModules() {
        return this.modules;
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
        writer.writeCollectionProperty(propertyModules, this.modules);
    }

    /**
     * Reads a json.
     */
    public static ICLionProject readJson(IJsonObjectReader reader) {
        String name = reader.readStringProperty(propertyName);
        Path rootPath = reader.readProperty(propertyRootPath, value -> { return Paths.create(value); });
        List<ICLionModule> modules = reader.readListProperty(propertyModules, CLionModule.class);

        return new CLionProject(
            name,
            rootPath,
            modules);
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
    public boolean isEqual(ICLionProject other) {
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
    public int compareTo(ICLionProject other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ICLionProject> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a clion module manifest.
     */
    public static final class Comparator extends AbstractBinaryComparator<ICLionProject> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ICLionProject obj) {
            return new HashCodeBuilder(3, 5)
                .withString(obj.getName())
                .withString(obj.getRootPath().toString())
                .withCollection(obj.getModules())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ICLionProject lhs, ICLionProject rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withString(lhs.getName(), rhs.getName())
                .withObject(lhs.getRootPath(), rhs.getRootPath())
                .withCollection(lhs.getModules(), rhs.getModules())
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
        public int compareTo(ICLionProject lhs, ICLionProject rhs) {
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
                .withCollection(lhs.getModules(), rhs.getModules())
                .build();
        }
    }
}
