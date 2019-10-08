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
    private static int RandomCollectionsSize = 10;
    private static int RandomMinCollectionSize = 100;
    private static int RandomMaxCollectionSize = 1000;

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

        data.add(this.getBitArrayData1());
        data.add(this.getBitArrayData2());
        data.add(this.getBitArrayData3());

        for (int i = 0; i < RandomCollectionsSize; ++i) {
            data.add(this.getRandomBitArrayData(RandomMinCollectionSize, RandomMaxCollectionSize));
        }

        return data;
    }

    /**
     * Gets the data of bit array1.
     */
    private IBitArrayData getBitArrayData1() {
        List<Boolean> creationData = this.createList(5);
        List<Boolean> expectedData = creationData;

        return new BitArrayData(
                creationData,
                expectedData);
    }

    /**
     * Gets the data of bit array2.
     */
    private IBitArrayData getBitArrayData2() {
        List<Boolean> creationData = this.createList(32);
        List<Boolean> expectedData = creationData;

        return new BitArrayData(
            creationData,
            expectedData);
    }

    /**
     * Gets the data of bit array3.
     */
    private IBitArrayData getBitArrayData3() {
        List<Boolean> creationData = this.createList(500);
        List<Boolean> expectedData = creationData;

        return new BitArrayData(
            creationData,
            expectedData);
    }

    /**
     * Gets the random data of a bit array.
     */
    private IBitArrayData getRandomBitArrayData(int fromSize, int toSize) {
        int size = this.randomGenerator.nextInteger(fromSize, toSize);

        List<Boolean> creationData = this.createList(size);
        List<Boolean> expectedData = creationData;

        return new BitArrayData(
            creationData,
            expectedData);
    }

    /**
     * Creates a list of bits.
     */
    private List<Boolean> createList(int size) {
        List<Boolean> data = new ArrayList<>();

        for (int i = 0; i < size; ++i) {
            boolean currBit = (i % 2) == 0;
            data.add(currBit);
        }

        return data;
    }
}
