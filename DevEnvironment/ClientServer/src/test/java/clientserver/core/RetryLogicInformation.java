package clientserver.core;

import clientserver.interfaces.IRetryLogicInformation;

/**
 * The RetryLogicInformation class implements information of a retry logic.
 */
public final class RetryLogicInformation implements IRetryLogicInformation {
    private final int expectedSuccessfulAttempt;
    private int actualSuccessfulAttempt;

    /**
     * The RetryLogicInformation constructor.
     */
    public RetryLogicInformation(int expectedSuccessfulAttempt) {
        this.expectedSuccessfulAttempt = expectedSuccessfulAttempt;
    }

    /**
     * Gets expected successful attempt.
     */
    @Override
    public int getExpectedSuccessfulAttempt() {
        return this.expectedSuccessfulAttempt;
    }

    /**
     * Gets actual successful attempt.
     */
    @Override
    public int getActualSuccessfulAttempt() {
        return this.actualSuccessfulAttempt;
    }

    /**
     * Sets the actual successful attempt.
     */
    public void setActualSuccessfulAttempt(int attemptIndex) {
        this.actualSuccessfulAttempt = attemptIndex;
    }
}
