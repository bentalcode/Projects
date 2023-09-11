package datastructures.bitarray.core;

import base.core.RandomGenerator;
import base.interfaces.IRandomGenerator;
import datastructures.bitarray.interfaces.IBitArrayData;
import datastructures.bitarray.interfaces.IBitArrayTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The BitArrayTestData class implements data of tests for a bit array.
 */
public final class BitArrayTestData implements IBitArrayTestData {
    private static final int RANDOM_COLLECTIONS_SIZE = 10;
    private static final int RANDOM_MIN_COLLECTION_SIZE = 100;
    private static final int RANDOM_MAX_COLLECTION_SIZE = 1000;

    private final IRandomGenerator randomGenerator = new RandomGenerator();

    /**
     * The BitArrayTestData constructor.
     */
    public BitArrayTestData() {
    }

    /**
     * Gets data of the tests of a bit array.
     */
    @Override
    public List<IBitArrayData> getData() {
        List<IBitArrayData> data = new ArrayList<>();

        data.add(this.createBitArrayData(5));
        data.add(this.createBitArrayData(32));
        data.add(this.createBitArrayData(50));

        for (int i = 0; i < RANDOM_COLLECTIONS_SIZE; ++i) {
            data.add(this.createRandomBitArrayData(RANDOM_MIN_COLLECTION_SIZE, RANDOM_MAX_COLLECTION_SIZE));
        }

        return data;
    }

    /**
     * Creates the random data of a bit array.
     */
    private IBitArrayData createRandomBitArrayData(int fromSize, int toSize) {
        int size = this.randomGenerator.nextInteger(fromSize, toSize);
        List<Boolean> data = this.createBitArray(size);
        return new BitArrayData(data);
    }

    /**
     * Creates data of a bit array.
     */
    private IBitArrayData createBitArrayData(int size) {
        List<Boolean> data = this.createBitArray(size);
        return new BitArrayData(data);
    }

    /**
     * Creates a bit array.
     */
    private List<Boolean> createBitArray(int size) {
        List<Boolean> data = new ArrayList<>(size);

        for (int i = 0; i < size; ++i) {
            boolean currBit = (i % 2) == 0;
            data.add(currBit);
        }

        return data;
    }
}
