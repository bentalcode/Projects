package algorithms.core;

import algorithms.interfaces.IGrayCode;
import base.core.IntegerArrayIterator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The GrayCodeTest class implements tests for a gray code.
 */
public final class GrayCodeTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The GrayCodeTest constructor.
     */
    public GrayCodeTest() {
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
     * Tests the logic of a gray code.
     */
    @Test
    public void grayCodeTest() {
        int numberOfBits0 = 0;
        int[] grayCodes0 = {};

        int numberOfBits1 = 1;
        int[] grayCodes1 = {0, 1};

        int numberOfBits2 = 2;
        int[] grayCodes2 = {0, 1, 3, 2};

        int numberOfBits3 = 3;
        int[] grayCodes3 = {0, 1, 3, 2, 6, 7, 5, 4};

        int numberOfBits4 = 4;
        int[] grayCodes4 = {0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8};

        int numberOfBits5 = 5;
        int[] grayCodes5 = {
            0, 1, 3, 2, 6, 7, 5, 4, 12, 13,
            15, 14, 10, 11, 9, 8, 24, 25, 27, 26,
            30, 31, 29, 28, 20, 21, 23, 22, 18, 19,
            17, 16
        };

        int numberOfBits6 = 6;
        int[] grayCodes6 = {
            0, 1, 3, 2, 6, 7, 5, 4, 12, 13,
            15, 14, 10, 11, 9, 8, 24, 25, 27, 26,
            30, 31, 29, 28, 20, 21, 23, 22, 18, 19,
            17, 16, 48, 49, 51, 50, 54, 55, 53, 52,
            60, 61, 63, 62, 58, 59, 57, 56, 40, 41,
            43, 42, 46, 47, 45, 44, 36, 37, 39, 38,
            34, 35, 33, 32
        };

        int numberOfBits7 = 7;
        int[] grayCodes7 = {
              0,   1,   3,   2,   6,   7,   5,   4,  12,  13,
             15,  14,  10,  11,   9,   8,  24,  25,  27,  26,
             30,  31,  29,  28,  20,  21,  23,  22,  18,  19,
             17,  16,  48,  49,  51,  50,  54,  55,  53,  52,
             60,  61,  63,  62,  58,  59,  57,  56,  40,  41,
             43,  42,  46,  47,  45,  44,  36,  37,  39,  38,
             34,  35,  33,  32,  96,  97,  99,  98, 102, 103,
            101, 100, 108, 109, 111, 110, 106, 107, 105, 104,
            120, 121, 123, 122, 126, 127, 125, 124, 116, 117,
            119, 118, 114, 115, 113, 112,  80,  81,  83,  82,
             86,  87,  85,  84,  92,  93,  95,  94,  90,  91,
             89,  88,  72,  73,  75,  74,  78,  79,  77,  76,
             68,  69,  71,  70,  66,  67,  65,  64
        };

        int numberOfBits8 = 8;
        int[] grayCodes8 = {
              0,   1,   3,   2,   6,   7,   5,   4,  12,  13,
             15,  14,  10,  11,   9,   8,  24,  25,  27,  26,
             30,  31,  29,  28,  20,  21,  23,  22,  18,  19,
             17,  16,  48,  49,  51,  50,  54,  55,  53,  52,
             60,  61,  63,  62,  58,  59,  57,  56,  40,  41,
             43,  42,  46,  47,  45,  44,  36,  37,  39,  38,
             34,  35,  33,  32,  96,  97,  99,  98, 102, 103,
            101, 100, 108, 109, 111, 110, 106, 107, 105, 104,
            120, 121, 123, 122, 126, 127, 125, 124, 116, 117,
            119, 118, 114, 115, 113, 112,  80,  81,  83,  82,
             86,  87,  85,  84,  92,  93,  95,  94,  90,  91,
             89,  88,  72,  73,  75,  74,  78,  79,  77,  76,
             68,  69,  71,  70,  66,  67,  65,  64, 192, 193,
            195, 194, 198, 199, 197, 196, 204, 205, 207, 206,
            202, 203, 201, 200, 216, 217, 219, 218, 222, 223,
            221, 220, 212, 213, 215, 214, 210, 211, 209, 208,
            240, 241, 243, 242, 246, 247, 245, 244, 252, 253,
            255, 254, 250, 251, 249, 248, 232, 233, 235, 234,
            238, 239, 237, 236, 228, 229, 231, 230, 226, 227,
            225, 224, 160, 161, 163, 162, 166, 167, 165, 164,
            172, 173, 175, 174, 170, 171, 169, 168, 184, 185,
            187, 186, 190, 191, 189, 188, 180, 181, 183, 182,
            178, 179, 177, 176, 144, 145, 147, 146, 150, 151,
            149, 148, 156, 157, 159, 158, 154, 155, 153, 152,
            136, 137, 139, 138, 142, 143, 141, 140, 132, 133,
            135, 134, 130, 131, 129, 128
        };

        this.testGrayCode(numberOfBits0, grayCodes0);
        this.testGrayCode(numberOfBits1, grayCodes1);
        this.testGrayCode(numberOfBits2, grayCodes2);
        this.testGrayCode(numberOfBits3, grayCodes3);
        this.testGrayCode(numberOfBits4, grayCodes4);
        this.testGrayCode(numberOfBits5, grayCodes5);
        this.testGrayCode(numberOfBits6, grayCodes6);
        this.testGrayCode(numberOfBits7, grayCodes7);
        this.testGrayCode(numberOfBits8, grayCodes8);
    }

    /**
     * Tests the logic of a gray code.
     */
    private void testGrayCode(
        int numberOfBits,
        int[] expectedResult) {

        IGrayCode grayCode = new GrayCode(numberOfBits);

        this.assertion.assertEqualsWithIterators(
            grayCode.getIterator(),
            IntegerArrayIterator.make(expectedResult),
            "Invalid logic for gray codes.");
    }
}
