package clientserver.core;

import base.core.Conditions;
import base.interfaces.IRunnable;
import clientserver.ClientServerException;
import org.joda.time.Duration;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The IdleHandler class implements an idle handler.
 */
public final class IdleHandler implements IRunnable {
    private final Duration duration;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The SleepIdleLogic constructor.
     */
    public IdleHandler(Duration duration) {
        Conditions.validateNotNull(
            duration,
            "The duration to be idle.");

        this.duration = duration;
    }

    /**
     * Retries to run a logic.
     */
    @Override
    public void run() {
        long millisecondsToSleep = this.duration.getMillis();

        try {
            Thread.sleep(millisecondsToSleep);
        }
        catch (InterruptedException e) {
            String errorMessage =
                "The Idle Handler failed to sleep between retry attempts for: " +
                this.duration +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new ClientServerException(errorMessage);
        }
    }
}
