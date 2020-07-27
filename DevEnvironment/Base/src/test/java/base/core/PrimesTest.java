package base.core;

import base.interfaces.IIterator;
import base.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.io.InputStream;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

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
        List<Integer> primes = readPrimesFromResource(path);
        this.testPrimeIteration(primes);
    }

    /**
     * Tests the logic of whether a number is a prime.
     */
    private void testIsPrime(Scanner scanner) {
        int maxCachedNumber = 100;
        Prime prime = new Prime(maxCachedNumber);

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
        Prime prime = new Prime();
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

    /**
     * Reads the prime numbers from a resource.
     */
    private static List<Integer> readPrimesFromResource(Path path) {
        List<Integer> result = new ArrayList<>();

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            InputStream stream = ResourceReader.open(path);
            destructorHandler.register(stream);
            Scanner scanner = Scanners.createScanner(stream);
            destructorHandler.register(scanner);

            while (scanner.hasNext()) {
                String currLine = scanner.nextLine();

                String[] primesStrings = currLine.split(",");

                for (String primeString : primesStrings) {
                    primeString = primeString.trim();
                    int prime = Integer.parseInt(primeString);
                    result.add(prime);
                }
            }
        }

        return result;
    }
}
