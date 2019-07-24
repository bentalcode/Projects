package testbase.core;

import base.core.DestructorHandler;
import base.core.Prime;
import base.core.ResourceReader;
import base.core.Scanners;
import base.interfaces.ITestData;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import java.nio.file.Path;
import java.util.Scanner;

/**
 * The PrimesTest class implements tests for primes.
 */
public final class PrimesTest {
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
     * Tests primes.
     */
    @Test
    public void primesTest() {
        Path path = this.testData.getPrimesResourcePath();
        String content = ResourceReader.loadString(path);

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            Scanner scanner = Scanners.createStringScanner(content);
            destructorHandler.register(scanner);

            this.testPrimes(scanner);
        }
    }

    /**
     * Tests primes.
     */
    private void testPrimes(Scanner scanner) {
        int number = 0;

        int maxCachedNumber = 100;
        Prime prime = new Prime(maxCachedNumber);

        while (scanner.hasNext()) {
            ++number;
            String currLine = scanner.nextLine();

            boolean result = prime.isPrime(number);
            boolean expectedResult = Boolean.parseBoolean(currLine);

            Assert.assertTrue(
                "The primes logic is invalid.",
                result == expectedResult);
        }
    }
}
