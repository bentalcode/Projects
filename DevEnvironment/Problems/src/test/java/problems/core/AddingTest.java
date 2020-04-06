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
    public void addingTest() {

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

        this.testAdding(left1, right1, result1);
        this.testAdding(left2, right2, result2);
        this.testAdding(left3, right3, result3);
        this.testAdding(left4, right4, result4);
        this.testAdding(left5, right5, result5);
        this.testAdding(left6, right6, result6);
        this.testAdding(left7, right7, result7);
        this.testAdding(left8, right8, result8);
        this.testAdding(left9, right9, result9);
        this.testAdding(left10, right10, result10);
    }

    /**
     * Tests the logic for adding numbers.
     */
    private void testAdding(int[] left, int[] right, int[] expectedResult) {
        IAdding adding = new Adding();
        int[] result = adding.add(left, right);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for adding numbers.");
    }
}
