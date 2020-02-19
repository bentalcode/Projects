package datastructures.list.core;

import base.core.RandomGenerator;
import base.interfaces.IRandomGenerator;
import datastructures.list.interfaces.IListData;
import datastructures.list.interfaces.IListTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The ListTestData class implements data of tests for a list.
 */
public final class ListTestData implements IListTestData {
    private static int randomCollectionsSize = 10;
    private static int randomMinCollectionSize = 100;
    private static int randomMaxCollectionSize = 1000;

    private final IRandomGenerator randomGenerator = new RandomGenerator();

    /**
     * The ListTestData constructor.
     */
    public ListTestData() {
    }

    /**
     * Gets data of the tests of a list.
     */
    @Override
    public List<IListData<Integer>> getData() {
        List<IListData<Integer>> data = new ArrayList<>();

        data.add(this.getListData1());
        data.add(this.getListData2());
        data.add(this.getListData3());

        for (int i = 0; i < randomCollectionsSize; ++i) {
            data.add(this.getRandomListData(randomMinCollectionSize, randomMaxCollectionSize));
        }

        return data;
    }

    /**
     * Gets the data of list1.
     */
    private IListData<Integer> getListData1() {
        List<Integer> data = new ArrayList<>();

        return new ListData<>(
            Integer.class,
            data,
            data);
    }

    /**
     * Gets the data of list2.
     */
    private IListData<Integer> getListData2() {
        List<Integer> data = this.createList(10);

        return new ListData<>(
            Integer.class,
            data,
            data);
    }

    /**
     * Gets the data of list3.
     */
    private IListData<Integer> getListData3() {
        List<Integer> data = this.createList(100);

        return new ListData<>(
            Integer.class,
            data,
            data);
    }

    /**
     * Gets the random data of list.
     */
    private IListData<Integer> getRandomListData(int fromSize, int toSize) {
        int size = this.randomGenerator.nextInteger(fromSize, toSize);
        List<Integer> data = this.createList(size);

        return new ListData<>(
            Integer.class,
            data,
            data);
    }

    /**
     * Creates a list.
     */
    private List<Integer> createList(int size) {
        List<Integer> data = new ArrayList<>();

        int currValue = 1;
        for (int i = 0; i < size; ++i) {
            data.add(currValue);

            ++currValue;
        }

        return data;
    }
}
