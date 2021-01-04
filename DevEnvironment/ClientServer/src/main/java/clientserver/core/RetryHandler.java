package clientserver.core;

import base.core.Conditions;
import base.interfaces.ILogic;
import clientserver.interfaces.IRetryLogic;
import clientserver.interfaces.IRetryHandler;
import clientserver.interfaces.IRetryPolicy;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The RetryHandler class implements a retry handler.
 */
public final class RetryHandler implements IRetryHandler {
    private final IRetryPolicy policy;
    private final ILogic idleLogic;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The RetryHandler constructor.
     */
    public RetryHandler() {
        this(
            RetryPolicy.defaultRetryPolicy(),
            null);
    }

    /**
     * The RetryHandler constructor.
     */
    public RetryHandler(IRetryPolicy policy, ILogic idleLogic) {
        Conditions.validateNotNull(
            policy,
            "The retry policy.");

        this.policy = policy;

        if (idleLogic != null) {
            this.idleLogic = idleLogic;
        } else {
            this.idleLogic = new IdleHandler(policy.getIntervalDuration());
        }
    }

    /**
     * Retries to run a logic.
     */
    @Override
    public void retry(IRetryLogic logic) {
        Conditions.validateNotNull(
            logic,
            "The retry logic for running.");

        int attemptIndex = 0;

        String logicInformation = this.getLogicInformation(logic);

        String informationalMessage = "Retry Handler started running for " + logicInformation;
        this.log.info(informationalMessage);

        while (attemptIndex <= this.policy.getNumberOfAttempts()) {
            ++attemptIndex;

            String attemptInformation = this.getRetryLogicAttemptInformation(logic, attemptIndex);

            informationalMessage = "Running " + attemptInformation;
            this.log.info(informationalMessage);

            try {
                logic.run();

                informationalMessage = "Successful " + attemptInformation;
                this.log.info(informationalMessage);

                return;
            } catch (RetryException e) {
                String warningMessage = "Failed " + attemptInformation + ", with error: " + e.getMessage();
                this.log.warn(warningMessage);

                if (attemptIndex < this.policy.getNumberOfAttempts() && this.isAbsorbedException(logic, e)) {
                    this.idleLogic.run();

                    continue;
                }

                String errorMessage = "Retry Handler failed running: " + logicInformation;
                this.log.error(errorMessage);

                throw e;
            }
        }
    }

    /**
     * Checks whether an exception is absorbed.
     */
    private boolean isAbsorbedException(IRetryLogic logic, Exception exception) {
        for (Class<?> absorbedExceptionType : logic.getAbsorbedExceptions()) {
            if (absorbedExceptionType.isAssignableFrom(exception.getClass())) {
                return true;
            }
        }

        return false;
    }

    /**
     * Gets the information of a retry logic.
     */
    private String getLogicInformation(IRetryLogic logic) {
        return "Logic: " + logic + ", with Retry Policy: " + this.policy;
    }

    /**
     * Gets the information of a retry attempt.
     */
    private String getRetryLogicAttemptInformation(IRetryLogic logic, int attemptIndex) {
        return
            "Attempt: " + attemptIndex + "/" + this.policy.getNumberOfAttempts() +
            " of Logic: " + logic;
    }
}
