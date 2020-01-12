package clientserver.interfaces;

/**
 * The IRetryLogicInformation interface defines information of a retry logic.
 */
public interface IRetryLogicInformation {
    /**
     * Gets expected successful attempt.
     */
    int getExpectedSuccessfulAttempt();

    /**
     * Gets actual successful attempt.
     */
    int getActualSuccessfulAttempt();
}
