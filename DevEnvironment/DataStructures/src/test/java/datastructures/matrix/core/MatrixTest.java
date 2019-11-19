package datastructures.matrix.core;

import base.core.TwoDimensionalListIterator;
import datastructures.core.TestData;
import datastructures.dimentions.core.Position;
import datastructures.dimentions.interfaces.IPosition;
import datastructures.interfaces.ITestData;
import datastructures.matrix.interfaces.IMatrixData;
import datastructures.matrix.interfaces.IMatrix;
import java.util.List;
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
     * Tests the logic of a creating a sub matrix.
     */
    @Test
    public void subMatrixCreationTest() {
        for (IMatrixData<Integer> data : this.testData.getMatrixData().getData()) {
            this.testSubMatrixCreation(data);
        }
    }

    /**
     * Tests the creation logic of a matrix.
     */
    private <T extends Comparable<T>> void testCreation(IMatrixData<T> data) {
        IMatrix<T> matrix = this.createMatrix(data);

        this.assertion.assertEqualsWithIterators(
            matrix.getIterator(),
            TwoDimensionalListIterator.of(data.getData()),
            "Invalid creation logic of a matrix.");
    }

    /**
     * Tests the creation logic of a sub-matrix.
     */
    private <T extends Comparable<T>> void testSubMatrixCreation(IMatrixData<T> data) {
        IMatrix<T> matrix = this.createMatrix(data);

        this.assertion.assertEqualsWithIterators(
            matrix.getIterator(),
            TwoDimensionalListIterator.of(data.getData()),
            "Invalid creation logic of a matrix.");

        for (int x = 0; x < matrix.xSize(); ++x) {
            for (int y = 0; y < matrix.ySize(); ++y) {
                IPosition bottomLowerPosition = new Position(x, y);

                int subXSize = matrix.xSize() - x;
                int subYSize = matrix.ySize() - y;

                for (int subX = 0; subX <= subXSize; ++subX) {
                    for (int subY = 0; subY <= subYSize; ++subY) {
                        IMatrix<T> subMatrix = matrix.getSubMatrix(bottomLowerPosition, subX, subY);

                        int subMatrixSize = subXSize * subYSize;

                        this.assertion.assertTrue(
                            subMatrixSize == subMatrix.size(),
                            "Invalid creation logic of a sub-matrix.");
                    }
                }
            }
        }
    }

    /**
     * Creates a matrix.
     */
    private <T extends Comparable<T>> IMatrix<T> createMatrix(IMatrixData<T> data) {
        IMatrix<T> matrix = new Matrix<>(data.getCreationData());
        return matrix;
    }
}
