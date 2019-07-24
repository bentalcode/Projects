package base.core;

import base.interfaces.IArrayComparator;
import base.interfaces.IBinaryComparator;
import base.interfaces.ICollectionComparator;
import base.interfaces.IComparatorFactory;
import base.interfaces.IEqualBuilder;
import base.interfaces.IIterator;

import java.util.Collection;

/**
 * The EqualBuilder class implements an equal builder.
 */
public final class EqualBuilder implements IEqualBuilder {
    private final IComparatorFactory comparatorFactory = new ComparatorFactory();

    private boolean equalityStatus = true;

    /**
     * The EqualBuilder constructor.
     */
    public EqualBuilder() {
    }

    /**
     * With an equality status.
     */
    @Override
    public IEqualBuilder withStatus(boolean status) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = status;

        return this;
    }

    /**
     * With a boolean.
     */
    @Override
    public IEqualBuilder withBoolean(boolean lhs, boolean rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = lhs == rhs;

        return this;
    }

    /**
     * With a byte.
     */
    @Override
    public IEqualBuilder withByte(byte lhs, byte rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = lhs == rhs;

        return this;
    }

    /**
     * With a short.
     */
    @Override
    public IEqualBuilder withShort(short lhs, short rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = lhs == rhs;

        return this;
    }

    /**
     * With an integer.
     */
    @Override
    public IEqualBuilder withInteger(int lhs, int rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = lhs == rhs;

        return this;
    }

    /**
     * With a long.
     */
    @Override
    public IEqualBuilder withLong(long lhs, long rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = lhs == rhs;

        return this;
    }

    /**
     * With a float.
     */
    @Override
    public IEqualBuilder withFloat(float lhs, float rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = lhs == rhs;

        return this;
    }

    /**
     * With a double.
     */
    @Override
    public IEqualBuilder withDouble(double lhs, double rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = lhs == rhs;

        return this;
    }

    /**
     * With a character.
     */
    @Override
    public IEqualBuilder withCharacter(char lhs, char rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = lhs == rhs;

        return this;
    }

    /**
     * With a string.
     */
    @Override
    public IEqualBuilder withString(String lhs, String rhs) {
        IBinaryComparator<String> comparator = this.comparatorFactory.createComparator();
        return this.withObject(lhs, rhs, comparator);
    }

    /**
     * With a boolean array.
     */
    @Override
    public IEqualBuilder withBooleanArray(boolean[] lhs, boolean[] rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null || rhs == null) {
            this.equalityStatus = false;
            return this;
        }

        if (lhs.length != rhs.length) {
            this.equalityStatus = false;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.equalityStatus = lhs[i] == rhs[i];

            if (!this.equalityStatus) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a byte array.
     */
    @Override
    public IEqualBuilder withByteArray(byte[] lhs, byte[] rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null || rhs == null) {
            this.equalityStatus = false;
            return this;
        }

        if (lhs.length != rhs.length) {
            this.equalityStatus = false;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.equalityStatus = lhs[i] == rhs[i];

            if (!this.equalityStatus) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a short array.
     */
    @Override
    public IEqualBuilder withShortArray(short[] lhs, short[] rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null || rhs == null) {
            this.equalityStatus = false;
            return this;
        }

        if (lhs.length != rhs.length) {
            this.equalityStatus = false;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.equalityStatus = lhs[i] == rhs[i];

            if (!this.equalityStatus) {
                return this;
            }
        }

        return this;
    }

    /**
     * With an integer array.
     */
    @Override
    public IEqualBuilder withIntegerArray(int[] lhs, int[] rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null || rhs == null) {
            this.equalityStatus = false;
            return this;
        }

        if (lhs.length != rhs.length) {
            this.equalityStatus = false;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.equalityStatus = lhs[i] == rhs[i];

            if (!this.equalityStatus) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a long array.
     */
    @Override
    public IEqualBuilder withLongArray(long[] lhs, long[] rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null || rhs == null) {
            this.equalityStatus = false;
            return this;
        }

        if (lhs.length != rhs.length) {
            this.equalityStatus = false;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.equalityStatus = lhs[i] == rhs[i];

            if (!this.equalityStatus) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a float array.
     */
    @Override
    public IEqualBuilder withFloatArray(float[] lhs, float[] rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null || rhs == null) {
            this.equalityStatus = false;
            return this;
        }

        if (lhs.length != rhs.length) {
            this.equalityStatus = false;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.equalityStatus = lhs[i] == rhs[i];

            if (!this.equalityStatus) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a double array.
     */
    @Override
    public IEqualBuilder withDoubleArray(double[] lhs, double[] rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null || rhs == null) {
            this.equalityStatus = false;
            return this;
        }

        if (lhs.length != rhs.length) {
            this.equalityStatus = false;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.equalityStatus = lhs[i] == rhs[i];

            if (!this.equalityStatus) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a character array.
     */
    @Override
    public IEqualBuilder withCharacterArray(char[] lhs, char[] rhs) {
        if (!this.equalityStatus) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null || rhs == null) {
            this.equalityStatus = false;
            return this;
        }

        if (lhs.length != rhs.length) {
            this.equalityStatus = false;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.equalityStatus = lhs[i] == rhs[i];

            if (!this.equalityStatus) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a string array.
     */
    @Override
    public IEqualBuilder withStringArray(String[] lhs, String[] rhs) {
        IBinaryComparator<String> comparator = this.comparatorFactory.createComparator();

        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a generic object.
     */
    @Override
    public <T> IEqualBuilder withObject(T lhs, T rhs, IBinaryComparator<T> comparator) {
        if (!this.equalityStatus) {
            return this;
        }

        this.equalityStatus = comparator.isEqual(lhs, rhs);

        return this;
    }

    /**
     * With a generic array.
     */
    @Override
    public <T> IEqualBuilder withArray(T[] lhs, T[] rhs, IBinaryComparator<T> comparator) {
        if (!this.equalityStatus) {
            return this;
        }

        IArrayComparator<T> arrayComparator = new ArrayComparator<>();
        this.equalityStatus = arrayComparator.isEqual(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic collection.
     */
    @Override
    public <T> IEqualBuilder withCollection(Collection<T> lhs, Collection<T> rhs, IBinaryComparator<T> comparator) {
        if (!this.equalityStatus) {
            return this;
        }

        ICollectionComparator<T> collectionComparator = this.comparatorFactory.createCollectionComparator();
        this.equalityStatus = collectionComparator.isEqual(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic iterator.
     */
    @Override
    public <T> IEqualBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs, IBinaryComparator<T> comparator) {
        if (!this.equalityStatus) {
            return this;
        }

        ICollectionComparator<T> collectionComparator = this.comparatorFactory.createCollectionComparator();
        this.equalityStatus = collectionComparator.isEqual(lhs, rhs, comparator);

        return this;
    }

    /**
     * Builds the resultant equality status.
     * In this case, simply return the calculated equality status.
     */
    public boolean build() {
        return this.equalityStatus;
    }
}
