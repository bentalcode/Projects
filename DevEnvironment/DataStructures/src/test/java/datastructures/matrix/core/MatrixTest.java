package datastructures.matrix.core;

import base.core.TwoDimensionalListIterator;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.matrix.interfaces.IMatrixData;
import datastructures.matrix.interfaces.IMatrix;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The MatrixTest class implements tests for a matrix.
 */
public final class MatrixTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The MatrixTest constructor.
     */
    public MatrixTest() {
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
     * Tests the creation logic of a matrix.
     */
    @Test
    public void matrixCreationTest() {
        for (IMatrixData<Integer> data : this.testData.getMatrixData().getData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the creation logic of a matrix.
     */
    private <T extends Comparable<T>> void testCreation(IMatrixData<T> data) {
        IMatrix<T> matrix = this.createMatrix(data);

        this.assertion.assertEqualsWithIterators(
            matrix.getIterator(),
            TwoDimensionalListIterator.make(data.getData()),
            "Invalid creation logic of a matrix.");
    }

    /**
     * Creates a matrix.
     */
    private <T extends Comparable<T>> IMatrix<T> createMatrix(IMatrixData<T> data) {
        IMatrix<T> matrix = new Matrix<>(data.getCreationData());
        return matrix;
    }
}
