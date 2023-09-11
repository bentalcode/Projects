package datastructures.stack.core;

import base.core.Lists;
import base.core.RandomGenerator;
import base.interfaces.IRandomGenerator;
import datastructures.stack.interfaces.IStackData;
import datastructures.stack.interfaces.IStackTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The StackTestData class implements data of tests for a stack.
 */
public final class StackTestData implements IStackTestData {
    private static final int RANDOM_COLLECTIONS_SIZE = 10;
    private static final int RANDOM_MIN_COLLECTION_SIZE = 100;
    private static final int RANDOM_MAX_COLLECTION_SIZE = 1000;

    private final IRandomGenerator randomGenerator = new RandomGenerator();

    /**
     * The StackTestData constructor.
     */
    public StackTestData() {
    }

    /**
     * Gets data of the tests of a stack.
     */
    @Override
    public List<IStackData<Integer>> getData() {
        List<IStackData<Integer>> data = new ArrayList<>();

        data.add(this.getStackData1());
        data.add(this.getStackData2());
        data.add(this.getStackData3());

        for (int i = 0; i < RANDOM_COLLECTIONS_SIZE; ++i) {
            data.add(this.getRandomStackData(RANDOM_MIN_COLLECTION_SIZE, RANDOM_MAX_COLLECTION_SIZE));
        }

        return data;
    }

    /**
     * Gets the data of stack1.
     */
    private IStackData<Integer> getStackData1() {
        List<Integer> data = new ArrayList<>();

        return new StackData<>(
            Integer.class,
            data,
            data);
    }

    /**
     * Gets the data of stack2.
     */
    private IStackData<Integer> getStackData2() {
        List<Integer> creationData = this.createList(10);
        List<Integer> expectedData = Lists.reverse(creationData);

        return new StackData<>(
            Integer.class,
            creationData,
            expectedData);
    }

    /**
     * Gets the data of stack3.
     */
    private IStackData<Integer> getStackData3() {
        List<Integer> creationData = this.createList(100);
        List<Integer> expectedData = Lists.reverse(creationData);

        return new StackData<>(
            Integer.class,
            creationData,
            expectedData);
    }

    /**
     * Gets the random data of a stack.
     */
    private IStackData<Integer> getRandomStackData(int fromSize, int toSize) {
        int size = this.randomGenerator.nextInteger(fromSize, toSize);

        List<Integer> creationData = this.createList(size);
        List<Integer> expectedData = Lists.reverse(creationData);

        return new StackData<>(
            Integer.class,
            creationData,
            expectedData);
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
