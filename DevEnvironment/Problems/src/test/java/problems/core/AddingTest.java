package problems.core;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import problems.interfaces.IAdding;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The AddingTest class implements tests for an adding problem.
 */
public final class AddingTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The AddingTest constructor.
     */
    public AddingTest() {
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
     * Tests the logic for adding numbers.
     */
    @Test
    public void addNumbersTest() {
        this.testAddDecimalNumbers();
        this.testAddBinaryNumbers();
    }

    /**
     * Tests the logic for adding string numbers.
     */
    @Test
    public void addStringNumbersTest() {
        this.testAddDecimalStringNumbers();
        this.testAddBinaryStringNumbers();
    }

    /**
     * Tests the logic for adding decimal numbers.
     */
    private void testAddDecimalNumbers() {
        int[] left1 = {0};
        int[] right1 = {0};
        int[] result1 = {0};

        int[] left2 = {0};
        int[] right2 = {1};
        int[] result2 = {1};

        int[] left3 = {1};
        int[] right3 = {0};
        int[] result3 = {1};

        int[] left4 = {1};
        int[] right4 = {1};
        int[] result4 = {2};

        int[] left5 = {3, 1};
        int[] right5 = {7, 9};
        int[] result5 = {1, 1, 0};

        int[] left6 = {1, 2, 3};
        int[] right6 = {2, 3};
        int[] result6 = {1, 4, 6};

        int[] left7 = {1, 2, 3};
        int[] right7 = {8, 7};
        int[] result7 = {2, 1, 0};

        int[] left8 = {9, 9, 9};
        int[] right8 = {9, 9, 9};
        int[] result8 = {1, 9, 9, 8};

        int[] left9 = {9, 9, 9, 1};
        int[] right9 = {1, 9, 9, 9};
        int[] result9 = {1, 1, 9, 9, 0};

        int[] left10 = {1, 9, 9, 9};
        int[] right10 = {9, 9, 9, 1};
        int[] result10 = {1, 1, 9, 9, 0};

        int base = 10;

        this.testAddNumbers(left1, right1, base, result1);
        this.testAddNumbers(left2, right2, base, result2);
        this.testAddNumbers(left3, right3, base, result3);
        this.testAddNumbers(left4, right4, base, result4);
        this.testAddNumbers(left5, right5, base, result5);
        this.testAddNumbers(left6, right6, base, result6);
        this.testAddNumbers(left7, right7, base, result7);
        this.testAddNumbers(left8, right8, base, result8);
        this.testAddNumbers(left9, right9, base, result9);
        this.testAddNumbers(left10, right10, base, result10);
    }

    /**
     * Tests the logic for adding binary numbers.
     */
    private void testAddBinaryNumbers() {
        int base = 2;

        int[] left1 = {1};
        int[] right1 = {0};
        int[] result1 = {1};

        int[] left2 = {1};
        int[] right2 = {1};
        int[] result2 = {1, 0};

        int[] left3 = {1};
        int[] right3 = {1, 0};
        int[] result3 = {1, 1};

        int[] left4 = {1};
        int[] right4 = {1, 1};
        int[] result4 = {1, 0, 0};

        int[] left5 = {1};
        int[] right5 = {1, 0, 0};
        int[] result5 = {1, 0, 1};

        int[] left6 = {1};
        int[] right6 = {1, 0, 1};
        int[] result6 = {1, 1, 0};

        int[] left7 = {1};
        int[] right7 = {1, 1, 0};
        int[] result7 = {1, 1, 1};

        int[] left8 = {1};
        int[] right8 = {1, 1, 1};
        int[] result8 = {1, 0, 0, 0};

        int[] left9 = {1};
        int[] right9 = {1, 0, 0, 0};
        int[] result9 = {1, 0, 0, 1};

        int[] left10 = {1, 1, 0, 1};
        int[] right10 = {1, 0, 0, 1};
        int[] result10 = {1, 0, 1, 1, 0};

        this.testAddNumbers(left1, right1, base, result1);
        this.testAddNumbers(left2, right2, base, result2);
        this.testAddNumbers(left3, right3, base, result3);
        this.testAddNumbers(left4, right4, base, result4);
        this.testAddNumbers(left5, right5, base, result5);
        this.testAddNumbers(left6, right6, base, result6);
        this.testAddNumbers(left7, right7, base, result7);
        this.testAddNumbers(left8, right8, base, result8);
        this.testAddNumbers(left9, right9, base, result9);
        this.testAddNumbers(left10, right10, base, result10);
    }

    /**
     * Tests the logic for adding decimal string numbers.
     */
    private void testAddDecimalStringNumbers() {
        int base = 10;

        this.testAddStringNumbers("0", "0", base, "0");
        this.testAddStringNumbers("0", "1", base, "1");
        this.testAddStringNumbers("1", "0", base, "1");
        this.testAddStringNumbers("1", "1", base, "2");
        this.testAddStringNumbers("31", "79", base, "110");
        this.testAddStringNumbers("123", "23", base, "146");
        this.testAddStringNumbers("123", "87", base, "210");
        this.testAddStringNumbers("999", "999", base, "1998");
        this.testAddStringNumbers("9991", "1999", base, "11990");
        this.testAddStringNumbers("1999", "9991", base, "11990");
        this.testAddStringNumbers("1999", "9991", base, "11990");
    }

    /**
     * Tests the logic for adding binary string numbers.
     */
    private void testAddBinaryStringNumbers() {
        int base = 2;

        //
        // add(0, [0-8])...
        //
        this.testAddStringNumbers("0", "0", base, "0");
        this.testAddStringNumbers("0", "1", base, "1");
        this.testAddStringNumbers("0", "10", base, "10");
        this.testAddStringNumbers("0", "11", base, "11");
        this.testAddStringNumbers("0", "101", base, "101");
        this.testAddStringNumbers("0", "110", base, "110");
        this.testAddStringNumbers("0", "111", base, "111");
        this.testAddStringNumbers("0", "1000", base, "1000");

        //
        // add(1, [0-8])...
        //
        this.testAddStringNumbers("1", "0", base, "1");
        this.testAddStringNumbers("1", "1", base, "10");
        this.testAddStringNumbers("1", "10", base, "11");
        this.testAddStringNumbers("1", "11", base, "100");
        this.testAddStringNumbers("1", "101", base, "110");
        this.testAddStringNumbers("1", "110", base, "111");
        this.testAddStringNumbers("1", "111", base, "1000");
        this.testAddStringNumbers("1", "1000", base, "1001");

        //
        // add(2, [0-8])...
        //
        this.testAddStringNumbers("10", "0", base, "10");
        this.testAddStringNumbers("10", "1", base, "11");
        this.testAddStringNumbers("10", "10", base, "100");
        this.testAddStringNumbers("10", "11", base, "101");
        this.testAddStringNumbers("10", "101", base, "111");
        this.testAddStringNumbers("10", "110", base, "1000");
        this.testAddStringNumbers("10", "111", base, "1001");
        this.testAddStringNumbers("10", "1000", base, "1010");

        //
        // add(3, [0-8])...
        //
        this.testAddStringNumbers("11", "0", base, "11");
        this.testAddStringNumbers("11", "1", base, "100");
        this.testAddStringNumbers("11", "10", base, "101");
        this.testAddStringNumbers("11", "11", base, "110");
        this.testAddStringNumbers("11", "101", base, "1000");
        this.testAddStringNumbers("11", "110", base, "1001");
        this.testAddStringNumbers("11", "111", base, "1010");
        this.testAddStringNumbers("11", "1000", base, "1011");

        //
        // add(00, [0-8])...
        //
        this.testAddStringNumbers("00", "0", base, "0");
        this.testAddStringNumbers("00", "1", base, "1");
        this.testAddStringNumbers("00", "10", base, "10");
        this.testAddStringNumbers("00", "11", base, "11");
        this.testAddStringNumbers("00", "101", base, "101");
        this.testAddStringNumbers("00", "110", base, "110");
        this.testAddStringNumbers("00", "111", base, "111");
        this.testAddStringNumbers("00", "1000", base, "1000");

        //
        // add(01, [0-8])...
        //
        this.testAddStringNumbers("01", "0", base, "1");
        this.testAddStringNumbers("01", "1", base, "10");
        this.testAddStringNumbers("01", "10", base, "11");
        this.testAddStringNumbers("01", "11", base, "100");
        this.testAddStringNumbers("01", "101", base, "110");
        this.testAddStringNumbers("01", "110", base, "111");
        this.testAddStringNumbers("01", "111", base, "1000");
        this.testAddStringNumbers("01", "1000", base, "1001");

        //
        // add(010, [0-8])...
        //
        this.testAddStringNumbers("010", "0", base, "10");
        this.testAddStringNumbers("010", "1", base, "11");
        this.testAddStringNumbers("010", "10", base, "100");
        this.testAddStringNumbers("010", "11", base, "101");
        this.testAddStringNumbers("010", "101", base, "111");
        this.testAddStringNumbers("010", "110", base, "1000");
        this.testAddStringNumbers("010", "111", base, "1001");
        this.testAddStringNumbers("010", "1000", base, "1010");

        //
        // add(011, [0-8])...
        //
        this.testAddStringNumbers("011", "0", base, "11");
        this.testAddStringNumbers("011", "1", base, "100");
        this.testAddStringNumbers("011", "10", base, "101");
        this.testAddStringNumbers("011", "11", base, "110");
        this.testAddStringNumbers("011", "101", base, "1000");
        this.testAddStringNumbers("011", "110", base, "1001");
        this.testAddStringNumbers("011", "111", base, "1010");
        this.testAddStringNumbers("011", "1000", base, "1011");

        //
        // add(0, 0[0-8])...
        //
        this.testAddStringNumbers("0", "00", base, "0");
        this.testAddStringNumbers("0", "01", base, "1");
        this.testAddStringNumbers("0", "010", base, "10");
        this.testAddStringNumbers("0", "011", base, "11");
        this.testAddStringNumbers("0", "0101", base, "101");
        this.testAddStringNumbers("0", "0110", base, "110");
        this.testAddStringNumbers("0", "0111", base, "111");
        this.testAddStringNumbers("0", "1000", base, "1000");

        //
        // add(1, 0[0-8])...
        //
        this.testAddStringNumbers("1", "00", base, "1");
        this.testAddStringNumbers("1", "01", base, "10");
        this.testAddStringNumbers("1", "010", base, "11");
        this.testAddStringNumbers("1", "011", base, "100");
        this.testAddStringNumbers("1", "0101", base, "110");
        this.testAddStringNumbers("1", "0110", base, "111");
        this.testAddStringNumbers("1", "0111", base, "1000");
        this.testAddStringNumbers("1", "01000", base, "1001");

        //
        // add(2, 0[0-8])...
        //
        this.testAddStringNumbers("10", "00", base, "10");
        this.testAddStringNumbers("10", "01", base, "11");
        this.testAddStringNumbers("10", "010", base, "100");
        this.testAddStringNumbers("10", "011", base, "101");
        this.testAddStringNumbers("10", "0101", base, "111");
        this.testAddStringNumbers("10", "0110", base, "1000");
        this.testAddStringNumbers("10", "0111", base, "1001");
        this.testAddStringNumbers("10", "01000", base, "1010");

        //
        // add(3, 0[0-8])...
        //
        this.testAddStringNumbers("11", "00", base, "11");
        this.testAddStringNumbers("11", "01", base, "100");
        this.testAddStringNumbers("11", "010", base, "101");
        this.testAddStringNumbers("11", "011", base, "110");
        this.testAddStringNumbers("11", "0101", base, "1000");
        this.testAddStringNumbers("11", "0110", base, "1001");
        this.testAddStringNumbers("11", "0111", base, "1010");
        this.testAddStringNumbers("11", "01000", base, "1011");
    }

    /**
     * Tests the logic for adding numbers.
     */
    private void testAddNumbers(int[] left, int[] right, int base, int[] expectedResult) {
        IAdding adding = new Adding();
        int[] result = adding.add(left, right, base);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for adding numbers.");
    }

    /**
     * Tests the logic for adding string numbers.
     */
    private void testAddStringNumbers(String left, String right, int base, String expectedResult) {
        IAdding adding = new Adding();
        String result = adding.addStringNumbers(left, right, base);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for adding string numbers.");
    }
}
