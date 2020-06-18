package cmakebuildsystem.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import cmakebuildsystem.interfaces.IEditorSettings;
import json.core.JsonObjectStream;
import json.interfaces.IJsonObjectReader;
import json.interfaces.IJsonObjectWriter;

/**
 * The EditorSettings class implements settings of an editor.
 */
public final class EditorSettings implements IEditorSettings {
    private static final String propertyTabSize = "tabSize";
    private static final int defaultTabSize = 4;

    private final int tabSize;

    private final IBinaryComparator<IEditorSettings> comparator = defaultComparator();
    private final int hashCode;

    /**
     * Gets the default editor settings.
     */
    public static IEditorSettings defaultEditorSettings() {
        return new EditorSettings(defaultTabSize);
    }

    /**
     * The EditorSettings constructor.
     */
    public EditorSettings(int tabSize) {
        this.tabSize = tabSize;
        this.hashCode = this.comparator.hashCode();
    }

    /**
     * Gets the size of a tab.
     */
    @Override
    public int getTabSize() {
        return this.tabSize;
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
    public static IEditorSettings fromJson(String json) {
        return JsonObjectStream.deserialize(json, EditorSettings.class);
    }

    /**
     * Writes an object to a json writer.
     */
    @Override
    public void writeJson(IJsonObjectWriter writer) {
        writer.writeIntegerProperty(propertyTabSize, this.tabSize);
    }

    /**
     * Reads a json.
     */
    public static IEditorSettings readJson(IJsonObjectReader reader) {
        int tabSize = reader.hasProperty(propertyTabSize) ?
            reader.readIntegerProperty(propertyTabSize) :
            defaultTabSize;

        return new EditorSettings(
            tabSize);
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
    public boolean isEqual(IEditorSettings other) {
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
    public int compareTo(IEditorSettings other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IEditorSettings> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of an editor settings.
     */
    public static final class Comparator extends AbstractBinaryComparator<IEditorSettings> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IEditorSettings obj) {
            return new HashCodeBuilder(3, 5)
                .withInteger(obj.getTabSize())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IEditorSettings lhs, IEditorSettings rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withInteger(lhs.getTabSize(), rhs.getTabSize())
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
        public int compareTo(IEditorSettings lhs, IEditorSettings rhs) {
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
                .withInteger(lhs.getTabSize(), rhs.getTabSize())
                .build();
        }
    }
}
