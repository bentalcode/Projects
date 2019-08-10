package base.core;

import base.interfaces.IArrayComparator;
import base.interfaces.ICollectionComparator;
import base.interfaces.IComparableComparator;
import base.interfaces.IComparatorFactory;
import base.interfaces.ICompareToBuilder;
import base.interfaces.IIterator;
import base.interfaces.IIteratorComparator;
import base.interfaces.IMapComparator;
import base.interfaces.ITwoDimensionalArrayComparator;
import java.math.BigInteger;
import java.util.Collection;
import java.util.Map;

/**
 * The CompareToBuilder class implements an equal builder.
 */
public final class CompareToBuilder implements ICompareToBuilder {
    private final IComparatorFactory comparatorFactory = new ComparatorFactory();

    private int compareStatus;

    /**
     * The CompareToBuilder constructor.
     */
    public CompareToBuilder() {
    }

    /**
     * With a compare status.
     */
    @Override
    public ICompareToBuilder withCompareStatus(int status) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = status;

        return this;
    }

    /**
     * With a boolean.
     */
    @Override
    public ICompareToBuilder withBoolean(boolean lhs, boolean rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = Boolean.compare(lhs, rhs);

        return this;
    }

    /**
     * With a byte.
     */
    @Override
    public ICompareToBuilder withByte(byte lhs, byte rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = Byte.compare(lhs, rhs);

        return this;
    }

    /**
     * With a short.
     */
    @Override
    public ICompareToBuilder withShort(short lhs, short rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = Short.compare(lhs, rhs);

        return this;
    }

    /**
     * With an integer.
     */
    @Override
    public ICompareToBuilder withInteger(int lhs, int rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = Integer.compare(lhs, rhs);

        return this;
    }

    /**
     * With a long.
     */
    @Override
    public ICompareToBuilder withLong(long lhs, long rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = Long.compare(lhs, rhs);

        return this;
    }

    /**
     * With a float.
     */
    @Override
    public ICompareToBuilder withFloat(float lhs, float rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = Float.compare(lhs, rhs);

        return this;
    }

    /**
     * With a double.
     */
    @Override
    public ICompareToBuilder withDouble(double lhs, double rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = Double.compare(lhs, rhs);

        return this;
    }

    /**
     * With a character.
     */
    @Override
    public ICompareToBuilder withCharacter(char lhs, char rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = Character.compare(lhs, rhs);

        return this;
    }

    /**
     * With a string.
     */
    @Override
    public ICompareToBuilder withString(String lhs, String rhs) {
        IComparableComparator<String> comparator = this.comparatorFactory.createComparator();
        return this.withObject(lhs, rhs, comparator);
    }

    /**
     * With a big integer.
     */
    @Override
    public ICompareToBuilder withBigInteger(BigInteger lhs, BigInteger rhs) {
        IComparableComparator<BigInteger> comparator = this.comparatorFactory.createComparator();
        return this.withObject(lhs, rhs, comparator);
    }

    /**
     * With a boolean array.
     */
    @Override
    public ICompareToBuilder withBooleanArray(boolean[] lhs, boolean[] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.compareStatus = Boolean.compare(lhs[i], rhs[i]);

            if(this.compareStatus != 0) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a byte array.
     */
    @Override
    public ICompareToBuilder withByteArray(byte[] lhs, byte[] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.compareStatus = Byte.compare(lhs[i], rhs[i]);

            if(this.compareStatus != 0) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a short array.
     */
    @Override
    public ICompareToBuilder withShortArray(short[] lhs, short[] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.compareStatus = Short.compare(lhs[i], rhs[i]);

            if(this.compareStatus != 0) {
                return this;
            }
        }

        return this;
    }

    /**
     * With an integer array.
     */
    @Override
    public ICompareToBuilder withIntegerArray(int[] lhs, int[] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.compareStatus = Integer.compare(lhs[i], rhs[i]);

            if(this.compareStatus != 0) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a long array.
     */
    @Override
    public ICompareToBuilder withLongArray(long[] lhs, long[] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.compareStatus = Long.compare(lhs[i], rhs[i]);

            if(this.compareStatus != 0) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a float array.
     */
    @Override
    public ICompareToBuilder withFloatArray(float[] lhs, float[] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.compareStatus = Float.compare(lhs[i], rhs[i]);

            if(this.compareStatus != 0) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a double array.
     */
    @Override
    public ICompareToBuilder withDoubleArray(double[] lhs, double[] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.compareStatus = Double.compare(lhs[i], rhs[i]);

            if(this.compareStatus != 0) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a character array.
     */
    @Override
    public ICompareToBuilder withCharacterArray(char[] lhs, char[] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        int length = lhs.length;

        for (int i = 0; i < length; ++i) {
            this.compareStatus = Character.compare(lhs[i], rhs[i]);

            if(this.compareStatus != 0) {
                return this;
            }
        }

        return this;
    }

    /**
     * With a string array.
     */
    @Override
    public ICompareToBuilder withStringArray(String[] lhs, String[] rhs) {
        IComparableComparator<String> comparator = this.comparatorFactory.createComparator();

        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a big integer array.
     */
    @Override
    public ICompareToBuilder withBigIntegerArray(BigInteger[] lhs, BigInteger[] rhs) {
        IComparableComparator<BigInteger> comparator = this.comparatorFactory.createComparator();

        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a boolean two dimensional array.
     */
    @Override
    public ICompareToBuilder withBooleanArray(boolean[][] lhs, boolean[][] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs[0].length < rhs[0].length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs[0].length > rhs[0].length) {
            this.compareStatus = 1;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.compareStatus = Boolean.compare(lhs[row][column], rhs[row][column]);

                if(this.compareStatus != 0) {
                    return this;
                }
            }
        }

        return this;
    }

    /**
     * With a byte two dimensional array.
     */
    @Override
    public ICompareToBuilder withByteArray(byte[][] lhs, byte[][] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs[0].length < rhs[0].length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs[0].length > rhs[0].length) {
            this.compareStatus = 1;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.compareStatus = Byte.compare(lhs[row][column], rhs[row][column]);

                if(this.compareStatus != 0) {
                    return this;
                }
            }
        }

        return this;
    }

    /**
     * With a short two dimensional array.
     */
    @Override
    public ICompareToBuilder withShortArray(short[][] lhs, short[][] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs[0].length < rhs[0].length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs[0].length > rhs[0].length) {
            this.compareStatus = 1;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.compareStatus = Short.compare(lhs[row][column], rhs[row][column]);

                if(this.compareStatus != 0) {
                    return this;
                }
            }
        }

        return this;
    }

    /**
     * With an integer two dimensional array.
     */
    @Override
    public ICompareToBuilder withIntegerArray(int[][] lhs, int[][] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs[0].length < rhs[0].length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs[0].length > rhs[0].length) {
            this.compareStatus = 1;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.compareStatus = Integer.compare(lhs[row][column], rhs[row][column]);

                if(this.compareStatus != 0) {
                    return this;
                }
            }
        }

        return this;
    }

    /**
     * With a long two dimensional array.
     */
    @Override
    public ICompareToBuilder withLongArray(long[][] lhs, long[][] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs[0].length < rhs[0].length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs[0].length > rhs[0].length) {
            this.compareStatus = 1;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.compareStatus = Long.compare(lhs[row][column], rhs[row][column]);

                if(this.compareStatus != 0) {
                    return this;
                }
            }
        }

        return this;
    }

    /**
     * With a float two dimensional array.
     */
    @Override
    public ICompareToBuilder withFloatArray(float[][] lhs, float[][] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs[0].length < rhs[0].length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs[0].length > rhs[0].length) {
            this.compareStatus = 1;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.compareStatus = Float.compare(lhs[row][column], rhs[row][column]);

                if(this.compareStatus != 0) {
                    return this;
                }
            }
        }

        return this;
    }

    /**
     * With a double two dimensional array.
     */
    @Override
    public ICompareToBuilder withDoubleArray(double[][] lhs, double[][] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs[0].length < rhs[0].length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs[0].length > rhs[0].length) {
            this.compareStatus = 1;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.compareStatus = Double.compare(lhs[row][column], rhs[row][column]);

                if(this.compareStatus != 0) {
                    return this;
                }
            }
        }

        return this;
    }

    /**
     * With a character two dimensional array.
     */
    @Override
    public ICompareToBuilder withCharacterArray(char[][] lhs, char[][] rhs) {
        if (this.compareStatus != 0) {
            return this;
        }

        if (lhs == null && rhs == null) {
            return this;
        }

        if (lhs == null) {
            this.compareStatus = -1;
            return this;
        }

        if (rhs == null) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs.length < rhs.length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs.length > rhs.length) {
            this.compareStatus = 1;
            return this;
        }

        if (lhs[0].length < rhs[0].length) {
            this.compareStatus = -1;
            return this;
        }

        if (lhs[0].length > rhs[0].length) {
            this.compareStatus = 1;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.compareStatus = Character.compare(lhs[row][column], rhs[row][column]);

                if(this.compareStatus != 0) {
                    return this;
                }
            }
        }

        return this;
    }

    /**
     * With a string two dimensional array.
     */
    @Override
    public ICompareToBuilder withStringArray(String[][] lhs, String[][] rhs) {
        IComparableComparator<String> comparator = this.comparatorFactory.createComparator();

        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a big integer two dimensional array.
     */
    @Override
    public ICompareToBuilder withBigIntegerArray(BigInteger[][] lhs, BigInteger[][] rhs) {
        IComparableComparator<BigInteger> comparator = this.comparatorFactory.createComparator();

        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a generic.
     */
    @Override
    public <T> ICompareToBuilder withObject(T lhs, T rhs, IComparableComparator<T> comparator) {
        if (this.compareStatus != 0) {
            return this;
        }

        this.compareStatus = comparator.compareTo(lhs, rhs);

        return this;
    }

    /**
     * With a generic array.
     */
    @Override
    public <T> ICompareToBuilder withArray(T[] lhs, T[] rhs, IComparableComparator<T> comparator) {
        if (this.compareStatus != 0) {
            return this;
        }

        IArrayComparator<T> arrayComparator = this.comparatorFactory.createArrayComparator();
        this.compareStatus = arrayComparator.compareTo(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic two dimensional array.
     */
    @Override
    public <T> ICompareToBuilder withArray(T[][] lhs, T[][] rhs, IComparableComparator<T> comparator) {
        if (this.compareStatus != 0) {
            return this;
        }

        ITwoDimensionalArrayComparator<T> arrayComparator = this.comparatorFactory.createTwoDimensionalArrayComparator();
        this.compareStatus = arrayComparator.compareTo(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic collection.
     */
    public <T> ICompareToBuilder withCollection(Collection<T> lhs, Collection<T> rhs, IComparableComparator<T> comparator) {
        if (this.compareStatus != 0) {
            return this;
        }

        ICollectionComparator<T> collectionComparator = this.comparatorFactory.createCollectionComparator();
        this.compareStatus = collectionComparator.compareTo(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic iterator.
     */
    @Override
    public <T> ICompareToBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs, IComparableComparator<T> comparator) {
        if (this.compareStatus != 0) {
            return this;
        }

        IIteratorComparator<T> collectionComparator = this.comparatorFactory.createIteratorComparator();
        this.compareStatus = collectionComparator.compareTo(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic map.
     */
    @Override
    public <TKey, TValue> ICompareToBuilder withMap(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IComparableComparator<TKey> keyComparator,
        IComparableComparator<TValue> valueComparator) {

        if (this.compareStatus != 0) {
            return this;
        }

        IMapComparator<TKey, TValue> mapComparator = this.comparatorFactory.createMapComparator();
        this.compareStatus = mapComparator.compareTo(lhs, rhs, keyComparator, valueComparator);

        return this;
    }

    /**
     * Builds the resultant equality status.
     * In this case, simply return the calculated compare status.
     */
    public int build() {
        return this.compareStatus;
    }
}
