package problems.core;

import base.interfaces.IValidator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The NumberValidatorTest class implements tests for validating numbers.
 */
public final class NumberValidatorTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The NumberValidatorTest constructor.
     */
    public NumberValidatorTest() {
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
     * Tests the logic for validating numbers.
     */
    @Test
    public void validateNumberTest() {
        this.validateNumber("0", true);
        this.validateNumber("00", true);
        this.validateNumber("000", true);

        this.validateNumber("0.1", true);
        this.validateNumber(" 0.1", true);
        this.validateNumber("0.1 ", true);
        this.validateNumber(" 0.1 ", true);

        this.validateNumber(".", false);
        this.validateNumber("..", false);
        this.validateNumber(".09", true);
        this.validateNumber(".09.", false);

        this.validateNumber("abc", false);
        this.validateNumber("1a", false);
        this.validateNumber("1 a", false);
        this.validateNumber("a1", false);

        this.validateNumber("-", false);
        this.validateNumber("+", false);
        this.validateNumber("++1", false);
        this.validateNumber("--1", false);
        this.validateNumber(" --6 ", false);
        this.validateNumber("-+3", false);

        this.validateNumber("e", false);
        this.validateNumber("2e10", true);
        this.validateNumber(" -90e3   ", true);
        this.validateNumber(" 1e", false);
        this.validateNumber("e3", false);
        this.validateNumber(" 6e-1", true);
        this.validateNumber(" 99e2.5 ", false);
        this.validateNumber("53.5e93", true);
        this.validateNumber("95a54e53", false);
        this.validateNumber(".9554e53", true);
        this.validateNumber(".9554e5.3", false);
    }

    private void validateNumber(
        String value,
        boolean expectedStatus) {

        IValidator validator = new NumberValidator(value);
        boolean status = validator.validate();

        this.assertion.assertTrue(
            status == expectedStatus,
            "The logic of a number validator is incorrect.");
    }
}

