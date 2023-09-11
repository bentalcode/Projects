package algorithms.core;

import algorithms.interfaces.ICatalanNumber;
import algorithms.interfaces.ITestData;
import base.interfaces.IIterator;
import java.nio.file.Path;
import java.util.List;
import testbase.core.Assertion;
import testbase.core.FileDataReader;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The CatalanNumberTest class implements tests for catalan numbers.
 */
public final class CatalanNumberTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The CatalanNumberTest constructor.
     */
    public CatalanNumberTest() {
    }

    /**
     * Tests logic of iteration of catalan numbers.
     */
    @Test
    public void catalanIterationTest() {
        Path path = this.testData.getCatalanResourcePath();
        List<Long> catalans = FileDataReader.readLongs(path, ",");
        this.testCatalanIteration(catalans);
    }

    /**
     * Tests logic of iteration of catalan numbers.
     */
    private void testCatalanIteration(List<Long> expectedCatalans) {
        ICatalanNumber catalanNumber = new CatalanNumber();
        IIterator<Long> iterator = catalanNumber.getIterator();

        int currIndex = 0;
        while (iterator.hasNext() && currIndex < expectedCatalans.size()) {
            long currCatalan = iterator.next();
            long expectedCatalan = expectedCatalans.get(currIndex);

            this.assertion.assertEquals(
                currCatalan,
                expectedCatalan,
                "The logic of iteration of catalan numbers is incorrect.");

            ++currIndex;
        }
    }
}
