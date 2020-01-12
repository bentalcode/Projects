package clientserver.core;

import base.core.ArrayLists;
import clientserver.interfaces.IRetryHandler;
import clientserver.interfaces.IRetryLogic;
import clientserver.interfaces.IRetryLogicInformation;
import clientserver.interfaces.RetryException;
import org.joda.time.Duration;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * The RetryHandlerTest class implements tests for a retry handler.
 */
public final class RetryHandlerTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The RetryHandlerTest constructor.
     */
    public RetryHandlerTest() {
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
     * Tests the retry handler logic.
     */
    @Test
    public void testRetryHandler() {
        Map<String, RetryLogicInformation> retryLogicInformation = new HashMap<>();

        IRetryLogic retryLogic1 = new RetryLogic("RetryLogic1", 3, retryLogicInformation);
        IRetryLogic retryLogic2 = new RetryLogic("RetryLogic2", 5, retryLogicInformation);

        List<IRetryLogic> logicList = ArrayLists.of(retryLogic1, retryLogic2);
        this.testRetryHandlers(logicList, retryLogicInformation);
    }

    /**
     * Tests the retry handlers.
     */
    private void testRetryHandlers(
        List<IRetryLogic> logicList,
        Map<String, RetryLogicInformation> retryLogicInformation) {

        for(IRetryLogic logic : logicList) {
            this.testRetryHandler(logic, retryLogicInformation);
        }
    }

    /**
     * Tests the retry handler.
     */
    private void testRetryHandler(
        IRetryLogic logic,
        Map<String, RetryLogicInformation> retryLogicInformation) {

        IRetryHandler retryHandler = new RetryHandler(
            RetryPolicy.defaultRetryPolicy(),
            new IdleHandler(Duration.ZERO));

        retryHandler.retry(logic);

        IRetryLogicInformation logicInformation = retryLogicInformation.get(logic.name());
        this.assertion.assertEquals(
            logicInformation.getActualSuccessfulAttempt(),
            logicInformation.getExpectedSuccessfulAttempt(),
            "Incorrect Retry Logic.");
    }

    /**
     * The RetryLogic class implements a retry logic for testing.
     */
    private static final class RetryLogic extends BaseRetryLogic {
        private final Map<String, RetryLogicInformation> retryLogicInformation;
        private int currentAttemptIndex;

        /**
         * The RetryLogic constructor.
         */
        public RetryLogic(
            String name,
            int expectedSuccessfulAttemptIndex,
            Map<String, RetryLogicInformation> retryLogicInformation) {
            super(name);

            this.retryLogicInformation = retryLogicInformation;
            this.retryLogicInformation.put(name, new RetryLogicInformation(expectedSuccessfulAttemptIndex));
        }

        /**
         * Runs the retry logic.
         */
        @Override
        public void run() {
            ++this.currentAttemptIndex;

            if (this.currentAttemptIndex < this.getExpectedSuccessfulAttemptIndex()) {
                throw new RetryException("Test Error");
            }

            this.retryLogicInformation.get(this.name()).setActualSuccessfulAttempt(this.currentAttemptIndex);
        }

        /**
         * Gets the expected successful attempt index.
         */
        private int getExpectedSuccessfulAttemptIndex() {
            return this.retryLogicInformation.get(this.name()).getExpectedSuccessfulAttempt();
        }
    }
}
