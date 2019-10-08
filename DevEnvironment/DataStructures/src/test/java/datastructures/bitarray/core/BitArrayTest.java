package datastructures.bitarray.core;

import base.core.ListIterator;
import base.core.ListReverseIterator;
import datastructures.bitarray.interfaces.IBitArray;
import datastructures.bitarray.interfaces.IBitArrayData;
import datastructures.core.TestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListData;
import datastructures.interfaces.ITestData;
import datastructures.linkedlist.interfaces.ILinkedList;
import datastructures.linkedlist.interfaces.ILinkedListData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;

import java.util.List;

/**
 * The BitArrayTest class implements tests for a bit array.
 */
public final class BitArrayTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The BitArrayTest constructor.
     */
    public BitArrayTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the creation logic of a bit array.
     */
    @Test
    public void bitArrayCreationTest() {
        for (IBitArrayData data : this.testData.getBitArrayData().getData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the turn on/off logic of a bit array.
     */
    @Test
    public void bitArrayTurnOnOffTest() {
        for (IBitArrayData data : this.testData.getBitArrayData().getData()) {
            this.testTurnOnOff(data);
        }
    }

    /**
     * Tests the iteration logic of a bit array.
     */
    @Test
    public void bitArrayIterationTest() {
        for (IBitArrayData data : this.testData.getBitArrayData().getData()) {
            this.testIteration(data);
        }
    }

    /**
     * Tests the creation logic of a bit array.
     */
    private void testCreation(IBitArrayData data) {
        IBitArray bitArray = this.createBitArray(data);

        this.assertion.assertEqualsWithIterators(
            bitArray.getIterator(),
            ListIterator.of(data.getData()),
            "Invalid creation logic of a stack.");
    }

    /**
     * Tests the turn on and off logic of a bit array.
     */
    private void testTurnOnOff(IBitArrayData data) {
        IBitArray bitArray = this.createBitArray(data);
        IBitArray expectedBitArray = BitArray.copy(bitArray);
        expectedBitArray.flip();

        for (int i = 0; i < bitArray.size(); ++i) {
            if (bitArray.isOn(i)) {
                bitArray.turnOff(i);

                this.assertion.assertTrue(
                    bitArray.isOff(i),
                    "Invalid turn off logic of a bit array.");
            }
            else
            {
                bitArray.turnOn(i);

                this.assertion.assertTrue(
                    bitArray.isOn(i),
                    "Invalid turn on logic of a bit array.");
            }
        }

        this.assertion.assertEquals(
            bitArray,
            expectedBitArray,
            "Invalid turn on/off logic of a bit array.");
    }

    /**
     * Tests the iteration logic of a bit array.
     */
    private <T extends Comparable<T>> void testIteration(IBitArrayData data) {
        //
        // Create the container...
        //
        IBitArray container = this.createBitArray(data);

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            ListIterator.of(data.getData()),
            "BitArray");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            ListIterator.of(data.getData()),
            "BitArray");

        //
        // Test the reverse iterator of the container...
        //
        iterationTest.testReverseIteration(
            container,
            ListReverseIterator.of(data.getData()),
            "BitArray");
    }

    /**
     * Creates a bit array.
     */
    private IBitArray createBitArray(IBitArrayData data) {
        IBitArray bitArray = new BitArray(data.getCreationData().size());

        for (int i = 0; i < bitArray.size(); ++i) {
            if (data.getCreationData().get(i)) {
                bitArray.turnOn(i);
            }
            else {
                bitArray.turnOff(i);
            }
        }

        return bitArray;
    }
}
