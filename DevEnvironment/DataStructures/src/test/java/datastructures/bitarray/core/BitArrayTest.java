package datastructures.bitarray.core;

import base.core.Dimensions;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import datastructures.bitarray.interfaces.IBitArray;
import datastructures.bitarray.interfaces.IBitArrayData;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;

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
     * Tests the cardinality logic of a bit array.
     */
    @Test
    public void bitArrayCardinalityTest() {
        for (IBitArrayData data : this.testData.getBitArrayData().getData()) {
            this.testCardinality(data);
        }
    }

    /**
     * Tests the clearing logic of a bit array.
     */
    @Test
    public void bitArrayClearingTest() {
        for (IBitArrayData data : this.testData.getBitArrayData().getData()) {
            this.testClearing(data);
        }
    }

    /**
     * Tests the enabling logic of a bit array.
     */
    @Test
    public void bitArrayEnablingTest() {
        for (IBitArrayData data : this.testData.getBitArrayData().getData()) {
            this.testEnabling(data);
        }
    }

    /**
     * Tests the creation logic of a bit array.
     */
    private void testCreation(IBitArrayData data) {
        IBitArray bitArray = this.createBitArray(data);

        this.assertion.assertEquals(
            bitArray.size(),
            data.getData().size(),
            "Invalid creation logic of a bit array.");

        this.assertion.assertEqualsWithIterators(
            bitArray.getIterator(),
            ListIterator.make(data.getData()),
            "Invalid creation logic of a bit array.");
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
    private void testIteration(IBitArrayData data) {
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
            ListIterator.make(data.getData()),
            "BitArray");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            ListIterator.make(data.getData()),
            "BitArray");

        //
        // Test the reverse iterator of the container...
        //
        iterationTest.testReverseIteration(
            container,
            ListReverseIterator.make(data.getData()),
            "BitArray");
    }

    /**
     * Tests the clearing logic of a bit array.
     */
    private void testClearing(IBitArrayData data) {
        IBitArray bitArray = this.createBitArray(data);

        bitArray.clear();
        int numberOfOnes = bitArray.cardinality();
        int expectedNumberOfOnes = 0;

        this.assertion.assertTrue(
            numberOfOnes == expectedNumberOfOnes,
            "Incorrect logic of clearing a bit array, the number of ones should be: " +
            expectedNumberOfOnes);

        for (int startIndex = 0; startIndex < bitArray.size(); ++startIndex) {
            for (int endIndex = startIndex; endIndex < bitArray.size(); ++endIndex) {

                bitArray.enable();
                bitArray.clear(startIndex, endIndex);

                numberOfOnes = bitArray.cardinality();
                expectedNumberOfOnes = bitArray.size() - Dimensions.length(startIndex, endIndex);

                this.assertion.assertTrue(
                    numberOfOnes == expectedNumberOfOnes,
                    "Incorrect logic of clearing a bit array, the number of ones should be: " +
                    expectedNumberOfOnes);
            }
        }
    }

    /**
     * Tests the enabling logic of a bit array.
     */
    private void testEnabling(IBitArrayData data) {
        IBitArray bitArray = this.createBitArray(data);

        bitArray.enable();
        int numberOfOnes = bitArray.cardinality();
        int expectedNumberOfOnes = bitArray.size();

        this.assertion.assertTrue(
            numberOfOnes == expectedNumberOfOnes,
            "Incorrect logic of enabling a bit array, the number of ones should be: " +
            expectedNumberOfOnes);

        for (int startIndex = 0; startIndex < bitArray.size(); ++startIndex) {
            for (int endIndex = startIndex; endIndex < bitArray.size(); ++endIndex) {

                bitArray.clear();
                bitArray.enable(startIndex, endIndex);

                numberOfOnes = bitArray.cardinality();
                expectedNumberOfOnes = Dimensions.length(startIndex, endIndex);

                this.assertion.assertTrue(
                    numberOfOnes == expectedNumberOfOnes,
                    "Incorrect logic of enabling a bit array, the number of ones should be: " +
                    expectedNumberOfOnes);
            }
        }
    }

    /**
     * Tests the cardinality logic of a bit array.
     */
    private void testCardinality(IBitArrayData data) {
        IBitArray bitArray = this.createBitArray(data);

        int result = bitArray.cardinality();

        int expectedResult = 0;

        for (int index = 0; index < bitArray.size(); ++index) {
            if (bitArray.isOn(index)) {
                ++expectedResult;
            }
        }

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of a cardinality logic of a bit array.");
    }

    /**
     * Creates a bit array.
     */
    private IBitArray createBitArray(IBitArrayData data) {
        IBitArray bitArray = BitArray.make(data.getData().size());

        for (int i = 0; i < bitArray.size(); ++i) {
            if (data.getData().get(i)) {
                bitArray.turnOn(i);
            }
            else {
                bitArray.turnOff(i);
            }
        }

        return bitArray;
    }
}
