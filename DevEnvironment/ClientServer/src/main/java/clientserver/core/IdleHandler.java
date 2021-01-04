package clientserver.core;

import base.core.Conditions;
import base.interfaces.ILogic;
import clientserver.ClientServerException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.time.Duration;

/**
 * The IdleHandler class implements an idle handler.
 */
public final class IdleHandler implements ILogic {
    private final Duration duration;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The IdleHandler constructor.
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
        long millisecondsToSleep = this.duration.toMillis();

        try {
            Thread.sleep(millisecondsToSleep);
        } catch (InterruptedException e) {
            String errorMessage =
                "The Idle Handler failed to sleep between retry attempts for: " +
                this.duration +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage);
            throw new ClientServerException(errorMessage);
        }
    }
}
