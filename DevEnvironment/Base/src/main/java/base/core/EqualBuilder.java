package base.core;

import base.interfaces.IArrayComparator;
import base.interfaces.ICollectionComparator;
import base.interfaces.IComparatorFactory;
import base.interfaces.IEqualBuilder;
import base.interfaces.IEquatableComparator;
import base.interfaces.IIterable;
import base.interfaces.IIterableComparator;
import base.interfaces.IIterator;
import base.interfaces.IIteratorComparator;
import base.interfaces.IMapComparator;
import base.interfaces.IReverseIterator;
import base.interfaces.ITwoDimensionalArrayComparator;
import java.math.BigInteger;
import java.time.Duration;
import java.util.Collection;
import java.util.Date;
import java.util.Map;

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
        IEquatableComparator<String> comparator = this.comparatorFactory.createComparator();
        return this.withObject(lhs, rhs, comparator);
    }

    /**
     * With an enum.
     */
    @Override
    public <T extends Enum<T>> IEqualBuilder withEnum(T lhs, T rhs) {
        IEquatableComparator<T> comparator = this.comparatorFactory.createComparator();
        return this.withObject(lhs, rhs, comparator);
    }

    /**
     * With a big integer.
     */
    @Override
    public IEqualBuilder withBigInteger(BigInteger lhs, BigInteger rhs) {
        IEquatableComparator<BigInteger> comparator = this.comparatorFactory.createComparator();
        return this.withObject(lhs, rhs, comparator);
    }

    /**
     * With a date.
     */
    @Override
    public IEqualBuilder withDate(Date lhs, Date rhs) {
        IEquatableComparator<Date> comparator = this.comparatorFactory.createDateComparator();
        return this.withObject(lhs, rhs, comparator);
    }

    /**
     * With a duration.
     */
    @Override
    public IEqualBuilder withDuration(Duration lhs, Duration rhs) {
        IEquatableComparator<Duration> comparator = this.comparatorFactory.createDurationComparator();
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
        IEquatableComparator<String> comparator = this.comparatorFactory.createComparator();

        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a big integer array.
     */
    @Override
    public IEqualBuilder withBigIntegerArray(BigInteger[] lhs, BigInteger[] rhs) {
        IEquatableComparator<BigInteger> comparator = this.comparatorFactory.createComparator();

        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a boolean two dimensional array.
     */
    @Override
    public IEqualBuilder withBooleanArray(boolean[][] lhs, boolean[][] rhs) {
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

        if (lhs[0].length != rhs[0].length) {
            this.equalityStatus = false;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.equalityStatus = lhs[row][column] == rhs[row][column];

                if (!this.equalityStatus) {
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
    public IEqualBuilder withByteArray(byte[][] lhs, byte[][] rhs) {
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

        if (lhs[0].length != rhs[0].length) {
            this.equalityStatus = false;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.equalityStatus = lhs[row][column] == rhs[row][column];

                if (!this.equalityStatus) {
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
    public IEqualBuilder withShortArray(short[][] lhs, short[][] rhs) {
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

        if (lhs[0].length != rhs[0].length) {
            this.equalityStatus = false;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.equalityStatus = lhs[row][column] == rhs[row][column];

                if (!this.equalityStatus) {
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
    public IEqualBuilder withIntegerArray(int[][] lhs, int[][] rhs) {
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

        if (lhs[0].length != rhs[0].length) {
            this.equalityStatus = false;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.equalityStatus = lhs[row][column] == rhs[row][column];

                if (!this.equalityStatus) {
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
    public IEqualBuilder withLongArray(long[][] lhs, long[][] rhs) {
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

        if (lhs[0].length != rhs[0].length) {
            this.equalityStatus = false;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.equalityStatus = lhs[row][column] == rhs[row][column];

                if (!this.equalityStatus) {
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
    public IEqualBuilder withFloatArray(float[][] lhs, float[][] rhs) {
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

        if (lhs[0].length != rhs[0].length) {
            this.equalityStatus = false;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.equalityStatus = lhs[row][column] == rhs[row][column];

                if (!this.equalityStatus) {
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
    public IEqualBuilder withDoubleArray(double[][] lhs, double[][] rhs) {
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

        if (lhs[0].length != rhs[0].length) {
            this.equalityStatus = false;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.equalityStatus = lhs[row][column] == rhs[row][column];

                if (!this.equalityStatus) {
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
    public IEqualBuilder withCharacterArray(char[][] lhs, char[][] rhs) {
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

        if (lhs[0].length != rhs[0].length) {
            this.equalityStatus = false;
            return this;
        }

        int rowsLength = lhs.length;
        int columnsLength = lhs[0].length;

        for (int row = 0; row < rowsLength; ++row) {
            for (int column = 0; column < columnsLength; ++column) {

                this.equalityStatus = lhs[row][column] == rhs[row][column];

                if (!this.equalityStatus) {
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
    public IEqualBuilder withStringArray(String[][] lhs, String[][] rhs) {
        IEquatableComparator<String> comparator = this.comparatorFactory.createComparator();

        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a big integer two dimensional array.
     */
    @Override
    public IEqualBuilder withBigIntegerArray(BigInteger[][] lhs, BigInteger[][] rhs) {
        IEquatableComparator<BigInteger> comparator = this.comparatorFactory.createComparator();

        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a generic object.
     */
    @Override
    public <T extends Comparable<T>> IEqualBuilder withObject(T lhs, T rhs) {
        IEquatableComparator<T> comparator = this.comparatorFactory.createComparator();
        return this.withObject(lhs, rhs, comparator);
    }

    /**
     * With a generic object and a comparator.
     */
    @Override
    public <T> IEqualBuilder withObject(T lhs, T rhs, IEquatableComparator<T> comparator) {
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
    public <T extends Comparable<T>> IEqualBuilder withArray(T[] lhs, T[] rhs) {
        IEquatableComparator<T> comparator = this.comparatorFactory.createComparator();
        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a generic array and a comparator.
     */
    @Override
    public <T extends Comparable<T>> IEqualBuilder withArray(T[] lhs, T[] rhs, IEquatableComparator<T> comparator) {
        if (!this.equalityStatus) {
            return this;
        }

        IArrayComparator<T> arrayComparator = this.comparatorFactory.createArrayComparator();
        this.equalityStatus = arrayComparator.isEqual(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic two dimensional array.
     */
    @Override
    public <T extends Comparable<T>> IEqualBuilder withArray(T[][] lhs, T[][] rhs) {
        IEquatableComparator<T> comparator = this.comparatorFactory.createComparator();
        return this.withArray(lhs, rhs, comparator);
    }

    /**
     * With a generic two dimensional array and a comparator.
     */
    @Override
    public <T> IEqualBuilder withArray(T[][] lhs, T[][] rhs, IEquatableComparator<T> comparator) {
        if (!this.equalityStatus) {
            return this;
        }

        ITwoDimensionalArrayComparator<T> arrayComparator = this.comparatorFactory.createTwoDimensionalArrayComparator();
        this.equalityStatus = arrayComparator.isEqual(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic collection.
     */
    @Override
    public <T extends Comparable<T>> IEqualBuilder withCollection(Collection<T> lhs, Collection<T> rhs) {
        IEquatableComparator<T> comparator = this.comparatorFactory.createComparator();
        return this.withCollection(lhs, rhs, comparator);
    }

    /**
     * With a generic collection and a comparator.
     */
    @Override
    public <T extends Comparable<T>> IEqualBuilder withCollection(Collection<T> lhs, Collection<T> rhs, IEquatableComparator<T> comparator) {
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
    public <T extends Comparable<T>> IEqualBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs) {
        IEquatableComparator<T> comparator = this.comparatorFactory.createComparator();
        return this.withIterator(lhs, rhs, comparator);
    }

    /**
     * With a generic iterator and a comparator.
     */
    @Override
    public <T extends Comparable<T>> IEqualBuilder withIterator(IIterator<T> lhs, IIterator<T> rhs, IEquatableComparator<T> comparator) {
        if (!this.equalityStatus) {
            return this;
        }

        IIteratorComparator<T> iteratorComparator = this.comparatorFactory.createIteratorComparator();
        this.equalityStatus = iteratorComparator.isEqual(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic iterator and a reverse iterator.
     */
    @Override
    public <T extends Comparable<T>> IEqualBuilder withIteratorAndReverseIterator(
        IIterator<T> lhs,
        IReverseIterator<T> rhs) {

        IEquatableComparator<T> comparator = this.comparatorFactory.createComparator();
        return this.withIteratorAndReverseIterator(lhs, rhs, comparator);
    }

    /**
     * With a generic iterator, a reverse iterator and a comparator.
     */
    @Override
    public <T extends Comparable<T>> IEqualBuilder withIteratorAndReverseIterator(
        IIterator<T> lhs,
        IReverseIterator<T> rhs,
        IEquatableComparator<T> comparator) {

        if (!this.equalityStatus) {
            return this;
        }

        while (lhs.hasNext() && rhs.hasNext()) {
            T lhsElement = lhs.next();
            T rhsElement = rhs.next();

            this.equalityStatus = comparator.isEqual(lhsElement, rhsElement);

            if (!this.equalityStatus) {
                return this;
            }
        }

        this.equalityStatus = !lhs.hasNext() && !rhs.hasNext();

        return this;
    }

    /**
     * With a generic iterable.
     */
    @Override
    public <T extends Comparable<T>> IEqualBuilder withIterable(IIterable<T> lhs, IIterable<T> rhs) {
        IEquatableComparator<T> comparator = this.comparatorFactory.createComparator();
        return this.withIterable(lhs, rhs, comparator);
    }

    /**
     * With a generic iterable and a comparator.
     */
    @Override
    public <T> IEqualBuilder withIterable(IIterable<T> lhs, IIterable<T> rhs, IEquatableComparator<T> comparator) {
        if (!this.equalityStatus) {
            return this;
        }

        IIterableComparator<T> iterableComparator = this.comparatorFactory.createIterableComparator();
        this.equalityStatus = iterableComparator.isEqual(lhs, rhs, comparator);

        return this;
    }

    /**
     * With a generic iterable.
     */
    @Override
    public <TKey extends Comparable<TKey>, TValue extends Comparable<TValue>> IEqualBuilder withMap(Map<TKey, TValue> lhs, Map<TKey, TValue> rhs) {
        IEquatableComparator<TKey> keyComparator = this.comparatorFactory.createComparator();
        IEquatableComparator<TValue> valueComparator = this.comparatorFactory.createComparator();

        return this.withMap(
            lhs,
            rhs,
            keyComparator,
            valueComparator);
    }

    /**
     * With a generic map and comparators.
     */
    @Override
    public <TKey, TValue> IEqualBuilder withMap(
        Map<TKey, TValue> lhs,
        Map<TKey, TValue> rhs,
        IEquatableComparator<TKey> keyComparator,
        IEquatableComparator<TValue> valueComparator) {

        if (!this.equalityStatus) {
            return this;
        }

        IMapComparator<TKey, TValue> mapComparator = this.comparatorFactory.createMapComparator();
        this.equalityStatus = mapComparator.isEqual(lhs, rhs, keyComparator, valueComparator);

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
