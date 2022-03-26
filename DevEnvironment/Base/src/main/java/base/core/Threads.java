package base.core;

import base.BaseException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Threads class implements complementary APIs for threads.
 */
public final class Threads {
    private static final Logger LOG = LoggerFactory.getLogger(Threads.class);

    /**
     * Sleeps the current thread.
     */
    public static void sleep(int milliseconds) {
        try {
            Thread.sleep(milliseconds);
        }
        catch (InterruptedException exception) {
            String errorMessage =
                "The current thread failed sleeping for: " + milliseconds + " milliseconds " +
                ", due to the following error: " + exception.getMessage();

            LOG.error(errorMessage);
            throw new BaseException(errorMessage);
        }
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Threads() {
    }
}
