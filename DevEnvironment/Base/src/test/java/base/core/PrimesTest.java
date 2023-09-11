package base.core;

import base.interfaces.IIterator;
import base.interfaces.IPrime;
import base.interfaces.ITestData;
import java.nio.file.Path;
import java.util.List;
import java.util.Scanner;
import testbase.core.Assertion;
import testbase.core.FileDataReader;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The PrimesTest class implements tests for primes.
 */
public final class PrimesTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The PrimesTest constructor.
     */
    public PrimesTest() {
    }

    /**
     * Tests the logic of whether a number is a prime.
     */
    @Test
    public void isPrimeTest() {
        Path path = this.testData.getIsPrimeResourcePath();
        String content = ResourceReader.loadString(path);

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            Scanner scanner = Scanners.createStringScanner(content);
            destructorHandler.register(scanner);

            this.testIsPrime(scanner);
        }
    }

    /**
     * Tests logic of iteration of primes.
     */
    @Test
    public void primeIterationTest() {
        Path path = this.testData.getPrimesResourcePath();
        List<Integer> primes = FileDataReader.readIntegers(path, ",");
        this.testPrimeIteration(primes);
    }

    /**
     * Tests the logic of whether a number is a prime.
     */
    private void testIsPrime(Scanner scanner) {
        int maxCachedNumber = 100;
        IPrime prime = new Prime(maxCachedNumber);

        int number = 0;
        while (scanner.hasNext()) {
            ++number;
            String currLine = scanner.nextLine();

            boolean result = prime.isPrime(number);
            boolean expectedResult = Boolean.parseBoolean(currLine);

            this.assertion.assertEquals(
                result,
                expectedResult,
                "The logic of is-prime logic is incorrect.");
        }
    }

    /**
     * Tests logic of iteration of primes.
     */
    private void testPrimeIteration(List<Integer> expectedPrimes) {
        IPrime prime = new Prime();
        IIterator<Integer> iterator = prime.getIterator();

        int currIndex = 0;
        while (iterator.hasNext() && currIndex < expectedPrimes.size()) {
            int currPrime = iterator.next();
            int expectedPrime = expectedPrimes.get(currIndex);

            this.assertion.assertEquals(
                currPrime,
                expectedPrime,
                "The logic of iteration of primes is incorrect.");

            ++currIndex;
        }
    }
}
