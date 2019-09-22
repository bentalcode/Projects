package datastructures.list.core;

import base.core.ArrayLists;
import datastructures.list.interfaces.IListData;
import datastructures.list.interfaces.IListTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The ListTestData class implements data of tests for a list.
 */
public final class ListTestData implements IListTestData {
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
        IListData<Integer> data1 = this.getListData1();
        IListData<Integer> data2 = this.getListData2();
        IListData<Integer> data3 = this.getListData3();

        return ArrayLists.of(
            data1,
            data2,
            data3);
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
